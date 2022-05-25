#include "BaseLuanchCommand.h"

BaseRequestText::BaseRequestText() {


	boxText.append(QString::fromLocal8Bit("�ۿػ��ϵ�"));
	boxText.append(QString::fromLocal8Bit("�ۿػ��µ�"));
	boxText.append(QString::fromLocal8Bit("�ۿػ��Լ�"));
	boxText.append(QString::fromLocal8Bit("�ɿ����״̬��ѯ"));
	boxText.append(QString::fromLocal8Bit("�������"));
	boxText.append(QString::fromLocal8Bit("�������ݲ���"));
	boxText.append(QString::fromLocal8Bit("GPS���ݲ���"));
	boxText.append(QString::fromLocal8Bit("�ŷ���λװ��"));
	boxText.append(QString::fromLocal8Bit("�ŷ�����"));
	boxText.append(QString::fromLocal8Bit("�ŷ�С��·����"));
	boxText.append(QString::fromLocal8Bit("�ŷ���ؼ�������"));
	boxText.append(QString::fromLocal8Bit("��Ԫ���ݿ���"));
	boxText.append(QString::fromLocal8Bit("��Ԫ�����ϴ�"));
	boxText.append(QString::fromLocal8Bit("��Ԫ�����´�"));
	boxText.append(QString::fromLocal8Bit("��Ԫ����У��"));
	boxText.append(QString::fromLocal8Bit("��Ԫ���ݼ���"));
	boxText.append(QString::fromLocal8Bit("ģ�������ϴ�"));
	boxText.append(QString::fromLocal8Bit("��Ʒ�˿ڲ���"));
	boxText.append(QString::fromLocal8Bit("��Ʒ��ֵ����"));
	boxText.append(QString::fromLocal8Bit("ˮƽ����"));
	boxText.append(QString::fromLocal8Bit("ת����"));
	boxText.append(QString::fromLocal8Bit("�ɿ����������д����"));
	boxText.append(QString::fromLocal8Bit("�ɿ���������ϴ�"));
	boxText.append(QString::fromLocal8Bit("�ɿ��������У������"));
	boxText.append(QString::fromLocal8Bit("����Ԥ��"));
	boxText.append(QString::fromLocal8Bit("��������"));
	boxText.append(QString::fromLocal8Bit("����Ԥ��"));
	boxText.append(QString::fromLocal8Bit("���ض���"));


	for (int i=0;i<28;i++)
	{
		datamap[i] = boxText[i];
	}

}


BaseLuanchCommand::BaseLuanchCommand() {
	m_requestData = new RocketGroundProtolDataFormat;
}

/**
	   @brief  �ۿػ��ϵ�����
	   �ⷢ�����ͨ��RS422���Դ����ģ�鷢���ۿػ��ϵ�ָ���Դ����ģ��������28V�ϵ������źţ�ʹ�ۿػ��ϵ硣��Э���޶�Ӧң����
	   @retval ��������
   **/
QByteArray BaseLuanchCommand::generalMachinePowerOnRequest() {

	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x01;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}
	
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;
}
/**
	@brief  �ۿػ��µ�����
	�ⷢ�����ͨ��RS422���Դ����ģ�鷢���ۿػ��µ�ָ�ʹ�ۿػ��µ硣��Э���޶�Ӧң��Э��
	@retval ��������
**/
QByteArray BaseLuanchCommand::generalMachinePowerOffRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x02;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;
}

/**
	@brief  �ۿػ��Լ�����
	����ⷢ��ϵͳ��100msΪ���ڣ����ۿػ������Լ�����ָ��ۿػ������������Լ���Ϣ��������������豸���ͨѶ������Լ�����Ϣ��
	�ۿػ��յ�ָ������������Լ��������״̬������ⷢ�ضԽ�������жϣ��Լ����Ƿ�����
	@retval
**/
QByteArray BaseLuanchCommand::generalMachineSelfCheckRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x14;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;

}


/**
	@brief  ����ⷢ��ϵͳ�����ۿػ�����״̬��ѯָ��ۿػ�����ָ��󣬷�����ǰ����״̬
	@retval ��ǰ����״̬
**/
QByteArray BaseLuanchCommand::flightControlSoftwareStatusQueryRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x16;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;


}

/**
	@brief  �����������
	����ⷢ���豸���������ָ��͸��ۿػ����ۿػ����յ������ݺ����ۿػ���絥Ԫ�Լ�ʱ��ģ����е�����硣
	��ɺ��ۿػ������ⷢ���豸��������ѹ��Ϣ��
	@retval
**/
QByteArray BaseLuanchCommand::singleDistributionRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x20;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;
	m_requestData->CKB = crc_cal >> 8;
	auto data = RocketFormat2ByteArray(m_requestData);return data;

}

/**
	@brief  �������ݲ���
	����ⷢ���豸���ۿػ����͹������ݲ��������ۿػ������˹��鵱ǰ������Ϣ�����������豸
	@retval
**/
QByteArray BaseLuanchCommand::intertialGroupDataMeasureRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x22;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;

}

/**
	@brief  GPS���ݲ���
	����ⷢ���豸���ۿػ�����GPS���ݲ��������ۿػ���GPS��ǰ������Ϣ�����������豸
	@retval
**/
QByteArray BaseLuanchCommand::gpsDataMeasureRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x24;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;

}

/**
	@brief  �ŷ���λװ��
	����ⷢ��ϵͳ����λ��Ϣ���͸��ۿػ����ۿػ����յ������ݺ����ŷ�ϵͳ������λ����װ������ɺ��ۿػ������ⷢ���豸����װ�����
	@retval
**/
QByteArray BaseLuanchCommand::servoZeroBindingRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x32;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;

}

/**
	@brief  �����ŷ�������Ϣ��ת����Ϣ
	����ⷢ��ϵͳ���ŷ�������Ϣ���͸��ۿػ����ۿػ����յ������ݺ����ŷ�ϵͳת������Ϣ�������ŷ�������Ϣת��������ⷢ��ϵͳ
	@retval
**/
QByteArray BaseLuanchCommand::servoMeasureRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x40;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;

}


/**
	@brief  ����ⷢ��ϵͳ���ŷ�С��·������Ϣ���͸��ۿػ����ۿػ����յ������ݺ󣬷ɿ����ִ�о����ƫָ����±��ɷɿ������̲�ִ�У���
	�ɿ������5����Ϊ����ʵʱ���ŷ��ؼ��������ݷ�ң�⣬ִ�����ƫָ��󣬷ɿ���������ⷢ�ط����ŷ��������
	@retval
**/
QByteArray BaseLuanchCommand::servoSmallLoopMeasureRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x42;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;

}

/**
	@brief ����ⷢ���豸���ŷ���ؼ���ָ��͸��ۿػ����ۿػ����յ������ݺ����ŷ�������ʱ���źŽ��е�ؼ��
	��ɺ��ۿػ������ⷢ���豸�����ŷ���ؼ�����Ϣ
	@retval
**/
QByteArray BaseLuanchCommand::servoBatteryActivateRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x44;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;

}

/**
	@brief  ����ⷢ��ϵͳ������Ԫ��д���ƣ�������Ϊ0x11��ָ������ϣ�������Ӧ�������Ԫ������д״̬��
	�������ⷢ��ϵͳ�ſ�������ϴ���Ԫ���ݣ�������ϲ�����ִ����Ԫ������д�������������Ԫ������д��
	����ⷢ��ϵͳ������Ԫ������д���ƣ�������Ϊ0x22����
	������Ӧ���˳���Ԫ������д״̬���ȴ�����ⷢ��ϵͳ��������ָ��
	@retval
**/
QByteArray BaseLuanchCommand::metaDataControlRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x50;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;
}

/**
	@brief  ��Ԫ�����ϴ�
	��Ԫ���ݽ��������д״̬�󣬽��ղ���Ӧ����ⷢ��ϵͳ���͵���Ԫ���ݣ�����ⷢ��ϵͳ���ݿ�ִ�г���������ݷְ���������������ܰ���������ʼ�ϴ���һ��������Ŵ�0�ſ�ʼ��ֱ�����һ����ÿ����Ч�������Ϊ250���ֽڡ�
	�ط����ʱ��100ms��������3��δ���յ��ۿػ���������ֹͣ����
	@retval �ϴ����  ���ؽ��Ӧ����Э�������ʽ
	����--->����
**/
QByteArray BaseLuanchCommand::metaDataUploadRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x60;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;
}

/**
	@brief  ��Ԫ�����´�
	�ۿػ����κ�״̬�¶����Խ�����Ԫ�����´�����Ԫ�������ݵ���ⷢ��ϵͳ���͵����ѯ���ݰ���Ž��������´���ÿ���������һ���´�250���ֽڡ�
	�ط����ʱ��100ms��������3��δ���յ��ۿػ���������ֹͣ����
	@retval �´����  ���ؽ��Ӧ����Э�������ʽ
	����--->����
**/
QByteArray BaseLuanchCommand::metaDataDownloadRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x62;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;
}

/**
	@brief  ��Ԫ�����˳���д״̬�󣬵���ⷢ��ϵͳ�ɷ�����Ԫ����У��ָ���Ԫ���ݶ�ȡflash�п�ִ�г��������������У��ͣ�����������ⷢ��ϵͳ��
	��У������У��ɿع�����������޷���Ӧ����ָ�
	��Ԫ�������У��󣬷���������ⷢ��ϵͳ
	@retval
**/
QByteArray BaseLuanchCommand::metaDataCheckRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x64;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;
}


/**
	@brief  ��Ԫ���ݼ���
	��Ԫ�����˳���д״̬�󣬵���ⷢ��ϵͳ�ɷ�����Ԫ���ݼ���ָ���Ԫ���ݼ���Flash�е���Ԫ���ݵ��ɿ�����У��ɿ�ʹ�ü��غ����Ԫ���ݡ�
	��Ԫ���ݼ�����ɺ󣬷���ִ�н��������ⷢ��ϵͳ
	@retval
**/
QByteArray BaseLuanchCommand::metaDataLoadingRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x66;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;
}

/**
	@brief  ģ�������ϴ�
	����ⷢ��ϵͳ���ݿ�ִ�г���������ݷְ���������������ܰ���������ʼ�ϴ���һ��������Ŵ�0�ſ�ʼ��ֱ�����һ����ÿ����Ч�������Ϊ250���ֽڡ�
	�ط����ʱ��100ms��������3��δ���յ��ۿػ���������ֹͣ����
	@retval
**/
QByteArray BaseLuanchCommand::simulationFlightDataUploadRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x68;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;
}

/**
	@brief  ��Ʒ�˿ڲ���
	����ⷢ��ϵͳ���ۿػ����ͻ�Ʒ�˿ڲ��������ۿػ�����ָ����л�Ʒ�˿ڲ��ԣ��ɿ������ѯʱ��2��Ķ˿�״̬��30���ӿ�����������30���˿���λ��Ϊ��0���������ز��Գɹ���
	����������������˿ڴ�ʱ��λΪ��1�������򷵻ز���ʧ�ܡ�
	�ӽ��յ���Ʒ�˿ڲ�������ʼ���ɿ������5����Ϊ����ʵʱ�ɼ�DRV_STATUS1��DRV_IN_STATSU1�������Ĵ���״̬����ң�⣬�ò�����ʱ����Ҫ��ӽ��ܵ���Ʒ�˿ڲ�����������15�롣
	15����Խ�������ز��Գɹ����򽫲��Խ�����͵���ⷢ��ϵͳ

	@retval
**/
QByteArray BaseLuanchCommand::explosivePortTestRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x6a;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;
}

/**
	@brief  ��Ʒ��ֵ����
	����ⷢ��ϵͳ���ۿػ����ͻ�Ʒ��ֵ���������ۿػ���ÿһ·�Ļ�Ʒ��ǰ������ֵ����������ⷢ��ϵͳ��
	@retval
**/
QByteArray BaseLuanchCommand::explosiveResistMeasureRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x70;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;
}

/**
	@brief  ˮƽ����
	����ⷢ��ϵͳ���ۿػ�����ˮƽ����ָ��ۿػ�����ָ�����ˮƽ���㣬��60��ʱ���ڣ��ڼ����ⷢ��ϵͳ��100msΪ�������ۿػ����͸�ָ�������������ת��ң�⣬
	ͬʱ���л��ֽ���ϳ���ת���ٶ� ��ϳɼ��ٶ� ��180��󽫽������ϳ���ת���ٶ� ��ϳɼ��ٶ� ���͵���ⷢ��ϵͳ��ͬʱ����ˮƽ��������
	����Ҫ���½���ˮƽ����ָ�����ԭִ��IDֵ��1��
	@retval
**/
QByteArray BaseLuanchCommand::levelComputeRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x72;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;
}

/**
	@brief  ת����
	����ⷢ��ϵͳ�����ˮƽ����󣬿����ۿػ�����ת����ָ��ۿػ����뵼��״̬�ɹ��󣬵���ⷢ��ϵͳ����ʱ�����ۿػ�����ת����ָ�ת����ָ�������ⷢ��ϵͳ������ǰ����״̬��
	@retval
**/
QByteArray BaseLuanchCommand::trunNavigateRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0xb0;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;
}

/**
	@brief  �ɿ������д����
	����ⷢ��ϵͳ���ͷɿ������д���ƣ�������Ϊ0x11��ָ������ϣ�������Ӧ�����ɿ������д״̬���������ⷢ��ϵͳ�ſ�������ϴ��ɿ������ִ�г������ݣ�������ϲ�����ִ�зɿ����������д����������ɷɿ������д�󣬵���ⷢ��ϵͳ���ͷɿ������д���ƣ�������Ϊ0x22����������Ӧ���˳������д״̬���ȴ�����ⷢ��ϵͳ��������ָ���Ҫ�ɿ��������ʱ������ⷢ��ϵͳ��ɿ�������ͷɿ������д���ƣ�������Ϊ0x33����
	�ط����ʱ��100ms��������3��δ���յ��ۿػ���������ֹͣ����
	@retval
**/
QByteArray BaseLuanchCommand::flightControlSoftwareUploadControlRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x5a;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;
}

/**
	@brief  �ɿ���������ϴ�
	�ɿ�������������д״̬�󣬽��ղ���Ӧ����ⷢ��ϵͳ���͵ķɿ�������ݣ�����ⷢ��ϵͳ���ݿ�ִ�г���������ݷְ���������������ܰ���������ʼ�ϴ���һ��������Ŵ�0�ſ�ʼ��ֱ�����һ����ÿ����Ч�������Ϊ250���ֽڡ��ط����ʱ��100ms��������3��δ���յ��ۿػ���������ֹͣ����
	@retval
**/
QByteArray BaseLuanchCommand::flightControlSoftwareDataUploadRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x5c;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;
}

/**
	@brief  �ɿ��������У��
	����ⷢ��ϵͳ�ɷ��ͷɿ��������У������ָ����а����ɿ������CRC���ɿ�������յ�ָ�����ȡDDR���ϴ��Ŀ�ִ�г��������������У��ͣ���������CRC�ͷɿ������CRC��ͬ����DDR�еķɿ�����������ص�Flash�У�У������صĹ��̹��ƻ����40s���ң����潨������1���ӵĳ�ʱ�жϣ��ۿػ�����������ؽ������������ⷢ��ϵͳ����У�����ع����У��ɿع�����������޷���Ӧ����ָ�
	�ɿ�������У��󣬷���������ⷢ��ϵͳ
	@retval
**/
QByteArray BaseLuanchCommand::flightControlSoftwareDataCheckRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0x5e;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;
}

/**
	@brief  ����Ԥ��
	����ⷢ���豸���ɿػ�����Ԥ��ɿػ����������󣬶������ⷢ��ϵͳ�ſ�����Ϸ��ͷ������������ϲ�����ִ�з�����ָ��
	@retval
**/
QByteArray BaseLuanchCommand::preLaunchCommandRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0xf6;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;
}

/**
	@brief  ����������
	����ⷢ���豸��������3�θ��ɿػ���������ɿػ����������󣬽�����ʽ�������̣����п�˨��𣩡���������ֻ�ڷɿؽ��յ�����Ԥ��󣬷�����Ӧ
	@retval ��������
**/
QByteArray BaseLuanchCommand::launchFireCommandRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0xf8;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;
}
/**
	@brief ����Ԥ��
	�ڷ����쳣����£�����ⷢ���豸���ۿػ����Ͱ���Ԥ��ɿػ����պ󣬽��밲�����̡����ض���ֻ�ڷɿؽ��յ�����Ԥ��󣬷�����Ӧ
	@retval ��������
**/
QByteArray BaseLuanchCommand::safeControlPreCommandRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0xf9;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;
}
/**
	@brief ���ض���
	�ڷ����쳣����£�����ⷢ���豸����3�����ۿػ����Ͱ���Ԥ��ɿػ������ж�ͨ���󣬽��밲�����̡����ض���ֻ�ڷɿؽ��յ�����Ԥ��󣬷�����Ӧ
	@retval ��������
**/
QByteArray BaseLuanchCommand::safeControlActivateCommandRequest() {
	//��Ҫ����ÿ���豸��������и�ֵ
	m_requestData->CKA = 0x55;
	m_requestData->CKB = 0xaa;
	m_requestData->LEN = NULL;
	m_requestData->SEQ = NULL;
	m_requestData->DEV = 0x03;
	m_requestData->MSG = 0xfa;

	for (int i = 0; i < 255; i++)
	{
		m_requestData->PAYLOAD[i] = 0xbb;
	}

	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_requestData->PAYLOAD), 255);
	m_requestData->CKA = crc_cal >> 0;//�Ͱ�λ
	m_requestData->CKB = crc_cal >> 8;//�߰�λ

	auto data = RocketFormat2ByteArray(m_requestData);return data;

	return data;
}


QByteArray BaseLuanchCommand::RocketFormat2ByteArray(RocketGroundProtolDataFormat* data) {

	QByteArray m_data;
	m_data.append(data->HDA);
	m_data.append(data->HDB);
	m_data.append(data->LEN);
	m_data.append(data->SEQ);
	m_data.append(data->DEV);
	m_data.append(data->MSG);
	for (int i=0;i<255;i++)
	{
		m_data.append(data->PAYLOAD[i]);
	}
	m_data.append(data->CKA);
	m_data.append(data->CKB);
	return m_data;

}