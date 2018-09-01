#pragma once
#include "TutorialModel.h"
#include "IFileRepository.h"
class Action {
public:
	Action() {};
	virtual void redo() = 0;
	virtual void undo() = 0;
};


class AddAction : public Action {
public:
	AddAction(IFileRepository* f, Tutorial l) :Action(), repo(f), t(l) {};
	IFileRepository* repo;
	Tutorial t;
	void undo() override {
		repo->removeTutorial(t.getPresenter(),t.getTitle());
	};
	void redo() override {
		repo->addTutorial(t);
	};
};

class RemoveAction : public Action {
public:
	RemoveAction(IFileRepository* f, Tutorial l) :Action(), repo(f), t(l) {};
	IFileRepository* repo;
	Tutorial t;
	void redo() override {
		repo->removeTutorial(t.getPresenter(), t.getTitle());
	};
	void undo() override {
		repo->addTutorial(t);
	};
};

class UpdateAction : public Action {
public:
	UpdateAction(IFileRepository* f, Tutorial old,Tutorial newT) :Action(), repo(f), old(old),newl(newT) {};
	IFileRepository* repo;
	Tutorial old;
	Tutorial newl;
	void redo() override {
		repo->updateTutorial(newl, old.getPresenter(), old.getTitle());
	};
	void undo() override {
		repo->updateTutorial(old, newl.getPresenter(), newl.getTitle());
	};
};