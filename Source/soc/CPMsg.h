/*! \file CPCPMsg.h
\brief Header file containing declarations of message structures.
*/

// _OS_INDEPENDENT_

#ifndef _CPMsg_h_
#define _CPMsg_h_

#include "COcxx.h"
#include "NTFMsg.h"
#include "COMMMsg.h"
#include "GFconst.h"



#include <memory.h>
#include <assert.h>

#pragma pack (push, 1)

// Шаблон для сообщений переменной длины. Такое сообщение состоит из постоянной 
// части С, поля длины L и массива переменной длины из объектов V.
template <class C, class L, class V, const int max>
class varmsg : public COMMMsg, public C
{
protected:

	// поле длины переменной части
	L m_VarLen;

	// массив якобы переменной длины
	V m_Var[max];

	// размер постоянной части
	enum { ConstantSize = sizeof(C) + sizeof(L) + sizeof(COMMMsg) };

public:

	// конструктор
	varmsg(int t, const C & c = C());

	// добавить и подправить длину
	void append(const V & v);// throw(overflow);
	void operator += (const V & v);

	// длина переменной части
	int varlen() const;

	// скобки для доступа к переменной части
	V & operator [] (int i);// throw(overflow);
	const V & operator [] (int i) const; // throw(overflow);
};

template <class C, class L, class V, const int max>
inline varmsg<C, L, V, max>::varmsg(int t, const C & c) : COMMMsg(t, ConstantSize, GFnumOurCP), C(c), m_VarLen(0) 
{
}

template <class C, class L, class V, const int max>
void varmsg<C, L, V, max>::append(const V & v)
{
	if (m_VarLen < max)
	{
		m_Var[m_VarLen++] = v;
		msgsize += sizeof(V);
	}
	else
	{
		assert(false); //throw overflow();
	}
}

template <class C, class L, class V, const int max>
inline void varmsg<C, L, V, max>::operator += (const V & v) 
{ 
	append(v); 
}

template <class C, class L, class V, const int max>
inline int varmsg<C, L, V, max>::varlen() const 
{ 
	return m_VarLen; 
}

template <class C, class L, class V, const int max>
inline V & varmsg<C, L, V, max>::operator [] (int i)
{
	if (i >= 0 && i < m_VarLen)
	{
		return m_Var[i];
	}
	else
	{
		assert(false); //throw badindex();
		return m_Var[0];
	}
}

template <class C, class L, class V, const int max>
inline const V & varmsg<C, L, V, max>::operator [] (int i) const
{
	if (i >= 0 && i < m_VarLen)
	{
		return m_Var[i];
	}
	else
	{
		assert(false); //throw badindex();
		return m_Var[0];
	}
}

//
// Messages from abonents protocols.
//


/*! \struct CPMsg001 CPMsg.h
\brief Message 1 (координаты ВО: X,Y,H )
*/
struct CPMsg001 : public COMMMsg
{
	enum { TYPE = 1};
	
	CPMsg001( int src = 0 ) : 
		COMMMsg(TYPE, sizeof(CPMsg001), src),
		numAbon(0),SubIndex(0), present_info(0),
		// byte 1 (aditional information for AO)
		inf_tracking(0),inf_unreliable_XY(0),inf_unreliable_H(0),inf_manual_tracking(0),inf_tracking_by_VKP(0),inf_bearing(0),
		// byte 2 (aditional information for AO)
		inf_trenag(0),inf_group(0),inf_intercepter_in_channel(0),inf_influence_REB(0),inf_interference_by_RPN(0),inf_off_line_mode_K9(0),
		// byte 3 (aditional information for AO)
		// byte 4 (aditional information for AO)
		inf_coord_system(0),
		srcObjnum(0),rsvrObjnum(0),unique_number(0),
		x(0),y(0),h(0),vx(0),vy(0),vh(0),
		countGropAO(0),nation(0),type(0),index(0),mnvr(0),influence(0),
		disaster(0),fuel(0),typeRLS(0),reserve(0),
		ChannelRPN(0),ChannelRazmn(0),locationTime(0),
		//byte 1 of sending information
		command(0),
		//byte 2 of sending information
		priority(0),target_designation(0),comander_target_designation(0),ban_fire(0),ban_target(0),
		//byte 3 of sending information
		reglament(0)
		//byte 4 of sending information
	{
	};
	
	/*! \var COUInt8 numAbon;
	\brief number of abonent (external number)
	*/
	COUInt8 numAbon; // номер абонента
	
	/*! \var COUInt8 SubIndex
	\brief index of subabonent
	*/
	COUInt8 SubIndex; // Индекс подразделения· 0-командный пункт 1-6· номер подчиненного КП
	
	/*! \var COUInt32 present_info;
	\brief mask of incoming information in message
	*/
	COUInt32 present_info; // признаковая информация о ВО

	enum present_info
	{
		INFO_NumberReplicationChannelRPN 	= 1 << 14,	// number channel of replication for RPN present 
														/// номер канала размножения на РПН
		INFO_NumberChannelRPN				= 1 << 15,	// number of channel RPN present
														/// номер канала РПН
		INFO_Command						= 1 << 16,	// arrangement(распоряжение) by AO present
														/// распоряжение по ВО 
		INFO_Time							= 1 << 17,	// time of location AO present
														/// время локации
		INFO_SourceInformation				= 1 << 18,	// type of source information 
														/// тип источника информации
		INFO_UniqueNumber					= 1 << 19,	// unique number of AO present 
														/// номер единый 
		INFO_Influence						= 1 << 20,	// info about action by AO present
														/// признак действия по цели
		INFO_RemainingFuel					= 1 << 21,	// remaining of fuel present
														///	остаток топлива
		INFO_Index							= 1 << 22,	// index AO present
														/// индекс ВО
		INFO_Disaster						= 1 << 23,	// disaster of AO present
														/// признак бедствия
		INFO_Maneuver						= 1 << 24,	// maneuver of AO present
														/// наличие маневра
		INFO_Type							= 1 << 25,	// type of AO present
														/// тип ВО
		INFO_Nation							= 1 << 26,	// nation of AO present
														/// гос принадлежность ВО
		INFO_NumberAOInGroup				= 1 << 27, 	// count AO in group present 
														/// колличество ВО в группе представленно
		INFO_H								= 1 << 28,	// height  present
														/// высота представлена
		INFO_Vh								= 1 << 29,	// velocity by H present
														/// скорость по высоте представлена
		INFO_Vxy							= 1 << 30,	// velocity present
														/// составляющие по скоростям представлены
		INFO_XY								= 1 << 31	// coordinates (and their mistakes) present
														/// координаты 
	};
 
	// ---------- byte 1 (aditional information for AO) ----------
	COUInt8 inf_tracking:3; 			// information about tracking AO 
	enum inf_tracking
	{
		TRACKING_REGULAR			= 0x00, 
		TRACKING_BEGIN				= 0x01,
		TRACKING_BY_BEARING_COMMAND	= 0x02,
		TRACKING_EXT				= 0x03, // exrapolate coord
		TRACKING_END				= 0x07
	};
	COUInt8 inf_unreliable_XY:1;		// information about is the coord unreliable (1 - unreliable coord)
	COUInt8 inf_unreliable_H:1;			// information about is the height unreliable (1 - unreliable height)
	COUInt8 inf_manual_tracking:1;		// the information from source typing manually (1 - manual input)
	COUInt8 inf_tracking_by_VKP:1;		// current AO tracking by information from VKP ( 1 - information from VKP)
	COUInt8 inf_bearing:1;				// if this information about bearing ( 0 - information about AO, 1 - information about bearing)

	// ---------- byte 2 (aditional information for AO) ----------
	COUInt8 				:1;
	COUInt8 inf_trenag			:1;	// (0 - real AO , 1 - simulated AO)
	COUInt8 inf_group			:1;	// is this AO group target (1 - group target, 0 - single target) 
	COUInt8 inf_intercepter_in_channel	:1;	//
	COUInt8 inf_influence_REB		:1;	// influence REB by AO (1 - influence)
	COUInt8 inf_interference_by_RPN		:2;	// AO interference to RPN
	enum inf_interference_by_RPN
	{
		INTERFERENCE_NONE,
		INTERFERENCE_ACTIV,
		INTERFERENCE_PASSIVE,
		INTERFERENCE_COMB
	}; 
	COUInt8 inf_off_line_mode_K9:1;		// off-line mode of K9 (1 - off-line)

	// ---------- byte 3 (aditional information for AO) ----------
	COUInt8 :8;
	
	// ---------- byte 4 (aditional information for AO) ----------
	COUInt8 inf_coord_system	:4;	// information about coord system in message (0-topocentric,1-geogref,2-gaus-cruger,3-geocentric) defines in file CODefine.h  enum TYPE_COORD
	COUInt8 inf_radial_velocity	:1;	// признак радиальной скорости (скорость передаётся в Vx)
	COUInt8 inf_Q_velocity		:1;	// признак курса (курс в Vx, значение скорости в Vy)
	COUInt8 			:2;
	// ------------------------------------------------------------

	/*! \var COUInt8 objnum;
	\brief Number of the air object in source numeration.
	*/
	COUInt16 srcObjnum;
	
	/*! \var COUInt8 objnum;
	\brief Number of the air object in receiver numeration.
	*/
	COUInt16 rsvrObjnum;

	/*! \var COUInt32 unique_number;
	\brief Unique number of AO
	*/
	COUInt32 unique_number;

	 /*! \var COInt16 x;
	\brief X coordinate of air object (12 бит).
	*/
	COInt32 x;
	
	/*! \var COInt16 y;
	\brief Y coordinate of air object (12 бит).
	*/
	COInt32 y;
	
	/*! \var COInt16 h;
	\brief Height of air object.
	*/
	COInt32 h;
	
	/*! \var COInt16 vx;
	\brief X velocity component.
	*/
	COInt16 vx;
	
	/*! \var COInt16 vy;
	\brief Y velocity component.
	*/
	COInt16 vy;
	
	/*! \var COInt16 vh;
	\brief Height velocity component.
	*/
	COInt16 vh; 

	/*! \var COInt8 countGropAO;
	\brief Count AO in group, if group present.
	*/
	COInt8 countGropAO;
	
	/*! \var COInt8 nation;
	\brief Nation of AO.
	*/
	COUInt8 nation;
	enum nation 
	{
		NATION_UNKNOWN 				= 0x00,
		NATION_FOE	 				= 0x01,
		NATION_FRIEND 				= 0x02,
		NATION_GUARANTED_FRIEND 	= 0x03
	};
	
	/*! \var COInt8 type;
	\brief Type of AO.
	*/
	COUInt8 type;

	/*! \var COInt8 index;
	\brief Index of AO.
	*/
	COUInt8 index;
 
	/*! \var COInt8 mnvr;
	\brief Maneuver of AO.
	*/
	COUInt8 mnvr;
	enum mnvr
	{
		MNVR_NO						= 0x00,
		MNVR_BY_COURSE				= 0x01,
		MNVR_BY_HEIGHT				= 0x02,
		MNVR_BY_VELOSITY			= 0x03,
		MNVR_BY_HEIGHT_AND_COURSE	= 0x04,
		MNVR_PRESENT				= 0x05	//maneuver present but type of maneuver not defined
	};
	/*! \var COInt8 influence;
	\brief Influence by AO.
	*/
	COUInt8 influence;
	enum influence
	{
		INFLUENCE_NO				= 0x00,
		INFLUENCE_SET_TD_TO_ZRK		= 0x01,
		INFLUENCE_TRACKING_BY_ZRK	= 0x02,
		INFLUENCE_AVIA				= 0x03, // aviation influence by this target
		INFLUENCE_AVIA_AND_ZRV		= 0x04
	};

	/*! \var COInt8 disaster;
	\brief Disaster of AO.
	*/
	COUInt8 disaster;
//todo Vovan_1001
	enum disaster
	{
		DISASTER_NO					= 0x00,
		DISASTER_1					= 0x01,
		DISASTER_2					= 0x02,
		DISASTER_3					= 0x03,
		DISASTER_4					= 0x04,
		DISASTER_5					= 0x05,
		DISASTER_6					= 0x06,
	};
	
	/*! \var COInt8 fuel;
	\brief Remaining of fuel by AO.
	*/
	COUInt8 fuel;

	/*! \var COInt8 typeRLS;
	\brief type of source information.
	*/
	COUInt8 typeRLS;
  
	COUInt8 reserve;

	/*! \var COInt8 Channel;
	\brief Number of channel of RPN.
	*/
	COUInt8 ChannelRPN;
	
	/*! \var COInt8 ChannelRazmn;
	\brief Number of replication's channel of RPN.
	*/
	COUInt8 ChannelRazmn;

	/*! \var COUInt32 locationTime;
	\brief time location information of AO.
	*/
	COUInt32 locationTime; // in second form begging of day

	/*! \var COUInt8 command;
	\brief command by AO
	*/
	COUInt8 command;//Распоряжение
	

	// byte 2 of sendig information
	COUInt8 priority:1;						//
	COUInt8 target_designation:2;			//
	enum target_designation
	{
		TD_None_Target_Designation = 0x00,
		TD_Receive_Target_Designation = 0x01,
		TD_Cancel_Target_Designation = 0x02,
		TD_Ban_Target_Designation = 0x03
	};
//todo Vovan_1001
	COUInt8 comander_target_designation:1;	//
	COUInt8 ban_fire:1;						//
	COUInt8 ban_target:1;					//
	COUInt8 reserve_5:1;					//

	//byte 3 of sending information
	COUInt8 :5;
	COUInt8 reglament:3;					//
//todo Vovan_1001

        // номер ЗРК, на который выдаётся ЦУ
        COUInt8 num_ZRK:8;

};

/*! \struct CPMsg002 CPMsg.h
\brief Message 2 (Дополнитьельная информация по ВО)
*/
struct CPMsg002 : public COMMMsg
{
  enum { TYPE = 2};
  
  CPMsg002( int src = 0 ) : COMMMsg(TYPE, sizeof(CPMsg002), src),
	numAbon(0), SubIndex(0),signObj(0), srcObjnum(0),rsvrObjnum(0),
	type(0),index(0),h(0),numUnited(0),PilotIndex(0),influence(0),
	disaster(0),Fuel(0),reserv(0) 
 {
  }

   /*! \var COUInt8 numAbon;
  \brief Number of the Abonent.
  */
  COUInt8 numAbon;

  // Индекс подразделения· 0-командный пункт 1-6· номер подчиненного КП
  COUInt8 SubIndex;

 // признаковая информация о ВО
  COUInt16 signObj;
  enum
  {
	  INDEX = 1,//Pilot index
	  Hight = 1 << 1,
	  Type = 1 << 2,
	  NED = 1 << 3,
	  INFLUENCE = 1 << 4,
	  FUEL = 1 << 5,
	  IVO = 1 << 6,
	  DISASTER = 1 << 7,
	  Trenazh = 1<<8		
  };


  /*! \var COUInt8 objnum;
  \brief Number of the air object in source numeration.
  */
  COUInt16 srcObjnum;

   /*! \var COUInt8 objnum;
  \brief Number of the air object in receiver numeration.
  */
  COUInt16 rsvrObjnum;

  COUInt8 type;
  
  COUInt8 index;

/*! \var COInt16 h;
  \brief Height of air object.
  */
  COInt32 h;
  
  COUInt32 numUnited;   //номер единый 

  COUInt32 PilotIndex;   //индекс летчика
  
  COUInt8 influence;

  COUInt8 disaster;//признак бедствия

  COUInt8 Fuel;    //отпл	

  COInt8 reserv;
};



/*! \
\brief Message 3 (characteristics of a bearing for air object)
*/
struct CPMsg003 : public COMMMsg
{
  enum 
  {	  TYPE = 3  };

  CPMsg003( int src = 0 ) : COMMMsg(TYPE, sizeof(CPMsg003), src) 
  {
  }
 
  /*! \var COUInt8 numAbon;
  \brief Number of the Abonent.
  */
  COUInt8 numAbon;

 // Индекс подразделения· 0-командный пункт 1-6· номер подчиненного КП
  COUInt8 SubIndex;


// ---------- byte 1 (aditional information for AO) ----------
	COUInt8 inf_trenag :1;	// (0 - real AO , 1 - simulated AO)
	COUInt8 inf_type_info :3;	// information about type reciving information
	enum eInf_type_info
	{
		TYPEINFO_FROM_STANDING_POINT			=0x00,
		TYPEINFO_WITH_DEVIATION_FROM_FIXED_POINT	=0x01,
		TYPEINFO_TWO_POINT				=0x02
	};
	COUInt8 inf_coord_system :4;	// information about coord system in message (0-topocentric,1-geogref,2-gaus-cruger,3-geocentric) defines in file CODefine.h  enum TYPE_COORD

// ---------- byte 2 (aditional information for AO) ----------
	COUInt8 inf_tracking:3; 			// information about tracking AO 
	enum eInf_tracking
	{
		TRACKING_REGULAR			= 0x00, 
		TRACKING_BEGIN				= 0x01,
		TRACKING_BY_BEARING_COMMAND	= 0x02,
		TRACKING_EXT				= 0x03, // exrapolate coord
		TRACKING_END				= 0x07
	};
	COUInt8 inf_velocity_by_azimuth :1; // information about azimuth velocity present in message
	COUInt8 inf_velocity_by_elevation :1; // information about elevation velocity present in message
	COUInt8 inf_elevation :1; // information about elevation present in message
	COUInt8 :2; //reserve
// ------------------------------------------------------------

  /*! \var COUInt8 objnum;
  \brief Номер пеленга на воздушный объект в системе нумерации источника
  */
  COUInt16 objnum;

  /*! \var COUInt8 td;
  \brief Number of target designation
  */
 // COUInt8 td;

   /*! \var 
  \brief Azimuth coordinate (beta) - Азимут  пеленга воздушного объекта 
    */
  float azimuth;

  //\brief Младшая часть угла места пеленга воздушного объекта
  float elevation;
    /*! \var 
  \brief Azimuth coordinate (beta) - Азимут  пеленга воздушного объекта 
    */
  float azimuthVel;

  //\brief Младшая часть угла места пеленга воздушного объекта
  float elevationVel;

  COUInt32 tlock;

  COUInt32 deltaTime;

	COInt32 	X1;			// Координата X первой точки
	COInt32		Y1;			// Координата Y первой точки
	COInt32		H1;			// Высота первой точки

	COInt32 	X2;			// Координата X второй точки
	COInt32		Y2;			// Координата Y второй точки
	COInt32		H2;			// Высота второй точки
};





/*! \struct CPMsg006     POLYANA  Команда по Воздушному Объекту
\brief Message 6 (relating to abonent: "target designation")
*/
struct CPMsg006: public COMMMsg
{
  enum
  {
	  TYPE = 6	  
  };

  CPMsg006( void ) : COMMMsg(TYPE, sizeof(CPMsg006),GFnumOurCP)   
  {  
	  numAb = 0;
	  numZRK = 0;
	  sign_cmd = 0;
	  command = 0;
	  numAirObjsrc = 0;
	  numAirObjrsvr = 0;
	  numZRKBatt = 0;
	  res = 0;
  }

 
/*! \var COUInt8 numAb;
\brief Number of abonent.
*/
  COUInt8 numAb;

    /*! индекс подразделения· 0-командный пункт 1-6· номер подчиненного КП.
*/
  COUInt8 numZRK;

  // признаковая информация о ВО
  COUInt8 sign_cmd;
  
  enum
  {
    INFO_DEL =1,
	ban_fire = 0x20,
	sign_target_designation = 0x10,
	priority = 2,
	telefone = 0x40 
  };
  //for target_designation
  enum
  {
	none_target_designation = 0,
	receive_target_designation = 0x4,
	cancel_target_designation = 0x8,
	ban_target_designation = 0xC
  };
  
/*! \var COUInt8 command;
\brief Code of command.
*/
  COUInt8 command;
  //command
  enum
  {
//cancelation last command.
    CANCEL_LAST_COMMAND1 = 0x00,
    //telephone talk on air object .
    TELEPHONE = 0x01,
	//indication.
	TARGET_INDICATION = 0x40,
    //destroy air object .
    DESTROY_AIR_OBJ = 0x11,
    //prohibition of influence on air object .
    PROHIBIT_INFLUENCE = 0x22,
    //absolute prohibition of influence on air object .
    ABS_PROHIBIT_INFLUENCE = 0x22,
    //prohibition of launch rocket .
    PROHIBIT_LAUNCH_ROCKET = 0x24,
    //permit of launch rocket  
	PERMIT_LAUNCH_ROCKET = 0x33,
    //detect air object by bearing 
	DETECT_AIR_OBJ_BY_BEARING = 0x51,
    //cancelation last command .
    CANCEL_LAST_COMMAND2 = 0x99
  };
   /*! \var COUInt8 objnum;
  \brief Number of the air object in source numeration.
  */
  COUInt16 numAirObjsrc;

   /*! \var COUInt8 objnum;
  \brief Number of the air object in receiver numeration.
  */
  COUInt16 numAirObjrsvr;

    /*! индекс подразделения· 0-командный пункт 1-6· номер подчиненного КП.
*/
  COUInt8 numZRKBatt; 
//
  COUInt8 res;
};



/*! \struct CPMsg012     POLYANA  Распоряжение по пеленгу

\brief Message 12 (relating to abonent: "target instruction")
*/
struct CPMsg012 : public COMMMsg
{
  enum { TYPE = 12};

  CPMsg012( void ) : COMMMsg(TYPE, sizeof(CPMsg012),GFnumOurCP),numAbon(0),SubIndex(0),
	  Channel(0),signs(0),numObj(0),x1(0),y1(0),h1(0),x2(0),y2(0),h2(0),azimuth(0)
  { 	 
  }

  COUInt8 numAbon;

  // Индекс подразделения· 0-командный пункт 1-6· номер подчиненного КП
  COUInt8 SubIndex;

  COUInt8 Channel;

 // признаковая информация о ВО
  COUInt8 signs;

  COUInt16 numObj;

  COInt32 x1;

  COInt32 y1;

  COInt32 h1;

  COInt32 x2;

  COInt32 y2;

  COInt32 h2;

  float azimuth;

};

/*! \struct CPMsg007     POLYANA  Донесение по Воздушному Объекту
\brief Message 07 (report from abonent)
*/
struct CPMsg007 : public COMMMsg
{
  enum { TYPE = 07};

  CPMsg007( void ) : COMMMsg(TYPE, sizeof(CPMsg007),GFnumOurCP)   
  { 
	  numAb= 0;
	  numZRK = 0;
	  prdMSNR = 0;
	  report = 0;
	  numAirObjsrc = 0;
	  numAirObjrsvr = 0;  
	  numBatt = 0;
	  numLnch = 0;	  
  }
/*! \var COUInt8 numAb;
\brief Number of abonent.
*/
  COUInt8 numAb;

 /*! индекс подразделения· 0-командный пункт 1-6· номер подчиненного КП.
*/
  COUInt8 numZRK;

  /*! \var COUInt8 prdMSNR;
\brief prdMSNR.
*/
  COUInt8 prdMSNR;
    enum
  {
	SUPPORT               = 0,  // сопровождение и передача координат цели
	SEARCH                = 1,  // поиск цели = ЦУ отработано
	RJCT                  = 2,  // отказ = отмена ЦУ принята 
	FIRE_FIRST            = 3,  // пуск произведен
	FREE                  = 4,  // канал свободен = цикл закончен
	ESCORT                = 5,  // захват на сопровождение = ПУ назначено
	PROHIBIT_LR           = 6,  // исполнение запрета стрельбы
	END_SUPPORT           = 7,   // сброс с АС
	RECEIPT				  = 32  // kvitanzija
  };

  /*! \var COUInt8 report;
\brief Code of report.
*/
  COUInt8 report;
  //report
  enum
  {
   //command: "cancelation last command" was received
    ON_CANCEL_LAST_COMMAND1 = 0x00,
	//telephone talk on air object (relating to abonents 1-6 ).
    TELEPHONE = 0x01,
    //command: "destroy air object" was received
    ON_DESTROY_AIR_OBJ = 0x11,
     //end of period battle operation 
    END_BO = 0x20,
    //command: "prohibition of influence on air object" was received
    ON_PROHIBIT_INFLUENCE = 0x22,
    //command: "absolute prohibition of influence on air object " was received
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
    //air object was designated on target channel
    AIR_OBJ_DESIGNATED_ON_TC = 0x47,
	//air object captured
	AIR_OBJ_CAPTURED = 0x46,
	//air object taken on tracking 
    AIR_OBJ_ON_TRACKING = 0x48,
	//air object discover 
    AIR_OBJ_DISCOVER = 0x49,
	//air object in zone 
    AIR_OBJ_IN_ZONE = 0x50,
	//air object fly 
    AIR_OBJ_FLY = 0x52,
	//command:"detect air object by bearing" was received 
	ON_DETECT_AIR_OBJ_BY_BEARING = 0x51,
    //reject target designation
    RJCT_TD_AIR_OBJ = 0x55,
	 //command: "prohibition of influence on air object"  can not be completed
    ON_PROHIBIT_INFLUENCE_NOT = 0x82,
    //command: "cancelation target designation" was completed
    CANCEL_TD_RCVD = 0x92,
    //command: "cancelation last command" was received
    ON_CANCEL_LAST_COMMAND2 = 0x99
  };

   /*! \var COUInt8 objnum;
  \brief Number of the air object in source numeration.
  */
  COUInt16 numAirObjsrc;

   /*! \var COUInt8 objnum;
  \brief Number of the air object in receiver numeration.
  */
  COUInt16 numAirObjrsvr;
  COUInt8 numBatt;
  COUInt8 numLnch;

};


//рубеж перехвата
struct CPMsg018 : public COMMMsg
{
  enum { TYPE = 18};

  CPMsg018(void ) : COMMMsg(TYPE, sizeof(CPMsg018), GFnumOurCP)
  {
  }
 
/*! \var COUInt8 numAbon;
  \brief Number of the Abonent.
  */
  COUInt8 numAbon;
  
  // Индекс подразделения· 0-командный пункт 1-6· номер подчиненного КП
  COUInt8 SubIndex;
  
  /*! \var COUInt8 objnum;
  \brief Number of the air object in source numeration.
  */




  COUInt16 srcObjnum;

  COInt32 x;
 
  COInt32 y;
  
  COUInt32 UnitedNum;
 
};

//  перезапуск ЭВК

struct CPMsg020 : public COMMMsg
{
  enum { TYPE = 20};

  CPMsg020( void ) : COMMMsg(TYPE, sizeof(CPMsg020), GFnumOurCP)
  {
	  
  }
 
/*! \var COUInt8 numAbon;
  \brief Number of the Abonent.
  */
  COUInt8 numAbon;
   // Индекс подразделения· 0-командный пункт 1-6· номер подчиненного КП
  COUInt8 SubIndex;
};

/*! \struct CPMsg021     POLYANA  Донесение о выполнениии команды по цели от С300П
\brief Message 21 (report from abonent)
*/
struct CPMsg021 : public COMMMsg
{
  enum { TYPE = 21};

  CPMsg021( void ) : COMMMsg(TYPE, sizeof(CPMsg021),GFnumOurCP)   
  {	  
  }
/*! \var COUInt8 numAb;
\brief Number of abonent.
*/
  COUInt8 numAb;

 /*! индекс подразделения· 0-командный пункт 1-6· номер подчиненного КП.
*/
  COUInt8 SubIndex;

  /*! \var COUInt8 res;
\brief reserv.
*/
  COUInt8 res;

  // признаковая информация о донесениях
  COUInt8 sign_rep;  
  enum   //sign_rep
  {
	  INFO_SOP	= 1,		//отказ от ЦУ(сброс по полученному номеру)
	  INFO_KPC	= 1 << 1,	//на запрет
      INFO_OK	= 1 << 2    //на ЦУ с номером зрк   
  };
 
   /*! \var COUInt8 objnum;
  \brief Number of the air object in source numeration.
  */
  COUInt16 numAirObjsrc;

   /*! \var COUInt8 objnum;
  \brief Number of the air object in receiver numeration.
  */
  COUInt16 numAirObjrsvr;

};

/*! \struct CPMsg022     POLYANA  Фазы боевых действий по цели по 6-ти каналам от С300П
\brief Message 22(report from abonent)
*/
struct CPMsg022 : public COMMMsg
{
  enum { TYPE = 22};

  CPMsg022( void ) : COMMMsg(TYPE, sizeof(CPMsg022),GFnumOurCP)   
  {	  
  }
/*! \var COUInt8 numAb;
\brief Number of abonent.
*/
  COUInt8 numAb;

// индекс подразделения· 1-6· номер подчиненного КП.
  COUInt8 SubIndex;
  enum  //State
  {
	  FREE       = 1,  // канал свободен
	  SEARCH     = 2,  // поиск цели
	  ESCORT     = 3,  // захват на сопровождение
	  SUPPORT    = 4,  // сопровождение и передача координат цели
	  FIRE       = 5,  // пуск произведен
	  NO_TRIG    = 6,  // канал не исправен
  };

  /*! \var COUInt8 gttRct_K;
  \brief боезапас ракет типа К.
  */
	COUInt8 gttRct_K;

  /*! \var COUInt8 gttRct_P;
  \brief боезапас ракет типа P.
  */
	COUInt8 gttRct_P;

  struct ChannelState
  {
	  // Number of target cannel.
	  COUInt8 Channel; 
	  
	  // Number of the air object in source numeration.
	  COUInt8 numAirObjsrc;
	  
	  //отказ от сопр. цели
	  COUInt8 Cancel;

	  //Information of state target cannel.
	  COUInt8 State;
	   //Information of Start the first missile.
	  COUInt8  Start_1;

	  //Information of Start the second missile.
	  COUInt8  Start_2;	
  };
  ChannelState ChanStat [GF_QTT_TARGET_CH];
};

/*! \struct CPMsg044 POLYANA \
Фазы боевых действий по цели по 6-ти каналам от С300П \
для выдачи с 1А032 на 9С52М1РБ
\brief Message 44(report from abonent)
*/
struct CPMsg044 : public COMMMsg
{
  enum { TYPE = 44};

  CPMsg044( void ) : COMMMsg(TYPE, sizeof(CPMsg044),GFnumOurCP)   
  {	  
  }
/*! \var COUInt8 numAb;
\brief Number of abonent.
*/
  COUInt8 numAb;

// индекс подразделения· 1-6· номер подчиненного КП.
  COUInt8 SubInd;
  COUInt8 nZRK;
  enum  //State
  {
	  FREE       = 1,  // канал свободен
	  SEARCH     = 2,  // поиск цели
	  ESCORT     = 3,  // захват на сопровождение
	  SUPPORT    = 4,  // сопровождение и передача координат цели
	  FIRE       = 5,  // пуск произведен
	  NO_TRIG    = 6,  // канал не исправен
  };

  struct ChannelState
  {
	  // Number of target cannel.
	  COUInt8 Channel; 
	  
	  // Number of the air object in source numeration.
	  COUInt8 numAirObjsrc;
	  
	  //отказ от сопр. цели
	  COUInt8 Cancel;

	  //Information of state target cannel.
	  COUInt8 State;
	   //Information of Start the first missile.
	  COUInt8  Start_1;

	  //Information of Start the second missile.
	  COUInt8  Start_2;	
  };
  ChannelState ChanStat [GF_QTT_TARGET_CH];
  
  /*! \var COUInt8 SignS;
\brief Признаки работы ЗРК.
*/
  COUInt8 Signs;   
  enum{
	   INFO_BETTA = 1,		//ручное управление(следуй за бетта)
	   INFO_TD = 1 << 1,	//автоматическое распределение(ЦР)
	   INFO_ALKP = 1 << 2,	//режим АЛКП
	   INFO_ACFI = 1 << 3,  //режим АСFi
	   INFO_MUP = 1 << 4,   //местное управление приводом
	   INFO_PC = 1 << 5,	//ручное сопровождение
	   INFO_PEL = 1 << 6	//поиск по пеленгу
   };
  
/*! \var COUInt8 gttRct_K;
\brief боезапас ракет типа К.
*/
  COUInt8 gttRct_K;
  
/*! \var COUInt8 gttRct_P;
\brief боезапас ракет типа P.
*/
  COUInt8 gttRct_P;

/*! \var COUInt32 Azimut_RPH;
\brief азимут биссектрисы раб. сек.РПН.
*/
  COFloat32 Azimut_RPH;
};

/*! \struct CPMsg025   POLYANA Выдать целеуказание по цели на РПН (5Н63)
\brief Message 25 (relating to abonent: "target instruction")
*/
struct CPMsg025 : public COMMMsg
{
  enum { TYPE = 25};

  CPMsg025( void ) : COMMMsg(TYPE, sizeof(CPMsg025), GFnumOurCP),
	  numAbon(0),SubIndex(0),	  
	  srcObjnum(0),
	  Nchannel(0), type(0),
	  x(0),y(0),h(0),vx(0),vy(0),vh(0),
	  Command (0), Signs(0)
  {
  };
  COUInt8 numAbon;

  // Индекс подразделения· 1-6· номер подчиненного КП
  COUInt8 SubIndex;

 
  /*! \var COUInt8 objnum;
  \brief Number of the air object in source numeration.
  */
  COUInt16 srcObjnum;

   /*! \var COUInt8 objnum;
  \brief Number of the air object in receiver numeration.
  */
  //COUInt16 rsvrObjnum;

   /*! \var COUInt8 Nchannel;
  \brief Number of the channel.
  */
  COUInt8 Nchannel;
  
  // type of air object
  COUInt8 type;

  /*! \var COInt16 x;
  \brief X coordinate of air object (12 бит).
  */
  COInt32 x;

  /*! \var COInt16 y;
  \brief Y coordinate of air object (12 бит).
  */
  COInt32 y;
   // Nationality signs:

 /*! \var COInt16 h;
  \brief Height of air object.
  */
  COInt32 h;

  /*! \var COInt16 vx;
  \brief X velocity component.
  */
  COInt16 vx;
  
  /*! \var COInt16 vy;
  \brief Y velocity component.
  */
  COInt16 vy;

    /*! \var COInt16 vh;
  \brief Height velocity component.
  */
  COInt16 vh;

   //for target_designation
  COUInt8 Command;
  enum
  {
	  absend = 0,
	  cancel_target_designation = 1,
	  receive_target_designation = 2
  };
  
  COUInt8 Signs;  
  enum  // for signs
  {
  	  sign_external = 1 << 4,
	  sign_trouble = 1 << 3,
      sign_ban_fire = 1 << 2,		
	  sign_urgent_fire = 1 << 1,
	  sign_priority = 1 << 0
  };
};
/*! \struct CPMsg028 CPMsg.h
\brief Message 28 (Донесение о боевых действиях по ВО и 
                   состоянии целевого канала РПН 5Н63)
*/
struct CPMsg028 : public COMMMsg
{
  enum { TYPE = 28};

  CPMsg028( void ) : COMMMsg(TYPE, sizeof(CPMsg028), GFnumOurCP),numAbon(0), SubIndex(0), vkpAirObjNum(0), 
Channel(0), ChannelRazmn(0),Signs(0), CombatReport(0),typemissile1(0), typemissile2(0),AirObjNumCP(0)
  {
  };
  COUInt8 numAbon;

  // Индекс подразделения·  1-6· номер подчиненного КП
  COUInt8 SubIndex;
  
  // Номер цели в системе нумерации ВКП (Номер ЦУ)
  COUInt16 vkpAirObjNum;

  /*! \var COUInt8 Channel;
  \brief Number of the channel.
  */
  COUInt8 Channel;
  
  COUInt8 ChannelRazmn;

  COUInt8 Signs;
  enum  // for Signs
  {
	  sign_canalrez = 1 << 0,
	  sign_trouble = 1 << 1,
	  sign_manual = 1 << 2,
	  sign_cancel = 1 << 3,
	  sign_start1 = 1 <<4,
      sign_meeting1 = 1 << 5,
	  sign_start2 = 1 <<6,
      sign_meeting2 = 1 << 7
  };
     
  COUInt8 CombatReport;

  COUInt8 typemissile1;

  COUInt8 typemissile2;

  // Системный номер цели
  COUInt16 AirObjNumCP;

};

// Сообщение 45 - Состояние ЦК РПН и БД по ВО (дополнительные признаки). Передаётся в паре с 28-м сообщением
struct CPMsg045 : public COMMMsg
{
	enum { TYPE = 45};
	
	CPMsg045( void ) : COMMMsg(TYPE, sizeof(CPMsg028), GFnumOurCP)
	{
	};

	COUInt8 numAbon;
	
	// Индекс подразделения·  1-6· номер подчиненного КП
	COUInt8 SubIndex;
	
	// номер целевого канала РПН
	COUInt8 nChannelRPN;

	// Номер цели в системе нумерации ВКП (Номер ЦУ)
	COUInt16 vkpAirObjNum;
	
	
	COUInt8 PrPr			:1; // признак проведения проверки соответствия Дцу и Дц
	COUInt8 CoordDifference		:1; // признак отличия кооднинат цели и координат ЦУ более чем на 3 км
	COUInt8 IncorrectDistance	:1; // признак отсутствия достоверной дальности
	COUInt8 ASfi			:1; // признак автоматического сопровождения цели по углам и ручного сопровождения по дальности и скорости
	COUInt8 			:4;

};

/*! \struct CPMsg034 CPMsg.h
\brief Message 34 (Команда по цели на СОУ 9А310МБ)
*/
struct CPMsg034 : public COMMMsg 
{
	enum { TYPE = 34};

    CPMsg034(void) : COMMMsg(TYPE,sizeof(CPMsg034),GFnumOurCP),
  numAb(0),numZRK(0),numAirObjCP(0),
  code(0),Send_signs(0)
	{}	
	/*! \var COUInt8 numAb;
	\brief Number of abonent.
	*/
	COUInt8 numAb;
	
	/*! \var COUInt8 numZRK;
	\brief Number of ZRK.
	*/
	COUInt8 numZRK;

    /*! \var COUInt16 numAirObjCP;
	\brief Number of air object in CP numeration.
	*/
	COUInt16 numAirObjCP;
	COUInt8 code;
	//code
	enum
	{
		//destroy air object 
		DESTROY_AIR_OBJ = 0x11,
		//prohibition of influence on air object
		PROHIBIT_INFLUENCE = 0x22,
		//permit of launch rocket on air object 
		LAUNCH_ROCKET = 0x33,
		//prohibition of launch rocket .
		PROHIBIT_LAUNCH_ROCKET = 0x24,
		//cancelation last command 
		CANCEL_LAST_COMMAND2 = 0x99
	};
    COUInt8 Send_signs;  
	enum  // for Send_signs
	{
		//признак автономного опознавания.
		sign_AutoRecognition = 1 << 3,
		//признак перенацеливания.

		sign_redirecting = 1 << 4,
		//разрешение на пуск только одной ракеты.
		sign_launchOneRckt = 1 << 2,
	    //выделение цели в группе.(нет,левая,правая)
		sign_noneselect_TrgtInGr = 0,
		sign_leftselect_TrgtInGr = 1 << 0,
		sign_rightselect_TrgtInGr = 1 << 1
	};
};

/*! \struct CPMsg035 CPMsg.h
\brief Message 35 (Донесение на команду по цели от СОУ 9А310МБ)
*/
struct CPMsg035 : public COMMMsg 
{
	enum { TYPE = 35};

    CPMsg035(void) : COMMMsg(TYPE,sizeof(CPMsg035),GFnumOurCP){}	
	/*! \var COUInt8 numAb;
	\brief Number of abonent.
	*/
	COUInt8 numAb;
	
	/*! \var COUInt8 numZRK;
	\brief Number of ZRK.
	*/
	COUInt8 numZRK;

    /*! \var COUInt16 numAirObjCP;
	\brief Number of air object in Abonent numeration.
	*/
	COUInt16 numAirObjAb;
    COUInt8 Signs;  
	enum  // for Signs
	{
		//признак пуска ракеты с ПЗУ.
		sign_Start1 = 1 << 4,
		//признак пуска ракеты с СОУ.
		sign_Start2 = 1 << 6,
	};
	COUInt8 Report;	
	enum//Report
	{
		//целеуказание по воздушному объекту получил и выполняю(11) 
		ON_DESTROY_AIR_OBJ = 0x11,
		//команду "Запрет боевых действий по цели " получил и выполняю (22)
		ON_PROHIBIT_INFLUENCE = 0x22,
		//разрешение пуска получил(33) 
		DESTROY_SELF_AIR_OBJ = 0x33,
		//запрет пуска получил (24)
		ON_PROHIBIT_LAUNCH_ROCKET = 0x24,
		//цель сопровождается (48) 
		AIR_OBJ_ON_TRACKING = 0x48,
		//цель в зоне (51)
		AIR_OBJ_ON_ZONE,
		//пуск ракеты (41)
		ROCKET_LAUNCHED = 0x41,
		//пролет (52)
		ROCKET_FLYBY = 0x52,
		//цель уничтожена (45)
		AIR_OBJ_DESTROYED = 0x45,
		//цель не уничтожена (43)
		AIR_OBJ_SKIP = 0x43,
		//команду "отмена целеуказания" получил и выполняю (99)
		ON_CANCEL_LAST_COMMAND2 = 0x99
	};

	//тип использованной ракеты на ПЗУ  
	COUInt8 typemissile1;

	//тип использованной ракеты на СОУ
	COUInt8 typemissile2;  
};

/*! \struct CPMsg040 CPMsg.h
\brief Message 40 (Донесение о боевых действиях по ВО и 
                   состоянии целевого канала C-200)
*/
struct CPMsg040 : public COMMMsg
{
  enum { TYPE = 40};

  CPMsg040( void ) : COMMMsg(TYPE, sizeof(CPMsg040), GFnumOurCP)
  {
  };
  COUInt8 numAbon;

  // Индекс подразделения·  1-6· номер подчиненного КП
  COUInt8 SubIndex;
  
//  \brief Number of the air object in source numeration.
  COUInt16 srcObjnum;
  
//  \brief Number of the air object in resive numeration.
  COUInt16 rsvrObjnum;

  COUInt8 Signs;
  enum  // for Signs
  {
	  sign_bearing        = 1 << 1,
	  sign_startRct       = 1 << 4,
      sign_independent    = 1 << 5,
	  sign_state_channel  = 1 << 6
  };
     
  COUInt8 CombatAction;
  enum  //CombatAction
  {
	  FREE       = 0,  // канал свободен
	  SEARCH     = 4,  // поиск цели
	  SUPPORT    = 5,  // сопровождение и передача координат цели
	  END        = 6,  // цикл окончен
	  REJECT     = 7   // отказ, или отмена ЦУ исполнена
  };

  float Azimuth;
  float Elevation;

  COUInt32 Distance;
  COInt16 RV;
};



/*! \struct CPMsg042 CPMsg.h
\brief Message 42 (Донесение о боевых действиях по ВО и 
                   состоянии целевого канала C-200)
*/
struct CPMsg042 : public COMMMsg
{
  enum { TYPE = 42};

  CPMsg042( void ) : COMMMsg(TYPE, sizeof(CPMsg042), GFnumOurCP)
  {
  };
  COUInt8 numAbon;

  // Индекс подразделения·  1-6· номер подчиненного КП
  COUInt8 SubIndex;

  COUInt8 numBatt;

  // Индекс подразделения·  1-6· номер подчиненного КП
  COUInt8 SubIndexBatt;

  
//  \brief Number of the air object in source numeration.
  COUInt16 srcObjnum;
  
//  \brief Number of the air object in resive numeration.
  COUInt16 rsvrObjnum;

  COUInt8 Signs;
  enum  // for Signs
  {
	  sign_bearing        = 1 << 1,
	  sign_startRct       = 1 << 4,
      sign_independent    = 1 << 5,
	  sign_state_channel  = 1 << 6
  };
     
  COUInt8 CombatAction;
  enum  //CombatAction
  {
	  FREE       = 0,  // канал свободен
	  SEARCH     = 4,  // поиск цели
	  SUPPORT    = 5,  // сопровождение и передача координат цели
	  END        = 6,  // цикл окончен
	  REJECT     = 7   // отказ, или отмена ЦУ исполнена
  };

  float Azimuth;
  float Elevation;

  COUInt32 Distance;
  COInt16 RV;
};



/*! \struct CPMsg101 CPMsg.h
\brief Generalized characteristics of air object.
*/
struct CPMsg101 : public COMMMsg
{
  enum { TYPE = 101 };

  CPMsg101( void ) : COMMMsg(TYPE, sizeof(CPMsg101), GFnumOurCP),
  objnum(0),master(0),nation(0),type(0),group(0),
          numUnited(0),x(0),y(0),h(0),vx(0),vy(0),vh(0),infl(0),
          signs(0), tracking(0), Index(0),
          mnvr(0),disaster(0),Fuel(0),
          signAbonentAction(0),signAbonentActionREB(0),signAbonentNotify(0),numberingZRK(0),real_course(0)
  {
	  memset(numbering,0,sizeof(numbering));
	  memset(numbering_out,0,sizeof(numbering_out));
  }

 // Number of air object.
  COUInt16 objnum;
  
  COUInt8 master;  
  
 // Nationality 
  COUInt8 nation;
  
  COUInt8 type;

  /*! \var COUInt8 group;
  \количественный состав
  */
  COUInt8 group;

  //  номер ВО в системе абонента 
  COUInt16 numbering[4];

  //номер единый; 
  COUInt32 numUnited;

  /*! \var COInt32 x;
  \brief X coordinate of air object.
  */
  COInt32 x;
  
  /*! \var COInt32 y;
  \brief Y coordinate of air object.
  */
  COInt32 y;
  
  /*! \var COInt32 h;
  \brief Height of air object.
  */
  COInt32 h;
 
  /*! \var COInt16 vx;
  \brief X velocity component.
  */
  COInt16 vx;
  
  /*! \var COInt16 vy;
  \brief Y velocity component.
  */
  COInt16 vy;
  
  /*! \var COInt16 vh;
  \brief Height velocity component.
  */
  COInt16 vh;
  
  COUInt8 infl;
    
  COUInt8 signs;
  
  COUInt8 tracking;
  
  COUInt8 Index;

// Maneuver signs:

  COUInt8 mnvr;
     
  COUInt8 disaster;
  
  COUInt8 Fuel;
  
 //  метки действия абонентов
  COUInt8 signAbonentAction;

    /*! COUInt16 signAbonentAction;
  метки действия абонентов
  */
   COUInt8 signAbonentActionREB;
  
  /*! COUInt16 signAbonentNotify;
  метки оповещения абонентов
  */
  COUInt8 signAbonentNotify;
   
  COUInt8 numberingZRK;

  COUInt8 rez[3];

  //  номер ВО под которым мы выдаем его абоненту 
  COUInt16 numbering_out[4];

  COUInt16 real_course;
};




/*! \struct CPMsg103 CPMsg.h
\конец передачи трассы
*/

struct CPMsg103 : public COMMMsg
{
  enum { TYPE = 103 };

  CPMsg103( void ) : COMMMsg(TYPE, sizeof(CPMsg103), GFnumOurCP) 
  {
  }
     /*! \var COUInt8 objnum;
  \brief Number of the air object in source numeration.
  */
  COUInt16 srcObjnum;

};




/*! \struct CPMsg105 CPMsg.h
\brief Bearing info.
*/
struct CPMsg105 : public COMMMsg
{
  enum { TYPE = 105 };

  CPMsg105( void ) : COMMMsg(TYPE, sizeof(CPMsg105), GFnumOurCP) 
  {
	  
  }


  COUInt8 numAbon;

  // Индекс подразделения· 0-командный пункт 1-6· номер подчиненного КП
  COUInt8 SubIndex;
 
   /*! \var COUInt8 objnum;
  \brief Number of the air object in source numeration.
  */
  COUInt16 srcObjnum;

   /*! \var COUInt8 objnum;
  \brief Number of the air object in receiver numeration.
  */
  COUInt16 sysObjnum;
 
  float	azimuth;

  float	elevation;

  float	azimuthVel;

  float	elevationVel;

  COUInt8	objNum;
  
  COUInt8	tracking;
  
  enum
  {
	  TRACKING_REGULAR			= 0,
	  BEARING_ON_COMMAND	= 2,
	  BEARING_END			= 5
  };
  COUInt8	state;
  enum
  {
	  STATE_SINGLE			= 0,
	  STATE_IDENTIFIED		= 1,
	  STATE_TRIANG			= 2
  };
	COUInt8 information_coord_system; 
	/*
	TOPOCENTRIC_COORD 	= 0,	// прямоугольные относительно репера
	GEODESIC_COORD		= 1,	// географические (широта, долгота)
	GAUSS_KRUGER_COORD	= 2,	// координаты в системе Гаусса-Крюгера 
	GEOCENTRIC_COORD	= 3,	// геоцентрические относительно центра земли
	POLAR_COORD		= 4	// полярная система координат
	*/
	COInt32 X;
	COInt32 Y;
	COInt32 H;
};




/*! \struct CPMsg124  POLYANA

\brief Outcome the resultant of the battle operations.
*/
struct CPMsg124 : public COMMMsg
{
  enum { TYPE = 124 };

  CPMsg124( void ) : COMMMsg(TYPE, sizeof(CPMsg124), GFnumOurCP) 
  {
	  res =0;
	  tmBegOpert =0;
	  tmEndOpert =0;
	  qtTrckngEnemyAO =0;
	  qtGroupTrckngEnemyAO =0;
	  qtTrckngFrendAO =0;
	  qtGroupTrckngFrendAO =0;
	  qtBattleHardenedAO =0;
	  qtDestroyedAO =0;


//	  typeRct1 =0;
//	  typeRct2 =0;
//	  qtRct1 =0;
//	  qtRct2 =0;
  }
  COUInt16 res;
  COInt64 tmBegOpert;
  COInt64 tmEndOpert;
  COUInt16 qtTrckngEnemyAO;
  COUInt16 qtGroupTrckngEnemyAO;
  COUInt16 qtTrckngFrendAO;
  COUInt16 qtGroupTrckngFrendAO;

/*! \var COUInt16 qtBattleHardenedAO;
\brief Quantity of battle-hardened air objects in calculation time.
*/
  COUInt16 qtBattleHardenedAO;

/*! \var COUInt16 qtDestroyedAO;
\brief Quantity of destroyed air objects in calculation time.
*/
  COUInt16 qtDestroyedAO;

/*! \var COUInt16 typeRct1;
\brief type of  rockets first type in calculation time.
*/
  struct RCT_Ab{
	  RCT_Ab (void)
	  {
		  RctType = 0;
		  qtRct =0;
	  }
	  COUInt16 RctType;
	  COUInt16 qtRct;
  };
  RCT_Ab massRCT_Ab[2];
};
  //  COUInt16 typeRct1;

///*! \var COUInt16 qtRct1;
//\brief Quantity of spent rockets first type in calculation time.
//*/
//  COUInt16 qtRct1;
//
///*! \var COUInt16 typeRct2;
//\brief type of  rockets second type in calculation time.
//*/
//  COUInt16 typeRct2;
///*! \var COUInt16 qtRct2;
//\brief Quantity of spent rockets second type in calculation time.
//*/
//  COUInt16 qtRct2;

/*! \struct CPMsg125   POLYANA
\brief Message 125 (Inquiry)
*/
struct CPMsg125 : public COMMMsg
{
  enum { TYPE = 125 };

  CPMsg125( void ) : COMMMsg(TYPE, sizeof(CPMsg125), GFnumOurCP) {}

	/*! \var COUInt8 type;
  \brief Type of information.

  */

	COUInt8 type;
  enum{
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

  

	/*! \var COUInt8 abNum;
  \brief Abonent number.
  */
	COUInt8 abNumber;

	/*! \var COUInt8 sabNum;
  \brief Sub Abonent number.
  */
  COUInt8 sabNumber;

  /*! \var COUInt8 param;
  \brief Parameter.
  */
  COUInt8 param;
};



/*! \struct CPMsg127 CPMsg.h
\brief Message 127 (the target distribution task solution)
*/
struct CPMsg127 : public COMMMsg
{
  enum { TYPE = 127 };

  CPMsg127( void ) : COMMMsg(TYPE, sizeof(CPMsg127), GFnumOurCP) {}

  /*! \var COUInt8 abnum;
  \brief Abonent number.
  */
  COUInt8 abnum;

  /*! \var COUInt8 cycend;
  \brief End of TD cycle sign.
  */
  COUInt8 cycend;

  enum
  {
    CONTINUE = 0x00, 
    END = 0x01
  };

  /*! \var COUInt8 rezerv;
  \brief Rezerv byte.
  */
  COUInt8 rezerv;

  /*! \var COUInt8 numofobj;
  \brief Number of the air objects recomended to this abonent.
  */
  COUInt8 numofobj;

  struct Recomendation
  {

    /*! \var COUInt8 objnum;
    \brief Number of the air object.
    */
    COUInt8 objnum;

    /*! \var COUInt8 recom;
    \brief Recommendation for the air object.
    */
    COUInt8 recom;

    /*! \var COUInt8 signif;
    \brief Significance of the air object.
    */
    COUInt8 signif;
    
    /*! \var COUInt8 meettime;
    \brief Time till the air object meet rocket.
    */
    COUInt8 meettime;

    /*! \var COUInt16 locktime;
    \brief Time the air object located in the hitting zone.
    */
    COUInt16 locktime;
  };

  /*! \var Recomendation targets[255];
  \brief The air objects recomended to this abonent.
  */
  Recomendation targets[255]; // Цели рекомендуемые абоненту

  /*!\fn void realSize(void);
  \brief To calculate the real size of message.
  */
  void realSize(void)
  {
    msgsize = sizeof(COMMMsg) + 4 + numofobj*sizeof(Recomendation);
  };
};

/*! \struct CPMsg128 CPMsg.h
\brief Message 128 (the target distribution task solution(sequel))
*/
struct CPMsg128 : public COMMMsg
{
  enum { TYPE = 128 };

  CPMsg128( void ) : COMMMsg(TYPE, sizeof(CPMsg128), GFnumOurCP) {}

  /*! \var COUInt8 abnum;
  \brief Abonent number.
  */
  COUInt8 abnum;

  /*! \var COUInt8 cycend;
  \brief End of TD cycle sign.
  */
  COUInt8 cycend;

  enum
  {
    CONTINUE = 0x00, 
    END = 0x01

  };


  /*! \var COUInt8 rezerv;
  \brief Rezerv byte.
  */
  COUInt8 rezerv;

  /*! \var COUInt8 numofobj;
  \brief Number of the air objects recomended to this abonent.
  */
  COUInt8 numofobj;

  struct Recomendation
  {
    /*! \var COUInt8 objnum;
    \brief Number of the air object.
    */
    COUInt8 objnum;

    /*! \var COUInt8 recom;
    \brief Recommendation for the air object.
    */
    COUInt8 recom;

    /*! \var COUInt16 time;
    \brief Time to fly target to the far boarder of the hitting zone.
    */
    COUInt16 time;
  };

  /*! \var Recomendation targets[255];
  \brief The air objects.
  */
  Recomendation targets[255];

  /*!\fn void realSize(void);
  \brief To calculate the real size of message.
  */
  void realSize(void)
  {
    msgsize = sizeof(COMMMsg) + 4 + numofobj*sizeof(Recomendation);
  };
};

/*! \struct CPMsg104 CPMsg.h
\brief Identification control.Ввод хар-к ВО с АРМ
*/
struct CPMsg104 : public COMMMsg

{
  enum { TYPE = 104 };

  CPMsg104( void ) : COMMMsg(TYPE, sizeof(CPMsg104), GFnumOurCP) {}

   /*! \var COUInt8 objnum;
  \brief Number of air object. NBO1
  */
   COUInt16 objnum;

    //вводимые данные: NBO2, или ГП 1-0 бит,или ПД-1-0 бит,
   // или ТИП 3-0 бит;
   //номер единый - 3 байта,inpt1-младшие цифры NED
   COUInt32 input;   

  /*! \var COUInt8 ctrl;
  \brief Control command.Признак информации. Ввод-отмена хар-ки
  */
  COUInt8 ctrl;

  enum
  {
	CTRL_ASSIGN_NumUnited =				0x01,// NED
    CTRL_CANCEL_NumUnited_ASSIGNMENT =	0x81,
   
	CTRL_ASSIGN_NATION =				0x02,// ГП
    CTRL_CANCEL_NATION_ASSIGNMENT =		0x82,
    
	CTRL_ASSIGN_ENEMY	=				0x03,//тип чужого ВО
    CTRL_CANCEL_ENEMY_ASSIGNMENT =		0x83,
    
	CTRL_ASSIGN_FRIEND	=				0x04,// тип своего ВО
    CTRL_CANCEL_FRIEND_ASSIGNMENT =		0x84,

	CTRL_ASSIGN_INFLUENCE	=			0x05, //ПД
    CTRL_CANCEL_INFLUENCE_ASSIGNMENT =	0x85,
    
    CTRL_IDENTIFY =						0x06,//отожд.
    CTRL_CANCEL_MANUAL_IDENTIFICATION =	0x86,
  
	CTRL_HIDE_BEARING	=				0x07,
    CTRL_CANCEL_BEARING_HIDING	=		0x87 ,

	CTRL_IDNT_FromTheSameSource =		0x08,//отождествить 2 ВО, сопровождаемые одним и тем же источниеом
    CTRL_CANCEL_IDNT_FromTheSameSource= 0x88,//отменить отождествление		
	
//	CTRL_HIDE_TRACK =					0x0B,
//	CTRL_CANCEL_TRACK_HIDING =			0x8B

	CTRL_ASSIGN_HEIGHT =				0x09,// высота
	CTRL_CANCEL_ASSIGN_HEIGHT =			0x89,

	CTRL_ASSIGN_QUANTITATIVE_COMPOSITION		= 	0x0A,// количественный состав
	CTRL_CANCEL_ASSIGN_QUANTITATIVE_COMPOSITION =	0x8A

  };

 
// Индекс подразделения· 0-командный пункт 1-6· номер подчиненного КП
  COUInt8 SubIndex;

 }; 


/*! \struct CPMsg107       POLYANA
\brief Command by air object.
*/
struct CPMsg107 : public COMMMsg 
{
	enum { TYPE = 107};

    CPMsg107(void) : COMMMsg(TYPE,sizeof(CPMsg107),GFnumOurCP)
  {  
	  numAb = 0;
	  numZRK = 0;
	  numAirObjCP = 0;
	  numAirObjAb = 0;
	  pr_info  = 0;
	  code   = 0;
	  numCannel  = 0;
	  RocketType = 0;
	  TDPriopNumber = 0;
	  m_numZU = 0;
  }
	
/*! \var COUInt8 numAb;
\brief Number of abonent.
*/
  COUInt8 numAb;
  
  /*! \var COUInt8 numZRK;
\brief Number of ZRK.
*/
  COUInt8 numZRK;

    /*! \var COUInt8 numAirObjCP;
\brief Number of air object in CP numeration.
*/
  COUInt16 numAirObjCP;

/*! \var COUInt8 numAirObjAb;
\brief Number of air object in abonent numeration.
*/
  COUInt16 numAirObjAb;

/*! \var COUInt8 pr_info;
\brief Sign of information.
*/

  COUInt8 pr_info;
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

  /*! \var COUInt8 code;
\brief Code of command.
*/
  COUInt8 code;
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
 /*! \var COUInt8 Channel;
 \brief Number of the channel.
 */
  COUInt8 numCannel;

 /*! \var COUInt8 RocketType;
 \brief type of the rocket.
 */
  COUInt8 RocketType;
 /*! \var COUInt8 TDPriopNumber;
 \brief Number of the TDprioritet.
 */
  COUInt8 TDPriopNumber;

  /*! \var COUInt8 m_numZU;
  \brief number ZU.
  */
  COUInt8 m_numZU;
  
};

/*! \struct CPMsg108  POLYANA
\brief Report on command by air object.
*/
struct CPMsg108 : public COMMMsg 
{
	enum { TYPE = 108};
	
    CPMsg108(void) : COMMMsg(TYPE,sizeof(CPMsg108),GFnumOurCP)
  {  
	  numAb = 0;
	  numZRK = 0;
	  numAirObjCP = 0;
	  numAirObjAb = 0;
	  pr_info  = 0;
	  code   = 0;
	  numCannel  = 0;
	  RocketType = 0;
	  QttRocket = 0;
	  m_numZU = 0;
  }

/*! \var COUInt8 numAb;
\brief Number of abonent.
*/
  COUInt8 numAb;

  /*! \var COUInt8 numZRK;
\brief Number of ZRK.
*/
  COUInt8 numZRK;
  
  	/*! \var COUInt8 numAirObjCP;
\brief Number of air object in CP numeration.
*/
  COUInt16 numAirObjCP;

/*! \var COUInt8 numAirObjAb;
\brief Number of air object in abonent numeration.
*/
  COUInt16 numAirObjAb;

/*! \var COUInt8 pr_info;
\brief sing of report.
*/
  COUInt8 pr_info;
  
  //pr_info
  enum
  {
	  REPORT_AIR_OBJ_TO =0x02,
	  //report by air object from abonent.
	  REPORT_AIR_OBJ_FROM= 0x08,
	  //report independent by air object from abonent.
	  REPORT_INDEPENDENT = 0x10
  };
  
  /*! \var COUInt8 code;
\brief Code of report.
*/
  COUInt8 code;
  //code
  enum
  {
	  //command: "cancelation last command" was received
	  ON_CANCEL_LAST_COMMAND1 = 0x00,
	  //telephone talk on air object (relating to abonents 1-6 )
	  TELEPHONE = 0x01,
	  //command: "destroy air object" was received
	  ON_DESTROY_AIR_OBJ = 0x11,
     //end of period battle operation 
	  END_BO = 0x20,
	  //command: "prohibition of influence on air object" was received
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
 /*! \var COUInt8 Channel;
 \brief Number of the channel.
 */
  COUInt8 numCannel;

 /*! \var COUInt8 RocketType;
 \brief type of the rocket.
 */
  COUInt8 RocketType;

 /*! \var COUInt8 QttRocket;
\brief Quantity of spent rockets.
 */
  COUInt8 QttRocket;

  /*! \var COUInt8 m_numZU;
  \brief number ZU.
  */
  COUInt8 m_numZU;

  };



struct CPMsg115 : public COMMMsg
{
	enum {TYPE = 115};

	CPMsg115(void) : COMMMsg(TYPE, sizeof(CPMsg115), GFnumOurCP) {}
	
	// Номер абонента 
	/*! \var COUInt8 numAb;
	\brief Number of the source.
	*/
	COUInt8 numAb;

	 // Индекс подразделения· 0-командный пункт 1-6· номер подчиненного КП
	COUInt8 SubIndex;
	
	// Максимальное количество воздушных объектов, выдаваемых на оповещение
	/*! \var COUInt8 maxQant;
	\brief Maximum quantity of air objects which are given out on the notification.
	*/
	COUInt8 maxQant;

	// Вид оповещения
	/*! \var COUInt8 modeNotif;
	\brief Mode of the notification.
	*/
	COUInt8 modeNotif;
	enum
	{
		AB_NOT_NOTIF,//абонент не оповещается
		SELECT_NOTIF,//оповещение выборочное
		ANALYSIS_SUPORT_NOTIF,//оповещение выборочное по признаку сопровождения
		ANALYSIS_SUPORT_INFL_NOTIF,//оповещение выборочное по признакам сопровождения и действия
		ANALYSIS_INFL_NOTIF,//оповещение выборочное по признаку действия
		ALL_NOTIF //полное оповещение невыборочное
	};

 	//
	COUInt8 signParamFirst;
	enum
	{
		NOT_SELECT_PARAM_FIRST = 0x00,//
		SELECT_FIRST = 0x01,//
		SELECT_PARAM = 0x10,//
		SELECT_PARAM_FIRST = 0x11//
	};
	// Колчество зон
	COUInt8 zoneQant;

	//  ключи зон
	NTFZoneKey zones[MAX_ZONES];

	// Приоритет целей, по которым выдано ЦУ
	COUInt8 priorCU;

	// Приоритет целей по команде оператора и из списка номеров единых, заданных оператором
	COUInt8 priorOperator;

	// Приоритет целей с признаком воздействия авиации
	/*! \var COUInt8 priorAvia;
	\brief Priority of the targets with an attribute of influence of aircraft.
	*/
	COUInt8 priorAvia;

	// Приоритет целей с признаком воздействия зенитно-ракетных частей
	/*! \var COUInt8 priorRocet;
	\brief Priority of the targets with an attribute of influence of rocket parts.
	*/
	COUInt8 priorRocet;

	// Приоритет целей без воздействия
	/*! \var COUInt8 priorWithout;
	\brief Priority of the targets without influence.
	*/
	COUInt8 priorWithout;

	// Приоритет целей с признаком государственного опознавания "свой"
	/*! \var COUInt8 priorFriend;
	\brief Priority of the targets with an attribute of the state identification "friend".
	*/
	COUInt8 priorFriend;

	// Отбор целей по типам ВО
	COUInt8 objType[MAX_SEL_TYPE];
	

	// Признак отбора целей при наличии номера единого
	COUInt8 signUnited;

	// Список номеров запретных источников
	COUInt8 prohibitAb[MAX_PROHIBIT_SOURCE];

	CPMsg115& operator= (const CPMsg115 * copy)
	{
		maxQant = copy->maxQant;
		modeNotif = copy->modeNotif;
		numAb = copy->numAb;
		SubIndex = copy->SubIndex;

     int i;
		for (i = 0; i<MAX_SEL_TYPE; i++)
		{
			objType[i] = copy->objType[i];
		}
		priorAvia = copy->priorAvia;
		priorCU = copy->priorCU;
		priorFriend = copy->priorFriend;
		priorOperator = copy->priorOperator;
		priorRocet = copy->priorRocet;
		priorWithout = copy->priorWithout;
		for( i=0; i<MAX_PROHIBIT_SOURCE; i++)
		{
			prohibitAb[i] = copy->prohibitAb[i];
		}
		signParamFirst = copy->signParamFirst;
		signUnited = copy->signUnited;
		zoneQant = copy->zoneQant;
		for(i = 0 ; i<MAX_ZONES; i++)
		{
			zones[i] = copy->zones[i];
		}
		return *this;
	}

};


/*! \struct CPMsg116
\brief Cancellation of zone.
*/
struct CPMsg116 : public COMMMsg
{
  enum { TYPE = 116};

  CPMsg116(void) : COMMMsg(TYPE,sizeof(CPMsg116),GFnumOurCP) 
	{
	}

  CPMsg116& operator= (const CPMsg116 * copy)
  {
	  includeSign = copy->includeSign;
	  numAb = copy->numAb;
	  SubIndex = copy->SubIndex;
	  number = copy->number;
	  
	  return *this;
  }
// Номер абонента 
	/*! \var COUInt8 numAb;
	\brief Number of the source.
	*/
	COUInt8 numAb;

	 // Индекс подразделения· 0-командный пункт 1-6· номер подчиненного КП
	COUInt8 SubIndex;

 	// Количество номеров воздушных объектов в сообщении
	/*! \var COUInt8 amountObj;
	\brief Amount of numbers of air objects in the message (K <= 20).
	*/
	COUInt32 number;


	// Признак включения (исключения) воздушных объектов с оповещения 
	/*! \var COUInt8 includeSign;
	\brief Sign of inclusion.
	*/
	COUInt8 includeSign;
};

struct CPMsg117IcData{
        /*! \var COUInt8 icType;
\brief Type of interceptor.
*/
        COUInt8 icType;

/*! \var COUInt8 rCode;
\brief Recomendation code.
*/
        COUInt8 rCode;

/*! \var COUInt16 appTime;
\brief Approaching time.
*/
        COUInt16 appTime;
};

struct CPMsg117V{

/*! \var COUInt8 confirmSign;
\brief Confirmation Sign.
*/
        COUInt8 confirmSign;

/*! \var COUInt8 abNumber;
\brief Abonent number.
*/
        COUInt8 abNumber;

/*! \var COUInt8 sabNumber;
\brief Sub abonent number.
*/
        COUInt8 sabNumber;
        COUInt8 rezerve;

/*! \var COUInt32 az;
\brief Sub abonent vs. Target azimuth.
*/
        COUInt32 az;

/*! \var COUInt32 az;
\brief Sub abonent vs. Target distance.
*/
        COUInt32 distance;

/*! \var COUInt32 az;
\brief Sub abonent vs. Target cource parameter.
*/
        COUInt32 cp;

/*! \var COUInt8 sector_sign;
\brief Sub abonent vs. Target "target in sector sign".
*/
        COUInt8 sector_sign;

/*! \var CPMsg117IcData icData[2];
\brief Data for two types of interceptors.
*/
        CPMsg117IcData icData[2];

        enum{
                TIME_FAR_BOARD = 0x01,
                TIME_NEAR_BOARD = 0x02,
                TIME_FAR_LESS30 = 0x03,
                TIME_NEAR_LESS30 = 0x04,
                OUT_TGT = 0x05,
                Q_TOO_LARGE = 0x06,
                CALC_NO_DATA = 0x07,
                H_NOT_IN_DIAPAZON = 0x08,
                AB_NOT_READY = 0x09,
                SECTOR_OUT_TGT = 0x0A,
                V_ZERO = 0x0B,
                P_TOO_LARGE = 0x0C,
                APP_TIME_ZERO = 0x0D,
                LNCH_EXCLUDE = 0x0E,
                V_TOO_LARGE = 0x10,
                NO_TRACKIN = 0x11
        };
};

struct CPMsg117C{
/*! \var COUInt8 tgtNum;
\brief Number of target.
*/
        COUInt16 tgtNum;

        COUInt16 rezerve;

/*! \var COUInt8 prrt;
\brief Priority.
*/
        COUInt8 prrt;
};

/*! \struct CPMsg117
\brief targets charakteristiks.
*/
struct CPMsg117 : public varmsg< CPMsg117C, COUInt8, CPMsg117V, _MAX_COUNT_LAUNCHER_ >{
  enum { TYPE = 117 };

  CPMsg117( void ) : varmsg<CPMsg117C, COUInt8, CPMsg117V, _MAX_COUNT_LAUNCHER_> ( TYPE ){};
};

struct CPMsg155V{
/*! \var COUInt8 Target number;
\brief Target number.
*/
	COUInt16 tgtNum;
};

struct CPMsg155C{
/*! \var COUInt8 abNum;
\brief Number of abonent.
*/
	COUInt8 abNum;

/*! \var COUInt8 subabNum;
\brief Subnumber of abonent.
*/
	COUInt8 subabNum;

/*! \var COUInt8 infSign;
\brief Sign of information.
*/
	COUInt8 infSign;
	enum{
		KONFLIKT = 0x01,
		KONFLIKT_OK = 0x81
	};
};

/*! \struct CPMsg155
\brief Blinkin' of Targets and Sectors.
*/
struct CPMsg155 : public varmsg< CPMsg155C, COUInt8, CPMsg155V, 6 >{
  enum { TYPE = 155 };
	  
  CPMsg155( void ) : varmsg<CPMsg155C, COUInt8, CPMsg155V, 6> ( TYPE ){};
};


/*! \struct CPMsg129
\brief Outcome the resultant of the battle operations.
*/
struct CPMsg129 : public COMMMsg
{
  enum { TYPE = 129 };

  CPMsg129(void) :
  COMMMsg(TYPE,sizeof(CPMsg129),GFnumOurCP) {}
  
/*! \var COInt64 tmBegOpert;
\brief time of beginning calculation.
*/
  COInt64 tmBegOpert;

/*! \var COInt64 tmEndOpert;
\brief time of ending calculation.
*/
  COInt64 tmEndOpert;

/*! \var COUInt16 qtTrckngAO;
\brief Quantity of tracking air objects in calculation time.
*/
  COUInt16 qtTrckngAO;

/*! \var COUInt16 qtTrckngEnemyAO;
\brief Quantity of tracking enemy air objects in calculation time.
*/
  COUInt16 qtTrckngEnemyAO;

/*! \var COUInt16 qtBattleHardenedAO;
\brief Quantity of battle-hardened air objects in calculation time.
*/
  COUInt16 qtBattleHardenedAO;

/*! \var COUInt16 qtDestroyedAO;
\brief Quantity of destroyed air objects in calculation time.
*/
  COUInt16 qtDestroyedAO;

/*! \var COUInt16 qtRct1;
\brief Quantity of spent rockets first type in calculation time.
*/
  COUInt16 qtRct1;

/*! \var COUInt16 qtRct2;
\brief Quantity of spent rockets second type in calculation time.
*/
  COUInt16 qtRct2;

/*! \var COUInt16 qtRct3;
\brief Quantity of spent rockets third type in calculation time.
*/
  COUInt16 qtRct3;

/*! \struct OutcomeBttlOprtLnchr
\brief Outcome the resultant of the battle operations by launcher.
*/
  struct OutcomeBttlOprtLnchr
  { 
  /*! \var COUInt16 qtTrckngAO;
  \brief Quantity of tracking air objects in calculation time.
  */
    COUInt16 qtTrckngAO;

  /*! \var COUInt16 qtTrckngEnemyAO;
  \brief Quantity of tracking enemy air objects in calculation time.
  */
    COUInt16 qtTrckngEnemyAO;

  /*! \var COUInt16 qtBattleHardenedAO;
  \brief Quantity of battle-hardened air objects in calculation time.
  */
    COUInt16 qtBattleHardenedAO;

  /*! \var COUInt16 qtDestroyedAO;
  \brief Quantity of destroyed air objects in calculation time.
  */
    COUInt16 qtDestroyedAO;

  /*! \var COUInt16 qtRct1;
  \brief Quantity of spent rockets first type in calculation time.
  */
    COUInt16 qtRct1;

  /*! \var COUInt16 qtRct2;
  \brief Quantity of spent rockets second type in calculation time.
  */
    COUInt16 qtRct2;
  };

/*! \var OutcomeBttlOprtLnchr oBObyLnchr[6];
\brief Array of outcome the resultant of the battle operations by launcher.
*/
  OutcomeBttlOprtLnchr oBObyLnchr[6];

/*! \struct OutcomeBttlOprtCover
\brief Outcome the resultant of the battle operations by cover unit.
*/

  struct OutcomeBttlOprtCover
  { 
  /*! \var COUInt16 qtTrckngAO;
  \brief Quantity of tracking air objects in calculation time.
  */
    COUInt16 qtTrckngAO;

  /*! \var COUInt16 qtTrckngEnemyAO;
  \brief Quantity of tracking enemy air objects in calculation time.
  */
    COUInt16 qtTrckngEnemyAO;

  /*! \var COUInt16 qtBattleHardenedAO;
  \brief Quantity of battle-hardened air objects in calculation time.
  */
    COUInt16 qtBattleHardenedAO;

  /*! \var COUInt16 qtDestroyedAO;
  \brief Quantity of destroyed air objects in calculation time.
  */
    COUInt16 qtDestroyedAO;

  /*! \var COUInt16 qtRct;
  \brief Quantity of spent rockets in calculation time.
  */
    COUInt16 qtRct;
  };

/*!\var OutcomeBttlOprtCover oBObyCover;
\brief Outcome the resultant of the battle operations by cover unit
*/
  OutcomeBttlOprtCover oBObyCover;

/*! \struct OutcomeBttlOprtOther
\brief Outcome the resultant of the battle operations by other source.
*/
  struct OutcomeBttlOprtOther
  {
  /*! \var COUInt16 qtTrckngAO;
  \brief Quantity of tracking air objects in calculation time.
  */
    COUInt16 qtTrckngAO;

  /*! \var COUInt16 qtTrckngEnemyAO;
  \brief Quantity of tracking enemy air objects in calculation time.
  */
    COUInt16 qtTrckngEnemyAO;
  };

/*! \var OutcomeBttlOprtOther oBObyOther[7];
\brief Outcome the resultant of the battle operations by other source.
*/
  OutcomeBttlOprtOther oBObyOther[7];

};


struct CPMsg123 : public COMMMsg 
{

	enum { TYPE = 123 };

	CPMsg123(void): COMMMsg( TYPE, sizeof(CPMsg123), GFnumOurCP),
					totalObjects(0),totalObjectsQuantyti(0),
					enemyObjects(0), enemyObjectsQuantyti(0), totalInputStream(0),
					influenceObjectsFLACK(0),influenceObjectsAVIA(0),
					bearingObjects(0), notifObjects(0)
	{
		memset(heightObjects,0,sizeof(heightObjects));
		memset(totalObjectsAb,0,sizeof(totalObjectsAb));
	}

	COUInt16 totalObjects;
	COUInt16 totalObjectsQuantyti;
	
	COUInt16 enemyObjects;
	COUInt16 enemyObjectsQuantyti;

	COUInt16 totalInputStream;

	COUInt16 influenceObjectsFLACK;
	COUInt16 influenceObjectsAVIA;

	COUInt16 bearingObjects;

	COUInt16 heightObjects[5][2];

	COUInt16 notifObjects;

	COUInt16 totalObjectsAb[4];
};




/*! \struct CPMsg134
\//Выдача команды по пеленгу на абонент с АРМ
*/
struct CPMsg134 : public COMMMsg
{
  enum { TYPE = 134 };

  CPMsg134(void) : COMMMsg(TYPE,sizeof(CPMsg134),GFnumOurCP),
					srcObjnum(0),numAbon(0),SubIndex(0),rsvrObjnum(0),
					ActionNumAbon(0),ActionSubIndex(0),NumChannel(0),command(0),Num_CU_pel(0)
  {}

 // Number of bearing object.
  COUInt16 srcObjnum;
  
  COUInt8 numAbon;

  // Индекс подразделения· 0-командный пункт 1-6· номер подчиненного КП
  COUInt8 SubIndex;
  
  COUInt8 rsvrObjnum;
  
  COUInt8 ActionNumAbon;

   // Индекс подразделения· 0-командный пункт 1-6· номер подчиненного КП
  COUInt8 ActionSubIndex;
  
  COUInt8 NumChannel;

  COUInt8 command;
  
  enum
  {
	  DETECT = 1,
	  CANCEL_COMMAND = 0x99
  };

 COUInt8 Num_CU_pel;
};

/*! \struct CPMsg126
\brief Diagnostic message->POLYNA
*/
struct CPMsg126 : public COMMMsg
{
  enum { TYPE = 126 };

  CPMsg126(void) : COMMMsg(TYPE,sizeof(CPMsg126),GFnumOurCP) {}

/*! \var COUInt8 txtMsg[64];
\brief Text message.
*/
 
  COUInt8 txtMsg[256];

};

/*! \struct CPMsg137       POLYANA
\brief Command by air object to Launcher.
*/
struct CPMsg137 : public COMMMsg 
{
	enum { TYPE = 137};

    CPMsg137(void) : COMMMsg(TYPE,sizeof(CPMsg137),GFnumOurCP),
  numAb(0),numZRK(0),numAirObjCP(0),numAirObjAb(0),Channel(0),
  code(0),Signs(0),select_TrgtInGr(0)
	{}	
	/*! \var COUInt8 numAb;
	\brief Number of abonent.
	*/
	COUInt8 numAb;
	
	/*! \var COUInt8 numZRK;
	\brief Number of ZRK.
	*/
	COUInt8 numZRK;

    /*! \var COUInt16 numAirObjCP;
	\brief Number of air object in CP numeration.
	*/
	COUInt16 numAirObjCP;

	/*! \var COUInt16 numAirObjAb;
	\brief Number of air object in abonent numeration.
	*/
	COUInt16 numAirObjAb;

	/*! \var COUInt8 Channel;
	\brief Number of the channel.
	*/
	COUInt8 Channel;

	/*! \var COUInt8 code;
	\brief Code of command.
	*/
	COUInt8 code;
	//code
	enum
	{
		//destroy air object 
		DESTROY_AIR_OBJ = 0x11,
		//prohibition of influence on air object
		PROHIBIT_INFLUENCE = 0x22,
		//absolute prohibition of influence on air object 
		DESTROY_SELF_AIR_OBJ = 0x33,
		//cancelation last command 
		CANCEL_LAST_COMMAND2 = 0x99
	};
    COUInt8 Signs;  
	enum  // for signs
	{
		//признак автономного опознавания.
		sign_AutoRecognition = 1 << 0,
		//признак перенацеливания.
		sign_redirecting = 1 << 1,
		//разрешение на пуск только одной ракеты.
		sign_launchOneRckt = 1 << 2,
		//признак запрета пуска ракет
		sign_NotLnchRckt = 1 << 3,
		//признак разрешения пуска ракет
		sign_LnchRckt = 1 << 4
	};

	//выделение цели в группе.
	COInt8 select_TrgtInGr;
};

/*! \struct CPMsg138
\brief Information for state of target cannel.
*/
struct CPMsg138 : public COMMMsg
{
	enum { TYPE = 138 };
	
	CPMsg138(void) : COMMMsg(TYPE,sizeof(CPMsg138),GFnumOurCP),
	numAb(0),SubIndex(0),Channel(0),numAirObjCPcu(0),numAirObjCPbd(0),
        ChannelState(0),  PhaseCU(0),PhaseBD(0), ChannelRazmn(0),signRez(0),sign_trouble(0),
	report_sign(0),numZU_AirObj_CP(0),numZU_Pel_CP(0), numZU_AirObj_AB(0), numZU_Pel_AB(0)
	{};

	// Номер абонента
	COUInt8 numAb;
	
	// Индекс подразделения·  1-6· номер подчиненного КП
	COUInt8 SubIndex;
	
	// номер канала РПН
	COUInt8 Channel;
	
	// Номер ВО, по которому поставлено ЦУ в нумерации ЦВМ
	COUInt16 numAirObjCPcu;
	
	// Номер ВО, по которому абонент ведёт боевые действия в нумерации ЦВМ
	COUInt16 numAirObjCPbd;

	// Состояние целевого канала
	COUInt8 ChannelState;
	enum
	{
		FREE                  = 0,  // канал свободен
		CHANNEL_BUZY          = 1,  // канал занят
		NO_TRIG               = 2   // канал не исправен
	};

	// Фаза ЦУ
	COUInt8 PhaseCU;
	enum
	{
		BD_DESTROY_AIR_OBJ		= 0x11, // (ЦУ)
		BD_PROHIBIT_LAUNCH_ROCKET	= 0x24, // Запрет пуска ракеты (ЗП)
		BD_PERMIT_LAUNCH_ROCKET		= 0x33, // Разрешение пуска ракеты (РП)
		BD_SUPPORT_CANSEL_CU		= 0x99 // 
	};

	// Фаза боевых действий
	COUInt8 PhaseBD;
	enum
	{
		BD_NOT_INF			= 0x00,  // нет информации
		BD_SEARCH			= 0x49,  // поиск цели //CPMsg108::AIR_OBJ_SEARCHING = 0x49 (П)
		BD_ESCORT			= 0x46,  // захват на сопровождение //CPMsg108::AIR_OBJ_CAPTURED = 0x46 (СЦ)
		BD_SUPPORT			= 0x48,  // сопровождение и передача координат цели//CPMsg108:: AIR_OBJ_ON_TRACKING = 0x48 (АС)
		BD_RKT_LAUNCHED			= 0x41,  // пуск произведен //CPMsg108::ROCKET_LAUNCHED = 0x41 (СР)
		BD_MITTING			= 0x52,   // встреча//CPMsg108::AIR_OBJ_DESTROYED = 0x52 (Вст)
		BD_CYCLE_END 			= 0x20, // Цикл работы по цели закончен (ЦЗ)
		BD_REJECT 			= 0x55, // Отказ от ЦУ (о-з)
		BD_SUPPORT_MANUAL		= 0x60, // Сопровождение в ручном режиме (РС)
		BD_AO_DESTROYED			= 0x45, // Цель уничтожена (Ун)
		BD_AO_SKIPPED			= 0x43 // Цель пропущена (Проп)
	};

	// номер канала, с которого произошло размножение
	COUInt8 ChannelRazmn;
	
	// признак резервирования канала
	COUInt8 signRez;
	
	// признак наличия помехи
	COUInt8 sign_trouble;

	// признак донесения
	COInt8 report_sign;
	enum
	{
		REPORT_ABS          = 0, // отсутствие донесения;
		REPORT_BEARING      = 4, // отрабатывается целеуказание по пеленгу;
		REPORT_AIR_OBJ_FROM = 8, // отрабатывается целеуказание по ВО;
		REPORT_INDEPENDENT  = 16 // производится самостоятельная боевая работа;
	};

	// Номер ЦУ по ВО (абоненту)
	COUInt8 numZU_AirObj_CP;
	
	// Номер ЦУ по пеленгу (абоненту)
	COUInt8 numZU_Pel_CP;
	
	// Номер ЦУ по ВО (отрабатываемого абонентом)
	COUInt8 numZU_AirObj_AB;
	
	// Номер ЦУ по пеленгу (отрабатываемого абонентом)
	COUInt8 numZU_Pel_AB;

	// тип первой ракеты
	COUInt8 typeRocket1;

	// тип второй ракеты
	COUInt8 typeRocket2;
};

/*! \struct CPMsg158
\brief Information for state of target cannel. (add info)
*/
struct CPMsg158 : public COMMMsg
{
	enum { TYPE = 158 };
	CPMsg158(void) : COMMMsg(TYPE,sizeof(CPMsg158),GFnumOurCP),
	numAb(0),SubIndex(0),nChannelRPN(0),AddSigns(0)
	{};
	
	COUInt8 numAb;
	COUInt8 SubIndex;
	
	COUInt8 nChannelRPN;

	// Номер цели в системе нумерации ВКП (Номер ЦУ)
	COUInt16 vkpAirObjNum;

	COUInt8 AddSigns;
	enum
	{
		PrPr = 1, // признак проведения проверки соответствия Дцу и Дц ( ПрПр )
		CoordDifference = 1 << 1, // признак отличия кооднинат цели и координат ЦУ более чем на 3 км ( Д* )
		IncorrectDistance = 1 << 2, // признак отсутствия достоверной дальности ( Д- )
		ASfi = 1 << 3 // признак автоматического сопровождения цели по углам и ручного сопровождения по дальности и скорости ( АСфи )
	};

};



//точка перехвата
struct CPMsg152 : public COMMMsg
{
	enum { TYPE = 152 };

	CPMsg152( void ) : COMMMsg(TYPE, sizeof(CPMsg152), GFnumOurCP),
		numAbon(0), numPoint(0), numObject(0), numFighter(0),x(0),y(0)
	{
	}
	COUInt8 numAbon;

	COUInt8 numPoint;

	COUInt16 numObject;

	COUInt16 numFighter;

	COInt32  x;

	COInt32  y;
};

/*! \struct CPMsg153       Kabina 
\brief azimuth, distance  RPC.
*/
struct CPMsg153 : public COMMMsg 
{
	enum { TYPE = 153};

	CPMsg153(void) : COMMMsg(TYPE,sizeof(CPMsg153),GFnumOurCP),
		azimuth (0),
		Dg (0),
		ChannelSigns (0),


		rSpeed (0),
                Dn (0),
                elevation (0),
                NTarget_CP (0),
                Ncu (0)

		{}
	
	COUInt8 numAb;		// номер абонента
	
	COUInt8 numZRK;		// номер канала
	
	float	azimuth;	// азимут
	
	COUInt32 Dg;		// дальность горизонтальная
	
	COUInt8 ChannelState;
		enum
		{
			NOT_INF               = 0,
			SEARCH                = 1,
			SUPPORT               = 3,
			START                 = 4,
			END                   = 6,
			REJECT                = 7
		};
	
	COUInt8 ChannelSigns;
		enum
		{
			ZU               = 0,		// работа по ЦУ
			INDEPENDACTION   = 1,		// автономные действия
			Pel              = 1 << 1,	// работа канала по постановщику помех
			BG               = 1 << 2	// боеготовность канала
		};

	COInt16 rSpeed;		// радиальная скорость
	COUInt32 Dn;		// дальность наклонная
	float elevation;	// угол места
	COUInt16 NTarget_CP;	// Номер воздушного объекта в системе номеров ЦВМ
	COUInt8	Ncu;		// Номер ЦУ
};

/*! \struct CPMsg154       APK
\brief Battle operation by air object.
*/
struct CPMsg154 : public COMMMsg 
{
	enum { TYPE = 154};

    CPMsg154(void) : COMMMsg(TYPE,sizeof(CPMsg154),GFnumOurCP) 
    {
    	numAb = 0;
	numZRK = 0;
	numAirObjCP = 0;
	numAirObjAb = 0;
	numUnited = 0;
	data = 0;
	azimuth = 0;
	h = 0;
	v = 0;
	distance = 0;
	type = 0;
	Phase = 0;
	pr_info = 0;	
	res = 0;
	res1 = 0;
	elevation = 0;
    }
	
/*! \var COUInt8 numAb;
\brief Number of abonent.
*/
  COUInt8 numAb;
  
  /*! \var COUInt8 numZRK;
\brief Number of ZRK.
*/
  COUInt8 numZRK;

    /*! \var COUInt8 numAirObjCP;
\brief Number of air object in CP numeration.
*/
  COUInt16 numAirObjCP;

/*! \var COUInt8 numAirObjAb;
\brief Number of air object in abonent numeration.
*/
  COUInt16 numAirObjAb;
  COUInt32 numUnited;   //номер единый 
  COInt64 data;
  float	azimuth;

 /*! \var COInt16 h;
  \brief Height of air object.
  */
  COInt32 h;
  COUInt32 distance;
  /*! \var COInt16 v;
  \brief  velocity .
  */
  COInt16 v;
  COUInt8 type;
  
/*! \var COUInt8 Phase;
\brief Phase of the battle operations.
*/
  COUInt8 Phase;
  
/*! \var COUInt8 pr_info;
\brief sing of report.
*/
  COUInt8 pr_info;
  
  //pr_info
  enum
  {
	  //command on air object to abonent.
	  I_COMMAND_AIR_OBJ_TO = 0x01,
	  //report by air object from abonent.
	  REPORT_AIR_OBJ_FROM= 0x08,
	  //report independent by air object from abonent.
	  REPORT_INDEPENDENT = 0x10
  };
  COInt8 res;
  COInt16 res1;
  float elevation;
};

//azimuth,elevation,distance of Target's
//Ustirovka KABINA 
struct CPMsg156V{
	CPMsg156V(void)
	{	
		memset( this, 0, sizeof(CPMsg156V) );			
	}

  COUInt16 numAb;
  
  COUInt16 numZRK;

  float	azimuth;

  float elevation;

  COUInt32 distance;
};

struct CPMsg156C{
 
 COUInt16 numAirObjCP;
};

/*! \struct CPMsg156
\brief Ustirovra of Targets.
*/
struct CPMsg156 : public varmsg< CPMsg156C, COUInt32, CPMsg156V, 7 >{
  enum { TYPE = 156 };
	  
  CPMsg156( void ) : varmsg<CPMsg156C, COUInt32, CPMsg156V, 7> ( TYPE ){};
};

/*! \struct CPMsg157
\brief Regimes from HCP.
*/
struct CPMsg157 : public COMMMsg{
  enum { TYPE = 157 };

  CPMsg157( void ) : COMMMsg( TYPE, sizeof( CPMsg157 ), GFnumOurCP ),
	  reg_alert( CPMsg157::NOT_SET_REGIME ),\
	  reg_radiation( CPMsg157::NOT_SET_REGIME ), \
	  reg_regime( CPMsg157::NOT_SET_REGIME ), \
	  reglament( CPMsg157::NOT_SET_REGLAMENT ),
	  work_by_NVO( CPMsg157::NOT_SET_REGIME ){}
// not set signs...
  enum{
//"not set value" for regime.
	  NOT_SET_REGIME = 0,
//"not set value" for reglament.
	  NOT_SET_REGLAMENT = 255
  };
  /*! \var COUInt8 numAb;
  \brief Number of abonent.
  */
    COUInt8 numAb;

    /*! \var COUInt8 numZRK;
  \brief Number of ZRK.
  */
    COUInt8 numZRK;

// type of data
  COUInt8 data_type; 
  enum{
		DT_FROM_HCP = 0x01, // получено от ВКП
		DT_FROM_CVM_TO_F2 = 0x02, // на АРМ об изменениях устанавливаемых с ЦЭВМ на Ф2
		DT_FROM_F2 = 0x03 // получено от Ф2
  };

// update info
  COUInt8 update_mask;  
  enum
  {
	  UPD_WORK_REG 		= 1,
	  UPD_TREVOGA 		= 1 << 1,
	  UPD_REGULATION 	= 1 << 2,
	  UPD_RADIO_FREQNS 	= 1 << 3,
	  UPD_WORK_BY_NVO 	= 1 << 4
  };

// regime ALERT - trevoga.  
  COUInt8 reg_alert; 
  enum{
	  NOT_Trevoga = 1,		
	  YES_Trevoga = 2	  
  };  

// regime RADIATION - izluchenie.
  COUInt8 reg_radiation; 
  enum{
	  IZL_full_radiation = 3,	//отсутствие запретов
	  IZL_not_radiation  = 5,	//запрет излучения
	  IZL_low_radiation  = 6  //изл. с мал. мощностью
  };	

// regime REGIME of.  
  COUInt8 reg_regime; 
  enum{				
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
  COUInt8 reglament; 

//признак работы с низковысотным обнаружителем
  COUInt8 work_by_NVO;
  enum{ 			
	  //Без НВО.
	  RPN_not_nvo = 0,		
	  //С НВО.
	  RPN_yes_nvo = 1
  };
 
};

//*************************************************
//*    Кодировка сетки ПВО                        * 
//*************************************************

struct Kodirovka
{
	Kodirovka()
	{
		memset(this, 0, sizeof(Kodirovka));
	}
/*! \var COUInt8 Num_k_zoni;
	\brief номер k-й зоны.
*/	
  COUInt8 Num_zoni;
  
/*! \var COUInt8 Kod_k_zoni;
	\brief код k-й зоны.
*/	
  COUInt8 Kod_zoni;

/*! \var COUInt16 KodiSek_zoni;
	\brief коды секторов k-й зоны.
*/	
  COUInt8 KodiSek_zoni[10];
  
/*! \var COUInt8 Kod_BK;
	\brief коды больших квадратов 0-го - 9-го сектора к-й зоны.
*/	
  COUInt8 Kod_BK_Sek[10][10];

  //void set_zone(TZoneKodi z) {}//KodiSek_zoni=z;}
  //TZoneKodi get_zone() {return KodiSek_zoni;}
  /*
  COUInt8 Kod_BK_Sek0[10];
  COUInt8 Kod_BK_Sek1[10];
  COUInt8 Kod_BK_Sek2[10];
  COUInt8 Kod_BK_Sek3[10];
  COUInt8 Kod_BK_Sek4[10];
  COUInt8 Kod_BK_Sek5[10];
  COUInt8 Kod_BK_Sek6[10];
  COUInt8 Kod_BK_Sek7[10];
  COUInt8 Kod_BK_Sek8[10];
  COUInt8 Kod_BK_Sek9[10];
  */
};





// Message Q request for server
struct CPMsg200 : public COMMMsg
{
	enum { TYPE = 200 };
	
	CPMsg200( void ) : COMMMsg(TYPE, sizeof(CPMsg200), 0) {}
};

// Message R from CPM
struct CPMsg201 : public COMMMsg
{
	enum { TYPE = 201 };
	
	COUInt16 nomPortSrv;
	
	CPMsg201() : COMMMsg(TYPE, sizeof(CPMsg201), GFnumOurCP){}
};

// Message K from Client
struct CPMsg202 : public COMMMsg
{
	enum { TYPE = 202};
	
	COUInt8 nomAbonnetwork;
	
	CPMsg202() : COMMMsg(TYPE, sizeof(CPMsg202), GFnumOurCP){}
};

// Message C from   Client
struct CPMsg203 : public COMMMsg
{
	enum { TYPE = 203};
	
	COUInt8 request;
	//
	enum E203_request{
		E203_r_request = 0x01,
		E203_r_answer = 0x02
	};
	
	CPMsg203() : COMMMsg(TYPE, sizeof(CPMsg203), 0){}
};


// Message 218 Logout_for_SFK

struct CPMsg218 : public COMMMsg
{
	enum { TYPE = 218};

	CPMsg218() :
	 COMMMsg( TYPE, sizeof(CPMsg218), GFnumOurCP )
	{
		 msgdstID = COMMnumSFK;
	}
};

//
// Message from DataBase
//

/*! \struct CPMsg210 CPMsg.h
\brief Message 210 (Inquiry of data)
*/
struct CPMsg210 : public COMMMsg
{
  enum { TYPE = 210 };

  CPMsg210( void ) : COMMMsg(TYPE, sizeof(CPMsg210), 0) {}

  /*! \var COUInt8 dttp;
  \brief Data type.
  */
  COUInt8 dttp;

	/*! \var COUInt8 pr1;
  \brief Parameter 1.
  */
  COUInt8 pr1;

	/*! \var COUInt8 pr2;
  \brief Parameter 2.
  */
	COUInt8 pr2;

	/*! \var COUInt8 pr3;
  \brief Parameter 3.
  */
  COUInt8 pr3;

};

/*! \struct CPMsg211 CPMsg.h
\brief Message 211 (inquiry answer)
*/
struct CPMsg211 : public COMMMsg
{
  enum { TYPE = 211 };

  CPMsg211( void ) : COMMMsg(TYPE, sizeof(CPMsg211), 0) {}

  /*! \var COUInt8 dttp;
  \brief Asked data type.
  */
  COUInt8 dttp;

	/*! \var COUInt8 pr1;
  \brief Parameter 1.
  */
  COUInt8 pr1;

	/*! \var COUInt8 pr2;
  \brief Parameter 2.
  */
	COUInt8 pr2;

	/*! \var COUInt8 pr3;
  \brief Parameter 3.
  */
  COUInt8 pr3;
};

/*! \struct CPMsg212 CPMsg.h
\brief Message 212 (change abonent point)
*/
struct CPMsg212 : public COMMMsg
{
  enum { TYPE = 212 };

  CPMsg212( void ) : COMMMsg(TYPE, sizeof(CPMsg212), 0) {}

  /*! \var COUInt8 number;
  \brief Number abonent.
  */
  COUInt8 number;

  /*! \var COUInt8 number;
  \brief Number abonent.
  */
  COUInt8 type;//1-

  /*! \var COUInt8 pr1;
  \brief Parameter 1.
  */
  COUInt32 x;
  COUInt32 y;
  COUInt32 h;
};

struct CPMsg214_C{
	CPMsg214_C( void ){
		::memset( this, 0, sizeof( CPMsg214_C ) );
		m_cnt_app = 1;
		m_readiness = 1;
	}
	//Функциональная роль данной ЦВМ("1/0"-"master/slave").
	COUInt8 m_CVM_role;
	//Состояние соединения в кластере("1/0"-"disconnect/connect").
	COUInt8 m_CVM_2_CVM_sgn;
	//Количество приложений
	COUInt8 m_cnt_app;
	//Имя приложения.
	char m_name[17];
	//Признак готовности приложения("1/0"-"ready/standby").
	COUInt8 m_readiness;
};

struct CPMsg214_V{
	CPMsg214_V( void ){
		::memset( this, 0, sizeof( CPMsg214_V ) );
	}
	//Идентификатор клиента(51h-58h - terminals, 41h-44h - MSD ).
	COUInt8 m_ID;
	//Состояние соединения с клиентом("1/0"-"connect/disconnect").
	COUInt8 m_cnnct_condition;
};

/*! \struct CPMsg214 CPMsg.h
\brief Message 214 (change abonent point)
*/
struct CPMsg214 : public varmsg< CPMsg214_C, COUInt8, CPMsg214_V, 12 >
{
	enum{ TYPE = 214 };

	CPMsg214( void ) : varmsg< CPMsg214_C, COUInt8, CPMsg214_V, 12 >( TYPE ) {
		msgsrcID = GFnumOurCP;
		msgdstID = COMMnumSFK;
	}
};

/*! \struct CPMsg220 CPMsg.h

\brief Message 220 (Points of abonents standing)
*/
struct CPMsg220 : public COMMMsg
{
  enum { TYPE = 220 };

  CPMsg220( void ) : COMMMsg(TYPE, sizeof(CPMsg220), 0) {}

  /*! \var COUInt8 abnum;
  \brief Number of abonents.
  */
  COUInt8 abnum;
	
	struct abData
	{
		/*! \var COUInt8 abcode;
		\brief Abonent code.
		*/
		COUInt8 abcode;

		/*! \var COInt32 x1;
		\brief X1.
		*/
		COInt32 x1;

		/*! \var COInt32 y1;
		\brief Y1.
		*/
		COInt32 y1;

		/*! \var COInt32 h1;
		\brief H1.
		*/
		COInt32 h1;
	};

	/*! \var abData abdata[14];
  \brief Information for the every abonent.
  */
	abData abdata[15];
};

/*! \struct CPMsg221 CPMsg.h
\brief Message 221 (Characteristics of sectors)
*/
struct CPMsg221 : public COMMMsg
{
  enum { TYPE = 221 };

  CPMsg221( void ) : COMMMsg(TYPE, sizeof(CPMsg221), 0) {}

  /*! \var COUInt8 sectype;
  \brief Type of sector.
  */
  COUInt8 sectype;

  /*! \var COUInt16 secsize;
  \brief Sector size.
  */
  COUInt16 secsize;

  /*! \var COInt8 minang;
  \brief Minimum place angle.
  */
  COInt8 minang;

	/*! \var COInt8 maxang;
  \brief Maximum place angle.
  */
  COInt8 maxang;

	/*! \var COInt32 minrang;
  \brief Minimum range.
  */
  COInt32 minrang;

	/*! \var COInt32 maxrang;
  \brief Maximum range.
  */
  COInt32 maxrang;	
};

/*! \struct CPMsg222 CPMsg.h
\brief Message 222 (Source errors)
*/
struct CPMsg222 : public COMMMsg
{
  enum { TYPE = 222 };

  CPMsg222( void ) : COMMMsg(TYPE, sizeof(CPMsg222), 0) {}

  /*! \var COUInt8 nstype;
  \brief Number of source type.
  */
  COUInt8 nstype;


	struct errData
	{
		/*! \var COUInt8 stype1;
		\brief Type of source1.
		*/
		COUInt8 stype1;

		/*! \var COUInt8 azserr;
		\brief Azimuth source1 error.
		*/
		COUInt8 azserr;

		/*! \var COUInt8 serrap;
		\brief Source1 error in angle of place .
		*/
		COUInt8 serrap;

		/*! \var COUInt8 rgserr;
		\brief Range source1 error.
		*/
		COUInt8 rgserr;

		/*! \var COUInt8 spserr;
		\brief Speed source1 error.
		*/
		COUInt8 spserr;	
	};

	/*! \var errData errdata[14];
  \brief Information for the every source error.
  */
	errData abdata[14];
};

/*! \struct CPMsg223 CPMsg.h
\brief Message 223 (Ballistic coefficient)
*/
struct CPMsg223 : public COMMMsg
{
  enum { TYPE = 223 };

  CPMsg223( void ) : COMMMsg(TYPE, sizeof(CPMsg223), 0) {}

  /*! \var COUInt8 bttype;
  \brief Ballistic target type.
  */
  COUInt8 bttype;

  /*! \var COUInt8 thrang;
  \brief Throwing angle.
  */
  COUInt8 thrang;

  /*! \var COInt32 thrh;
  \brief Throwing hight.

  */

  COInt32 thrh;

  /*! \var COUInt16 thrsp;
  \brief Throwing speed.
  */
  COUInt16 thrsp;

	/*! \var COUInt8 numpn;
  \brief Number of points.
  */
  COUInt8 numpn;

	struct pointData
	{
		/*! \var COInt32 hpoint;
		\brief Hight of 1 point.
		*/
		COInt32 hpoint1;
		COInt32 hpoint2;

		/*! \var COUInt16 sppoint;
		\brief Speed of 1 point.
		*/
		COUInt16 sppoint1;		
		COUInt16 sppoint2;		

		/*! \var float sppoint;
		\brief Ballistic coefficient of 1 point.
		*/
		float bcpoint;		

	};
	
	/*! \var pointData ptdata[100];
  \brief Information for the every point.
  */
	pointData ptdata[100];
};

/*! \struct CPMsg224 CPMsg.h
\brief Message 224 (Characteristic of S-300)
*/
struct CPMsg224 : public COMMMsg
{
  enum { TYPE = 224 };

  CPMsg224( void ) : COMMMsg(TYPE, sizeof(CPMsg224), 0) {}

  /*! \var COUInt8 wtime;
  \brief Working time of S-300.
  */
  COUInt8 wtime;

  /*! \var COUInt8 marktime;
  \brief Time of result marking of shooting.
  */
  COUInt8 marktime;
};

/*! \struct CPMsg225 CPMsg.h
\brief Message 225 (Covered objects)
*/
struct CPMsg225 : public COMMMsg
{
  enum { TYPE = 225 };

  CPMsg225( void ) : COMMMsg(TYPE, sizeof(CPMsg225), 0) {}

  /*! \var COUInt8 idobj;
  \brief object ID.
  */
  COUInt8 idobj;

  /*! \var float objsig;
  \brief Object significance.
  */
  float objsig;

	/*! \var COUInt8 btgord;
  \brief Ballistic target 1 order.
  */
  COUInt8 btgord1;

	/*! \var COUInt8 btgord;
  \brief Ballistic target 2 order.
  */
  COUInt8 btgord2;

  /*! \var COUInt8 btgord;
  \brief Ballistic target 3 order.
  */
  COUInt8 btgord3;

	/*! \var COUInt8 adtord;
  \brief Aerodynamic target order.
  */
  COUInt8 adtord;

	/*! \var COUInt8 cmsord;
  \brief Cruise missile order.
  */
  COUInt8 cmsord;

	/*! \var COUInt8 nposp;
  \brief Number of position points.
  */
  COUInt8 nposp;
	

	struct points
	{
		/*! \var COInt32 xpoint;
		\brief X point.
		*/
		COInt32 xpoint;

		/*! \var COInt32 ypoint;
		\brief Y point.
		*/
		COInt32 ypoint;

		/*! \var COInt32 zpoint;
		\brief Z point.
		*/
		COInt32 zpoint;
	};
	/*! \var points pts[10];
  \brief Points data.
  */
	points pts[10];
};

/*! \struct CPMsg226 CPMsg.h
\brief Message 226 (Hide angle)
*/
struct CPMsg226 : public COMMMsg
{
  enum { TYPE = 226 };

  CPMsg226( void ) : COMMMsg(TYPE, sizeof(CPMsg226), 0) {}

  /*! \var COUInt8 idobj;
  \brief object ID. 
  */
  COUInt8 idobj;

  /*! \var COUInt16 azth;
  \brief Azimuth.
  */
  COUInt16 azth;

	/*! \var COUInt8 hcent;
  \brief Hight of center.
  */
  COUInt8 hcent;

	/*! \var COUInt16 numpoint;
  \brief Number of points.
  */
  COUInt16 numpoint;
	
	struct pointsData
	{
		/*! \var COInt32 dist;
		\brief Distance.
		*/
		COInt32 dist;

		/*! \var float hideang;
		\brief Hide angle.
		*/
		float hideang;
	};
	/*! \var pointsData ptsdata[200];
  \brief Points data.
  */
	pointsData ptsdata[100];
};

/*! \struct CPMsg227 CPMsg.h
\brief Message 227 (Additional parameters of missile)
*/
struct CPMsg227 : public COMMMsg
{
  enum { TYPE = 227 };

  CPMsg227( void ) : COMMMsg(TYPE, sizeof(CPMsg227), 0) {}

  /*! \var COUInt8 mistype;
  \brief Missile type. 
  */
  COUInt8 mistype;

  /*! \var COInt32 minhight;
  \brief Minimum hight of defeat zone.
  */
  COInt32 minhight;

	/*! \var COInt32 maxhight;
  \brief Maximum hight of defeat zone.
  */
  COInt32 maxhight;

	/*! \var COInt32 minrange;
  \brief Minimum range of defeat zone.
  */
  COInt32 minrange;
	
	/*! \var COInt32 maxrange;
  \brief Maximum range of defeat zone.
  */
  COInt32 maxrange;
	
	/*! \var COUInt16 avspeed;
  \brief Average missile speed.
  */
  COUInt16 avspeed;

	/*! \var float dfprobbt;
  \brief Defeat probability of ballistic target.
  */
  float dfprobbt;

	/*! \var float dfprobat;
  \brief Defeat probability of aerodynamic target.
  */
  float dfprobat;
};

/*! \struct CPMsg228 CPMsg.h
\brief Message 228 (Defeat zone)
*/

struct CPMsg228 : public COMMMsg
{
  enum { TYPE = 228 };

  CPMsg228( void ) : COMMMsg(TYPE, sizeof(CPMsg228), 0) {}

  /*! \var COUInt8 mistype;
  \brief Missile type. 
  */
  COUInt8 mistype;

	/*! \var COUInt8 tgType;
  \brief Zone type. 
  */
  COUInt8 zoneType;

	/*! \var COUInt8 maxCrsAngle;
  \brief Maximum course angle. 
  */
  COUInt8 maxCrsAngle;

	/*! \var COInt32 maxCrsParam;
  \brief Maximum course parameter. 
  */
  COInt32 maxCrsParam;

	/*! \var COUInt16 maxSpeed;
  \brief Maximum speed. 
  */
  COUInt16 maxSpeed;

	/*! \var COUInt16 minSpeed;
  \brief Minimum speed. 
  */
  COUInt16 minSpeed;

	/*! \var COUInt8 numPoint;
  \brief Number of zone points. 
  */
  COUInt8 numPoint;

	struct pointsData
	{
		/*! \var COInt32 pointDist;
		\brief Point distance. 
		*/
		COInt32 pointDist;
	
		/*! \var COInt32 pointHight;
		\brief Point hight. 
		*/
		COInt32 pointHight;
	};
	/*! \var pointsData ptsdata[16];
  \brief Points data.
  */
	pointsData ptsdata[16];
};

struct CPMsg1999 : public COMMMsg
{
	enum 
	{ TYPE = 1999 };

	CPMsg1999( int src = 0 ) : COMMMsg(TYPE, sizeof(CPMsg1999), src) 
	{
		m_srcid = 0;
	}
	
	COUInt16 m_srcid;
};

//
//  Message from Gateway
//

/*! \struct struct CPMsg255
\brief Staff of abonent.
*/
struct CPMsg255 : public COMMMsg
{
  enum { TYPE = 255 };

  CPMsg255(void) : COMMMsg(TYPE,sizeof(CPMsg255),GFnumOurCP) {}

/*! \var COUInt16 staff;
\brief Staff of abonent.
*/
  COUInt16 staff;

};

#pragma pack (pop)

#endif //_CPMsg_h_










































