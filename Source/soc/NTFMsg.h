#ifndef _NTFMSG_H_
#define _NTFMSG_H_

#ifdef WIN32
#pragma warning (disable : 4786)
#endif

#include "GLGeometry.h"
#include "COTypes.h"
#include "GLTime.h"
#include "CODefine.h"


#define MAX_ZONES	2 
#define MAX_POINT_POLYGON 8
#define MAX_NUM_DIRECT 2
#define MAX_SEL_TYPE 5
#define MAX_PROHIBIT_SOURCE 4
#define MAX_INCL_OBJ 20


#include "COMMMsg.h"

using namespace std;

#pragma pack(1)

//sendAddInfo  AC.ini
enum
{
	NOT_ADD_INFO = 0,//не даем дополнительную информацию
	ONLY_NED_INFL_DISASTER_FUEL = 1,//только номер единый, ПД, ПБ, ОТ
	ALL_ADD_INFO = 2,//всю дополнительную информацию
	ONLY_INFLUENCE_WHITH_COORD = 4,//только признак действия с координатами ВО
//	WHITH_HIS_TARGET_NUMBER = 8,//оповещение по его номеру
	CU_AND_SUPPORT = 16,//сопровождает сам и не один, 
							//ему выдана команда по цели, то оповещать целью на приоритете ЦУ
	CHECK_CHANNEL_TARGET = 32, //проверка канальной цели
	NOT_NOTIFY_ONLY_CMD = 64, // оповещается только целями с ЦУ
	NOT_SEND_BIND	= 128	  //не выдавать связку 
};

enum 
{
	NOT_INCLUDED_IN_NOTIFICATION,
		INCLUDED_IN_NOTIFICATION,
		INCLUDED_IN_NOTIFICATION_BY_OPERATOR
};

enum
{
	NOT_ZONE, 
	ZONE_RING, 
	ZONE_SECTOR, 
	ZONE_POLYGON  
};

enum
{
	NOT_SELECT_PARAM_FIRST = 0x00,
	SELECT_FIRST = 0x01,
	SELECT_PARAM = 0x10,
	SELECT_PARAM_FIRST = 0x11
};

enum
{
	PRIOR_OPER        = 0x01,      // Оповещение по приоритету оператора (при вводе и выдаче)  
	CANCEL_PRIOR_OPER = 0x81,      // Отмена оповещения по приоритету оператора (при вводе)
	PROHIBIT_NOTIF_AB = 0x02,      // Запрет на оповещение абонента       (при вводе и выдаче)
	CANCEL_PROHIB_NOTIF_AB = 0x82, // Отмена запрета на оповещение абонента(при вводе)
	SEND_NUM_UNITED   = 0x03,      // Оповещение по номеру единому         (при вводе и выдаче)
	CANCEL_NUM_UNITED = 0x83,       // Снятие с оповещения по номеру единому(при вводе)
	NOT_NOTIF		  = 0x04,	
	CANCEL_NOT_NOTIF  = 0x84
};	

enum
{
	NON_SUPPORT,//0
	OUR_SUPPORT,//1
	OTHER_SUPPORT,//2
	OUR_OTHER_SUPPORT,//3 = OUR_SUPPORT + OTHER_SUPPORT
	PROHIBIT_SUPPORT,//4 
	OUR_PROHIBIT_SUPPORT,//5 = OUR_SUPPORT + PROHIBIT_SUPPORT
	SUBORD_SUPPORT = 8
};
/*
enum
{
	PARAM_BUKI = 40000,    //40км
	PARAM_C300 = 80000,    //80км
	PARAM_PMU = 75000,     //75км 
	PARAM_BUKI_BALL = 17000, //17км
	PARAM_C300_BALL = 30000  //30км
};*/

/*!\enum  Перечисление кодов классов приоритетов 
  \brief Codes of classes of priorities for HCP.
  */
enum
{
		
		pc_ballistic,
		pc_task_cu,
		pc_operator,
		pc_influence_avia,
		pc_influence_rocet,
		pc_enemy_whith_type,
		pc_without_influence,
		pc_friends_whith_type,
		pc_friends,
		priority_count
};

struct NTFMsgNotification : public COMMMsg
{
	enum {TYPE = 199};

	NTFMsgNotification(void) : COMMMsg(TYPE, sizeof(NTFMsgNotification), 0) {}

	COUInt8 operation;

	COUInt8 num_obj;
};




////////////////////////////////////////////////////////////////////////////
//

// Структура KEY_ID содержит "идентификатор" ключа в менеджере приоритетов.
// Используется для доступа к отдельным ключам в менеджере.
struct KEY_ID
{
	/*! \var long lClass;
	\brief Class of priority of a key.
	*/
	long lClass;	// класс приоритета ключа

	/*! \var long pos;	
	\brief Position of a key in list of keys of class.
	*/
	long pos;	// "позиция" ключа в списке ключей класса

	/*! \fn KEY_ID()
	\brief Structure constructor.
	*/
	KEY_ID()
	{
		lClass = -1;
		pos = -1;
	};

	/*! \fn operator = (const KEY_ID& id)
	\brief Reload operator =.
	\return Selfpointer.
	*/
	KEY_ID& operator = (const KEY_ID& id)
	{
		lClass = id.lClass;
		pos = id.pos;
		return *this;
	};

	/*! \fn Empty()
	\brief lClass = -1 and pos = -1.
	*/
	void Empty()
	{
		lClass = -1;
		pos = -1;
	};

	/*! \fn IsEmpty()
	\brief Check if struct empty.
	\return True - if empty, False - not empty.
	*/
	bool IsEmpty()
	{
		if ((lClass == -1) && (pos == -1))
			return true;
		else
			return false;
	};
};

// Структура, содержащая информацию о цели, необходимую для задачи
// выборочного оповещения.
/*! \struct NOTIF_INFO NTFMsg.h
\brief Struct contains information about target. Need for task notification.
*/
struct NOTIF_INFO
{
	
	KEY_ID aKeyIDs[SRC_COUNT];

	
	/*! \var bool aNotify[SRC_COUNT];
	\brief Sign of inclusion target in task notification. True - notify target, False - no.
	\param SRC_COUNT - maximum quantity of abonents.
	*/
	bool aNotify[SRC_COUNT];

	// Признак запрещения работы оператора с целью(true - запретить работу, false - разрешить)
	// (ТОЛЬКО ДЛЯ ВКП !!!)
	/*! \var bool aNoChange[SRC_COUNT];
	\brief Sign of prohibition of job operator with target. True - prohibit job, false - no.
	\param SRC_COUNT - maximum quantity of abonents.
	*/
	bool aNoChange[SRC_COUNT];

	// Признак наличия ЦУ по ВО
	/*! \var bool aHaveCU[SRC_COUNT];
	\brief Sign of tagret order.
	\param SRC_COUNT - maximum quantity of abonents.
	*/
	bool aHaveCU[SRC_COUNT];

	COInt8 aInclude[SRC_COUNT];//для формирования 101 сообщения

	// Счетчик выхода из зоны
		/*! \var COInt8 aExitCount[SRC_COUNT];
	\brief The counter of exit from a zone.
	\param SRC_COUNT - maximum quantity of abonents.
	*/
	COInt8 aExitCount[SRC_COUNT];

	// время последней выдачи по этому борту - нужно для выдачи с периодичностью в 10 сек (примерно)
	/*! \var COUInt64 TimeLastOutput[SRC_COUNT];
	\brief Last time of output information to abonent.
	\param SRC_COUNT - maximum quantity of abonents.
	*/
	COUInt64 TimeLastOutput[SRC_COUNT];


	// признак выдачи информации по цели на абонента при след срабатывании таймера (Т выдачи = 10 сек)
	COUInt8 aGiveOutInfo[SRC_COUNT];	// int т.к. 
					
	enum
	{
		NO_OUTPUT_TO_ABONENT = 0,   //не выдавать
		SEND_UPDATE_TO_ABONENT = 1,    //выдать инф по ВО
		SEND_END_TO_ABONENT = 2,    //выдать КПТ
		SEND_TO_ABONENT_FIRST_TIME //выдать  первый раз
	};

	/*! \fn NOTIF_INFO()
	\brief Structure constructor.
	*/
	 NOTIF_INFO()
	{
		// По умолчанию оповещать
		for (int i = 0; i < SRC_COUNT; i++)
		{
			aExitCount[i] = -1;
			aGiveOutInfo[i] = 0;
			aHaveCU[i] = false;
			aInclude[i] = NOT_INCLUDED_IN_NOTIFICATION;
			aNotify[i] = true;
			aNoChange[i] = false;		
 			TimeLastOutput[i] = 0;
		}
	}
	 NOTIF_INFO& operator=(const NOTIF_INFO& copy)
	 {
		 for (int j= 0; j < SRC_COUNT; j++)
		 {
			 aExitCount[j] = copy.aExitCount[j];
			 aGiveOutInfo[j]= copy.aGiveOutInfo[j];
			 aHaveCU[j] = copy.aHaveCU[j];
			 aInclude[j] = copy.aInclude[j];
			 aKeyIDs[j] = copy.aKeyIDs[j];
			 aNoChange[j] = copy.aNoChange[j];
			 aNotify[j] = copy.aNotify[j];
			 TimeLastOutput[j] = copy.TimeLastOutput[j];
		 }
		 return *this;
	 }
};

// Структура, описывающая все свойства абонента, хранящиеся в базе данных.
/*! \struct PROPERTIES NTFMsg.h
\brief Struct describes abonent.
*/
struct PROPERTIES
{
	// максимальное количество целей в составе оповещения
	/*! \var COInt32 lLimit;	
	\brief Maximum quantity of targets which in task of notification.
	*/
	COUInt32 lLimit;	

	// Приоритеты
	/*! \var COInt32 prior_avia;
	\brief Priority.
	*/
	COUInt32 prior_avia;

	/*! \var COInt32 prior_rocet;
	\brief Priority.
	*/
	COUInt32 prior_rocet;

	/*! \var COInt32 prior_without;
	\brief Priority.
	*/
	COUInt32 prior_without;

	/*! \var COInt32 prior_friend;
	\brief Priority.
	*/
	COUInt32 prior_friend;

	// минимальная скорость цели в составе оповещения
	/*! \var COInt32 lVmin;
	\brief Minimum velocity of target which in target of notification.
	*/
	COUInt32 lVmin;

	// максимальная скорость цели в составе оповещения
	/*! \var COInt32 lVmax;
	\brief Maximum velocity of target which in target of notification.
	*/
	COUInt32 lVmax;

	// минимальный радиус кольца
	/*! \var COInt32 lRmin;
	\brief Minimum radius of zone.
	*/
	COUInt32 lRmin;

	// максимальный радиус кольца
	/*! \var COInt32 lRmax;
	\brief Maximum radius of zone.
	*/
	COUInt32 lRmax;

	// минимальная высота цели в кольце
	/*! \var COInt32 lHmin;
	\brief Minimum height of target in zone.
	*/
	COUInt32 lHmin;

	// максимальная высота цели в кольце
	/*! \var COInt32 lHmax;
	\brief Maximum height of target in zone.
	*/
	COUInt32 lHmax;

	/*! \fn PROPERTIES()
	\brief Structure constructor.
	*/
	PROPERTIES()
	{
		// По умолчанию берутся максимально допустимые значения (из протокола)
		lLimit = 80;
		prior_avia = 1;
		prior_rocet = 2;
		prior_without = 3;
		prior_friend = 4;
		lVmin = 0;
		lVmax = 5000;
		lRmin = 0;
		lRmax = 300000;
		lHmin = 0;
		lHmax = 200000;
	};

};



struct NTFZoneKey
{
	
	NTFZoneKey()
	{
		typeZone = 0;
		numDirect = 0;
		minV = 0;
		maxV = 0;
	}
	NTFZoneKey& operator=(const NTFZoneKey& copy)
	{
		maxV = copy.maxV;
		minV = copy.minV;
		numDirect = copy.numDirect;
		typeZone = copy.typeZone;
		return *this;
	}
/*!\var typeZone
\brief Type of zone.
*/
  COUInt8 typeZone;

  /*!\var numDirect
\brief Direction number.
*/
  COUInt8 numDirect;

  /*!\var minV
brief Minimal velocity of air object selecting to notify.
*/
  COUInt16 minV;

/*!\var maxV
brief Maximal velocity of air object selecting to notify.
*/
  COUInt16 maxV;

};

struct NTFNotifyZoneRing
{
	NTFNotifyZoneRing();
	NTFNotifyZoneRing& operator= (const NTFNotifyZoneRing& copy)
	{
		x = copy.x;
		y = copy.y;
		minR = copy.minR;
		maxR = copy.maxR;
		minH = copy.minH;
		maxH = copy.maxH;
		return *this;
	}
		/*!\fn bool PointInRouteZone(GLPoint3D &point);
  \brief Is point in Circular zone HCP or no.
	\param point Reference on 3D coordinates of a point
	\return True - point in zone, False - no.
  */
	bool ptInRing(GLPoint3D &point);

	bool ptInRing(GLPoint2D &koord);

/*!\var maxQttAO
\brief Maximal quantiy of air objects for notify.
*/
//  COUInt8 maxQttAO;


/*!\var priorInflAircraft
\brief Priority of air objects influenced by aircraft.
*/
//  COUInt8 priorInflAircraft;

/*!\var priorInflLnchr
\brief Priority of air objects influenced by launchers.
*/
//  COUInt8 priorInflLnchr;



//  COUInt8 priorNoInfl;

/*!\var priorOurAO
brief Priority of our air objects.
*/
 // COUInt8 priorOurAO;


	// Координата Х центра зоны относительно реперной точки ЦЗВМ
	COInt32 x;

	// Координата Y центра зоны относительно реперной точки ЦЗВМ	
	COInt32 y;

	// Минимальный радиус зоны оповещения
	/*! \var COUInt32 minRadius;
	\brief Minimal radius of a zone of the notification.
	*/
	COUInt32 minR;

	// Максимальный радиус зоны оповещения
	/*! \var COUInt32 maxRadius;
	\brief Maximal radius of a zone of the notification.
	*/
	COUInt32 maxR;
	
	// Минимальная высота зоны оповещения относительно уровня моря
	/*! \var COUInt32 minHeight;
	\brief Minimal height of a zone of the notification concerning a sea level.
	*/
	COInt32 minH;

	// Максиальная высота зоны оповещения относительно уровня моря
	/*! \var COUInt32 maxHeight;
	\brief Maximal height of a zone of the notification concerning a sea level.
	*/
	COInt32 maxH;

};


#pragma pack(8)

#endif // _NTFMSG_H_
