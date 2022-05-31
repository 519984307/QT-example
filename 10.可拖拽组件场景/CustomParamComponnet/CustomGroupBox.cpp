#include "CustomGroupBox.h"
#include "CustomParamComponent.h"

class CUSTOM_PARAM_COMPONENT::CustomParamComponent;

using namespace CUSTOM_GROUP_BOX;

CustomGroupBox::CustomGroupBox(QWidget* parent /* = nullptr */) {

	this->setParent(parent);
	this->setAcceptDrops(true);
	this->setTitle(QString::fromLocal8Bit("�༭Box����"));
	mousePressed = false;
	selectSelf = false;
	boxLayout = new QGridLayout(this);
	this->setLayout(boxLayout);
	this->setObjectName("customGroupBox");

	if (parent->objectName() == "customGroupBox")
	{
		myParentType = MY_PARENT_TYPE::CUSTOM_GROUPBOX;

	}
	else
	{
		myParentType = MY_PARENT_TYPE::CUSTOM_LISTWIDGET;
	}

}

CustomGroupBox::~CustomGroupBox() {

}

//void CustomGroupBox::paintEvent(QPaintEvent* event) {
//	setTitle(myTitle);
//}


QWidget* CustomGroupBox::loadAttributeWidget() {
	{

		attributeWidget.setMaximumWidth(200);

		QGridLayout* attributeLayout = new QGridLayout();
		QLabel* label1 = new QLabel(QString::fromLocal8Bit("�ؼ�����:"));

		QLineEdit* lineEdit1 = new QLineEdit();


		QPushButton* buttonOK = new QPushButton();
		buttonOK->setText(QString::fromLocal8Bit("Ӧ�ÿؼ�����"));


		attributeLayout->addWidget(label1, 0, 0 );
		attributeLayout->addWidget(lineEdit1, 0, 1);
		attributeLayout->addWidget(buttonOK, 1, 1);
		

		//�������Ա༭��������
		//ȫ���������֮�󱣴���sql�������½���
		connect(buttonOK, &QPushButton::clicked, this, [=]() {
			/*����Curve*/
		
			setTitle(lineEdit1->text());
			this->update();
			});

		if (!attributeWidget.layout())
		{
			attributeWidget.setLayout(attributeLayout);
		}

		return &attributeWidget;
	}
}



/**
    @brief 
    @param event - 
**/
void CustomGroupBox::dragEnterEvent(QDragEnterEvent* event) {
	
	if (event->mimeData()->hasFormat("selectIndex"))
	{
		if (event->source() == this)
		{
			event->setDropAction(Qt::MoveAction);
			event->accept();
		}
		else
		{
			event->acceptProposedAction();
		}

	}
	else
	{
		event->ignore();
	}
}

/**
    @brief 
    @param event - 
**/
void CustomGroupBox::dragMoveEvent(QDragMoveEvent* event) {

	if ( event->mimeData()->hasFormat("selectIndex"))
	{
		if (event->source() == this)
		{
			event->setDropAction(Qt::MoveAction);
			event->accept();
		}
		else
		{

			event->acceptProposedAction();

		}

	}
	else
	{
		event->ignore();
	}
}

/**
    @brief 
    @param event - 
**/
void CustomGroupBox::dropEvent(QDropEvent* event) {

	if (event->source() == this)
	{
		event->setDropAction(Qt::MoveAction);
		
		return;
	}
	event->acceptProposedAction();
	if (event->mimeData()->hasFormat("selectIndex"))
	{
		QByteArray itemData = event->mimeData()->data("selectIndex");
		QDataStream dataStream(&itemData, QIODevice::ReadOnly);

		//��ȡ���͵���Ϣ��
		int dropType = itemData.toInt();
		QPoint offset;
		dataStream >> dropType >> offset;

		QWidget* dropObject = nullptr;

		//������ק���ʹ���ʵ��
		switch (dropType)
		{
		case 0:
			dropObject = new CUSTOM_LABEL::CustomLabel("label",this);

			break;
		case 1:
			dropObject = new CUSTOM_PUSHBUTTON::CustomPushButton("button",this);
			break;
		case 2:
			dropObject = new CUSTOM_CURVE_PLOT::CustomCurvePlot(this);
			break;
		
		default:
			break;
		}

		
        if (dropObject)
        {
			dropObject->setAttribute(Qt::WA_NoMousePropagation);
			dropObject->resize(QSize(80, 80));
			boxLayout->addWidget(dropObject,hasWidgetNum/2,hasWidgetNum%2);
			hasWidgetNum++;
			//dropObject->move(event->pos() - offset);
			dropObject->show();
			dropObject->setAttribute(Qt::WA_DeleteOnClose);

        }

	}


}

/**
	@brief
	@param event -
**/
void CustomGroupBox::mousePressEvent(QMouseEvent* event) {

	this->raise();

	if (myParentType == MY_PARENT_TYPE::CUSTOM_LISTWIDGET)
	{
		//�źŲ�
		connect(this, &CustomGroupBox::displayAttribute, static_cast<CUSTOM_PARAM_COMPONENT::CustomParamComponent*>(this->parent()->parent()), &CUSTOM_PARAM_COMPONENT::CustomParamComponent::displayAttributeWindow);

	}
	else
	{
		//�źŲ�
		connect(this, &CustomGroupBox::displayAttribute, static_cast<CUSTOM_PARAM_COMPONENT::CustomParamComponent*>(this->parent()->parent()->parent()), &CUSTOM_PARAM_COMPONENT::CustomParamComponent::displayAttributeWindow);
	}

	loadAttributeWidget();

	/*����GroupBox*/
	if (myParentType == MY_PARENT_TYPE::CUSTOM_LISTWIDGET)
	{
		selection->addWidget(this);
		selection->show(this);
	}


	if (event->button() == Qt::LeftButton)
	{
		mousePressed = true;
		selectSelf = true;
		
		m_point = event->globalPos();
		m_pos = this->frameGeometry().topLeft();
		

	}
	
	QWidget::mousePressEvent(event);

	emit displayAttribute(attributeWidget);
	this->grabKeyboard();
}

/**
    @brief 
    @param event - 
**/
void CustomGroupBox::mouseMoveEvent(QMouseEvent* event) {
	if ((event->buttons() == Qt::LeftButton) && mousePressed)
	{
		QPoint relativePos = event->globalPos()-m_point;

		this->move(m_pos + relativePos);
	}
	selection->clear();
	
	QWidget::mouseMoveEvent(event);

}

void CustomGroupBox::leaveEvent(QEvent* event) {

	mousePressed = false;
	selection->hide(this);
	selection->removeWidget(this);
}

/**
	@brief ��Ӧ�����¼�
	@param event -
**/
void CustomGroupBox::keyPressEvent(QKeyEvent* event) {

	//�Ȼ�ȡ�������
	if (!selectSelf)
	{
		return;
	}

	//��ӦDelete
	if (event->key() == Qt::Key_Delete)
	{
		qDebug() << "key event";

		selection->~Selection();
		this->~CustomGroupBox();

	}

	//QWidget::keyPressEvent(event);
	this->releaseKeyboard();
	selectSelf = false;
}