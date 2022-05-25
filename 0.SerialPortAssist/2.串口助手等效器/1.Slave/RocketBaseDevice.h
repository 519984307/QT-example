#pragma once
#ifndef ROCKET_BASE_DEVICE_H
#define ROCKET_BASE_DEVICE_H


#include <QtCore>
//#include "RocketGroundBaseProtol.h"
#include "RocketGroundProtolDataFormat.h"
#include "CrcCompute.h"


enum FlightControlMode
{
	LUANCH_CONTROL_MODE = 0x11,
	HARDWARE_IN_THE_LOOP_SIMULATION_MODE = 0x22,
	TEST_MODE = 0x33,
	TEST_AND_PRACTICE_SIMULATION_FLYING_MODE = 0x44,
	TEST_AND_FORMAL_FLYING_MODE = 0x55,
	OTHER_MODE = 0xff

};


/**

    @class   RocketBaseDevice
    @brief  �����豸��Ϣ
    @details ~

**/
class RocketBaseDevice
{

    //�����豸�ȱ�����Ϣ
    bool generalControlMachineSelfCheckStatus = 0;
    bool intertialGroundSelfCheckStatus = 0;
    bool gpsSelfCheckStatus = 0;
    bool servoSelfCheckStatus = 0;
    bool squentialPlatePortTestStatus = 0;

    bool generalControlMachineSelfCheckResult = 0;
    bool intertialGroundSelfCheckResult = 0;
    bool gpsSelfCheckResult = 0;
    bool servoSelfResult = 0;
    bool squentialPlatePortTestResult = 0;

    bool intertialGroundComStatus = 0;
    bool gpsComStatus = 0;
    bool servoComStatus = 0;

    unsigned short explosiveTruthOrFakeTestResult = 0xbbbb;

    byte currentFlightControlMode = FlightControlMode::OTHER_MODE;
    byte flightControlUploadVersion1 = 0;
    byte flightControlUploadVersion2 = 0;
    byte flightControlUploadTimeYear1 = 0;
    byte flightControlUploadTimeYear2 = 0;
    byte flightControlUploadTimeMonth = 0;
    byte flightControlUploadTimeDay = 0;
    byte flightControlUploadTimeHour = 0;
    byte flightControlUploadTimeMinute = 0;
    byte metaDataUploadVersion1 = 0;
    byte metaDataUploadVersion2 = 0;
    byte metaDataUploadTimeYear1 = 0;
    byte metaDataUploadTimeYear2 = 0;
    byte metaDataUploadTimeMonth = 0;
    byte metaDataUploadTimeDay = 0;
    byte metaDataUploadTimeHour = 0;
    byte metaDataUploadTimeMinute = 0;


};

/**

    @class   GeneralControlMachineDevice
    @brief   �ۿػ��豸
    @details ~�����ۿػ��豸�������ۿػ������к�������

**/
class GeneralControlMachineDevice
{
public:
    GeneralControlMachineDevice();

public:
    /**
        @brief  �ۿػ��ϵ�����
        �ⷢ�����ͨ��RS422���Դ����ģ�鷢���ۿػ��ϵ�ָ���Դ����ģ��������28V�ϵ������źţ�ʹ�ۿػ��ϵ硣��Э���޶�Ӧң����
        @retval �޷���
    **/
    void generalMachinePowerOn(RocketGroundProtolDataFormat& frameData);//�ϵ�
    /**
        @brief  �ۿػ��µ�����
        �ⷢ�����ͨ��RS422���Դ����ģ�鷢���ۿػ��µ�ָ�ʹ�ۿػ��µ硣��Э���޶�Ӧң��Э��
        @retval �޷���
    **/
    void generalMachinePowerOff(RocketGroundProtolDataFormat& frameData);//�µ�
    /**
        @brief  �ۿػ��Լ�����
        ����ⷢ��ϵͳ��100msΪ���ڣ����ۿػ������Լ�����ָ��ۿػ������������Լ���Ϣ��������������豸���ͨѶ������Լ�����Ϣ��
        �ۿػ��յ�ָ������������Լ��������״̬������ⷢ�ضԽ�������жϣ��Լ����Ƿ�����
        @retval 
    **/
    bool generalMachineSelfCheck(RocketGroundProtolDataFormat& frameData);//�Լ�
    /**
        @brief  �����ۿػ��Լ���
        @retval �Լ���
    **/
    RocketGroundProtolDataFormat generalMachineSelfCheckResult(RocketGroundProtolDataFormat& frameData);

    /**
        @brief  ����ⷢ��ϵͳ�����ۿػ�����״̬��ѯָ��ۿػ�����ָ��󣬷�����ǰ����״̬
        @retval ��ǰ����״̬
    **/
    bool flightControlSoftwareStatusQuery(RocketGroundProtolDataFormat& frameData);//�ɿ�״̬
    /**
        @brief  �ɿ�״̬��ѯ���
        @retval 
    **/
    RocketGroundProtolDataFormat flightControlSoftwareStatusQueryResult(RocketGroundProtolDataFormat& frameData);//�ɿ�״̬

    /**
        @brief  �����������
        ����ⷢ���豸���������ָ��͸��ۿػ����ۿػ����յ������ݺ����ۿػ���絥Ԫ�Լ�ʱ��ģ����е�����硣
        ��ɺ��ۿػ������ⷢ���豸��������ѹ��Ϣ��
        @retval 
    **/
    bool singleDistribution(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  �������������
        @retval ����ѹ��Ϣ
    **/
    RocketGroundProtolDataFormat singleDistributionResult(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  �������ݲ���
        ����ⷢ���豸���ۿػ����͹������ݲ��������ۿػ������˹��鵱ǰ������Ϣ�����������豸
        @retval 
    **/
    bool intertialGroupDataMeasure(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  �������ݲ����������
        @retval ���˹��鵱ǰ������Ϣ
    **/
    RocketGroundProtolDataFormat intertialGroupDataMeasureResult(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  GPS���ݲ���
        ����ⷢ���豸���ۿػ�����GPS���ݲ��������ۿػ���GPS��ǰ������Ϣ�����������豸
        @retval 
    **/
    bool gpsDataMeasure(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  GPS���ݲ����������
        @retval GPS��ǰ������Ϣ
    **/
    RocketGroundProtolDataFormat gpsDataMeasureResult(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  �ŷ���λװ��
        ����ⷢ��ϵͳ����λ��Ϣ���͸��ۿػ����ۿػ����յ������ݺ����ŷ�ϵͳ������λ����װ������ɺ��ۿػ������ⷢ���豸����װ�����
        @retval 
    **/
    bool servoZeroBinding(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  �ŷ���λװ���������
        @retval װ�����
    **/
    RocketGroundProtolDataFormat servoZeroBindingResult(RocketGroundProtolDataFormat& frameData);

    /**
        @brief  �����ŷ�������Ϣ��ת����Ϣ
        ����ⷢ��ϵͳ���ŷ�������Ϣ���͸��ۿػ����ۿػ����յ������ݺ����ŷ�ϵͳת������Ϣ�������ŷ�������Ϣת��������ⷢ��ϵͳ
        @retval 
    **/
    bool servoMeasure(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  �ŷ������������
        @retval �ŷ�������Ϣ
    **/
    RocketGroundProtolDataFormat servoMeasureResult(RocketGroundProtolDataFormat& frameData);
 
 
    /**
        @brief  ����ⷢ��ϵͳ���ŷ�С��·������Ϣ���͸��ۿػ����ۿػ����յ������ݺ󣬷ɿ����ִ�о����ƫָ����±��ɷɿ������̲�ִ�У���
        �ɿ������5����Ϊ����ʵʱ���ŷ��ؼ��������ݷ�ң�⣬ִ�����ƫָ��󣬷ɿ���������ⷢ�ط����ŷ��������
        @retval 
    **/
    bool servoSmallLoopMeasure(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  �ŷ�С��·�����������
        @retval �ŷ��������
    **/
    RocketGroundProtolDataFormat servoSmallLoopMeasureResult(RocketGroundProtolDataFormat& frameData);

    /**
        @brief ����ⷢ���豸���ŷ���ؼ���ָ��͸��ۿػ����ۿػ����յ������ݺ����ŷ�������ʱ���źŽ��е�ؼ��
        ��ɺ��ۿػ������ⷢ���豸�����ŷ���ؼ�����Ϣ
        @retval 
    **/
    bool servoBatteryActivate(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  �ŷ���ؼ���������
        @retval ��ؼ�����Ϣ
    **/
    RocketGroundProtolDataFormat servoBatteryActivateResult(RocketGroundProtolDataFormat& frameData);

    /**
        @brief  ����ⷢ��ϵͳ������Ԫ��д���ƣ�������Ϊ0x11��ָ������ϣ�������Ӧ�������Ԫ������д״̬��
        �������ⷢ��ϵͳ�ſ�������ϴ���Ԫ���ݣ�������ϲ�����ִ����Ԫ������д�������������Ԫ������д��
        ����ⷢ��ϵͳ������Ԫ������д���ƣ�������Ϊ0x22����
        ������Ӧ���˳���Ԫ������д״̬���ȴ�����ⷢ��ϵͳ��������ָ��
        @retval 
    **/
    bool metaDataControl(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  ��Ԫ���ݿ��ƽ������
        @retval ��д״̬����
    **/
    RocketGroundProtolDataFormat metaDataControlResult(RocketGroundProtolDataFormat& frameData);

    /**
        @brief  ��Ԫ�����ϴ�
        ��Ԫ���ݽ��������д״̬�󣬽��ղ���Ӧ����ⷢ��ϵͳ���͵���Ԫ���ݣ�����ⷢ��ϵͳ���ݿ�ִ�г���������ݷְ���������������ܰ���������ʼ�ϴ���һ��������Ŵ�0�ſ�ʼ��ֱ�����һ����ÿ����Ч�������Ϊ250���ֽڡ�
        �ط����ʱ��100ms��������3��δ���յ��ۿػ���������ֹͣ����
        @retval �ϴ����  ���ؽ��Ӧ����Э�������ʽ 
        ����--->����
    **/
    bool metaDataUpload(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  ��Ԫ�ϴ��������
        @retval �ϴ����
    **/
    RocketGroundProtolDataFormat metaDataUploadResult(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  ��Ԫ�����´�
		�ۿػ����κ�״̬�¶����Խ�����Ԫ�����´�����Ԫ�������ݵ���ⷢ��ϵͳ���͵����ѯ���ݰ���Ž��������´���ÿ���������һ���´�250���ֽڡ�
		�ط����ʱ��100ms��������3��δ���յ��ۿػ���������ֹͣ����
		@retval �´����  ���ؽ��Ӧ����Э�������ʽ
		����--->����
    **/
    bool metaDataDownload(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  ��Ԫ�´��������
        @retval ��Ԫ�´����
    **/
    RocketGroundProtolDataFormat metaDataDownloadResult(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  ��Ԫ�����˳���д״̬�󣬵���ⷢ��ϵͳ�ɷ�����Ԫ����У��ָ���Ԫ���ݶ�ȡflash�п�ִ�г��������������У��ͣ�����������ⷢ��ϵͳ��
        ��У������У��ɿع�����������޷���Ӧ����ָ�
        ��Ԫ�������У��󣬷���������ⷢ��ϵͳ
        @retval 
    **/
    bool metaDataCheck(RocketGroundProtolDataFormat& frameData);

    /**
        @brief  ��ԪУ��������
        @retval ����У����  �����Э�������ʽ
    **/
    RocketGroundProtolDataFormat metaDataCheckResult(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  ��Ԫ���ݼ���
        ��Ԫ�����˳���д״̬�󣬵���ⷢ��ϵͳ�ɷ�����Ԫ���ݼ���ָ���Ԫ���ݼ���Flash�е���Ԫ���ݵ��ɿ�����У��ɿ�ʹ�ü��غ����Ԫ���ݡ�
        ��Ԫ���ݼ�����ɺ󣬷���ִ�н��������ⷢ��ϵͳ
        @retval 
    **/
    bool metaDataLoading(RocketGroundProtolDataFormat& frameData);
    /**
        @brief ��Ԫ���ݼ��ؽ������
        @retval ���ؽ��  �����Э�������ʽ
    **/
    RocketGroundProtolDataFormat metaDataLoadingResult(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  ģ�������ϴ� 
        ����ⷢ��ϵͳ���ݿ�ִ�г���������ݷְ���������������ܰ���������ʼ�ϴ���һ��������Ŵ�0�ſ�ʼ��ֱ�����һ����ÿ����Ч�������Ϊ250���ֽڡ�
        �ط����ʱ��100ms��������3��δ���յ��ۿػ���������ֹͣ����
        @retval 
    **/
    bool simulationFlightDataUpload(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  Ī�������ϴ��������
		@retval ģ�������ϴ����
		Э�������ʽ��OS-X1B���ز��ͨ��Э��
    **/
    RocketGroundProtolDataFormat simulationFlightDataUploadResult(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  ��Ʒ�˿ڲ���
		����ⷢ��ϵͳ���ۿػ����ͻ�Ʒ�˿ڲ��������ۿػ�����ָ����л�Ʒ�˿ڲ��ԣ��ɿ������ѯʱ��2��Ķ˿�״̬��30���ӿ�����������30���˿���λ��Ϊ��0���������ز��Գɹ���
        ����������������˿ڴ�ʱ��λΪ��1�������򷵻ز���ʧ�ܡ�
        �ӽ��յ���Ʒ�˿ڲ�������ʼ���ɿ������5����Ϊ����ʵʱ�ɼ�DRV_STATUS1��DRV_IN_STATSU1�������Ĵ���״̬����ң�⣬�ò�����ʱ����Ҫ��ӽ��ܵ���Ʒ�˿ڲ�����������15�롣
        15����Խ�������ز��Գɹ����򽫲��Խ�����͵���ⷢ��ϵͳ

        @retval 
    **/
    bool explosivePortTest(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  ��Ʒ�˿�У��������
        @retval ��Ʒ���Խ��  Э�������ʽ��OS-X1B���ز��ͨ��Э��
    **/
    RocketGroundProtolDataFormat explosivePortTestResult(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  ��Ʒ��ֵ����
        ����ⷢ��ϵͳ���ۿػ����ͻ�Ʒ��ֵ���������ۿػ���ÿһ·�Ļ�Ʒ��ǰ������ֵ����������ⷢ��ϵͳ��
        @retval 
    **/
    bool explosiveResistMeasure(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  ��Ʒ��ֵ�����������
        @retval �������  Э�������ʽ��OS-X1B���ز��ͨ��Э��
    **/
    RocketGroundProtolDataFormat explosiveResistMeasureResult(RocketGroundProtolDataFormat& frameData);

    /**
        @brief  ˮƽ����
        ����ⷢ��ϵͳ���ۿػ�����ˮƽ����ָ��ۿػ�����ָ�����ˮƽ���㣬��60��ʱ���ڣ��ڼ����ⷢ��ϵͳ��100msΪ�������ۿػ����͸�ָ�������������ת��ң�⣬
        ͬʱ���л��ֽ���ϳ���ת���ٶ� ��ϳɼ��ٶ� ��180��󽫽������ϳ���ת���ٶ� ��ϳɼ��ٶ� ���͵���ⷢ��ϵͳ��ͬʱ����ˮƽ��������
        ����Ҫ���½���ˮƽ����ָ�����ԭִ��IDֵ��1��
        @retval 
    **/
    bool levelCompute(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  ˮƽ����������
        @retval ������  Э�������ʽ��OS-X1B���ز��ͨ��Э��
    **/
    RocketGroundProtolDataFormat levelComputeResult(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  ת���� 
        ����ⷢ��ϵͳ�����ˮƽ����󣬿����ۿػ�����ת����ָ��ۿػ����뵼��״̬�ɹ��󣬵���ⷢ��ϵͳ����ʱ�����ۿػ�����ת����ָ�ת����ָ�������ⷢ��ϵͳ������ǰ����״̬��
        @retval  
    **/
    bool trunNavigate(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  ת�����������
        @retval ת������� 
    **/
    RocketGroundProtolDataFormat trunNavigateResult(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  �ɿ������д����
        ����ⷢ��ϵͳ���ͷɿ������д���ƣ�������Ϊ0x11��ָ������ϣ�������Ӧ�����ɿ������д״̬���������ⷢ��ϵͳ�ſ�������ϴ��ɿ������ִ�г������ݣ�������ϲ�����ִ�зɿ����������д����������ɷɿ������д�󣬵���ⷢ��ϵͳ���ͷɿ������д���ƣ�������Ϊ0x22����������Ӧ���˳������д״̬���ȴ�����ⷢ��ϵͳ��������ָ���Ҫ�ɿ��������ʱ������ⷢ��ϵͳ��ɿ�������ͷɿ������д���ƣ�������Ϊ0x33����
        �ط����ʱ��100ms��������3��δ���յ��ۿػ���������ֹͣ����
        @retval
    **/
    bool flightControlSoftwareUploadControl(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  �ɿ������д���ƽ������
        @retval  �ɿ������д״̬����
    **/
    RocketGroundProtolDataFormat flightControlSoftwareUploadStatus(RocketGroundProtolDataFormat& frameData);

    /**
        @brief  �ɿ���������ϴ�
        �ɿ�������������д״̬�󣬽��ղ���Ӧ����ⷢ��ϵͳ���͵ķɿ�������ݣ�����ⷢ��ϵͳ���ݿ�ִ�г���������ݷְ���������������ܰ���������ʼ�ϴ���һ��������Ŵ�0�ſ�ʼ��ֱ�����һ����ÿ����Ч�������Ϊ250���ֽڡ��ط����ʱ��100ms��������3��δ���յ��ۿػ���������ֹͣ����
        @retval 
    **/
    bool flightControlSoftwareDataUpload(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  �ɿ���������ϴ����
        @retval �ɿ���������ϴ����
    **/
    RocketGroundProtolDataFormat flightControlSoftwareDataUploadResult(RocketGroundProtolDataFormat& frameData);

    /**
        @brief  �ɿ��������У��
        ����ⷢ��ϵͳ�ɷ��ͷɿ��������У������ָ����а����ɿ������CRC���ɿ�������յ�ָ�����ȡDDR���ϴ��Ŀ�ִ�г��������������У��ͣ���������CRC�ͷɿ������CRC��ͬ����DDR�еķɿ�����������ص�Flash�У�У������صĹ��̹��ƻ����40s���ң����潨������1���ӵĳ�ʱ�жϣ��ۿػ�����������ؽ������������ⷢ��ϵͳ����У�����ع����У��ɿع�����������޷���Ӧ����ָ�
        �ɿ�������У��󣬷���������ⷢ��ϵͳ
        @retval 
    **/
    bool flightControlSoftwareDataCheck(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  �ɿ��������У����
        @retval �ɿ��������У����
    **/
    RocketGroundProtolDataFormat flightControlSoftwareDataCheckResult(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  ����Ԥ��
        ����ⷢ���豸���ɿػ�����Ԥ��ɿػ����������󣬶������ⷢ��ϵͳ�ſ�����Ϸ��ͷ������������ϲ�����ִ�з�����ָ��
        @retval 
    **/
    bool preLaunchCommand(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  Ԥ����ָ����
        @retval Ԥ����ָ����
    **/
    RocketGroundProtolDataFormat preLaunchCommandResult(RocketGroundProtolDataFormat& frameData);
    /**
        @brief  ����������
        ����ⷢ���豸��������3�θ��ɿػ���������ɿػ����������󣬽�����ʽ�������̣����п�˨��𣩡���������ֻ�ڷɿؽ��յ�����Ԥ��󣬷�����Ӧ
        @retval �޷���
    **/
    void launchFireCommand(RocketGroundProtolDataFormat& frameData);
    /**
        @brief ����Ԥ��
        �ڷ����쳣����£�����ⷢ���豸���ۿػ����Ͱ���Ԥ��ɿػ����պ󣬽��밲�����̡����ض���ֻ�ڷɿؽ��յ�����Ԥ��󣬷�����Ӧ
        @retval �޷���
    **/
    void safeControlPreCommand(RocketGroundProtolDataFormat& frameData);
    /**
        @brief ���ض���
        �ڷ����쳣����£�����ⷢ���豸����3�����ۿػ����Ͱ���Ԥ��ɿػ������ж�ͨ���󣬽��밲�����̡����ض���ֻ�ڷɿؽ��յ�����Ԥ��󣬷�����Ӧ
        @retval �޷���
    **/
    void safeControlActivateCommand(RocketGroundProtolDataFormat& frameData);
private:


    RocketGroundProtolDataFormat* m_retData=nullptr;
    //���Ϲ���
    RocketBaseDevice m_baseDevice;

};



/**

    @class   ServoDevice
    @brief   �ŷ��豸
    @details ~

**/
class ServoDevice
{
public:


private:

};


/**

    @class   PowerManageModule
    @brief   ��Դ����ģ��
    @details ~

**/
class PowerManageModule
{
public:


private:

};









#endif