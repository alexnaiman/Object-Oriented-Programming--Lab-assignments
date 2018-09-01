#pragma once
#include "gui.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel.h>
#include <qpushbutton.h>
#include <qboxlayout.h>
#include <qmessagebox.h>
#include "IFileRepository.h"
#include "CSVRepository.h"
#include "HTMLRepo.h"
#include "Controller.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	IFileRepository *watchlist = nullptr;

	QMessageBox msgBox{};
	msgBox.setWindowTitle("Watchlist type choice");
	msgBox.setText("Type of watchlist:");
	QPushButton *csv = msgBox.addButton("CSV", QMessageBox::ActionRole);
	QPushButton *html = msgBox.addButton("HTML", QMessageBox::AcceptRole);

	msgBox.exec();
	if (msgBox.clickedButton() == csv)
		watchlist = new CSVRepository{"playlist.txt"};
	else
		watchlist = new HTMLRepository{"html/watchlist.json", "http://127.0.0.1:8000/watchlist"};

	IFileRepository* r = new CSVRepository{ "source.txt" }; //new CSVRepository("source.txt");

	Controller* cont =  new Controller{ r , watchlist };
	GUI ui{cont};
	ui.show();
	a.exec();
	delete cont;
	return 0;
}