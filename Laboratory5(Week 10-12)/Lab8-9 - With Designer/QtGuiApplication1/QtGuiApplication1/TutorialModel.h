#pragma once
#include <QObject>
#include <QAbstractTableModel>
#include "IFileRepository.h"
#include <functional>
#include <vector>
#include "Undo.h"
#include <memory>
class TutorialModel : public QAbstractTableModel
{
private:
	IFileRepository * repo;
public:
	std::vector<std::unique_ptr<Action>> undoActions;
	std::vector<std::unique_ptr<Action>> redoActions;
	TutorialModel();
	TutorialModel(IFileRepository* repo);
	~TutorialModel();
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &/*parent*/) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;
	void undo();
	void redo();


	// repository
	IFileRepository* getRepo() { return repo; };
	bool addTutorialToRepository(Tutorial t);
	bool removeTutorialFromRepository(int row);
	Qt::ItemFlags flags(const QModelIndex & index) const override;
	bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;
	void likeTutorial(Tutorial& t);
};