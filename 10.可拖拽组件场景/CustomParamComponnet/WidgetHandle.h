#pragma once
#ifndef WIDGET_HANDLE_H
#define WIDGET_HANDLE_H

#include <QWidget>
#include <QHash>

/**
    @namespace WIDGET_HANDLE
    @brief     �Զ���ؼ�������
**/
namespace WIDGET_HANDLE {

	class WidgetHandle : public QWidget
	{
		

		Q_OBJECT
	public:
		enum  Type
		{
			LeftTop = 0,
			Top = 1,
			RightTop = 2,
			Right = 3,
			RightBottom = 4,
			Bottom = 5,
			LeftBottom = 6,
			Left = 7,

			TypeCount = 8
		};
		WidgetHandle(QWidget* parent, Type t);
		~WidgetHandle() {

		}

		void    setWidget(QWidget* w);
		void    setCurrent(bool b);
	protected:
	protected:
		void paintEvent(QPaintEvent*);
		void mousePressEvent(QMouseEvent* e);
		void mouseMoveEvent(QMouseEvent* e);
		void mouseReleaseEvent(QMouseEvent* e);

	protected:
		void    updateCursor();
		void    trySetGeometry(QWidget* w, int x, int y, int width, int height);
		void    tryResize(QWidget* w, int width, int height);
	signals:
		void sizeChanged(int x, int y, int width, int height);
		void    mouse_button_release(const QRect& old, const QRect& now);
	protected:
		Type        m_type;
		QWidget* m_widget;
		bool        m_current;
		QPoint      m_origPressPos;
		QRect       m_geom, m_origGeom;
	};

	class WidgetSelection : public QObject
	{
		Q_OBJECT
	public:
		WidgetSelection(QWidget* parent);
		~WidgetSelection() {

		}

		void setWidget(QWidget* w);
		QWidget* widget();
		bool isUsed() const;

		void hide();
		void show();
		void update();
		void updateGeometry();

		void setCurrent(bool b);
	protected:
		bool eventFilter(QObject* object, QEvent* event);

	protected slots:
		void    changedsize(int x, int y, int width, int height);
		void    mouse_button_release(const QRect& old, const QRect& now);
	signals:
		void sizeChanged(QWidget* wid, const QRect& old, const QRect& now);
	protected:
		WidgetHandle* m_handles[WidgetHandle::TypeCount];
		QWidget* m_widget;
		QWidget* m_formWindow;
	};

	class Selection : public QObject
	{
		Q_OBJECT
	public:
		Selection(QWidget* formwindow);
		~Selection();

		void clear();

		void  clearSelectionPool();

		void repaintSelection(QWidget* w);
		void repaintSelection();

		bool isWidgetSelected(QWidget* w) const;
		QWidgetList selectedWidgets() const;

		WidgetSelection* addWidget(QWidget* w);
		QWidget* removeWidget(QWidget* w);
		QWidget* current();

		void raiseList(const QWidgetList& l);
		void raiseWidget(QWidget* w);

		void updateGeometry(QWidget* w);

		void hide(QWidget* w);
		void show(QWidget* w);


		void setCurrent(QWidget* w);
	signals:
		void sizeChanged(QWidget* wid, const QRect& old, const QRect& now);

	private:

		typedef QList<WidgetSelection*> SelectionPool;
		SelectionPool m_selectionPool;

		typedef QHash<QWidget*, WidgetSelection*> SelectionHash;
		SelectionHash m_usedSelections;
		WidgetSelection* m_current;
		QWidget* m_formwindow;
	};

}

#endif // QSELECTWIDGET_H