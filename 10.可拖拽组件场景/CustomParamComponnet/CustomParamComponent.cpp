#include "CustomParamComponent.h"

using namespace CUSTOM_PARAM_COMPONENT;




CustomParamComponent::CustomParamComponent(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    

    //���沼��
    customPlot = new CUSTOM_PLOT::CustomPlot();
    customPlot->setBaseSize(size());
    QVector<double> xData;
    QVector<double> yData;

    customPlot->setCurveXYAxis(0, 10, 0, 5, QString::fromLocal8Bit("x��"),QString::fromLocal8Bit( "y��"));

    customPlot->addOneCurve("test1",Qt::blue);
    customPlot->addOneCurve("test2", Qt::black);

    xData = { 0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0 };
    yData = { 0.0,1.0,2.0,3.0,5.0,3.0,2.0,1.0 };
    
    customPlot->setDataSource(0, xData, yData);

    customPlot->setDataSource(1, yData, xData);

    customButton = new CUSTOM_PUSHBUTTON::CustomPushButton("testtext");
    //customCurvePlot = new CUSTOM_CURVE_PLOT::CustomCurvePlot();
    customLabel = new CUSTOM_LABEL::CustomLabel("textLabel");
    dropWidget =new DROP_WIDGET::DropWidget(this);

    customPlot->resize(QSize(100, 60));
    customPlot->move(QPoint(60, 60));

    customListWidget = new CUSTOM_LIST_WIDGET::CustomListWidget(this);
    
    dropWidget->setMinimumWidth(500);


    customListWidget->addItem(new QListWidgetItem(QIcon(QPixmap("img/boat.png")), QString::fromLocal8Bit("��ǩ")));
    customListWidget->addItem(new QListWidgetItem(QIcon(QPixmap("img/car.png")), QString::fromLocal8Bit("��ť")));
    customListWidget->addItem(new QListWidgetItem(QIcon(QPixmap("img/house.png")), QString::fromLocal8Bit("�ź�ͼ")));

    customListWidget->setMaximumWidth(100);

    //attributeWidget = new QWidget(nullptr);
    attributeWidget->setFixedWidth(200);

    //windowLayout = new QGridLayout(this);

    windowLayout->addWidget(dropWidget,0,1);
    windowLayout->addWidget(customListWidget, 0, 0);
    windowLayout->addWidget(attributeWidget, 0, 2);

    ui.centralWidget->setLayout(windowLayout);


}


CustomParamComponent::~CustomParamComponent() {

}


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
        itemPos->close();

    }

    windowLay->addWidget(&widget, 0, 2);
    widget.show();

}