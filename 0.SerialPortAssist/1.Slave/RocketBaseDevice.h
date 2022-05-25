#pragma once
#ifndef ROCKET_BASE_DEVICE_H
#define ROCKET_BASE_DEVICE_H


#include <QtCore>
#include "RocketGroundBaseProtol.h"


class RocketBaseDevice
{
};

/**

    @class   GeneralControlMachineDevice
    @brief   �ۿػ��豸
    @details ~

**/
class GeneralControlMachineDevice
{
public:
    /**
        @brief  �ۿػ��ϵ�
        @retval �ϵ���
    **/
    bool powerOn();//�ϵ�
    /**
        @brief  �ۿػ��µ�
        @retval �µ���
    **/
    bool powerOff();//�µ�
    /**
        @brief  �ۿػ��Լ�
        @retval �Լ���
    **/
    bool selfCheck();//�Լ�
    /**
        @brief  ����ⷢ��ϵͳ�����ۿػ�����״̬��ѯָ��ۿػ�����ָ��󣬷�����ǰ����״̬
        @retval ��ǰ����״̬
    **/
    quint32 FlightControlStatusQuery();//�ɿ�״̬
    /**
        @brief  �������
        @retval ����ѹ��Ϣ
    **/
    quint32 singleDistribution();
    /**
        @brief  �������ݲ���
        @retval ���˹��鵱ǰ������Ϣ
    **/
    quint32 intertialGroupDataMeasure();
    /**
        @brief  GPS���ݲ���
        @retval GPS��ǰ������Ϣ
    **/
    bool gpsDataMeasure();
    /**
        @brief  �ŷ���λװ��
        @retval װ�����
    **/
    quint32 servoZeroBinding();

    /**
        @brief  �����ŷ�������Ϣ��ת����Ϣ
        �����ŷ�������Ϣ��ת��������ⷢ��
        @retval �ŷ�������Ϣ
    **/
    quint32 servoMeasure();
 
 
    /**
        @brief  ����ⷢ��ϵͳ���ŷ�С��·������Ϣ���͸��ۿػ����ۿػ����յ������ݺ󣬷ɿ����ִ�о����ƫָ����±��ɷɿ������̲�ִ�У���
        �ɿ������5����Ϊ����ʵʱ���ŷ��ؼ��������ݷ�ң�⣬ִ�����ƫָ��󣬷ɿ���������ⷢ�ط����ŷ��������
        @retval �ŷ��������
    **/
    quint32 servoSmallLoopMeasure();
    /**
        @brief ����ⷢ���豸���ŷ���ؼ���ָ��͸��ۿػ����ۿػ����յ������ݺ����ŷ�������ʱ���źŽ��е�ؼ��
        ��ɺ��ۿػ������ⷢ���豸�����ŷ���ؼ�����Ϣ
        @retval ��ؼ�����Ϣ
    **/
    bool servoBatteryOn();
    /**
        @brief  ����ⷢ��ϵͳ������Ԫ��д���ƣ�������Ϊ0x11��ָ������ϣ�������Ӧ�������Ԫ������д״̬��
        �������ⷢ��ϵͳ�ſ�������ϴ���Ԫ���ݣ�������ϲ�����ִ����Ԫ������д�������������Ԫ������д��
        ����ⷢ��ϵͳ������Ԫ������д���ƣ�������Ϊ0x22����
        ������Ӧ���˳���Ԫ������д״̬���ȴ�����ⷢ��ϵͳ��������ָ��
        @retval ��д״̬����
    **/
    quint32 metaDataControl();

private:

};


/**

    @class   GeneralControlMachineDevice
    @brief   �ŷ��豸
    @details ~

**/
class ServoDevice
{
public:


private:

};


/**

    @class   GeneralControlMachineDevice
    @brief   ��Դ����ģ��
    @details ~

**/
class PowerManageModule
{
public:


private:

};

#endif