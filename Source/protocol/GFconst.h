#ifndef _GFconst_h_
#define _GFconst_h_

#include "COTypes.h"
#include <vector>

// Defines for firing Zones descriptions
#define MAX_PRIORITY_TYPES 14
#define MAX_POINTS_QUA 13
#define MAX_ZONE_SECTIONS 300
#define MAX_VELOCITY_DIAPAZONES 5
#define MAX_INTERCEPTORS_TYPES_QUA 15
#define STEP_CP 1000 // 1 km
#define AT_IN 0
#define AT_OUT 1
#define BT_IN 2
#define ERROR_INDEX MAX_ZONE_SECTIONS + 1 // Код - индекс не найден

#define _MAX_COUNT_LAUNCHER_ 18

const int GF_type_virt_cp = 255;

struct GFCoverObj;
typedef std::vector< GFCoverObj* > GFCoverObjArr;

enum GFtypeAbonent{
	//Не указывается (Not define).
	GFTA_None = 8,  //0
	//Пусковая Установка.
	GFTA_Launcher = 4,
	//Зенитно-Ракетный ДивизиоН.
	GFTA_Battalion = 3,//2,
	//Источник РадиоЛокационной Информации.
	GFTA_Radar = 6,//3,
	//Зенитно-Ракетная БРигада(ВзКП).
	GFTA_Brigade = 2,//4,
	//Армия(ВКП).
	GFTA_Army = 1,//5,
	//Наш КП.
	GFTA_OurCP = 0,//6,
	//РЛС
	GFTA_RadarUnit = 5,//7
	//Виртуальный КП.
	GFTA_VirtualCP = 7//7
};

//типы команд
enum GFETypeCMD{
	//не определено.
	GFETC_NO_TYPE = 0,
	//команда общего типа.
	GFETC_GenCMD = 1,
	//команда по зоне ответственности.
	GFETC_RespZ = 1 << 1,
	//команда по ракето опасному направлению.
	GFETC_RcktDD = 1 << 2,
	//команда по зоне дежурства.
	GFETC_DutyZ = 1 << 3,
	//команда по зоне запрета.
	GFETC_ProhibitZ = 1 << 4
};

enum GF_ASU_TYPE
{
	GFASUT_BOR_CKP      = 1,//9С800М1
	GFASUT_BOR_PKP      = 2,//9С810
	GFASUT_BOR_KPOTK    = 3,//9С820
	GFASUT_BOR_PKPOTK   = 4,//9С830
	GFASUT_BOR_KPPVO    = 5,//9С833

	GFASUT_POLYNA_M     = 23,//9c52M1РБ
	
	GFASUT_C300V         = 41,//9c457.
	GFASUT_BUKI         = 45,//9c470M1-2
	GFASUT_BUKMB        = 48,//9c470MБ.
	GFASUT_BUK          = 49,//9c470

	GFASUT_19G6M        = 59, // 19Ж6М

	GFASUT_RIF1         = 60,//7В930
	GFASUT_RIF2         = 61,//7В940
	GFASUT_RIF3         = 62,//7В950
	GFASUT_RIF4         = 63,//7В960
	GFASUT_RIF5         = 64,//7В970

	GFASUT_PORI_P1      = 65,//9c467-1.
	GFASUT_PORI_P2      = 67,//9c467-2.

	GFASUT_A50          = 78,//АК РЛДН

	GFASUT_C300_PT      = 85,//5Н83.
	GFASUT_C300_PC      = 86,//5Н83С.
	GFASUT_C300_PM      = 87,//5Н83П.

	GFASUT_C200_GR      = 88,//5Ж53 группа.

	GFASUT_POLE         = 91,//86Ж6.
	GFASUT_MEGA_M       = 92,//5Н93М(5H55M).
	GFASUT_NIZINA       = 93,//5У69.
	GFASUT_OSNOVA       = 94,//68К6
	GFASUT_NIVA         = 96,//46Л6.
	GFASUT_OSNRTBR      = 97,//5K60.

	GFASUT_SOU          = 101,//9А310МБ.
	GFASUT_MSNR         = 102,//9С32-1.
	GFASUT_RPN          = 103, //5Н63
	GFASUT_S200         = 106, //ЗРК C200.
	GFASUT_VIRTUAL      = 255 //Virtual CP
};

const unsigned int GFqttAAStype = 4;

/*static const char* GF_AntiaircraftSystemTypeArr[GFqttAAStype] =
{
	"S300",
	"POLYNA",
	"POLYNA_M",
	"C300_PM"
};*/


enum GF_ASU_TYPE_NOTIF
{	
	GF_ASU_NONE = 0,
	GF_ASU_POLYNA = 1,
	GF_ASU_BAIKAL = 2,
	GF_ASU_C300 = 3,
	GF_ASU_PMU = 4,
	GF_ASU_BUKI = 5,
	GF_ASU_RANGIR = 6,
	GF_ASU_PORI = 7,
	GF_ASU_NIVA = 8,
	GF_ASU_OSNOVA = 9,
	GF_ASU_POLE = 10,
	GF_ASU_MEGA = 11,
	GF_ASU_RUBEJ = 12,
	GF_ASU_VERTIKAL = 13
};
const unsigned int GFquantityAbonentTypes = 5;
const unsigned int GFqttZRK = 6;
const unsigned int GFqttZRDN = 6;
const unsigned int GFqttPSN = 7;
const unsigned int GFqttTypeTK = 3;
const unsigned int GFqttRU = 2;
const int GFqttOur_CP_TK = 23;
const unsigned int MAX_NUM_TRGT_SETKA_PVO = 10000;
const unsigned int MAX_QTT_ZN_CODING_SETKA_PVO = 9;

enum GFsignAbonentActing{
	//Не указывается.
	GFSAA_ND = 0,
	//Подчиненный.
	GFSAA_Subordinate = 1,
	//Взаимодействующий
	GFSAA_Cooperative = 2,
	//Вышестоящий.
	GFSAA_Superior = 3
};

enum GFtrainSign
{
	//абонент реальный.
	GFTS_REAL = 1,
	//абонент имитированный.
	GFTS_IMAGE = 2,
	//абонент не участвует.
	GFTS_NOT_INCLUDE = 0,
	//боевая работа.
	GFTS_COMBAT_MODE = 8
};

//основной режим работы для КП.
enum GFmode_Operation{
	//боевой.
	GFMO_battle = 1 << 0,
	//дежурный.
	GFMO_On_Duty = 1 << 1,
	//тренаж.
	GFMO_training = 1 << 2,
	//режим контроля.
	GFMO_ctrl = 1 << 3
};

enum GFConditionSubUnit{
	//не настроен.
	GFCSU_not_adjustment = 0,
	//настроен.
	GFCSU_adjustment = 1
};

enum GFdirectionAbonentActing{
	//Не указывается (Not define).
	GFDAA_ND = 0,
	//На абонента.
	GFDAA_To = 1 << 0,
	//От абонента.
	GFDAA_From = 1 << 1
};

enum GFreadiness
{
	GFR_NotInfo = 0,
	GFR_NotReady = 1,
	GFR_Ready = 2
};

enum GF_protoITS_5K60
{
	GFPITS5K60_akkord = 0,
	GFPITS5K60_aragva = 1
};

//максимальное количество каналов.
const unsigned int GF_QTT_CHANNEL = 3;

//максимальное количество ракетных каналов(ракет в канале).
const unsigned int GF_QTT_ROCKET_CH = 2;

//максимальное количество ракетных каналов.
const unsigned int GF_QTT_TARGET_CH = 6;

//максимальное число основных абонентов.
const unsigned int GFSRC_BASE_QTT = 16;
//максимальное число подчиненных абонентов.
const unsigned int GFSUBSRC_BASE_QTT = 6;

//максимальное число зон ответственности.
const unsigned int GF_QTT_RESP_Z = 2;
//максимальное число РОН.
const unsigned int GF_QTT_RCKT_DD = 2;
//максимальное число зон дежурства.
const unsigned int GF_QTT_DUTY_Z = 2;
//максимальное число зон запрета.
const unsigned int GF_QTT_PROHIBIT_Z = 2;

const COUInt8 GF_AbNameLength = 9;
const COUInt8 GF_AbMembershipLength = 9;

//максимальное число команд по всем зонам и направлениям для одного абонента.
const COUInt8 GF_MaxCntZoneCMD = 9;

const COUInt8 GF_pwd_length = 6;

#endif //_GFconst_h_
