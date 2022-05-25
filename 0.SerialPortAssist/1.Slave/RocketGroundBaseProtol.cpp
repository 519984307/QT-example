#include "RocketGroundBaseProtol.h"



quint32 RocketGroundBaseProtol::parseRocketGroundProtol(byte* input_buf, byte* ret_buf) {
	byte dataLen = 0xff;
	quint32 retDataLen = 0;
	do 
	{
		//
		if ((input_buf == nullptr) || ret_buf == nullptr)
		{
			retDataLen = 0;
			break;
		}
		//���Э��ͷ
		if ((input_buf[0]==HDA) && (input_buf[1]==HDB))
		{
			dataLen = input_buf[2];
			//��ȡ����� CKBΪ��λ��CKAΪ��λ
			quint16 crc_ret = ((input_buf[6 + 255+1]) << 8 | (input_buf[6 + 255 ]) << 0);
			//����У���
			CRC16 crc16(CRC16::eCCITT_FALSE);
			//
			quint16 crc_cal = crc16.crcCompute((char*)(input_buf + 6), 255);
			//�Ƚ�����У���
			if (crc_ret!=crc_cal)
			{
				retDataLen = 0;
				break;;

			}
			else
			{
				//��ȥ֡ͷ����������֡����
				retDataLen = 255 + 8 - 2 - 2;
				for (int i=0;i<retDataLen;i++)
				{
					ret_buf[i] = input_buf[i + 2];
				}
			}
		}
	} while (0);
	//���ؽ��������Ч��������
	return retDataLen;
}

//����ͨ��Э���еľ���Э��Ҫ��
bool RocketGroundBaseProtol::parseProtolRequest() {
	SEQ = FRAME_TAB[1];
	DEV = FRAME_TAB[2];
	MSG = FRAME_TAB[3];
	switch (DEV)
	{
	case 0x01://�ۿػ�
		//��������豸
		
		break;
	case 0x02://�ŷ�
		break;
	case 0x03://��Դ����
		break;
	default:
		break;
	}
	return true;
}

void RocketGroundBaseProtol::generalControlMachineDevice() {


}

void RocketGroundBaseProtol::servoSystemDevice() {


}

void RocketGroundBaseProtol::powerManageModule() {


}
