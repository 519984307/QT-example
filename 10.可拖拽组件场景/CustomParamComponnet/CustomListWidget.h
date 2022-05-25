#pragma once

#ifndef CUSTOM_LIST_WIDGET_H
#define CUSTOM_LIST_WIDGET_H


#include <qlistwidget.h>
#include <QMouseEvent>
#include <QtWidgets>

/**
    @namespace CUSTOM_LIST_WIDGET
    @brief     �Զ���ListWidget��
**/
namespace CUSTOM_LIST_WIDGET
{
    //Q_DECLARE_METATYPE (int)

    class CustomListWidget :
        public QListWidget
    {

    public:
        CustomListWidget(QWidget* parent=nullptr);
        ~CustomListWidget();
        int selectIndex;
    private:
        
        bool selectElement;
        QPoint dragStartPosition;

    protected:
        
        void mouseMoveEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
		void mousePressEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
        void mouseReleaseEvent(QMouseEvent* event) Q_DECL_OVERRIDE;

    };
}

#endif