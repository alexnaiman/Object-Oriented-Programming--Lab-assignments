
#include <QStyledItemDelegate>
#include <QString>

class PlayButtonDelegate : public QStyledItemDelegate
{
private:
	QModelIndex source;
public:
	PlayButtonDelegate(QWidget *parent = 0);
	// these two functions need to be overridden to draw an image for each item
	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
	QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
	bool editorEvent(QEvent * event, QAbstractItemModel * model, const QStyleOptionViewItem & option, const QModelIndex & index);
};

