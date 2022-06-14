#include "CustomParamComponent.h"

using namespace CUSTOM_PARAM_COMPONENT;



/**
    @brief  ���캯��
    @param  parent - 
    @retval        - 
**/
CustomParamComponent::CustomParamComponent(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    

    /*���ô������ϲ�*/
	/*this->setWindowFlags(Qt::FramelessWindowHint |
		Qt::WindowStaysOnTopHint |
		Qt::Tool| Qt::WindowSystemMenuHint |
		Qt::WindowCloseButtonHint|
		Qt::MacWindowToolBarButtonHint|
		Qt::WindowContextHelpButtonHint
		);*/


    QLabel* labelComponnet = new QLabel(QString::fromLocal8Bit("�������"));
    
    //labelComponnet->setPixmap((QPixmap("img/groupbox.png").scaled(QSize(20,20))));
    labelComponnet->setAlignment(Qt::AlignCenter);
    labelComponnet->setMargin(4);
    
    labelComponnet->setStyleSheet("* {background-color:0f0000}");

	dropWidget = new DROP_WIDGET::DropWidget(this);

	dropWidget->setMinimumWidth(600);
    customListWidget = new CUSTOM_LIST_WIDGET::CustomListWidget(this);

    customListWidget->addItem(new QListWidgetItem(QIcon(QPixmap("img/label.png").scaled(QSize(60,60))), QString::fromLocal8Bit("��ǩ")));
    customListWidget->addItem(new QListWidgetItem(QIcon(QPixmap("img/button.png").scaled(QSize(60, 60))), QString::fromLocal8Bit("��ť")));
    customListWidget->addItem(new QListWidgetItem(QIcon(QPixmap("img/plot.png").scaled(QSize(60, 60))), QString::fromLocal8Bit("�ź�ͼ")));
    customListWidget->addItem(new QListWidgetItem(QIcon(QPixmap("img/groupbox.png").scaled(QSize(60, 60))), QString::fromLocal8Bit("����")));

    customListWidget->setFixedWidth(90);
    customListWidget->setMinimumHeight(400);

    
    QVBoxLayout* listLayout = new QVBoxLayout();
    listLayout->addWidget(labelComponnet);
    listLayout->addWidget(customListWidget);

    windowLayout->addWidget(dropWidget,0,1);
    //windowLayout->addWidget(customListWidget, 1, 0);
    windowLayout->addLayout(listLayout, 0, 0);
    
    ui.centralWidget->setLayout(windowLayout);

    
}

    
CustomParamComponent::~CustomParamComponent() {

    QFrame* attributeWidget = new QFrame;
    attributeWidget->setFixedWidth(200);

}

/**
    @brief ��д���ƺ���
    @param event - 
**/
void CustomParamComponent::paintEvent(QPaintEvent* event) {

}

/**
    @brief �������Դ���
    @param widget - 
**/
void CustomParamComponent::displayAttributeWindow(QWidget& widget) {
   
    /*this->findChild<QWidget*>("attr")->*/

	//QGridLayout* windowLay = static_cast<QGridLayout*>(this->layout());
	//if (windowLay->itemAtPosition(0, 2))
	//{
	//	auto itemPos = windowLay->itemAtPosition(0, 2)->widget();
 //       itemPos->hide();
	//	windowLay->removeWidget(itemPos);
 //       itemPos->close();
	//	
	//}
 //   /*this->windowLayout->addWidget(widget,0,2);
 //   widget->setParent(attributeWidget);*/
	//windowLay->addWidget(widget, 0, 2);
 //   widget->show();

    QGridLayout* windowLay = static_cast<QGridLayout*>(this->layout());
    if (windowLay->itemAtPosition(0, 2))
    {
        auto itemPos = windowLay->itemAtPosition(0, 2)->widget();
        itemPos->hide();
        windowLay->removeWidget(itemPos);
        
        //itemPos->close();

        //itemPos->show();

    }
    widget.setStyleSheet("* {background-color:#f0ffff }");
	windowLay->addWidget(&widget, 0, 2);
	widget.show();

}