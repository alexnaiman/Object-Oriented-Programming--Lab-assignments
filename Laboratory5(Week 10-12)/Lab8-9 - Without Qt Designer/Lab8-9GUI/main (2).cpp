//#include <iostream>
//#include <stdlib.h>
//#include "UI.h"
//#include <crtdbg.h>
//#include <string>
//#include <fstream>
//#include "CSVRepository.h"
//#include "HTMLRepo.h"
//#include "Tests.h"
//#include "SqlRepository.h"
//
//
//
//int main() {
//	{
//		try {
//			IFileRepository* r = nullptr; //new CSVRepository("source.txt");
//			IFileRepository* watch = nullptr;// new CSVRepository("playlist.txt");
//			std::string fileType{};
//			std::cout << "What type of file whould you like to use to store the informations? (CSV/HTML)" << std::endl;
//			std::cin >> fileType;
//			if (fileType == "CSV") {
//				r = new CSVRepository("source.txt");
//				watch = new CSVRepository("playlist.txt");	
//			}
//			else {
//				r = new HTMLRepository("html/data.json", "http://127.0.0.1:8000");
//				watch = new HTMLRepository("html/watchlist.json", "http://127.0.0.1:8000/watchlist");
//			}
//			std::cout << std::endl << "SqlRepo?(y/n)" << std::endl;
//			std::string ans{ "" };
//			std::cin >> ans;
//			/*if (ans == "y")
//				r = new SqlRepository{ "" };*/
//			Controller* ctrl = new Controller(r, watch);
//			UI* ui = new UI(ctrl);
//			ui->run();
//			delete ui;
//		}
//		catch (RepositoryException& exp) {
//			std::cout << exp.what() << std::endl;
//		}
//	}
//	_CrtDumpMemoryLeaks();
//
//	system("pause");
//
//	return 0;
//
//}
//
//
