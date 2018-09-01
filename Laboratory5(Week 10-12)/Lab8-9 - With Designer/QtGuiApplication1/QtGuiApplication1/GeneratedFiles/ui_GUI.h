/********************************************************************************
** Form generated from reading UI file 'GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_GUIClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *adminTab;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *leftLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *presenterLineEdit;
    QLabel *titleLabel;
    QLineEdit *titleLineEdit;
    QLabel *noLikesLabel;
    QLineEdit *noLikesLineEdit;
    QLabel *noViewsLabel;
    QLineEdit *noViewsLineEdit;
    QLabel *sourceLabels;
    QLineEdit *sourceLineEdit;
    QLabel *durationLabel;
    QLineEdit *durationLineEdit;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addButton;
    QPushButton *removeButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *filterButton;
    QLineEdit *noViewsFilterLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *undoButton;
    QPushButton *redoButton;
    QTableView *tutorialView;
    QWidget *userTab;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *presenterFilter;
    QPushButton *searchButtom;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_6;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QLabel *presenterLabel;
    QLabel *label_3;
    QLabel *titlelabel;
    QLabel *label_6;
    QLabel *sourceLabel;
    QLabel *label_7;
    QLabel *noLikesLabel_2;
    QLabel *label_8;
    QLabel *noViewsLabel_2;
    QLabel *label_9;
    QLabel *Duration;
    QLabel *label_11;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_10;
    QTableView *watchlistView;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *likeButton;
    QPushButton *nextButton;
    QPushButton *addToWatchlistButton;
    QPushButton *removeFromWatchlist;
    QPushButton *openTutorial;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *undoWatchlist;
    QPushButton *redoWatchlist;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_8;
    QCustomPlot *barChart;

    void setupUi(QMainWindow *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName(QStringLiteral("GUIClass"));
        GUIClass->resize(874, 716);
        centralWidget = new QWidget(GUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        adminTab = new QWidget();
        adminTab->setObjectName(QStringLiteral("adminTab"));
        horizontalLayout_9 = new QHBoxLayout(adminTab);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        leftLayout = new QVBoxLayout();
        leftLayout->setSpacing(6);
        leftLayout->setObjectName(QStringLiteral("leftLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(adminTab);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        presenterLineEdit = new QLineEdit(adminTab);
        presenterLineEdit->setObjectName(QStringLiteral("presenterLineEdit"));
        presenterLineEdit->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, presenterLineEdit);

        titleLabel = new QLabel(adminTab);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, titleLabel);

        titleLineEdit = new QLineEdit(adminTab);
        titleLineEdit->setObjectName(QStringLiteral("titleLineEdit"));
        titleLineEdit->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, titleLineEdit);

        noLikesLabel = new QLabel(adminTab);
        noLikesLabel->setObjectName(QStringLiteral("noLikesLabel"));
        noLikesLabel->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, noLikesLabel);

        noLikesLineEdit = new QLineEdit(adminTab);
        noLikesLineEdit->setObjectName(QStringLiteral("noLikesLineEdit"));
        noLikesLineEdit->setFont(font);

        formLayout->setWidget(2, QFormLayout::FieldRole, noLikesLineEdit);

        noViewsLabel = new QLabel(adminTab);
        noViewsLabel->setObjectName(QStringLiteral("noViewsLabel"));
        noViewsLabel->setFont(font);
        noViewsLabel->setCursor(QCursor(Qt::ClosedHandCursor));

        formLayout->setWidget(3, QFormLayout::LabelRole, noViewsLabel);

        noViewsLineEdit = new QLineEdit(adminTab);
        noViewsLineEdit->setObjectName(QStringLiteral("noViewsLineEdit"));
        noViewsLineEdit->setFont(font);
        noViewsLineEdit->setCursor(QCursor(Qt::ClosedHandCursor));

        formLayout->setWidget(3, QFormLayout::FieldRole, noViewsLineEdit);

        sourceLabels = new QLabel(adminTab);
        sourceLabels->setObjectName(QStringLiteral("sourceLabels"));
        sourceLabels->setFont(font);
        sourceLabels->setCursor(QCursor(Qt::ClosedHandCursor));

        formLayout->setWidget(4, QFormLayout::LabelRole, sourceLabels);

        sourceLineEdit = new QLineEdit(adminTab);
        sourceLineEdit->setObjectName(QStringLiteral("sourceLineEdit"));
        sourceLineEdit->setFont(font);
        sourceLineEdit->setCursor(QCursor(Qt::ClosedHandCursor));

        formLayout->setWidget(4, QFormLayout::FieldRole, sourceLineEdit);

        durationLabel = new QLabel(adminTab);
        durationLabel->setObjectName(QStringLiteral("durationLabel"));
        durationLabel->setFont(font);
        durationLabel->setCursor(QCursor(Qt::ClosedHandCursor));

        formLayout->setWidget(5, QFormLayout::LabelRole, durationLabel);

        durationLineEdit = new QLineEdit(adminTab);
        durationLineEdit->setObjectName(QStringLiteral("durationLineEdit"));
        durationLineEdit->setFont(font);
        durationLineEdit->setCursor(QCursor(Qt::ClosedHandCursor));

        formLayout->setWidget(5, QFormLayout::FieldRole, durationLineEdit);


        leftLayout->addLayout(formLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        addButton = new QPushButton(adminTab);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout_3->addWidget(addButton);

        removeButton = new QPushButton(adminTab);
        removeButton->setObjectName(QStringLiteral("removeButton"));

        horizontalLayout_3->addWidget(removeButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        filterButton = new QPushButton(adminTab);
        filterButton->setObjectName(QStringLiteral("filterButton"));

        horizontalLayout_2->addWidget(filterButton);

        noViewsFilterLineEdit = new QLineEdit(adminTab);
        noViewsFilterLineEdit->setObjectName(QStringLiteral("noViewsFilterLineEdit"));

        horizontalLayout_2->addWidget(noViewsFilterLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        undoButton = new QPushButton(adminTab);
        undoButton->setObjectName(QStringLiteral("undoButton"));

        horizontalLayout_4->addWidget(undoButton);

        redoButton = new QPushButton(adminTab);
        redoButton->setObjectName(QStringLiteral("redoButton"));

        horizontalLayout_4->addWidget(redoButton);


        verticalLayout->addLayout(horizontalLayout_4);


        leftLayout->addLayout(verticalLayout);


        horizontalLayout_9->addLayout(leftLayout);

        tutorialView = new QTableView(adminTab);
        tutorialView->setObjectName(QStringLiteral("tutorialView"));
        tutorialView->setAlternatingRowColors(true);
        tutorialView->setSelectionMode(QAbstractItemView::SingleSelection);
        tutorialView->setSelectionBehavior(QAbstractItemView::SelectRows);

        horizontalLayout_9->addWidget(tutorialView);

        tabWidget->addTab(adminTab, QString());
        userTab = new QWidget();
        userTab->setObjectName(QStringLiteral("userTab"));
        verticalLayout_3 = new QVBoxLayout(userTab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(userTab);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setPointSize(16);
        label_2->setFont(font1);

        horizontalLayout_5->addWidget(label_2);

        presenterFilter = new QLineEdit(userTab);
        presenterFilter->setObjectName(QStringLiteral("presenterFilter"));
        presenterFilter->setFont(font1);

        horizontalLayout_5->addWidget(presenterFilter);

        searchButtom = new QPushButton(userTab);
        searchButtom->setObjectName(QStringLiteral("searchButtom"));

        horizontalLayout_5->addWidget(searchButtom);


        verticalLayout_3->addLayout(horizontalLayout_5);

        label_5 = new QLabel(userTab);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_4 = new QLabel(userTab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        presenterLabel = new QLabel(userTab);
        presenterLabel->setObjectName(QStringLiteral("presenterLabel"));
        QPalette palette;
        QBrush brush(QColor(170, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        presenterLabel->setPalette(palette);
        QFont font2;
        font2.setFamily(QStringLiteral("Trebuchet MS"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        presenterLabel->setFont(font2);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, presenterLabel);

        label_3 = new QLabel(userTab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_3);

        titlelabel = new QLabel(userTab);
        titlelabel->setObjectName(QStringLiteral("titlelabel"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        titlelabel->setPalette(palette1);
        titlelabel->setFont(font2);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, titlelabel);

        label_6 = new QLabel(userTab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_6);

        sourceLabel = new QLabel(userTab);
        sourceLabel->setObjectName(QStringLiteral("sourceLabel"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        sourceLabel->setPalette(palette2);
        sourceLabel->setFont(font2);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, sourceLabel);

        label_7 = new QLabel(userTab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_7);

        noLikesLabel_2 = new QLabel(userTab);
        noLikesLabel_2->setObjectName(QStringLiteral("noLikesLabel_2"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        noLikesLabel_2->setPalette(palette3);
        noLikesLabel_2->setFont(font2);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, noLikesLabel_2);

        label_8 = new QLabel(userTab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font1);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_8);

        noViewsLabel_2 = new QLabel(userTab);
        noViewsLabel_2->setObjectName(QStringLiteral("noViewsLabel_2"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        noViewsLabel_2->setPalette(palette4);
        noViewsLabel_2->setFont(font2);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, noViewsLabel_2);

        label_9 = new QLabel(userTab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font1);

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_9);

        Duration = new QLabel(userTab);
        Duration->setObjectName(QStringLiteral("Duration"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        Duration->setPalette(palette5);
        Duration->setFont(font2);
        Duration->setTextFormat(Qt::PlainText);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, Duration);


        horizontalLayout_6->addLayout(formLayout_2);

        label_11 = new QLabel(userTab);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_6->addWidget(label_11);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_10 = new QLabel(userTab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);

        verticalLayout_2->addWidget(label_10);

        watchlistView = new QTableView(userTab);
        watchlistView->setObjectName(QStringLiteral("watchlistView"));
        watchlistView->setSelectionMode(QAbstractItemView::ContiguousSelection);
        watchlistView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_2->addWidget(watchlistView);


        horizontalLayout_6->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        likeButton = new QPushButton(userTab);
        likeButton->setObjectName(QStringLiteral("likeButton"));

        horizontalLayout_7->addWidget(likeButton);

        nextButton = new QPushButton(userTab);
        nextButton->setObjectName(QStringLiteral("nextButton"));

        horizontalLayout_7->addWidget(nextButton);

        addToWatchlistButton = new QPushButton(userTab);
        addToWatchlistButton->setObjectName(QStringLiteral("addToWatchlistButton"));

        horizontalLayout_7->addWidget(addToWatchlistButton);

        removeFromWatchlist = new QPushButton(userTab);
        removeFromWatchlist->setObjectName(QStringLiteral("removeFromWatchlist"));
        removeFromWatchlist->setCheckable(false);

        horizontalLayout_7->addWidget(removeFromWatchlist);

        openTutorial = new QPushButton(userTab);
        openTutorial->setObjectName(QStringLiteral("openTutorial"));

        horizontalLayout_7->addWidget(openTutorial);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        undoWatchlist = new QPushButton(userTab);
        undoWatchlist->setObjectName(QStringLiteral("undoWatchlist"));

        horizontalLayout_10->addWidget(undoWatchlist);

        redoWatchlist = new QPushButton(userTab);
        redoWatchlist->setObjectName(QStringLiteral("redoWatchlist"));

        horizontalLayout_10->addWidget(redoWatchlist);


        verticalLayout_3->addLayout(horizontalLayout_10);

        tabWidget->addTab(userTab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        horizontalLayout_8 = new QHBoxLayout(tab_3);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        barChart = new QCustomPlot(tab_3);
        barChart->setObjectName(QStringLiteral("barChart"));

        horizontalLayout_8->addWidget(barChart);

        tabWidget->addTab(tab_3, QString());

        horizontalLayout->addWidget(tabWidget);

        GUIClass->setCentralWidget(centralWidget);

        retranslateUi(GUIClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *GUIClass)
    {
        GUIClass->setWindowTitle(QApplication::translate("GUIClass", "GUI", nullptr));
        label->setText(QApplication::translate("GUIClass", "Presenter", nullptr));
        presenterLineEdit->setText(QString());
        titleLabel->setText(QApplication::translate("GUIClass", "Title", nullptr));
        noLikesLabel->setText(QApplication::translate("GUIClass", "No. likes", nullptr));
        noViewsLabel->setText(QApplication::translate("GUIClass", "No. Views", nullptr));
        sourceLabels->setText(QApplication::translate("GUIClass", "Source", nullptr));
        durationLabel->setText(QApplication::translate("GUIClass", "Duration", nullptr));
        addButton->setText(QApplication::translate("GUIClass", "Add a tutorial", nullptr));
        removeButton->setText(QApplication::translate("GUIClass", "Remove a tutorial", nullptr));
        filterButton->setText(QApplication::translate("GUIClass", "Filter By Number of views", nullptr));
        undoButton->setText(QApplication::translate("GUIClass", "Undo", nullptr));
        redoButton->setText(QApplication::translate("GUIClass", "Redo", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(adminTab), QApplication::translate("GUIClass", "Admin", nullptr));
        label_2->setText(QApplication::translate("GUIClass", "Enter presenter:", nullptr));
        searchButtom->setText(QApplication::translate("GUIClass", "Search", nullptr));
        label_5->setText(QString());
        label_4->setText(QApplication::translate("GUIClass", "Presenter:", nullptr));
        presenterLabel->setText(QApplication::translate("GUIClass", "No tutorial Selected", nullptr));
        label_3->setText(QApplication::translate("GUIClass", "Title:", nullptr));
        titlelabel->setText(QApplication::translate("GUIClass", "No tutorial Selected", nullptr));
        label_6->setText(QApplication::translate("GUIClass", "Source:", nullptr));
        sourceLabel->setText(QApplication::translate("GUIClass", "No tutorial Selected", nullptr));
        label_7->setText(QApplication::translate("GUIClass", "No. Likes:", nullptr));
        noLikesLabel_2->setText(QApplication::translate("GUIClass", "No tutorial Selected", nullptr));
        label_8->setText(QApplication::translate("GUIClass", "No. views:", nullptr));
        noViewsLabel_2->setText(QApplication::translate("GUIClass", "No tutorial Selected", nullptr));
        label_9->setText(QApplication::translate("GUIClass", "Duration:", nullptr));
        Duration->setText(QApplication::translate("GUIClass", "No tutorial Selected", nullptr));
        label_11->setText(QString());
        label_10->setText(QApplication::translate("GUIClass", "Watchlist", nullptr));
        likeButton->setText(QApplication::translate("GUIClass", "Like this tutorial", nullptr));
        nextButton->setText(QApplication::translate("GUIClass", "Next Tutorial", nullptr));
        addToWatchlistButton->setText(QApplication::translate("GUIClass", "Add to watchlist", nullptr));
        removeFromWatchlist->setText(QApplication::translate("GUIClass", "Remove from watchlist", nullptr));
        openTutorial->setText(QApplication::translate("GUIClass", "Open the tutorial", nullptr));
        undoWatchlist->setText(QApplication::translate("GUIClass", "Undo", nullptr));
        redoWatchlist->setText(QApplication::translate("GUIClass", "Redo", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(userTab), QApplication::translate("GUIClass", "User", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("GUIClass", "BarChart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
