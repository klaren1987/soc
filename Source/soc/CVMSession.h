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

	//Тип КСА абонента.
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
	\количественный состав
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int group;

	//  номер ВО в системе абонента
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		TArray<int> numbering;

	//номер единый; 
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

	//  метки действия абонентов
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int signAbonentAction;

	/*! int signAbonentAction;
	метки действия абонентов
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int signAbonentActionREB;

	/*! int signAbonentNotify;
	метки оповещения абонентов
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int signAbonentNotify;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numberingZRK;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		TArray<int> rez;

	//  номер ВО под которым мы выдаем его абоненту 
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
		INQ_SEND_ALERTNESS_ON_HCP = 0x07,//БГ на ВКП
		INQ_STOP_SEND_ALERTNESS_ON_HCP = 0x87,//Отмена БГ на ВКП  
		INQ_SEND_PSN_ON_HCP = 0x08,//ПОЛОЖЕНИЕ на ВКП
		INQ_SEND_FIXPSN_ON_HCP = 0x09,//РЕПЕР  на АБОНЕНТ
		INQ_START_OBO = 0x0B,//ВКЛЮЧИТЬ РБД
		INQ_STOP_OBO = 0x0C,//ВЫКЛ РБД
		INQ_REGISTR = 0x1C,//Документирование
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
	\brief признак командного пункта(КП).
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int SubIndex;

	/*! \var int Azimut_RPH;
	\brief азимут биссектрисы сектора ответственности.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	float Azimut_RPH;

	// half size of sector.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	float m_half_sector;

	/*! \var int Sign_Zoni;
	\brief признак зоны поиска по углу места.
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
	\brief резерв.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int rezerv;


};
USTRUCT(BlueprintType)
struct  FBPCPMsg138
{
	GENERATED_BODY()

	
	// Номер абонента
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numAb;

	// Индекс подразделения·  1-6· номер подчиненного КП
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int SubIndex;

	// номер канала РПН
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int Channel;

	// Номер ВО, по которому поставлено ЦУ в нумерации ЦВМ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numAirObjCPcu;

	// Номер ВО, по которому абонент ведёт боевые действия в нумерации ЦВМ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numAirObjCPbd;

	// Номер ВО в нумерации абонента
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numAirObjAb;

	// Состояние целевого канала
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int ChannelState;
	enum
	{
		FREE = 0,  // канал свободен
		CHANNEL_BUZY = 1,  // канал занят
		NO_TRIG = 2   // канал не исправен
	};

	// Фаза ЦУ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int PhaseCU;
	
	enum
	{
		BD_DESTROY_AIR_OBJ = 0x11, // (ЦУ)
		BD_PROHIBIT_LAUNCH_ROCKET = 0x24, // Запрет пуска ракеты (ЗП)
		BD_PERMIT_LAUNCH_ROCKET = 0x33, // Разрешение пуска ракеты (РП)
		BD_SUPPORT_CANSEL_CU = 0x99 // 
	};

	// Фаза боевых действий
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int PhaseBD;
	enum
	{
		BD_NOT_INF = 0x00,  // нет информации
		BD_SEARCH = 0x49,  // поиск цели //CPMsg108::AIR_OBJ_SEARCHING = 0x49 (П)
		BD_ESCORT = 0x46,  // захват на сопровождение //CPMsg108::AIR_OBJ_CAPTURED = 0x46 (СЦ)
		BD_SUPPORT = 0x48,  // сопровождение и передача координат цели//CPMsg108:: AIR_OBJ_ON_TRACKING = 0x48 (АС)
		BD_RKT_LAUNCHED = 0x41,  // пуск произведен //CPMsg108::ROCKET_LAUNCHED = 0x41 (СР)
		BD_MITTING = 0x52,   // встреча//CPMsg108::AIR_OBJ_DESTROYED = 0x52 (Вст)
		BD_CYCLE_END = 0x20, // Цикл работы по цели закончен (ЦЗ)
		BD_REJECT = 0x55, // Отказ от ЦУ (о-з)
		BD_SUPPORT_MANUAL = 0x60, // Сопровождение в ручном режиме (РС)
		BD_AO_DESTROYED = 0x45, // Цель уничтожена (Ун)
		BD_AO_SKIPPED = 0x43 // Цель пропущена (Проп)
	};

	// номер канала, с которого произошло размножение
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int ChannelRazmn;

	// признак резервирования канала
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int signRez;

	// признак наличия помехи
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int sign_trouble;

	// признак донесения
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int report_sign;
	enum
	{
		REPORT_ABS = 0, // отсутствие донесения;
		REPORT_BEARING = 4, // отрабатывается целеуказание по пеленгу;
		REPORT_AIR_OBJ_FROM = 8, // отрабатывается целеуказание по ВО;
		REPORT_INDEPENDENT = 16 // производится самостоятельная боевая работа;
	};

	// Номер ЦУ по ВО (абоненту)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numZU_AirObj_CP;

	// Номер ЦУ по пеленгу (абоненту)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numZU_Pel_CP;

	// Номер ЦУ по ВО (отрабатываемого абонентом)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numZU_AirObj_AB;

	// Номер ЦУ по пеленгу (отрабатываемого абонентом)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int numZU_Pel_AB;

	// тип первой ракеты
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int typeRocket1;

	// тип второй ракеты
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
	\brief признак командного пункта(КП).
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int SubIndex;

	/*! \var int Betta_MUP;
	\brief способ управления рабочим сектором.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int Betta_MUP;

	/*! \var int PC;
	\brief ручное сопровождение.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int RC;

	/*! \var int ACFI;
	\brief сопровождение цели по угловым координатам.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int ACFI;

	/*! \var int ALKP;
	\brief алгоритм компенсации помех.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int ALKP;

	/*! \var int PEL;
	\brief боевые действия по пеленгу.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int PEL;

	/*! \var int ZR;
	\brief автоматическое распределение.
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
	\brief признак командного пункта(КП).
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int SubIndex;

	/*! \var int Alert_CP;
	\brief признак боеготовности КП.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int Alert_CP;
	enum {
		Alert_CP_NotInfo = 0, //нет информации
		Alert_CP_Not = 1,     //КП не боеготов
		Alert_CP_Yes = 2      //КП боеготов
	};

	/*! \var int Alert_RLO;
	\brief признак исправности РЛС.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int Alert_RLO;
	enum {
		Alert_RLO_NotInfo = 0, //нет информации
		Alert_RLO_Not = 1,     //РЛС неисправна
		Alert_RLO_Yes = 2      //РЛС исправна
	};
	/*! \var int Work_COU;
	\brief признак исправности СОУ.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int Work_COU;
	enum {
		Work_COU_NotInfo = 0, //нет информации
		Work_COU_Not = 1,     //СОУ неисправна
		Work_COU_Yes = 2      //СОУ исправна
	};

	/*! \var int Work_PZU;
	\brief признак исправности ПЗУ.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int Work_PZU;
	enum {
		Work_PZU_NotInfo = 0, //нет информации
		Work_PZU_Not = 1,     //ПЗУ неисправна 
		Work_PZU_Yes = 2      //ПЗУ исправна
	};

	/*! \var int Work_PIP;
	\brief признак исправности ПИП.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int Work_PIP;
	enum {
		Work_PIP_NotInfo = 0,//нет информации
		Work_PIP_Not = 1,    //передатчик подсвета неисправен
		Work_PIP_Yes = 2     //передатчик подсвета исправенЮ
	};

	/*! \var int Work_PPZ;
	\brief признак перезапуска.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int Work_PPZ;
	enum {
		Work_PPZ_NotInfo = 0,//Нет информации		
		Work_PPZ_Not = 1,    //Нет перезапуска		
		Work_PPZ_Yes = 2     //Перезапуск
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
	int numUnited;   //номер единый 
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
		DT_FROM_HCP = 0x01, // получено от ВКП
		DT_FROM_CVM_TO_F2 = 0x02, // на АРМ об изменениях устанавливаемых с ЦЭВМ на Ф2
		DT_FROM_F2 = 0x03 // получено от Ф2
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
		IZL_full_radiation = 3,	//отсутствие запретов
		IZL_not_radiation = 5,	//запрет излучения
		IZL_low_radiation = 6  //изл. с мал. мощностью
	};

	// regime REGIME of.  
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int reg_regime;
	enum {
		//Боевой.
		RPN_fighting_trim = 6,
		//Тренаж.
		RPN_training = 3,
		//Контроль
		RPN_control = 1,
		//Дежурн.
		RPN_on_duty = 5
	};

	// reglament ЦУ 0...6 + 255
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int reglament;

	//признак работы с низковысотным обнаружителем
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int work_by_NVO;
	enum {
		//Без НВО.
		RPN_not_nvo = 0,
		//С НВО.
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

	// Номер цели в системе нумерации ВКП (Номер ЦУ)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int vkpAirObjNum;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
	int AddSigns;	
	enum
	{
		PrPr = 1, // признак проведения проверки соответствия Дцу и Дц ( ПрПр )
		CoordDifference = 1 << 1, // признак отличия кооднинат цели и координат ЦУ более чем на 3 км ( Д* )
		IncorrectDistance = 1 << 2, // признак отсутствия достоверной дальности ( Д- )
		ASfi = 1 << 3 // признак автоматического сопровождения цели по углам и ручного сопровождения по дальности и скорости ( АСфи )
	};

};


UENUM(BlueprintType)
enum class Reportcf :uint8
{
	REPORT_AIR_OBJ_TO UMETA(DisplayName = "REPORT_AIR_OBJ_TO"),

	REPORT_AIR_OBJ_FROM UMETA(DisplayName = "REPORT_AIR_OBJ_FROM"),

	REPORT_INDEPENDENT UMETA(DisplayName = "REPORT_INDEPENDENT")
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
			
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
		int code;
	
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TCP Messages for CVM")
			TEnumAsByte<Reportcf> test;
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

