#include "CustomGroupBoxWidget.h"

using namespace CUSTOM_GROUP_BOX_WIDGET;

CustomGroupBoxWidget::CustomGroupBoxWidget(QWidget* parent/* =nullptr */) {
    
    groupBox = new CUSTOM_GROUP_BOX::CustomGroupBox(parent);
    elementWidget = nullptr;

}

/**
    @brief  ���ݴ�������ͻ�ȡgroup
    @param  type - 
    @retval      - 
**/
CUSTOM_GROUP_BOX::CustomGroupBox* CustomGroupBoxWidget::getGroupWidget(CUSTOM_GROUP_WIDGET_TYPE type) {
   
    
   // groupBox->setMinimumSize(QSize(100, 20));
    QGridLayout* boxLayout = new QGridLayout(groupBox);

   
    switch (type)
    {
    case CUSTOM_GROUP_BOX_WIDGET::LABEL_GROUP:
        customLabel = new CUSTOM_LABEL::CustomLabel();
        boxLayout->addWidget(customLabel);
        break;
    case CUSTOM_GROUP_BOX_WIDGET::CURVE_PLOT:
        customCurvePlot = new CUSTOM_CURVE_PLOT::CustomCurvePlot();
        boxLayout->addWidget(customCurvePlot);
        break;
    default:
        break;
    }

    groupBox->setLayout(boxLayout);
    return groupBox;

}

/**
      @brief ������������Ӱ�ťʱ�Ľӿ�
      @param type -
  **/
void CustomGroupBoxWidget::addWidget2Group(CUSTOM_GROUP_WIDGET_TYPE type) {
    //���ж�

}


