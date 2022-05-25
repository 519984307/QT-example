#pragma once
#include <QtWidgets>
class DropWidget:public QWidget
{
public:
	DropWidget();
	~DropWidget();

	int typeint;

protected:
	void dragEnterEvent(QDragEnterEvent* event);
	void dragLeaveEvent(QDragLeaveEvent* event);
	void dragMoveEvent(QDragMoveEvent* event);
	void dropEvent(QDropEvent* event);
	void mousePressEvent(QMouseEvent* event);

protected slots:
	void dealPressEvent(int number);

};
//��Ҽ��ӡ��
//�����峿��һ�������µ���ʱ��Ҽ·
//Ҳ�߹�ĺҹ���������е���ʱ��Ҽ·
//��������Ŭ��ƴ����ģ��

