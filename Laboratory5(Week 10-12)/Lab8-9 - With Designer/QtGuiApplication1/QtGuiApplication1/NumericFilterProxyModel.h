#pragma once
#include <qsortfilterproxymodel.h>

class NumericFilterProxyModel:public QSortFilterProxyModel
{
	Q_OBJECT

public:
	NumericFilterProxyModel(QObject *parent = 0);
	void setFilteredValue(QString value) { filterValue = value; invalidateFilter(); }

protected:
	bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;
	bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;

private:
	QString filterValue = "";
};