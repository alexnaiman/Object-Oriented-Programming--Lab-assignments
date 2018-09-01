#include "PlayButtonDelegate.h"
#include <QPixmap>
#include <QPainter>
#include <QtGui>
#include <Windows.h>
#include <shellapi.h>
PlayButtonDelegate::PlayButtonDelegate(QWidget * parent)
{
}

void PlayButtonDelegate::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	QString organism = index.model()->data(index, Qt::EditRole).toString();

	// show a picture only in the second column; the other columns remain unchanged
	if (index.column() != 6)
	{
		QStyledItemDelegate::paint(painter, option, index);
		return;
	}
	
	QPixmap pixMap("play-button.png");
	painter->drawPixmap(option.rect, pixMap);

}

QSize PlayButtonDelegate::sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	if (index.column() == 6)
	{
		return QSize(100, 100);
	}
	return QSize();
}


bool PlayButtonDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
	if (event->type() == QEvent::MouseButtonRelease && index.column()==6)
	{
		ShellExecuteA(NULL, NULL, "chrome.exe", index.data().toString().toStdString().c_str(), NULL, SW_SHOWMAXIMIZED);
		return true;
	}
	
	return QStyledItemDelegate::editorEvent(event, model, option, index);
}