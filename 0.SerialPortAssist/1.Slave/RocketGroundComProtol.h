#pragma once

#ifndef ROCKET_GROUND_COM_PROTOL_H
#define ROCKET_GROUND_COM_PROTOL_H


#include <QtWidgets/QMainWindow>
#include "ui_RocketGroundComProtol.h"

#include <QSerialPortInfo>
#include "SerialPortThread.h"

typedef QMap<QString, QString> stringMap;

class RocketGroundComProtol : public QMainWindow
{
    Q_OBJECT

public:
    RocketGroundComProtol(QWidget *parent = Q_NULLPTR);

private:
    Ui::RocketGroundComProtolClass ui;

    SerialPortThread m_thread;

private:
    /**
        @brief ��ʼ���������ý���
    **/
    void initSerialWindow();
    /**
        @brief ���ڲ���
    **/
    void protolTest();

private slots:
    void startSerialPort();
    void activateRunButton();
    void processError(const QString& s);
    void processTimeout(const QString& s);
    //void showRequest(const QString& s);
    void showRequest(const QByteArray& s);

};


#endif