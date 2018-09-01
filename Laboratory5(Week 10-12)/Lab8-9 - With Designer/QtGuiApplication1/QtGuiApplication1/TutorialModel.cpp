#include "TutorialModel.h"
#include <qmessagebox.h>
#include "Utils.h"
TutorialModel::TutorialModel():QAbstractTableModel(),undoActions(),redoActions()
{
		
}
TutorialModel::TutorialModel(IFileRepository * repo)
{
	this->repo = repo;
}
TutorialModel::~TutorialModel()
{
	delete repo;
}
int TutorialModel::rowCount(const QModelIndex & parent) const
{
	return repo->getTutorials()->size();
}
int TutorialModel::columnCount(const QModelIndex &) const
{
	return 7;
}
QVariant TutorialModel::data(const QModelIndex & index, int role) const
{
	if (!index.isValid() || role != Qt::DisplayRole)
		return QVariant();
	//if (index.column() == 1) {
		auto v = repo->getTutorials();
			
		auto tut = (*v)[index.row()];
	//}
		switch (index.column()) {
		case 0: {
				return tr(tut.getPresenter().c_str());
			}
			case 1:
				return tr(tut.getTitle().c_str());
			case 2:
				return tr(std::to_string(tut.getNoLikes()).c_str());
			case 3:
				return tr(std::to_string(tut.getNoViews()).c_str());
			case 4:
				return tr(tut.getSource().c_str());
			case 5: {
				std::string duration = std::to_string(tut.getDuration().getMinutes()) + ":" + std::to_string(tut.getDuration().getMinutes());
				return tr(duration.c_str());
			}
			case 6:
				return tr(tut.getSource().c_str());
			default:
				return QVariant();
			}
		return QVariant();
}
QVariant TutorialModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	{
		if (role != Qt::DisplayRole)
			return QVariant();

		if (orientation == Qt::Horizontal) {
			switch (section) {
			case 0:
				return tr("Presenter");

			case 1:
				return tr("Title");
			case 2:
				return tr("No. likes");
			case 3:
				return tr("No. views");
			case 4:
				return tr("Source");
			case 5:
				return tr("Duration");
			case 6:
				return tr("Play");
			default:
				return QVariant();
			}
		}
		return QVariant();
	}
}

void TutorialModel::undo()
{	
	if (undoActions.empty())
	{
		//throw RepositoryException{ "There are no more actions to undo." };
		return;
	}

	try
	{
		//undoActions.back()->executeUndo();
		std::unique_ptr<Action> last = std::move(undoActions.back());
		last->undo();

		undoActions.pop_back();
		redoActions.push_back(std::move(last));
		
	}
	catch (RepositoryException& e)
	{
		//cout << e.what() << endl;
	}
}

void TutorialModel::redo()
{
	if (redoActions.empty())
	{
		//throw RepositoryException{ "There are no more actions to undo." };
		return;
	}

	try
	{
		//undoActions.back()->executeUndo();
		std::unique_ptr<Action> last = std::move(redoActions.back());
		last->redo();

		redoActions.pop_back();
		undoActions.push_back(std::move(last));

	}
	catch (RepositoryException& e)
	{
		//cout << e.what() << endl;
	}
}

bool TutorialModel::addTutorialToRepository(Tutorial t)
{
	try {

	beginInsertRows(QModelIndex(), 0, 0);
	repo->addTutorial(t);
	std::unique_ptr<Action> action {new AddAction{ repo,t }};
	undoActions.push_back(std::move(action));
	redoActions.clear();
	endInsertRows();
	return true;
	}
	catch (RepositoryException &e)
	{
		throw e;
	}
	catch (ValidationException &e) {
		throw e;
	}
}

bool TutorialModel::removeTutorialFromRepository(int row)
{
	Tutorial v = (*repo->getTutorials())[row];
	beginInsertRows(QModelIndex(), 0, 0);
	repo->removeTutorial(v.getPresenter(), v.getTitle());
	std::unique_ptr<Action> action{ new RemoveAction{ repo,v } };
	undoActions.push_back(std::move(action));
	redoActions.clear();
	endInsertRows();
	return true;
}

Qt::ItemFlags TutorialModel::flags(const QModelIndex & index) const

{
	if (index.column() == 6)
		return Qt::DisplayRole;
	return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}


bool TutorialModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
	if (!index.isValid() || role != Qt::EditRole)
		return false;
	
		int row = index.row();

	Tutorial p= (*repo->getTutorials())[row];
	try {

		switch (index.column()) {
		case 0: {
			std::string presenter = index.data().toString().toStdString();
			//repo->updateTutorial(Tutorial{ p.getTitle(),value.toString().toStdString(),Duration{ p.getDuration().getMinutes(),p.getDuration().getSeconds() },p.getNoLikes(),p.getSource(),p.getNoViews() }, presenter, p.getTitle());
			repo->updateTutorial(TutorialFactory::MakeTutorial(p.getTitle(), value.toString().toStdString(), std::to_string(p.getDuration().getMinutes()), std::to_string(p.getDuration().getSeconds()), std::to_string(p.getNoLikes()), p.getSource(), std::to_string(p.getNoViews())), presenter, p.getTitle());
			Tutorial newT = Tutorial{ p.getTitle(),value.toString().toStdString(),Duration{ p.getDuration().getMinutes(),p.getDuration().getSeconds() },p.getNoLikes(),p.getSource(),p.getNoViews() };
			std::unique_ptr<Action> action{ new UpdateAction(repo,p,newT) };
			undoActions.push_back(std::move(action));
			redoActions.clear();
		}
				break;
		case 1: {
			std::string title = index.data().toString().toStdString();
			repo->updateTutorial(TutorialFactory::MakeTutorial(value.toString().toStdString(), p.getPresenter(), std::to_string(p.getDuration().getMinutes()), std::to_string(p.getDuration().getSeconds()), std::to_string(p.getNoLikes()), p.getSource(), std::to_string(p.getNoViews())), p.getPresenter(),title);
			Tutorial newT = TutorialFactory::MakeTutorial(value.toString().toStdString(), p.getPresenter(), std::to_string(p.getDuration().getMinutes()), std::to_string(p.getDuration().getSeconds()), std::to_string(p.getNoLikes()), p.getSource(), std::to_string(p.getNoViews()));
			std::unique_ptr<Action> action{ new UpdateAction(repo,p,newT) };
			undoActions.push_back(std::move(action));
			redoActions.clear(); 
		};

				break;
		case 2: {
			std::string noLikes = value.toString().toStdString();
			repo->updateTutorial(TutorialFactory::MakeTutorial(p.getTitle(), p.getPresenter(), std::to_string(p.getDuration().getMinutes()),std::to_string(p.getDuration().getSeconds()), noLikes, p.getSource(), std::to_string(p.getNoViews())), p.getPresenter(), p.getTitle());
			Tutorial newT = TutorialFactory::MakeTutorial(p.getTitle(), p.getPresenter(), std::to_string(p.getDuration().getMinutes()), std::to_string(p.getDuration().getSeconds()), noLikes, p.getSource(), std::to_string(p.getNoViews()));
			std::unique_ptr<Action> action{ new UpdateAction(repo,p,newT) };
			undoActions.push_back(std::move(action));
			redoActions.clear();
		};
				break;
		case 3: {
			std::string noViews = value.toString().toStdString();
			repo->updateTutorial(TutorialFactory::MakeTutorial(p.getTitle(), p.getPresenter(), std::to_string(p.getDuration().getMinutes()), std::to_string(p.getDuration().getSeconds()), std::to_string(p.getNoLikes()), p.getSource(), value.toString().toStdString()), p.getPresenter(), p.getTitle());
			Tutorial newT=TutorialFactory::MakeTutorial(p.getTitle(), p.getPresenter(), std::to_string(p.getDuration().getMinutes()), std::to_string(p.getDuration().getSeconds()), std::to_string(p.getNoLikes()), p.getSource(), value.toString().toStdString());
			std::unique_ptr<Action> action{ new UpdateAction(repo,p,newT) };
			undoActions.push_back(std::move(action));
			redoActions.clear();
		}
				break;
		case 4: {
			std::string source = value.toString().toStdString();
			repo->updateTutorial(TutorialFactory::MakeTutorial(p.getTitle(), p.getPresenter(), std::to_string(p.getDuration().getMinutes()), std::to_string(p.getDuration().getSeconds()), std::to_string(p.getNoLikes()) , source, std::to_string(p.getNoViews())), p.getPresenter(), p.getTitle());
			Tutorial newT = TutorialFactory::MakeTutorial(p.getTitle(), p.getPresenter(), std::to_string(p.getDuration().getMinutes()), std::to_string(p.getDuration().getSeconds()), std::to_string(p.getNoLikes()), source, std::to_string(p.getNoViews()));
			std::unique_ptr<Action> action{ new UpdateAction(repo,p,newT) };
			undoActions.push_back(std::move(action));
			redoActions.clear();
		}
				break;
		case 5: {
			std::string duration = value.toString().toStdString();
			std::vector<std::string> durationTokens = tokenize(duration, ':');
			if (durationTokens.size() != 2)
			{
				QMessageBox messageBox;
				messageBox.critical(0, "Error", "The duration must be formated as \"M:S\"!");
				return true;
			}
			repo->updateTutorial(TutorialFactory::MakeTutorial(p.getTitle(), p.getPresenter(), durationTokens[0], durationTokens[1], std::to_string(p.getNoLikes()), p.getSource(), std::to_string(p.getNoViews())), p.getPresenter(), p.getTitle());
			Tutorial newT = TutorialFactory::MakeTutorial(p.getTitle(), p.getPresenter(), durationTokens[0], durationTokens[1], std::to_string(p.getNoLikes()), p.getSource(), std::to_string(p.getNoViews()));
			std::unique_ptr<Action> action{ new UpdateAction(repo,p,newT) };
			undoActions.push_back(std::move(action));
			redoActions.clear();
		}
				break;
		};

	}
	catch (ValidationException& e)
	{

		QMessageBox messageBox;
		repo->updateTutorial(p, p.getPresenter(), p.getTitle());
		messageBox.critical(0, "Error", QString::fromStdString("Invalid data!"));
	}
	catch (RepositoryException& e)
	{
		std::cout << e.what();
		QMessageBox messageBox;
		repo->updateTutorial(p, p.getPresenter(), p.getTitle());

		messageBox.critical(0, "Error", "Cannot add element! Tutorial already existing");
	}

	emit dataChanged(index, index);

	return true;

}

void TutorialModel::likeTutorial(Tutorial &t)
{
	int pos = repo->findPosOfTutorial(t);
	beginResetModel();
	repo->updateTutorial(t, t.getPresenter(), t.getTitle());
	int likes = t.getNoLikes();
	likes--;
	Tutorial p = Tutorial(t.getTitle(), t.getPresenter(), Duration{ t.getDuration().getMinutes(),t.getDuration().getSeconds() }, likes, t.getSource(), t.getNoViews());
	std::unique_ptr<Action> action{ new UpdateAction(repo,p,t) };
	undoActions.push_back(std::move(action));
	redoActions.clear();
	endResetModel();
}
