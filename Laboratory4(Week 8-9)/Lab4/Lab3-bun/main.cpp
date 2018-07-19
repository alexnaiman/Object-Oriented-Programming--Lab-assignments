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

void testDsV() {

	// Domain test
	Tutorial s1{ "Fuck", "D", Duration{ 3, 38 },200, "https://www.youtube.com/watch?v=68oqLtQhrPk",20 };
	assert(s1.getPresenter() == "D");
	assert(s1.getTitle() == "Fuck");
	assert(s1.getDuration().getMinutes() == 3);
	assert(s1.getDuration().getSeconds() == 38);
	assert(s1.getNoLikes() == 200);
	assert(s1.getSource() == "https://www.youtube.com/watch?v=68oqLtQhrPk");
	s1.like();
	assert(s1.getNoLikes() == 201);
	//s1.open();
	Tutorial t;
	/*std::cin >> t;
	std::cout << t;*/
	//Repository
	/*Repository* repo = new Repository();
	repo->addTutorial(s1);
	Controller* c = new Controller(repo);
	c->addTutorialToWatchlist(s1);
	Controller* c2 = new Controller(*c);
	UI u{ c };*/
	//FileRepository repo{"test.txt"};
	//Tutorial s2{ "This", "I", Duration{ 8, 12 },200, "https://www.youtube.com/watch?v=XYKUeZQbMF0" };
	//Tutorial s3{ "Shit", "E", Duration{ 3, 47 },200, "https://www.youtube.com/watch?v=6L-_DiZlrUI" };
	//assert(s2 < s1.getNoViews());
	//repo.addTutorial(s1);
	//repo.addTutorial(s2);
	//repo.addTutorial(s3);

	//// find by title and presenter
	//assert(repo.findByPresenterAndTitle("D", "Fuck").getPresenter() == s1.getPresenter());
	//assert(repo.findByPresenterAndTitle("D", "Fuck").getTitle() == s1.getTitle());
	//// find pos of tutorial 
	//assert(repo.findPosOfTutorial(s1) == 0);
	//assert(repo.findPosOfTutorial(s2) == 1);
	//assert(repo.findPosOfTutorial(Tutorial{}) == -1);


	//// remove
	//assert(repo.removeTutorial(s1.getPresenter(), s1.getTitle()));
	//repo.addTutorial(s1); 

	//// controller
	//Controller ctrl{ repo };
	//// repo + watchlist
	//assert(ctrl.getRepo().getTutorials().size() == repo.getTutorials().size());
	//assert(ctrl.getWatchlist().getTutorials().size() == 0);
	//// add
	//assert(!ctrl.addTutorialToRepository(s1.getPresenter(), s1.getTitle(), 2, 2, 2, "232"));
	//assert(!ctrl.addTutorialToRepository(s1.getPresenter(), s1.getTitle(), 2, 2, 2, "232"));
	//// remove
	//assert(ctrl.removeTutorialFromRepository(s1.getPresenter(), s1.getTitle()));
	//assert(!ctrl.removeTutorialFromRepository(s1.getPresenter(), s1.getTitle()));
	//// update
	//assert(!ctrl.updateTutorialFromRepository(s2.getPresenter(), s2.getTitle(), 23, 23, 23, "sdfs", s3.getPresenter(), s3.getTitle()));
	//assert(ctrl.updateTutorialFromRepository(s3.getPresenter(), s3.getTitle(), 23, 23, 23, "sdfs", "test", "update"));
	//assert(!ctrl.updateTutorialFromRepository(s1.getPresenter(), s1.getTitle(), 23, 23, 23, "sdfs", "test", "update"));
	////watchlist
	////add
	//ctrl.addTutorialToWatchlist(s1);
	//ctrl.addTutorialToRepository(s1.getPresenter(), s1.getTitle(), 22, 2, 2, "sdfs");
	//assert(ctrl.getWatchlist().getTutorials().size() == 1);
	//// iteration + search
	//ctrl.configIterator(s1.getTitle());
	//ctrl.startIteration();
	//FileRepository repo2{"test.txt"};
	//repo2.addTutorial(s1);
	//repo2.addTutorial(s2);
	//Controller ctrl2{ repo2 };
	//ctrl.configIterator("");
	//ctrl.startIteration();
	//ctrl2.configIterator(s1.getPresenter());
	//ctrl2.startIteration();
	//assert(ctrl2.getCurrentTutorial().getTitle() == s1.getTitle());
	//assert(!ctrl.deleteTutorialFromWatchlist(s2));
	//ctrl2.next();
	//assert(ctrl.getCurrentTutorial().getPresenter() == s2.getPresenter());
	//ctrl2.likeTutorial();
	//assert(ctrl2.getCurrentTutorial().getNoLikes() == s2.getNoLikes() + 1);
	//// iterator
	//Iterator iter{};
	//iter.next();
	//assert(iter.getCurrentTutorial().getPresenter()=="");
	//iter.add(s1);
	//assert(iter.getCurrentTutorial().getPresenter() == s1.getPresenter());
	//iter.emptyIterator();
	//assert(iter.isEmpty());
	//delete repo;
	//delete c;
	//delete c2;
}

void testFileRepo() {
	IFileRepository* fl = new CSVRepository("test.txt");
	IFileRepository* fl2 = new CSVRepository("test.txt");
	Tutorial s1{ "Fuck", "D", Duration{ 3, 38 },200, "https://www.youtube.com/watch?v=68oqLtQhrPk",20 };
	//fl->addTutorial(s1);
	Controller* c = new Controller(fl, fl2);
//	c->addTutorialToRepository("2", "2", 2, 2, 2, "2", 23);
	//delete fl;
	delete c;
}


void testExceptions();

int main() {
	{
		//testDsV();
		testMain();
		testFileRepo();
		//std::ofstream f("source.txt");

		try {
			IFileRepository* r = nullptr; //new CSVRepository("source.txt");
			IFileRepository* watch = nullptr;// new CSVRepository("playlist.txt");
			std::string fileType{};
			std::cout << "What type of file whould you like to use to store the informations? (CSV/HTML)" << std::endl;
			std::cin >> fileType;
			if (fileType == "CSV") {
				r = new CSVRepository("source.txt");
				watch = new CSVRepository("playlist.txt");	
			}
			else {
				r = new HTMLRepository("html/data.json", "http://127.0.0.1:8000");
				watch = new HTMLRepository("html/watchlist.json", "http://127.0.0.1:8000/watchlist");
			}
			std::cout << std::endl << "SqlRepo?(y/n)" << std::endl;
			std::string ans{ "" };
			std::cin >> ans;
			if (ans == "y")
				r = new SqlRepository{ "" };
			Controller* ctrl = new Controller(r, watch);
			UI* ui = new UI(ctrl);
			ui->run();
			delete ui;
		}
		catch (RepositoryException& exp) {
			std::cout << exp.what() << std::endl;
		}
	}
	_CrtDumpMemoryLeaks();

	system("pause");

	return 0;

}


