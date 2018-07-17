#include <iostream>
#include <stdlib.h>
#include "UI.h"
#include <crtdbg.h>
#include <string>


void testDsV() {
	DynamicVector<int> d{ 2 };
	//add + getSize
	d = 2 + d;
	d = d + 1;
	d.add(3);
	d.add(4);
	d.add(5);
	assert(d.getSize() == 5);
	//delete + overloading operator []
	d.deleteElem(1);
	d.deleteElem(-1);
	assert(d.getSize() == 4);
	assert(d[1] == 3);
	assert(d[0] == 2);
	d.getAllElems();
	assert(d[0] == 2);



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
	s1.open();

	//Repository
	Repository repo{};
	Tutorial s2{ "This", "I", Duration{ 8, 12 },200, "https://www.youtube.com/watch?v=XYKUeZQbMF0" };
	Tutorial s3{ "Shit", "E", Duration{ 3, 47 },200, "https://www.youtube.com/watch?v=6L-_DiZlrUI" };
	assert(s2 < s1.getNoViews());
	repo.addTutorial(s1);
	repo.addTutorial(s2);
	repo.addTutorial(s3);

	// find by title and presenter
	assert(repo.findByPresenterAndTitle("D", "Fuck").getPresenter() == s1.getPresenter());
	assert(repo.findByPresenterAndTitle("D", "Fuck").getTitle() == s1.getTitle());
	// find pos of tutorial 
	assert(repo.findPosOfTutorial(s1) == 0);
	assert(repo.findPosOfTutorial(s2) == 1);
	assert(repo.findPosOfTutorial(Tutorial{}) == -1);

	// get all
	DynamicVector<Tutorial> dRepo = repo.getTutorials();
	assert(dRepo[0].getPresenter() == s1.getPresenter());
	assert(dRepo[1].getPresenter() == s2.getPresenter());
	assert(dRepo[2].getPresenter() == s3.getPresenter());

	// remove
	assert(repo.removeTutorial(s1.getPresenter(), s1.getTitle()));
	repo.addTutorial(s1); 

	// controller
	Controller ctrl{ repo };
	// repo + watchlist
	assert(ctrl.getRepo().getTutorials().getSize() == repo.getTutorials().getSize());
	assert(ctrl.getWatchlist().getTutorials().getSize() == 0);
	// add
	assert(!ctrl.addTutorialToRepository(s1.getPresenter(), s1.getTitle(), 2, 2, 2, "232"));
	assert(!ctrl.addTutorialToRepository(s1.getPresenter(), s1.getTitle(), 2, 2, 2, "232"));
	// remove
	assert(ctrl.removeTutorialFromRepository(s1.getPresenter(), s1.getTitle()));
	assert(!ctrl.removeTutorialFromRepository(s1.getPresenter(), s1.getTitle()));
	// update
	assert(!ctrl.updateTutorialFromRepository(s2.getPresenter(), s2.getTitle(), 23, 23, 23, "sdfs", s3.getPresenter(), s3.getTitle()));
	assert(ctrl.updateTutorialFromRepository(s3.getPresenter(), s3.getTitle(), 23, 23, 23, "sdfs", "test", "update"));
	assert(!ctrl.updateTutorialFromRepository(s1.getPresenter(), s1.getTitle(), 23, 23, 23, "sdfs", "test", "update"));
	//watchlist
	//add
	ctrl.addTutorialToWatchlist(s1);
	ctrl.addTutorialToRepository(s1.getPresenter(), s1.getTitle(), 22, 2, 2, "sdfs");
	assert(ctrl.getWatchlist().getTutorials().getSize() == 1);
	// iteration + search
	ctrl.configIterator(s1.getTitle());
	ctrl.startIteration();
	Repository repo2{};
	repo2.addTutorial(s1);
	repo2.addTutorial(s2);
	Controller ctrl2{ repo2 };
	ctrl.configIterator("");
	ctrl.startIteration();
	ctrl2.configIterator(s1.getPresenter());
	ctrl2.startIteration();
	assert(ctrl2.getCurrentTutorial().getTitle() == s1.getTitle());
	assert(!ctrl.deleteTutorialFromWatchlist(s2));
	ctrl2.next();
	assert(ctrl.getCurrentTutorial().getPresenter() == s2.getPresenter());
	ctrl2.likeTutorial();
	assert(ctrl2.getCurrentTutorial().getNoLikes() == s2.getNoLikes() + 1);
	// iterator
	Iterator iter{};
	iter.next();
	assert(iter.getCurrentTutorial().getPresenter()=="");
	iter.add(s1);
	assert(iter.getCurrentTutorial().getPresenter() == s1.getPresenter());
	iter.emptyIterator();
	assert(iter.isEmpty());
}
int main() {
	{
		testDsV();
			Repository repo{};
			Tutorial s1{ "Memory Mangement", "Bjarne Stroustrup", Duration{ 3, 38 },200, "https://www.youtube.com/watch?v=smiFk6KHr_8",100 };
			Tutorial s2{ "Pointers", "Bjarne Stroustrup", Duration{ 8, 12 },200, "https://www.youtube.com/watch?v=69edOm889V4", 100 };
			Tutorial s3{ "Templates", "Iuliana Bocicor", Duration{ 3, 47 },200, "https://sites.google.com/view/iuliana-bocicor/teaching/oop", 120 };
			repo.addTutorial(s1);
			repo.addTutorial(s2);
			repo.addTutorial(s3);

			Controller ctrl{ repo };
			UI ui{ ctrl };
			ui.run();
		}

		system("pause");
		_CrtDumpMemoryLeaks();
		
		return 0;
	
}


