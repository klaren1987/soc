// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SocketerBPLibrary.h"
#include "CPMsg.h"
#include "COMMMsg.h"
#include "CPGFMsg.h"
#include "CPGF_msg_ab_conf.h"
#include "CVMSession.generated.h"


USTRUCT(BlueprintType)
struct FBP_CPMsg082 {
	GENERATED_BODY()
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int m_numAb;

	//��� ��� ��������.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int m_typeKSA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		TArray<int> chan_state;

};
USTRUCT(BlueprintType)
struct  FBPCPMsg82
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	    int m_cnt_cell;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	TArray<FBP_CPMsg082> m_l;
	
};

USTRUCT(BlueprintType)
struct  FBPCPMsg101
{
	GENERATED_BODY()

		
	// Number of air object.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int objnum;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int master;

	// Nationality 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int nation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int type;

	/*! \var int group;
	\�������������� ������
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int group;

	//  ����� �� � ������� ��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		TArray<int> numbering;

	//����� ������; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numUnited;

	/*! \var int x;
	\brief X coordinate of air object.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int x;

	/*! \var int y;
	\brief Y coordinate of air object.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int y;

	/*! \var int h;
	\brief Height of air object.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int h;

	/*! \var int vx;
	\brief X velocity component.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int vx;

	/*! \var int vy;
	\brief Y velocity component.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int vy;

	/*! \var int vh;
	\brief Height velocity component.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int vh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int infl;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int signs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int tracking;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int Index;

	// Maneuver signs:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int mnvr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int disaster;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int Fuel;

	//  ����� �������� ���������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int signAbonentAction;

	/*! int signAbonentAction;
	����� �������� ���������
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int signAbonentActionREB;

	/*! int signAbonentNotify;
	����� ���������� ���������
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int signAbonentNotify;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numberingZRK;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		TArray<int> rez;

	//  ����� �� ��� ������� �� ������ ��� �������� 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		TArray<int> numbering_out;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int real_course;

};
/*
struct  FBPCPMsg102
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM");

}
*/
USTRUCT(BlueprintType)
struct  FBPCPMsg103
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int srcObjnum;

};
USTRUCT(BlueprintType)
struct  FBPCPMsg107
{
	GENERATED_BODY()

		
	/*! \var int numAb;
	\brief Number of abonent.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numAb;

	/*! \var int numZRK;
	\brief Number of ZRK.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numZRK;

	/*! \var int numAirObjCP;
	\brief Number of air object in CP numeration.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numAirObjCP;

	/*! \var int numAirObjAb;
	\brief Number of air object in abonent numeration.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numAirObjAb;

	/*! \var int pr_info;
	\brief Sign of information.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int pr_info;
	//pr_info
	enum
	{
		//command on air object to abonent.
		I_COMMAND_AIR_OBJ_TO = 0x01,
		//command on air object from abonent.
		I_COMMAND_AIR_OBJ_FROM = 0x04,
		//delete command on air object to abonent.
		I_DEL_COMMAND_AIR_OBJ_TO = 0x81,
		//delete command on air object from abonent.
		I_DEL_COMMAND_AIR_OBJ_FROM = 0x84
	};

	/*! \var int code;
	\brief Code of command.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int code;
	//code
	enum
	{
		//cancelation last command
		CANCEL_LAST_COMMAND1 = 0x00,
		//telephone talk on air object (relating to abonents 1-6 )
		TELEPHONE = 0x01,
		//destroy air object 
		DESTROY_AIR_OBJ = 0x11,
		//specify nationality 
		//prohibition of influence on air object
		PROHIBIT_INFLUENCE = 0x22,
		//absolute prohibition of influence on air object 
		ABS_PROHIBIT_INFLUENCE = 0x22,
		//prohibition of launch rocket 
		PROHIBIT_LAUNCH_ROCKET = 0x24,
		//permit of launch rocket 
		PERMIT_LAUNCH_ROCKET = 0x33,
		//cancelation last command 
		CANCEL_LAST_COMMAND2 = 0x99
	};
	/*! \var int Channel;
	\brief Number of the channel.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numCannel;

	/*! \var int RocketType;
	\brief type of the rocket.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int RocketType;
	/*! \var int TDPriopNumber;
	\brief Number of the TDprioritet.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int TDPriopNumber;

	/*! \var int m_numZU;
	\brief number ZU.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int m_numZU;

};
/*
struct  FBPCPMsg109
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM");

}
*/
USTRUCT(BlueprintType)
struct  FBPCPMsg112
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int x;
};
/*
struct  FBPCPMsg114
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM");

}
*/
USTRUCT(BlueprintType)
struct  FBPCPMsg117
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int x;


};
USTRUCT(BlueprintType)
struct  FBPCPMsg123
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int totalObjects;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int totalObjectsQuantyti;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int enemyObjects;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int enemyObjectsQuantyti;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int totalInputStream;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int influenceObjectsFLACK;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int influenceObjectsAVIA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int bearingObjects;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		TMap<int,int> heightObjects;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int notifObjects;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		TArray<int> totalObjectsAb;

};
USTRUCT(BlueprintType)
struct  FBPCPMsg125
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int type;
	enum {
		INQ_CONFIRM = 0x05, // TD Confirmation
		INQ_CONFIRM_CANCEL = 0x06, // TD Confirmation 
		INQ_SEND_ALERTNESS_ON_HCP = 0x07,//�� �� ���
		INQ_STOP_SEND_ALERTNESS_ON_HCP = 0x87,//������ �� �� ���  
		INQ_SEND_PSN_ON_HCP = 0x08,//��������� �� ���
		INQ_SEND_FIXPSN_ON_HCP = 0x09,//�����  �� �������
		INQ_START_OBO = 0x0B,//�������� ���
		INQ_STOP_OBO = 0x0C,//���� ���
		INQ_REGISTR = 0x1C,//����������������
		INQ_P_CNTRL = 0x0D,// Under full control
		INQ_INDPNDNT = 0x0E,// Independent combat
		INQ_TARGET_PARAM = 0x0F,// Target's param for ustirovka
		INQ_AUTODESIGN_ON = 0x10, // Automatic designation sendin' is on
		INQ_AUTODESIGN_OFF = 0x11 // Automatic designation sendin' is off
	};



	/*! \var int abNum;
	\brief Abonent number.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int abNumber;

	/*! \var int sabNum;
	\brief Sub Abonent number.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int sabNumber;

	/*! \var int param;
	\brief Parameter.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int param;

};
USTRUCT(BlueprintType)
struct  FBPCPMsg135
{
	GENERATED_BODY()

	
	/*! \var int numAb;
	\brief Number of abonent.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numAbon;

	/*! \var int SubIndex;
	\brief ������� ���������� ������(��).
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int SubIndex;

	/*! \var int Azimut_RPH;
	\brief ������ ����������� ������� ���������������.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	float Azimut_RPH;

	// half size of sector.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	float m_half_sector;

	/*! \var int Sign_Zoni;
	\brief ������� ���� ������ �� ���� �����.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int Sign_Zoni;

	enum {
		SI_current_wrk_sect = 1,
		//current operating sector.
		SI_prohibit_capture = 2,
		//prohibit capture sector.
		SI_assign_sect = 3,
		//assigned sector.
		SI_regular_view = 4,
		//regular view sector.
		SI_cancel_assign_sect = 5,
		//cancel assigned sector.
		SI_cancel_regular_view = 6,
		//cancel regular view sector.
		SI_cancel_prohibit_capture = 7,
		//cancel prohibit capture sector.
		SI_assign_resp_sector4launcher = 9,
		SI_cancel_resp_sector4launcher = 10,
		SI_cancel_wrk_sect = 11

	};

	/*! \var int rezerv;
	\brief ������.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int rezerv;


};
USTRUCT(BlueprintType)
struct  FBPCPMsg138
{
	GENERATED_BODY()

	
	// ����� ��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numAb;

	// ������ ��������������  1-6� ����� ������������ ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int SubIndex;

	// ����� ������ ���
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int Channel;

	// ����� ��, �� �������� ���������� �� � ��������� ���
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numAirObjCPcu;

	// ����� ��, �� �������� ������� ���� ������ �������� � ��������� ���
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numAirObjCPbd;

	// ����� �� � ��������� ��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numAirObjAb;

	// ��������� �������� ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int ChannelState;
	enum
	{
		FREE = 0,  // ����� ��������
		CHANNEL_BUZY = 1,  // ����� �����
		NO_TRIG = 2   // ����� �� ��������
	};

	// ���� ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int PhaseCU;
	
	enum
	{
		BD_DESTROY_AIR_OBJ = 0x11, // (��)
		BD_PROHIBIT_LAUNCH_ROCKET = 0x24, // ������ ����� ������ (��)
		BD_PERMIT_LAUNCH_ROCKET = 0x33, // ���������� ����� ������ (��)
		BD_SUPPORT_CANSEL_CU = 0x99 // 
	};

	// ���� ������ ��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int PhaseBD;
	enum
	{
		BD_NOT_INF = 0x00,  // ��� ����������
		BD_SEARCH = 0x49,  // ����� ���� //CPMsg108::AIR_OBJ_SEARCHING = 0x49 (�)
		BD_ESCORT = 0x46,  // ������ �� ������������� //CPMsg108::AIR_OBJ_CAPTURED = 0x46 (��)
		BD_SUPPORT = 0x48,  // ������������� � �������� ��������� ����//CPMsg108:: AIR_OBJ_ON_TRACKING = 0x48 (��)
		BD_RKT_LAUNCHED = 0x41,  // ���� ���������� //CPMsg108::ROCKET_LAUNCHED = 0x41 (��)
		BD_MITTING = 0x52,   // �������//CPMsg108::AIR_OBJ_DESTROYED = 0x52 (���)
		BD_CYCLE_END = 0x20, // ���� ������ �� ���� �������� (��)
		BD_REJECT = 0x55, // ����� �� �� (�-�)
		BD_SUPPORT_MANUAL = 0x60, // ������������� � ������ ������ (��)
		BD_AO_DESTROYED = 0x45, // ���� ���������� (��)
		BD_AO_SKIPPED = 0x43 // ���� ��������� (����)
	};

	// ����� ������, � �������� ��������� �����������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int ChannelRazmn;

	// ������� �������������� ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int signRez;

	// ������� ������� ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int sign_trouble;

	// ������� ���������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int report_sign;
	enum
	{
		REPORT_ABS = 0, // ���������� ���������;
		REPORT_BEARING = 4, // �������������� ������������ �� �������;
		REPORT_AIR_OBJ_FROM = 8, // �������������� ������������ �� ��;
		REPORT_INDEPENDENT = 16 // ������������ ��������������� ������ ������;
	};

	// ����� �� �� �� (��������)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numZU_AirObj_CP;

	// ����� �� �� ������� (��������)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numZU_Pel_CP;

	// ����� �� �� �� (��������������� ���������)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numZU_AirObj_AB;

	// ����� �� �� ������� (��������������� ���������)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numZU_Pel_AB;

	// ��� ������ ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int typeRocket1;

	// ��� ������ ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int typeRocket2;

};
USTRUCT(BlueprintType)
struct  FBPCPMsg139
{
	GENERATED_BODY()

		
	/*! \var int numAb;
	\brief Number of abonent.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numAbon;

	/*! \var int SubIndex;
	\brief ������� ���������� ������(��).
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int SubIndex;

	/*! \var int Betta_MUP;
	\brief ������ ���������� ������� ��������.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int Betta_MUP;

	/*! \var int PC;
	\brief ������ �������������.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int RC;

	/*! \var int ACFI;
	\brief ������������� ���� �� ������� �����������.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int ACFI;

	/*! \var int ALKP;
	\brief �������� ����������� �����.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int ALKP;

	/*! \var int PEL;
	\brief ������ �������� �� �������.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int PEL;

	/*! \var int ZR;
	\brief �������������� �������������.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int ZR;

};
USTRUCT(BlueprintType)
struct  FBPCPMsg148
{
	GENERATED_BODY()

	
	/*! \var int numAb;
	\brief Number of abonent.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numAbon;

	/*! \var int SubIndex;
	\brief ������� ���������� ������(��).
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int SubIndex;

	/*! \var int Alert_CP;
	\brief ������� ������������� ��.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int Alert_CP;
	enum {
		Alert_CP_NotInfo = 0, //��� ����������
		Alert_CP_Not = 1,     //�� �� ��������
		Alert_CP_Yes = 2      //�� ��������
	};

	/*! \var int Alert_RLO;
	\brief ������� ����������� ���.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int Alert_RLO;
	enum {
		Alert_RLO_NotInfo = 0, //��� ����������
		Alert_RLO_Not = 1,     //��� ����������
		Alert_RLO_Yes = 2      //��� ��������
	};
	/*! \var int Work_COU;
	\brief ������� ����������� ���.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int Work_COU;
	enum {
		Work_COU_NotInfo = 0, //��� ����������
		Work_COU_Not = 1,     //��� ����������
		Work_COU_Yes = 2      //��� ��������
	};

	/*! \var int Work_PZU;
	\brief ������� ����������� ���.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int Work_PZU;
	enum {
		Work_PZU_NotInfo = 0, //��� ����������
		Work_PZU_Not = 1,     //��� ���������� 
		Work_PZU_Yes = 2      //��� ��������
	};

	/*! \var int Work_PIP;
	\brief ������� ����������� ���.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int Work_PIP;
	enum {
		Work_PIP_NotInfo = 0,//��� ����������
		Work_PIP_Not = 1,    //���������� �������� ����������
		Work_PIP_Yes = 2     //���������� �������� ���������
	};

	/*! \var int Work_PPZ;
	\brief ������� �����������.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int Work_PPZ;
	enum {
		Work_PPZ_NotInfo = 0,//��� ����������		
		Work_PPZ_Not = 1,    //��� �����������		
		Work_PPZ_Yes = 2     //����������
	};

};
USTRUCT(BlueprintType)
struct  FBPCPMsg154
{
	GENERATED_BODY()

		
	/*! \var int numAb;
	\brief Number of abonent.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numAb;

	/*! \var int numZRK;
	\brief Number of ZRK.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numZRK;

	/*! \var int numAirObjCP;
	\brief Number of air object in CP numeration.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numAirObjCP;

	/*! \var int numAirObjAb;
	\brief Number of air object in abonent numeration.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numAirObjAb;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numUnited;   //����� ������ 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int data;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	float	azimuth;

	/*! \var int h;
	\brief Height of air object.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int h;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int distance;
	/*! \var int v;
	\brief  velocity .
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int v;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int type;

	/*! \var int Phase;
	\brief Phase of the battle operations.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int Phase;

	/*! \var int pr_info;
	\brief sing of report.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int pr_info;

	//pr_info
	enum
	{
		//command on air object to abonent.
		I_COMMAND_AIR_OBJ_TO = 0x01,
		//report by air object from abonent.
		REPORT_AIR_OBJ_FROM = 0x08,
		//report independent by air object from abonent.
		REPORT_INDEPENDENT = 0x10
	};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int res;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int res1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	float elevation;

};
USTRUCT(BlueprintType)
struct  FBPCPMsg157
{
	GENERATED_BODY()


		enum {
		//"not set value" for regime.
		NOT_SET_REGIME = 0,
		//"not set value" for reglament.
		NOT_SET_REGLAMENT = 255
	};
	/*! \var int numAb;
	\brief Number of abonent.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numAb;

	/*! \var int numZRK;
	\brief Number of ZRK.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numZRK;

	// type of data
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int data_type;
	enum {
		DT_FROM_HCP = 0x01, // �������� �� ���
		DT_FROM_CVM_TO_F2 = 0x02, // �� ��� �� ���������� ��������������� � ���� �� �2
		DT_FROM_F2 = 0x03 // �������� �� �2
	};

	// update info
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int update_mask;
	enum
	{
		UPD_WORK_REG = 1,
		UPD_TREVOGA = 1 << 1,
		UPD_REGULATION = 1 << 2,
		UPD_RADIO_FREQNS = 1 << 3,
		UPD_WORK_BY_NVO = 1 << 4
	};

	// regime ALERT - trevoga.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int reg_alert;
	enum {
		NOT_Trevoga = 1,
		YES_Trevoga = 2
	};

	// regime RADIATION - izluchenie.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int reg_radiation;
	enum {
		IZL_full_radiation = 3,	//���������� ��������
		IZL_not_radiation = 5,	//������ ���������
		IZL_low_radiation = 6  //���. � ���. ���������
	};

	// regime REGIME of.  
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int reg_regime;
	enum {
		//������.
		RPN_fighting_trim = 6,
		//������.
		RPN_training = 3,
		//��������
		RPN_control = 1,
		//������.
		RPN_on_duty = 5
	};

	// reglament �� 0...6 + 255
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int reglament;

	//������� ������ � ������������� �������������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int work_by_NVO;
	enum {
		//��� ���.
		RPN_not_nvo = 0,
		//� ���.
		RPN_yes_nvo = 1
	};

};
USTRUCT(BlueprintType)
struct  FBPCPMsg158
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numAb;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int SubIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int nChannelRPN;

	// ����� ���� � ������� ��������� ��� (����� ��)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int vkpAirObjNum;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int AddSigns;	
	enum
	{
		PrPr = 1, // ������� ���������� �������� ������������ ��� � �� ( ���� )
		CoordDifference = 1 << 1, // ������� ������� ��������� ���� � ��������� �� ����� ��� �� 3 �� ( �* )
		IncorrectDistance = 1 << 2, // ������� ���������� ����������� ��������� ( �- )
		ASfi = 1 << 3 // ������� ��������������� ������������� ���� �� ����� � ������� ������������� �� ��������� � �������� ( ���� )
	};

};

USTRUCT(BlueprintType)
struct  FBPCPMsg108
{
	GENERATED_BODY()
	
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int NumAb;		
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int NumZRK;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int numAirObjCP;		
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int numAirObjAb;	
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int pr_info;		
		enum
		{
			REPORT_AIR_OBJ_TO = 0x02,
			
			REPORT_AIR_OBJ_FROM = 0x08,
			
			REPORT_INDEPENDENT = 0x10
		};		
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int code;	
		enum
		{
			
			ON_CANCEL_LAST_COMMAND1 = 0x00,
			
			TELEPHONE = 0x01,
			
			ON_DESTROY_AIR_OBJ = 0x11,
			 
			END_BO = 0x20,
			
			ON_PROHIBIT_INFLUENCE = 0x22,
			//command: "absolute prohibition of influence on air object " was received.
			ON_ABS_PROHIBIT_INFLUENCE = 0x22,
			//command: "prohibition of launch rocket" was received 
			ON_PROHIBIT_LAUNCH_ROCKET = 0x24,
			//command: "permit of launch rocket" was received  
			ON_PERMIT_LAUNCH_ROCKET = 0x33,
			//rocket was launched 
			ROCKET_LAUNCHED = 0x41,
			//air object skipped 
			AIR_OBJ_SKIP = 0x43,
			//air object destroyed 
			AIR_OBJ_DESTROYED = 0x45,
			//air object captured
			AIR_OBJ_CAPTURED = 0x46,
			//air object was designated on target channel
			AIR_OBJ_DESIGNATED_ON_TC = 0x47,
			//air object taken on tracking 
			AIR_OBJ_ON_TRACKING = 0x48,
			//air object search
			AIR_OBJ_SEARCHING = 0x49,
			//air object in zone
			AIR_OBJ_IN_ZONE = 0x50,
			//command:"detect air object by bearing" was received 
			ON_DETECT_AIR_OBJ_BY_BEARING = 0x51,
			//mitting (flying)
			MITTING = 0x52,
			//reject target designation
			RJCT_TD_AIR_OBJ = 0x55,
			//command: "cancelation target designation" was completed
			CANCEL_TD_RCVD = 0x92,
			//command: "prohibition of launch rocket" was completed 
			ON_PROHIBIT_LAUNCH_ROCKET_COMPL = 0x94,
			//command: "cancelation last command" was received
			ON_CANCEL_LAST_COMMAND2 = 0x99
		};
		/*! \var int Channel;
		\brief Number of the channel.
		*/
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int numCannel;

		/*! \var int RocketType;
		\brief type of the rocket.
		*/
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int RocketType;

		/*! \var int QttRocket;
		\brief Quantity of spent rockets.
		*/
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int QttRocket;

		/*! \var int m_numZU;
		\brief number ZU.
		*/
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int m_numZU;

};

UCLASS()
class SOC_API ACVMSession : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACVMSession();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Send CPMsg202", Keywords = "CPMsg202"), Category = "TCP Messages for CVM")
		static bool SendCPMsg202(USocket* Connection);
	UFUNCTION(BlueprintCallable, Category = "TCP Messages for CVM")
		bool processMSG(USocket* Connection, FString &messagecome);
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_1_Come();
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_82_Come(FBPCPMsg82 msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_101_Come(FBPCPMsg101 msg);
//	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
//		void Message_102_Come(FBPCPMsg102 msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_103_Come(FBPCPMsg103 msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_107_Come(FBPCPMsg107 msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_108_Come(FBPCPMsg108 msg);
//	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
//		void Message_109_Come(FBPCPMsg109 msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_112_Come(FBPCPMsg112 msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_117_Come(FBPCPMsg117 msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_123_Come(FBPCPMsg123 msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_125_Come(FBPCPMsg125 msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_135_Come(FBPCPMsg135 msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_138_Come(FBPCPMsg138 msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_139_Come(FBPCPMsg139 msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_148_Come(FBPCPMsg148 msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_154_Come(FBPCPMsg154 msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_157_Come(FBPCPMsg157 msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "TCP Messages for CVM")
		void Message_158_Come(FBPCPMsg158 msg);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};

