#include "CustomCurvePlot.h"
#include "CustomParamComponent.h"

class CUSTOM_PARAM_COMPONENT::CustomParamComponent;

using namespace CUSTOM_CURVE_PLOT;

CustomCurvePlot::CustomCurvePlot(QWidget* parent) :QCustomPlot(parent) {

	//attributeWidget = nullptr;
	selectSelf = false;

	if (parent->objectName() == "customGroupBox")
	{
		myParentType = MY_PARENT_TYPE::CUSTOM_GROUPBOX;

}
	else
	{
		myParentType = MY_PARENT_TYPE::CUSTOM_LISTWIDGET;
	}

}

CustomCurvePlot::~CustomCurvePlot() {
	
}

QWidget* CustomCurvePlot::loadAttributeWidget() {
	{
		
		attributeWidget.setMaximumWidth(200);

		QGridLayout* attributeLayout = new QGridLayout();
		QLabel* label1 = new QLabel(QString::fromLocal8Bit("��ӻ�ɾ����:"));
		
		QPushButton* buttonAdd = new QPushButton();
		buttonAdd->setIcon(QIcon(QPixmap("img/+hao.png")));
		QPushButton* buttonSub = new QPushButton();
		buttonSub->setIcon(QIcon(QPixmap("img/-hao.png")));

		QListWidget* paramListWidget = new QListWidget;
		connect(buttonAdd, &QPushButton::clicked, this, [=]() {
			hasAddButNotNameParamNum++;
			paramListWidget->addItem(QString::fromLocal8Bit("��%1������").arg(hasAddButNotNameParamNum));
			});

		connect(buttonSub, &QPushButton::clicked, this, [=]() {
			if (hasAddButNotNameParamNum == 0)
		{
				QMessageBox::warning(this, "Warning!!!", QString::fromLocal8Bit("��������Ϊ0!!!"));
				return;
		}
			qDebug() << paramListWidget->currentIndex().row();
			if (paramListWidget->currentIndex().row()!=-1)
			{
				auto item1=paramListWidget->takeItem(paramListWidget->currentRow());
				item1->~QListWidgetItem();
			}
			});

		connect(paramListWidget, &QListWidget::itemClicked, this, [=]() {
			currentSelectParam = paramListWidget->currentRow();
			});

		QGroupBox* groupBox = new QGroupBox();
		groupBox->setTitle(QString::fromLocal8Bit("�������"));

		QLabel* label2 = new QLabel(QString::fromLocal8Bit("���ε�ɫ:"));
		QComboBox* comboBox1 = new QComboBox();
		QStringList colorList = QColor::colorNames();
		for each (QString color in colorList)
		{
			QPixmap pix(QSize(70, 20));
			pix.fill(QColor(color));
			comboBox1->addItem(QIcon(pix), "", QColor(color));
			comboBox1->setIconSize(QSize(70, 20));
			comboBox1->setSizeAdjustPolicy(QComboBox::AdjustToContents);
		}

		QLabel* label3 = new QLabel(QString::fromLocal8Bit("���ο��:"));
		QComboBox* comboBox2 = new QComboBox();
		QVector<qreal> widthList = { 1.0,2.0,3.0 };
		for each (qreal width in widthList)
		{
			
			comboBox2->addItem(QString::number(width));
	
			comboBox2->setSizeAdjustPolicy(QComboBox::AdjustToContents);
		}

		QPushButton* buttonParamOK = new QPushButton(QString::fromLocal8Bit("ȷ������"));
		/*����������ð�ť֮�����ö�Ӧ������*/
		connect(buttonParamOK, &QPushButton::clicked, this, [=]() {

			});

		QGridLayout* boxLayout = new QGridLayout();
		boxLayout->addWidget(label2,0,0);
		boxLayout->addWidget(comboBox1,0,1);
		boxLayout->addWidget(label3,1,0);
		boxLayout->addWidget(comboBox2,1,1);
		boxLayout->addWidget(buttonParamOK, 3, 0);

		groupBox->setLayout(boxLayout);


		QPushButton* buttonOK = new QPushButton();
		buttonOK->setText(QString::fromLocal8Bit("Ӧ�ÿؼ�����"));
		
		
		attributeLayout->addWidget(label1, 0, 0,1,2);
		attributeLayout->addWidget(buttonAdd, 1, 0);
		attributeLayout->addWidget(buttonSub, 1, 1);
		attributeLayout->addWidget(paramListWidget, 2, 0, 1, 2);
		attributeLayout->addWidget(groupBox, 3, 0,1,2);
		attributeLayout->addWidget(buttonOK, 4, 1,1,1);

		

		//�������Ա༭��������
		//ȫ���������֮�󱣴���sql�������½���
		connect(buttonOK, &QPushButton::clicked, this, [=]() {
			/*����Curve*/
			qDebug() << comboBox1->itemData(comboBox1->currentIndex());

			this->update();
			});

		if (!attributeWidget.layout())
		{
			attributeWidget.setLayout(attributeLayout);
		}

		return &attributeWidget;
	}
}

void CustomCurvePlot::mousePressEvent(QMouseEvent* event) {
	this->raise();
	//�źŲ�
#ifdef ONLY_CONTROL_COMPARAM
	connect(this, &CustomCurvePlot::displayAttribute, static_cast<CUSTOM_PARAM_COMPONENT::CustomParamComponent*>(this->parent()->parent()), &CUSTOM_PARAM_COMPONENT::CustomParamComponent::displayAttributeWindow);

#endif
	if (myParentType == MY_PARENT_TYPE::CUSTOM_LISTWIDGET)
	{
		//�źŲ�
		connect(this, &CustomCurvePlot::displayAttribute, static_cast<CUSTOM_PARAM_COMPONENT::CustomParamComponent*>(this->parent()->parent()), &CUSTOM_PARAM_COMPONENT::CustomParamComponent::displayAttributeWindow);

	}
	else
	{
		//�źŲ�
		connect(this, &CustomCurvePlot::displayAttribute, static_cast<CUSTOM_PARAM_COMPONENT::CustomParamComponent*>(this->parent()->parent()->parent()), &CUSTOM_PARAM_COMPONENT::CustomParamComponent::displayAttributeWindow);
	}

	/*����GroupBox*/
	if (myParentType == MY_PARENT_TYPE::CUSTOM_LISTWIDGET)
	{
		selection->addWidget(this);
		selection->show(this);
	}

	/*�ڴ��Ż�*/
	if (attributeWidget.isActiveWindow() == false)
	{
		loadAttributeWidget();
	}

	if (event->button() == Qt::LeftButton)
	{
		selectSelf = true;

		m_point = event->globalPos();

		m_pos = this->frameGeometry().topLeft();

	}
	mousePressed = true;
	QWidget::mousePressEvent(event);

	emit displayAttribute(attributeWidget);

	this->grabKeyboard();
}

void CustomCurvePlot::leaveEvent(QEvent* event) {
	this->releaseKeyboard();

	selection->hide(this);
	selection->removeWidget(this);
}

void CustomCurvePlot::mouseMoveEvent(QMouseEvent* event) {

	selection->clear();

	if (this->parent()->objectName() == "customGroupBox")
	{
		return;
	}

	if ((event->buttons() == Qt::LeftButton) && mousePressed)
	{
		QPoint relativePos = event->globalPos() - m_point;

		this->move(m_pos + relativePos);
		
	}

	
	QWidget::mouseMoveEvent(event);
}

/**
	@brief ��Ӧ�����¼�
	@param event -
**/
void CustomCurvePlot::keyPressEvent(QKeyEvent* event) {

	//�Ȼ�ȡ�������
	if (!selectSelf)
	{
		return;
	}
	if (event->key() == Qt::Key_Delete)
	{
		qDebug() << "key event";
		selection->~Selection();
		this->~CustomCurvePlot();
	}

}