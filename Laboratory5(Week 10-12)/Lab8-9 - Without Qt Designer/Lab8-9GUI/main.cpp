#include "Lab89GUI.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <stdlib.h>
#include "UI.h"
#include <crtdbg.h>
#include <string>
#include <fstream>
#include "CSVRepository.h"
#include "HTMLRepo.h"
#include "Tests.h"
#include "SqlRepository.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Controller* ctrl = nullptr;
	try {
		IFileRepository* r = new HTMLRepository("html/data.json", "http://127.0.0.1:8000");
		IFileRepository* watch = new HTMLRepository("html/watchlist.json", "http://127.0.0.1:8000/watchlist");
		ctrl = new Controller(r, watch);

	}
	catch (RepositoryException& exp) {
		std::cout << exp.what() << std::endl;
	}
	Lab89GUI w{ctrl};
	w.show();
	return a.exec();
}
