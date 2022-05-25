#include "DropWidget.h"

#include "instrumentpanel.h"

DropWidget::DropWidget(){

	this->setMinimumHeight(200);
	this->setMinimumWidth(200);
	this->setBackgroundRole(QPalette::Light);
	this->setAcceptDrops(true);



	//connect(listwidgetview, &ListWidgetView::emitdrag, this, &DropWidget::dealPressEvent);
}

DropWidget::~DropWidget() {

}

/**
    @brief ����֪ͨqtС�������յ���������
    @param event 
**/
void DropWidget::dragEnterEvent(QDragEnterEvent* event) {
	//�Ȳ鿴��ק�������������Ƿ���ģ��
	//����
	//auto type = event->mimeData();
	//if (event->mimeData()->hasFormat("application/x-qt-windows-mime"))
	//{
	//	event->setDropAction(Qt::MoveAction);
	//	event->accept();
	//}
	//else{
	//	event->ignore();
	//}
	const QMimeData* data = event->mimeData();
	QVariant type = data->property("TYPE");
	event->accept();

}
void DropWidget::dragLeaveEvent(QDragLeaveEvent* event) {


}
void DropWidget::dragMoveEvent(QDragMoveEvent* event) {
	
}
void DropWidget::dropEvent(QDropEvent* event) {
	
	auto data=event->mimeData();
	QByteArray itemData;
	QDataStream stream(&itemData, QIODevice::ReadOnly);
	QString copytype;



	QPixmap pixmap(QSize(50, 50));
	QLabel* newIcon = new QLabel(this);
	InstrumentPanel* newIns = new InstrumentPanel(this);
	newIcon->setPixmap(pixmap);

	newIns->resize(50, 50);
	newIns->move(event->pos());
	newIns->show();
	newIns->setAttribute(Qt::WA_DeleteOnClose);

	if (event->source() == this) {
		event->setDropAction(Qt::MoveAction);
		event->accept();
	}
	else {
		event->acceptProposedAction();
		event->setDropAction(Qt::CopyAction);
		event->accept();
	}


}

void DropWidget::mousePressEvent(QMouseEvent* event)
{
	//QWidget* currentitem;
	
	if (event->button() == Qt::LeftButton)
	{
		auto currentitem = QApplication::focusWidget();
		
	}
	//QLabel* child = static_cast<QLabel*>(childAt(event->pos()));
	auto* child = static_cast<QWidget*>(childAt(event->pos()));
	if (!child)
		return;

	//QPixmap pixmap = *child->pixmap();
	QPixmap pixmap(QSize(50, 50));

	QByteArray itemData;
	QDataStream dataStream(&itemData, QIODevice::WriteOnly);
	dataStream << QString(typeint);

	QMimeData* mimeData = new QMimeData;
	mimeData->setData("text/", itemData);

	//����QDrag���󣬲�����exec�����ϷŲ���
	QDrag* drag = new QDrag(this);
	drag->setMimeData(mimeData);
	drag->setPixmap(pixmap);
	drag->setHotSpot(event->pos() - child->pos());

	QPixmap tempPixmap = pixmap;
	QPainter painter;
	painter.begin(&tempPixmap);
	painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
	painter.end();

	//child->setPixmap(tempPixmap);

	if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
		child->close();
	}
	else {
		child->show();
		//child->setPixmap(pixmap);
	}
}


void DropWidget::dealPressEvent(int number) {

	typeint = number;
}