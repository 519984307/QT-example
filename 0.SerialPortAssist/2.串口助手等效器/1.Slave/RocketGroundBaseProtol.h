#pragma once
#ifndef ROCKET_GROUND_BASE_PROTOL_H
#define ROCKET_GROUND_BASE_PROTOL_H

#include <QtCore>
#include "CrcCompute.h"
#include "RocketGroundProtolDataFormat.h"
#include "RocketBaseDevice.h"

using namespace std;

//�����ֽ�
#define byte unsigned char
//ͨ��Э���ʽ
//RS422����ͨ��Э�飺�̶�����  255+8-2-2 �ֽ� ��ȥ֡ͷ�ͼ����
class RocketGroundBaseProtol
{
public:
	byte HDA = 0x55;
	byte HDB = 0xAA;
	byte LEN = 0XFF;
	byte SEQ;//֡���
	byte DEV;//���ʹ����ݵ��豸��
	byte MSG;//��ϢID
	byte PAYLOAD[255];//ͨ�����ݣ��ǹ̶����� �ܳ���Ϊ255  
	byte CKA;
	byte CKB;

private:
	byte FRAME_TAB[4 + 255];

public:
	virtual void deviceOperate() {

	}

	
 /**
     @brief  //��������Э�鲢����Э�����ݳ���6-2+255+2-2
     @param  input_buf ��������
     @param  ret_buf  ����������� 
     @retval Э�����ݳ���          
 **/
	quint32 parseRocketGroundProtol(byte* input_buf, byte* ret_buf);
	quint32 parseRocketGroundProtol(const QByteArray input_buf, QByteArray& ret_buf);
 /**
     @brief  ����ͨ��Э���еľ���Э��Ҫ��
     @retval 
 **/
	QByteArray parseProtolRequest(QByteArray& frameData);

private:

	//�豸
	GeneralControlMachineDevice generalControlMachine;

private:
	RocketGroundProtolDataFormat* retFrameData = nullptr;

};



//PAYLOAD���� 
class RocketDeviceProtol
{
public:
	byte EXECUTE_STATE;//no.7byte
	byte EXECUTE_RESULT;//no.8byte
	byte DEVICE_OVER_STATE;//no.9byte
	byte DEVICE_CHECK_RESULT;//no.10byte
	byte DEVICE_COM_STATE;//no.11byte

	byte EXPLOSIVE_DEVICE_TEST[2];//no.16-17
protected:
private:
};



#endif