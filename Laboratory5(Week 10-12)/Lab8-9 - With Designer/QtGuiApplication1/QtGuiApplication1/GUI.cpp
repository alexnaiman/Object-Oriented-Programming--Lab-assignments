#include "GUI.h"
#include <string>
#include "TutorialModel.h"
#include "Utils.h"
#include "qmessagebox.h"
#include <sstream>
#include "NumericFilterProxyModel.h"
#include "qdebug.h"
#include "PlayButtonDelegate.h"

GUI::GUI(Controller* c, QWidget *parent) : QMainWindow(parent), c(c)
{
	
	ui.setupUi(this);
	QMainWindow::showMaximized();
	model = new TutorialModel{c->getRepo()};
	watchlistModel = new TutorialModel{ c->getWatchlist() };
	viewsFilter = new NumericFilterProxyModel{};	
	viewsFilter->setSourceModel(model);
	//ui.tutorialView->setModel(model);
	/*for (int c = 0; c < ui.tutorialView->horizontalHeader()->count()-1; ++c)
	{
		ui.tutorialView->horizontalHeader()->setSectionResizeMode(
			c, QHeaderView::Stretch);
	}*/
	ui.tutorialView->setModel(viewsFilter);
	ui.tutorialView->resizeColumnsToContents();
	ui.tutorialView->resizeRowsToContents();

	ui.watchlistView->setModel(watchlistModel);
	/*for (int c = 0; c < ui.watchlistView->horizontalHeader()->count()-1; ++c)
	{
		ui.watchlistView->horizontalHeader()->setSectionResizeMode(
			c, QHeaderView::Stretch);
	}*/
	ui.watchlistView->resizeColumnsToContents();
	ui.watchlistView->resizeColumnToContents(6);

	ui.watchlistView->resizeRowsToContents();

	ui.tutorialView->setEditTriggers(QAbstractItemView::DoubleClicked);
	ui.tutorialView->setItemDelegate(new PlayButtonDelegate{});
	ui.watchlistView->setItemDelegate(new PlayButtonDelegate{});
	ui.tutorialView->setColumnWidth(6, 40);
	ui.watchlistView->setColumnWidth(6, 40);

	initBarChart();
	connectSignalAndSlots();
}

void GUI::addTutorial()
{
	std::string title = ui.titleLineEdit->text().toStdString();
	std::string presenter = ui.presenterLineEdit->text().toStdString();
	std::string noLikes = ui.noLikesLineEdit->text().toStdString();
	std::string duration = ui.durationLineEdit->text().toStdString();
	// get minutes and seconds
	std::vector<std::string> durationTokens = tokenize(duration, ':');
	if (durationTokens.size() != 2)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "The duration must be formated as \"M:S\"!");
		return;
	}
	std::string source = ui.sourceLineEdit->text().toStdString();
	std::string noViews = ui.noViewsLineEdit->text().toStdString();
	std::string tutorialString = presenter + ',' + title + ',' + noLikes + ',' + noViews+ ',' + durationTokens[0] + "," + durationTokens[1] + ',' + source;

	std::stringstream stream{ tutorialString };
	try
	{
		Tutorial t;
		stream >> t;
		model->addTutorialToRepository(t);
		initBarChart();

	}
	catch (ValidationException& e)
	{
		QMessageBox messageBox;
			messageBox.critical(0, "Error", QString::fromStdString("Invalid data!"));
	}
	catch (RepositoryException& e)
	{
		std::cout << e.what();
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Cannot add element! Tutorial already existing");
	}

}
void GUI::initBarChart() {
	ui.barChart->clearGraphs();
	ui.barChart->clearItems();
	ui.barChart->clearPlottables();
	QLinearGradient gradient(0, 0, 0, 400);
	gradient.setColorAt(0, QColor(90, 90, 90));
	gradient.setColorAt(0.38, QColor(105, 105, 105));
	gradient.setColorAt(1, QColor(70, 70, 70));
	ui.barChart->setBackground(QBrush(gradient));
	QCPBars *noLikes = new QCPBars(ui.barChart->xAxis, ui.barChart->yAxis);
	QCPBars *noViews = new QCPBars(ui.barChart->xAxis, ui.barChart->yAxis);
	noLikes->setAntialiased(false);
	noViews->setAntialiased(false);
	noLikes->setStackingGap(1);
	noViews->setStackingGap(1);
	// set names and colors:
	noViews->setName("No. Views");
	noViews->setPen(QPen(QColor(111, 9, 176).lighter(170)));
	noViews->setBrush(QColor(111, 9, 176));
	noLikes->setName("No. Likes");
	noLikes->setPen(QPen(QColor(250, 170, 20).lighter(150)));
	noLikes->setBrush(QColor(250, 170, 20));
	// stack bars on top of each other:
	noLikes->moveAbove(noViews);

	// prepare x axis with country labels:
	QVector<double> ticks;
	QVector<QString> labels;
	auto v = model->getRepo()->getTutorials();
	for (int i = 0; i < v->size(); i++) {
		ticks << i;
		std::string label = (*v)[i].getPresenter() + " - " + (*v)[i].getTitle();
		labels << label.c_str();
	}
	QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
	textTicker->addTicks(ticks, labels);
	ui.barChart->xAxis->setTicker(textTicker);
	ui.barChart->xAxis->setSubTicks(false);
	ui.barChart->xAxis->setTickLength(0, 4);
	ui.barChart->xAxis->setRange(0, 8);
	ui.barChart->xAxis->setBasePen(QPen(Qt::white));
	ui.barChart->xAxis->setTickPen(QPen(Qt::white));
	ui.barChart->xAxis->grid()->setVisible(true);
	ui.barChart->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
	ui.barChart->xAxis->setTickLabelColor(Qt::white);
	ui.barChart->xAxis->setLabelColor(Qt::white);

	// prepare y axis:
	ui.barChart->yAxis->setRange(0, 1000);
	ui.barChart->yAxis->setPadding(5); // a bit more space to the left border
	ui.barChart->yAxis->setLabel("Number of views + Number of likes");
	ui.barChart->yAxis->setBasePen(QPen(Qt::white));

	ui.barChart->yAxis->setTickPen(QPen(Qt::white));
	ui.barChart->yAxis->setSubTickPen(QPen(Qt::white));
	ui.barChart->yAxis->grid()->setSubGridVisible(true);
	ui.barChart->yAxis->setTickLabelColor(Qt::white);
	ui.barChart->yAxis->setLabelColor(Qt::white);
	ui.barChart->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
	ui.barChart->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

	// Add data:
	QVector<double> noViewsData, noLikesData;
	for (int i = 0; i < v->size(); i++) {
		noViewsData << (*v)[i].getNoViews();
		noLikesData << (*v)[i].getNoLikes();

	}
	noViews->setData(ticks, noViewsData);
	noLikes->setData(ticks, noLikesData);

	// setup legend:
	ui.barChart->legend->setVisible(true);
	ui.barChart->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignHCenter);
	ui.barChart->legend->setBrush(QColor(255, 255, 255, 100));
	ui.barChart->legend->setBorderPen(Qt::NoPen);
	QFont legendFont = font();
	legendFont.setPointSize(10);
	ui.barChart->legend->setFont(legendFont);
	ui.barChart->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

void GUI::removeTutorial()
{
	QItemSelectionModel *select = ui.tutorialView->selectionModel();
	QModelIndexList s = select->selectedRows();
	if (s.isEmpty()) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Null is undeletable!"));
		return;
	}
	auto index = s.at(0);
	//auto index = ui.tutorialView->
	if (index.isValid()){
		QString cellText = index.data().toString();
		qDebug() << cellText;
		int row = index.row();
		auto v = model->removeTutorialFromRepository(row);
		initBarChart();
	}

}

void GUI::removeFromWatchlist() {
	QItemSelectionModel *select = ui.watchlistView->selectionModel();
	QModelIndexList s = select->selectedRows();
	if (s.isEmpty()) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Null is undeletable!"));
		return;
	}
	auto index = s.at(0);
	//auto index = ui.tutorialView->
	if (index.isValid()) {
		QString cellText = index.data().toString();
		qDebug() << cellText;
		int row = index.row();
		auto v = watchlistModel->removeTutorialFromRepository(row);

	}
}


void GUI::setViewsFilterValue() {
	QString value = ui.noViewsFilterLineEdit->text();
	try {
	
		viewsFilter->setFilteredValue(value);
	}
	catch (ValidationException& e) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Invalid data!"));
	}
}

void GUI::configIterator()
{
	iterator.emptyIterator();
	std::string presenter = ui.presenterFilter->text().toStdString();
	std::vector<Tutorial>* s = model->getRepo()->getTutorials();
	if (presenter.size() == 0) {
		for (auto& it : *s) {
			iterator.add(it);
		}
	}
	else {
		for (auto& it : *s) {
			if (it.getPresenter() == presenter)
				iterator.add(it);
		}
	}
	updateCurrentTutorial();
}

void GUI::updateCurrentTutorial()
{
	
	Tutorial t = iterator.getCurrentTutorial();
	ui.presenterLabel->setText(QString(t.getPresenter().c_str()));
	ui.titlelabel->setText(QString(t.getTitle().c_str()));
	ui.sourceLabel->setText(QString(t.getSource().c_str()));
	ui.noLikesLabel_2->setText(QString(std::to_string(t.getNoLikes()).c_str()));
	ui.noViewsLabel_2->setText(QString(std::to_string(t.getNoViews()).c_str()));
	std::string duration = std::to_string(t.getDuration().getMinutes()) + ":" + std::to_string(t.getDuration().getSeconds());
	ui.Duration->setText(QString(duration.c_str()));

}

void GUI::addToWatchlist() {
	Tutorial t = iterator.getCurrentTutorial();
	try {
	watchlistModel->addTutorialToRepository(t);
	}
	catch (ValidationException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Invalid data!"));
	}
	catch (RepositoryException& e)
	{
		std::cout << e.what();
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Cannot add element! Tutorial already existing");
	}
}

void GUI::openCurrentTutorial() {
	Tutorial t = iterator.getCurrentTutorial();
	if(t.getPresenter()!="")  t.open();
}

void GUI::next() {
	if (iterator.getCurrentTutorial().getPresenter() != "") {
		iterator.next();
		updateCurrentTutorial();
	}
}

void GUI::likeCurrentTutorial() {
	Tutorial& t = iterator.getCurrentTutorial();
	if (t.getPresenter() == "") {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Null is undeletable!"));
		return;
	}
	t.like();
	model->likeTutorial(t);
	watchlistModel->likeTutorial(t);
	updateCurrentTutorial();
	initBarChart();

	
}

void GUI::filterByViews() {
	std::string value = ui.noViewsFilterLineEdit->text().toStdString();
	if(oldFilter!=value)
	try {
		int intValue = Validator::strToInt(value);
		//viewsFilter->setFilteredValue(intValue);
	}
	catch (ValidationException& e) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString("Invalid data!"));
	}
}


void GUI::connectSignalAndSlots()
{
	QObject::connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addTutorial()));
	QObject::connect(ui.removeButton, SIGNAL(clicked()), this, SLOT(removeTutorial()));
	QObject::connect(ui.filterButton, SIGNAL(clicked()), this, SLOT(setViewsFilterValue()));
	QObject::connect(ui.searchButtom, SIGNAL(clicked()), this, SLOT(configIterator()));
	QObject::connect(ui.addToWatchlistButton, SIGNAL(clicked()), this, SLOT(addToWatchlist()));
	QObject::connect(ui.removeFromWatchlist, SIGNAL(clicked()), this, SLOT(removeFromWatchlist()));
	QObject::connect(ui.nextButton, SIGNAL(clicked()), this, SLOT(next()));
	QObject::connect(ui.openTutorial, SIGNAL(clicked()), this, SLOT(openCurrentTutorial()));
	QObject::connect(ui.likeButton, SIGNAL(clicked()), this, SLOT(likeCurrentTutorial()));
	//QObject::connect(ui.tutorialView, SIGNAL	 (doubleClicked()), this, SLOT(initBarChart()));
	QObject::connect(ui.tutorialView->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(initBarChart()));
	QObject::connect(ui.noViewsFilterLineEdit, &QLineEdit::textChanged, this, &GUI::setViewsFilterValue);
	QObject::connect(ui.undoButton, SIGNAL(clicked()), this, SLOT(undo()));
	QObject::connect(ui.redoButton, SIGNAL(clicked()), this, SLOT(redo()));
	QObject::connect(ui.redoWatchlist, SIGNAL(clicked()), this, SLOT(redoWatchlist()));
	QObject::connect(ui.undoWatchlist, SIGNAL(clicked()), this, SLOT(undoWatchlist()));
	
}

void GUI::undo() {
	model->undo();
	ui.tutorialView->reset();
}
void GUI::redo() {
	model->redo();
	ui.tutorialView->reset();
}

void GUI::undoWatchlist() {
	watchlistModel->undo();
	model->undo();
	ui.watchlistView->reset();
	ui.tutorialView->reset();
	configIterator();
	this->updateCurrentTutorial();
}

void GUI::redoWatchlist() {
	watchlistModel->redo();
	model->redo();
	ui.watchlistView->reset();
	ui.tutorialView->reset();
	configIterator();
	this->updateCurrentTutorial();

}