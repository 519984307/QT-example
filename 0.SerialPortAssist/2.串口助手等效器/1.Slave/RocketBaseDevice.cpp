#include "RocketBaseDevice.h"

GeneralControlMachineDevice::GeneralControlMachineDevice() {
	m_retData = new RocketGroundProtolDataFormat;
}


/**
       @brief  �ۿػ��ϵ�����
       �ⷢ�����ͨ��RS422���Դ����ģ�鷢���ۿػ��ϵ�ָ���Դ����ģ��������28V�ϵ������źţ�ʹ�ۿػ��ϵ硣��Э���޶�Ӧң����
       @retval �޷���
   **/
void GeneralControlMachineDevice::generalMachinePowerOn(RocketGroundProtolDataFormat& frameData) {



}
/**
    @brief  �ۿػ��µ�����
    �ⷢ�����ͨ��RS422���Դ����ģ�鷢���ۿػ��µ�ָ�ʹ�ۿػ��µ硣��Э���޶�Ӧң��Э��
    @retval �޷���
**/
void GeneralControlMachineDevice::generalMachinePowerOff(RocketGroundProtolDataFormat& frameData) {

}

/**
    @brief  �ۿػ��Լ�����
    ����ⷢ��ϵͳ��100msΪ���ڣ����ۿػ������Լ�����ָ��ۿػ������������Լ���Ϣ��������������豸���ͨѶ������Լ�����Ϣ��
    �ۿػ��յ�ָ������������Լ��������״̬������ⷢ�ضԽ�������жϣ��Լ����Ƿ�����
    @retval
**/
bool GeneralControlMachineDevice::generalMachineSelfCheck(RocketGroundProtolDataFormat& frameData) {
    //��ȡ�豸���Լ���Ϣ

    return true;
}
/**
    @brief  �����ۿػ��Լ���
    @retval �Լ���
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::generalMachineSelfCheckResult(RocketGroundProtolDataFormat& frameData) {
    //��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0x15;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
    for (int i=0;i<4;i++)
    {
        m_retData->PAYLOAD[5 + i] = 0x0;
    }
    m_retData->PAYLOAD[9] = 0xaa;
    m_retData->PAYLOAD[10] = 0xaa;
    for (int i=0;i<4;i++)
    {
        m_retData->PAYLOAD[11+i] = 0xbb;
    }
    m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
    for (int i=0;i<(255-16);i++)
    {
        m_retData->PAYLOAD[16 + i] = 0xbb;
    }
    //CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
    m_retData->CKB = crc_cal << 8;//�߰�λ
    m_retData->CKA = crc_cal << 0;//�Ͱ�λ

    return *m_retData;
}

/**
    @brief  ����ⷢ��ϵͳ�����ۿػ�����״̬��ѯָ��ۿػ�����ָ��󣬷�����ǰ����״̬
    @retval ��ǰ����״̬
**/
bool GeneralControlMachineDevice::flightControlSoftwareStatusQuery(RocketGroundProtolDataFormat& frameData) {


    return true;
}
/**
    @brief  �ɿ�״̬��ѯ���
    @retval
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::flightControlSoftwareStatusQueryResult(RocketGroundProtolDataFormat& frameData) {

	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0x17;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
    return *m_retData;
}

/**
    @brief  �����������
    ����ⷢ���豸���������ָ��͸��ۿػ����ۿػ����յ������ݺ����ۿػ���絥Ԫ�Լ�ʱ��ģ����е�����硣
    ��ɺ��ۿػ������ⷢ���豸��������ѹ��Ϣ��
    @retval
**/
bool GeneralControlMachineDevice::singleDistribution(RocketGroundProtolDataFormat& frameData) {

    return true;
}
/**
    @brief  �������������
    @retval ����ѹ��Ϣ
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::singleDistributionResult(RocketGroundProtolDataFormat& frameData) {
	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0x21;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
    return *m_retData;
}
/**
    @brief  �������ݲ���
    ����ⷢ���豸���ۿػ����͹������ݲ��������ۿػ������˹��鵱ǰ������Ϣ�����������豸
    @retval
**/
bool GeneralControlMachineDevice::intertialGroupDataMeasure(RocketGroundProtolDataFormat& frameData) {

    return true;
}
/**
    @brief  �������ݲ����������
    @retval ���˹��鵱ǰ������Ϣ
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::intertialGroupDataMeasureResult(RocketGroundProtolDataFormat& frameData) {
	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0x23;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
    return *m_retData;
}
/**
    @brief  GPS���ݲ���
    ����ⷢ���豸���ۿػ�����GPS���ݲ��������ۿػ���GPS��ǰ������Ϣ�����������豸
    @retval
**/
bool GeneralControlMachineDevice::gpsDataMeasure(RocketGroundProtolDataFormat& frameData) {

    return true;
}
/**
    @brief  GPS���ݲ����������
    @retval GPS��ǰ������Ϣ
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::gpsDataMeasureResult(RocketGroundProtolDataFormat& frameData) {
	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0x25;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
    return *m_retData;
}
/**
    @brief  �ŷ���λװ��
    ����ⷢ��ϵͳ����λ��Ϣ���͸��ۿػ����ۿػ����յ������ݺ����ŷ�ϵͳ������λ����װ������ɺ��ۿػ������ⷢ���豸����װ�����
    @retval
**/
bool GeneralControlMachineDevice::servoZeroBinding(RocketGroundProtolDataFormat& frameData) {

    return true;
}
/**
    @brief  �ŷ���λװ���������
    @retval װ�����
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::servoZeroBindingResult(RocketGroundProtolDataFormat& frameData) {
	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0x33;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
    return *m_retData;
}

/**
    @brief  �����ŷ�������Ϣ��ת����Ϣ
    ����ⷢ��ϵͳ���ŷ�������Ϣ���͸��ۿػ����ۿػ����յ������ݺ����ŷ�ϵͳת������Ϣ�������ŷ�������Ϣת��������ⷢ��ϵͳ
    @retval
**/
bool GeneralControlMachineDevice::servoMeasure(RocketGroundProtolDataFormat& frameData) {

    return true;
}
/**
    @brief  �ŷ������������
    @retval �ŷ�������Ϣ
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::servoMeasureResult(RocketGroundProtolDataFormat& frameData) {
	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0x41;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
    return *m_retData;
}


/**
    @brief  ����ⷢ��ϵͳ���ŷ�С��·������Ϣ���͸��ۿػ����ۿػ����յ������ݺ󣬷ɿ����ִ�о����ƫָ����±��ɷɿ������̲�ִ�У���
    �ɿ������5����Ϊ����ʵʱ���ŷ��ؼ��������ݷ�ң�⣬ִ�����ƫָ��󣬷ɿ���������ⷢ�ط����ŷ��������
    @retval
**/
bool GeneralControlMachineDevice::servoSmallLoopMeasure(RocketGroundProtolDataFormat& frameData) {

    return true;
}
/**
    @brief  �ŷ�С��·�����������
    @retval �ŷ��������
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::servoSmallLoopMeasureResult(RocketGroundProtolDataFormat& frameData) {
	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0x43;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
    return *m_retData;
}

/**
    @brief ����ⷢ���豸���ŷ���ؼ���ָ��͸��ۿػ����ۿػ����յ������ݺ����ŷ�������ʱ���źŽ��е�ؼ��
    ��ɺ��ۿػ������ⷢ���豸�����ŷ���ؼ�����Ϣ
    @retval
**/
bool GeneralControlMachineDevice::servoBatteryActivate(RocketGroundProtolDataFormat& frameData) {

    return true;
}
/**
    @brief  �ŷ���ؼ���������
    @retval ��ؼ�����Ϣ
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::servoBatteryActivateResult(RocketGroundProtolDataFormat& frameData) {
	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0x44;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
    return *m_retData;
}

/**
    @brief  ����ⷢ��ϵͳ������Ԫ��д���ƣ�������Ϊ0x11��ָ������ϣ�������Ӧ�������Ԫ������д״̬��
    �������ⷢ��ϵͳ�ſ�������ϴ���Ԫ���ݣ�������ϲ�����ִ����Ԫ������д�������������Ԫ������д��
    ����ⷢ��ϵͳ������Ԫ������д���ƣ�������Ϊ0x22����
    ������Ӧ���˳���Ԫ������д״̬���ȴ�����ⷢ��ϵͳ��������ָ��
    @retval
**/
bool GeneralControlMachineDevice::metaDataControl(RocketGroundProtolDataFormat& frameData) {

    return true;
}
/**
    @brief  ��Ԫ���ݿ��ƽ������
    @retval ��д״̬����
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::metaDataControlResult(RocketGroundProtolDataFormat& frameData) {
	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0x51;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
    return *m_retData;
}

/**
    @brief  ��Ԫ�����ϴ�
    ��Ԫ���ݽ��������д״̬�󣬽��ղ���Ӧ����ⷢ��ϵͳ���͵���Ԫ���ݣ�����ⷢ��ϵͳ���ݿ�ִ�г���������ݷְ���������������ܰ���������ʼ�ϴ���һ��������Ŵ�0�ſ�ʼ��ֱ�����һ����ÿ����Ч�������Ϊ250���ֽڡ�
    �ط����ʱ��100ms��������3��δ���յ��ۿػ���������ֹͣ����
    @retval �ϴ����  ���ؽ��Ӧ����Э�������ʽ
    ����--->����
**/
bool GeneralControlMachineDevice::metaDataUpload(RocketGroundProtolDataFormat& frameData) {

    return true;
}
/**
    @brief  ��Ԫ�ϴ��������
    @retval �ϴ����
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::metaDataUploadResult(RocketGroundProtolDataFormat& frameData) {
	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0x61;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
    return *m_retData;
}
/**
    @brief  ��Ԫ�����´�
    �ۿػ����κ�״̬�¶����Խ�����Ԫ�����´�����Ԫ�������ݵ���ⷢ��ϵͳ���͵����ѯ���ݰ���Ž��������´���ÿ���������һ���´�250���ֽڡ�
    �ط����ʱ��100ms��������3��δ���յ��ۿػ���������ֹͣ����
    @retval �´����  ���ؽ��Ӧ����Э�������ʽ
    ����--->����
**/
bool GeneralControlMachineDevice::metaDataDownload(RocketGroundProtolDataFormat& frameData) {

    return true;
}
/**
    @brief  ��Ԫ�´��������
    @retval ��Ԫ�´����
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::metaDataDownloadResult(RocketGroundProtolDataFormat& frameData) {
	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0x63;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
	return *m_retData;
}
/**
    @brief  ��Ԫ�����˳���д״̬�󣬵���ⷢ��ϵͳ�ɷ�����Ԫ����У��ָ���Ԫ���ݶ�ȡflash�п�ִ�г��������������У��ͣ�����������ⷢ��ϵͳ��
    ��У������У��ɿع�����������޷���Ӧ����ָ�
    ��Ԫ�������У��󣬷���������ⷢ��ϵͳ
    @retval
**/
bool GeneralControlMachineDevice::metaDataCheck(RocketGroundProtolDataFormat& frameData) {

    return true;
}

/**
    @brief  ��ԪУ��������
    @retval ����У����  �����Э�������ʽ
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::metaDataCheckResult(RocketGroundProtolDataFormat& frameData) {
	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0x65;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
    return *m_retData;
}
/**
    @brief  ��Ԫ���ݼ���
    ��Ԫ�����˳���д״̬�󣬵���ⷢ��ϵͳ�ɷ�����Ԫ���ݼ���ָ���Ԫ���ݼ���Flash�е���Ԫ���ݵ��ɿ�����У��ɿ�ʹ�ü��غ����Ԫ���ݡ�
    ��Ԫ���ݼ�����ɺ󣬷���ִ�н��������ⷢ��ϵͳ
    @retval
**/
bool GeneralControlMachineDevice::metaDataLoading(RocketGroundProtolDataFormat& frameData) {

    return true;
}
/**
    @brief ��Ԫ���ݼ��ؽ������
    @retval ���ؽ��  �����Э�������ʽ
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::metaDataLoadingResult(RocketGroundProtolDataFormat& frameData) {
	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0x67;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
    return *m_retData;
}
/**
    @brief  ģ�������ϴ�
    ����ⷢ��ϵͳ���ݿ�ִ�г���������ݷְ���������������ܰ���������ʼ�ϴ���һ��������Ŵ�0�ſ�ʼ��ֱ�����һ����ÿ����Ч�������Ϊ250���ֽڡ�
    �ط����ʱ��100ms��������3��δ���յ��ۿػ���������ֹͣ����
    @retval
**/
bool GeneralControlMachineDevice::simulationFlightDataUpload(RocketGroundProtolDataFormat& frameData) {
	
    return true;
}
/**
    @brief  Ī�������ϴ��������
    @retval ģ�������ϴ����
    Э�������ʽ��OS-X1B���ز��ͨ��Э��
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::simulationFlightDataUploadResult(RocketGroundProtolDataFormat& frameData) {
	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0x69;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
    return *m_retData;
}
/**
    @brief  ��Ʒ�˿ڲ���
    ����ⷢ��ϵͳ���ۿػ����ͻ�Ʒ�˿ڲ��������ۿػ�����ָ����л�Ʒ�˿ڲ��ԣ��ɿ������ѯʱ��2��Ķ˿�״̬��30���ӿ�����������30���˿���λ��Ϊ��0���������ز��Գɹ���
    ����������������˿ڴ�ʱ��λΪ��1�������򷵻ز���ʧ�ܡ�
    �ӽ��յ���Ʒ�˿ڲ�������ʼ���ɿ������5����Ϊ����ʵʱ�ɼ�DRV_STATUS1��DRV_IN_STATSU1�������Ĵ���״̬����ң�⣬�ò�����ʱ����Ҫ��ӽ��ܵ���Ʒ�˿ڲ�����������15�롣
    15����Խ�������ز��Գɹ����򽫲��Խ�����͵���ⷢ��ϵͳ

    @retval
**/
bool GeneralControlMachineDevice::explosivePortTest(RocketGroundProtolDataFormat& frameData) {

    return true;
}
/**
    @brief  ��Ʒ�˿�У��������
    @retval ��Ʒ���Խ��  Э�������ʽ��OS-X1B���ز��ͨ��Э��
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::explosivePortTestResult(RocketGroundProtolDataFormat& frameData) {
	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0x6a;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
    return *m_retData;
}
/**
    @brief  ��Ʒ��ֵ����
    ����ⷢ��ϵͳ���ۿػ����ͻ�Ʒ��ֵ���������ۿػ���ÿһ·�Ļ�Ʒ��ǰ������ֵ����������ⷢ��ϵͳ��
    @retval
**/
bool GeneralControlMachineDevice::explosiveResistMeasure(RocketGroundProtolDataFormat& frameData) {

    return true;
}
/**
    @brief  ��Ʒ��ֵ�����������
    @retval �������  Э�������ʽ��OS-X1B���ز��ͨ��Э��
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::explosiveResistMeasureResult(RocketGroundProtolDataFormat& frameData) {
	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0x71;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
    return *m_retData;
}

/**
    @brief  ˮƽ����
    ����ⷢ��ϵͳ���ۿػ�����ˮƽ����ָ��ۿػ�����ָ�����ˮƽ���㣬��60��ʱ���ڣ��ڼ����ⷢ��ϵͳ��100msΪ�������ۿػ����͸�ָ�������������ת��ң�⣬
    ͬʱ���л��ֽ���ϳ���ת���ٶ� ��ϳɼ��ٶ� ��180��󽫽������ϳ���ת���ٶ� ��ϳɼ��ٶ� ���͵���ⷢ��ϵͳ��ͬʱ����ˮƽ��������
    ����Ҫ���½���ˮƽ����ָ�����ԭִ��IDֵ��1��
    @retval
**/
bool GeneralControlMachineDevice::levelCompute(RocketGroundProtolDataFormat& frameData) {

    return true;
}
/**
    @brief  ˮƽ����������
    @retval ������  Э�������ʽ��OS-X1B���ز��ͨ��Э��
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::levelComputeResult(RocketGroundProtolDataFormat& frameData) {
	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0x73;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
    return *m_retData;
}
/**
    @brief  ת����
    ����ⷢ��ϵͳ�����ˮƽ����󣬿����ۿػ�����ת����ָ��ۿػ����뵼��״̬�ɹ��󣬵���ⷢ��ϵͳ����ʱ�����ۿػ�����ת����ָ�ת����ָ�������ⷢ��ϵͳ������ǰ����״̬��
    @retval
**/
bool GeneralControlMachineDevice::trunNavigate(RocketGroundProtolDataFormat& frameData) {
	
    return true;
}
/**
    @brief  ת�����������
    @retval ת�������
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::trunNavigateResult(RocketGroundProtolDataFormat& frameData) {
	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0xe1;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
    return *m_retData;
}
/**
    @brief  �ɿ������д����
    ����ⷢ��ϵͳ���ͷɿ������д���ƣ�������Ϊ0x11��ָ������ϣ�������Ӧ�����ɿ������д״̬���������ⷢ��ϵͳ�ſ�������ϴ��ɿ������ִ�г������ݣ�������ϲ�����ִ�зɿ����������д����������ɷɿ������д�󣬵���ⷢ��ϵͳ���ͷɿ������д���ƣ�������Ϊ0x22����������Ӧ���˳������д״̬���ȴ�����ⷢ��ϵͳ��������ָ���Ҫ�ɿ��������ʱ������ⷢ��ϵͳ��ɿ�������ͷɿ������д���ƣ�������Ϊ0x33����
    �ط����ʱ��100ms��������3��δ���յ��ۿػ���������ֹͣ����
    @retval
**/
bool GeneralControlMachineDevice::flightControlSoftwareUploadControl(RocketGroundProtolDataFormat& frameData) {

    return true;
}
/**
    @brief  �ɿ������д���ƽ������
    @retval  �ɿ������д״̬����
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::flightControlSoftwareUploadStatus(RocketGroundProtolDataFormat& frameData) {
	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0x5b;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
    return *m_retData;
}

/**
    @brief  �ɿ���������ϴ�
    �ɿ�������������д״̬�󣬽��ղ���Ӧ����ⷢ��ϵͳ���͵ķɿ�������ݣ�����ⷢ��ϵͳ���ݿ�ִ�г���������ݷְ���������������ܰ���������ʼ�ϴ���һ��������Ŵ�0�ſ�ʼ��ֱ�����һ����ÿ����Ч�������Ϊ250���ֽڡ��ط����ʱ��100ms��������3��δ���յ��ۿػ���������ֹͣ����
    @retval
**/
bool GeneralControlMachineDevice::flightControlSoftwareDataUpload(RocketGroundProtolDataFormat& frameData) {

    return true;
}
/**
    @brief  �ɿ���������ϴ����
    @retval �ɿ���������ϴ����
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::flightControlSoftwareDataUploadResult(RocketGroundProtolDataFormat& frameData) {
	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0x5d;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
    return *m_retData;
}

/**
    @brief  �ɿ��������У��
    ����ⷢ��ϵͳ�ɷ��ͷɿ��������У������ָ����а����ɿ������CRC���ɿ�������յ�ָ�����ȡDDR���ϴ��Ŀ�ִ�г��������������У��ͣ���������CRC�ͷɿ������CRC��ͬ����DDR�еķɿ�����������ص�Flash�У�У������صĹ��̹��ƻ����40s���ң����潨������1���ӵĳ�ʱ�жϣ��ۿػ�����������ؽ������������ⷢ��ϵͳ����У�����ع����У��ɿع�����������޷���Ӧ����ָ�
    �ɿ�������У��󣬷���������ⷢ��ϵͳ
    @retval
**/
bool GeneralControlMachineDevice::flightControlSoftwareDataCheck(RocketGroundProtolDataFormat& frameData) {

    return true;
}
/**
    @brief  �ɿ��������У����
    @retval �ɿ��������У����
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::flightControlSoftwareDataCheckResult(RocketGroundProtolDataFormat& frameData) {
	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0x5f;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
    return *m_retData;
}
/**
    @brief  ����Ԥ��
    ����ⷢ���豸���ɿػ�����Ԥ��ɿػ����������󣬶������ⷢ��ϵͳ�ſ�����Ϸ��ͷ������������ϲ�����ִ�з�����ָ��
    @retval
**/
bool GeneralControlMachineDevice::preLaunchCommand(RocketGroundProtolDataFormat& frameData) {

    return true;
}
/**
    @brief  Ԥ����ָ����
    @retval Ԥ����ָ����
**/
RocketGroundProtolDataFormat GeneralControlMachineDevice::preLaunchCommandResult(RocketGroundProtolDataFormat& frameData) {
	//��Ҫ����ÿ���豸�ļ��״̬���и�ֵ
	m_retData->CKA = 0x55;
	m_retData->CKB = 0xaa;
	m_retData->LEN = NULL;
	m_retData->SEQ = NULL;
	m_retData->DEV = 0x01;
	m_retData->MSG = 0xf7;
	m_retData->PAYLOAD[0] = 0x22;//ִ�н��
	m_retData->PAYLOAD[1] = 0xaa;//ִ�гɹ�
	m_retData->PAYLOAD[2] = 0xff;//ȫ���Լ����
	m_retData->PAYLOAD[3] = 0xff;//ȫ���Լ�������
	m_retData->PAYLOAD[4] = 0x0e;//�����豸ͨ�����
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[5 + i] = 0x0;
	}
	m_retData->PAYLOAD[9] = 0xaa;
	m_retData->PAYLOAD[10] = 0xaa;
	for (int i = 0; i < 4; i++)
	{
		m_retData->PAYLOAD[11 + i] = 0xbb;
	}
	m_retData->PAYLOAD[15] = 0x33;//��ǰ�ɿ�ģʽ ����
	for (int i = 0; i < (255 - 16); i++)
	{
		m_retData->PAYLOAD[16 + i] = 0xbb;
	}
	//CKA CKB
	//����У���
	CRC16 crc16(CRC16::eCCITT_FALSE);
	//
	quint16 crc_cal = crc16.crcCompute((char*)(m_retData->PAYLOAD), 255);
	m_retData->CKB = crc_cal << 8;//�߰�λ
	m_retData->CKA = crc_cal << 0;//�Ͱ�λ
    return *m_retData;
}
/**
    @brief  ����������
    ����ⷢ���豸��������3�θ��ɿػ���������ɿػ����������󣬽�����ʽ�������̣����п�˨��𣩡���������ֻ�ڷɿؽ��յ�����Ԥ��󣬷�����Ӧ
    @retval �޷���
**/
void GeneralControlMachineDevice::launchFireCommand(RocketGroundProtolDataFormat& frameData) {

}
/**
    @brief ����Ԥ��
    �ڷ����쳣����£�����ⷢ���豸���ۿػ����Ͱ���Ԥ��ɿػ����պ󣬽��밲�����̡����ض���ֻ�ڷɿؽ��յ�����Ԥ��󣬷�����Ӧ
    @retval �޷���
**/
void GeneralControlMachineDevice::safeControlPreCommand(RocketGroundProtolDataFormat& frameData) {

}
/**
    @brief ���ض���
    �ڷ����쳣����£�����ⷢ���豸����3�����ۿػ����Ͱ���Ԥ��ɿػ������ж�ͨ���󣬽��밲�����̡����ض���ֻ�ڷɿؽ��յ�����Ԥ��󣬷�����Ӧ
    @retval �޷���
**/
void GeneralControlMachineDevice::safeControlActivateCommand(RocketGroundProtolDataFormat& frameData) {

}