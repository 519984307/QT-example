#pragma once
#ifndef ROCKET_GROUND_PROTOL_FORMAT_H
#define ROCKET_GROUND_PROTOL_FORMAT_H

#include <QtCore>
#define byte quint8

class RocketGroundProtolDataFormat
{
	byte HDA = 0x55;
	byte HDB = 0xAA;
	byte LEN = 0XFF;
	byte SEQ;//֡���
	byte DEV;//�豸��
	byte MSG;//��ϢID
	byte PAYLOAD[255];//ͨ�����ݣ��ǹ̶����� �ܳ���Ϊ255  
	byte CKA;
	byte CKB;

};

#endif