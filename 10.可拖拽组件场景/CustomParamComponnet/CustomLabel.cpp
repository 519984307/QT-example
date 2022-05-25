#include "CustomLabel.h"

using namespace CUSTOM_LABEL;

CustomLabel::CustomLabel(QString displayText,QWidget* parent):QLabel(parent) {

	mBackGroundColor = Qt::darkGray;
	mBorderColor = Qt::darkCyan;

	mBorderWidth = 4;
	mRoundRadius = 4;

	fontColor = Qt::black;

	mLabelText = displayText;
	this->setMaximumSize(QSize(100, 20));
	attributeWidget = nullptr;

	this->setFocusPolicy(Qt::ClickFocus);
	this->grabKeyboard();
	selectSelf = false;

}

CustomLabel::~CustomLabel() {

	
}

/**
    @brief 
    @param fontC - 
**/
void CustomLabel::setFontColor(QColor fontC) {
	fontColor = fontC;
	update();
}

/**
    @brief 
    @param backGroundC - 
**/
void CustomLabel::setBackGroundColor(QColor backGroundC) {
	mBackGroundColor = backGroundC;
	update();
}

/**
    @brief 
    @param labelT - 
**/
void CustomLabel::setLabelText(QString labelT) {
	mLabelText = labelT;
	update();
}

void CustomLabel::loadAttributeWidget(QWidget* widget) {
	{
		if (!widget)
		{
			widget = new QWidget();
		}

		QGridLayout* attributeLayout = new QGridLayout(attributeWidget);
		QLabel* label1 = new QLabel(QString::fromLocal8Bit("��������:"));
		QLineEdit* lineEdit1 = new QLineEdit();
		QLabel* label2 = new QLabel(QString::fromLocal8Bit("�߿��ɫ"));
		QComboBox* comboBox1 = new QComboBox();
		QStringList colorList = QColor::colorNames();
		for each (QString color in colorList)
		{
			QPixmap pix(QSize(70, 20));
			pix.fill(QColor(color));
			comboBox1->addItem(QIcon(pix), "");
			comboBox1->setIconSize(QSize(70, 20));
			comboBox1->setSizeAdjustPolicy(QComboBox::AdjustToContents);
		}
		attributeLayout->addWidget(label1, 0, 0);
		attributeLayout->addWidget(lineEdit1, 0, 1);
		attributeLayout->addWidget(label2, 1, 0);
		attributeLayout->addWidget(comboBox1, 1, 1);

		widget->setLayout(attributeLayout);

		widget->show();
	}
}


/**
    @brief ��дpaintEvent�ı����
    @param  - 
**/
void CustomLabel::paintEvent(QPaintEvent*) {

	

	QPainter painter(this);
	QPen pen;
	QBrush brush;

	painter.setRenderHint(QPainter::Antialiasing);

	pen.setColor(mBorderColor);
	pen.setStyle(Qt::SolidLine);

	painter.setPen(pen);
	QRect borderRect = QRect(this->rect().x(), this->rect().y(), this->rect().width() + mBorderWidth, this->rect().height() + mBorderWidth);
	painter.drawRoundedRect(borderRect, mRoundRadius, mRoundRadius);

	brush.setColor(mBackGroundColor);
	brush.setStyle(Qt::SolidPattern);
	painter.setBrush(brush);

	painter.drawRoundedRect(this->rect(), mRoundRadius, mRoundRadius);

	QPen newPen = QPen(fontColor);
	newPen.setStyle(Qt::SolidLine);
	painter.setPen(newPen);
	QFont font = painter.font();
	font.setPixelSize(20);
	font.setBold(true);
	painter.setFont(font);

	painter.drawText(this->rect(), mLabelText, Qt::AlignHCenter | Qt::AlignVCenter);
}


/**
    @brief 
    @param event - 
**/
void CustomLabel::mousePressEvent(QMouseEvent* event) {
	//����������

	selection->addWidget(this);

	if (!attributeWidget)
	{
		//loadAttributeWidget(attributeWidget);
	}
	if (event->button() == Qt::LeftButton)
	{
		selectSelf = true;

		m_point = event->globalPos();

		m_pos = this->frameGeometry().topLeft();

	}
	mousePressed = true;
	QWidget::mousePressEvent(event);

}

void CustomLabel::mouseMoveEvent(QMouseEvent* event) {
	if ((event->buttons() == Qt::LeftButton) && mousePressed)
	{
		QPoint relativePos = event->globalPos() - m_point;

		this->move(m_pos + relativePos);
	}

	selection->clear();
	QWidget::mouseMoveEvent(event);
}

/**
    @brief ��Ӧ�����¼�
    @param event - 
**/
void CustomLabel::keyPressEvent(QKeyEvent* event) {

	//�Ȼ�ȡ�������
	if (!selectSelf)
	{
		return;
	}

	//��ӦDelete
	if (event->key()==Qt::Key_Delete)
	{
		qDebug() << "key event";

		selection->~Selection();
		this->~CustomLabel();
		
	}

}

