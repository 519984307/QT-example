#pragma once

#ifndef CUSTOM_COMBINED_WIDGET_H
#define CUSTOM_COMBINED_WIDGET_H


#include <qwidget.h>


namespace CUSTOM_COMBINED_WIDGET {
    /**

        @class   CustomCombinedWidget
        @brief   ��Ͽؼ�  
        @details ~�ؼ������ֶ����ɾ����ϲ���

    **/
    class CustomCombinedWidget :
        public QWidget
    {
        Q_OBJECT

    public:
        CustomCombinedWidget(QWidget* parent = nullptr);
        ~CustomCombinedWidget();

    };

    

}



#endif