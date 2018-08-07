#ifndef _CPGFMsg_h_
#define _CPGFMsg_h_

#include <memory.h>
#include "COMMMsg.h"
#include "GFconst.h"
#include "CODefine.h"
#include "CPMsg.h"

#pragma pack (push,1)

/*************************************************
//* Команда или донесение на команнду общего типа *
//* от абонентов типа ВКП, ВзКП, ЗРДН, ИРЛИ.	  * 
//*************************************************

/*! \struct CPMsg004 CPGFMsg.h
\brief Message4 (relating " command and report on general command")
*/

struct CPMsg004 : public COMMMsg
{
  enum { TYPE = 4 };		
  
  CPMsg004( void ) : COMMMsg(TYPE, sizeof(CPMsg004),GFnumOurCP),signVid_KO(0),
  signComRep(0){}
 
/*! \var COUInt8 numAbon;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SudIndex;
\brief Индекс подразделения: 0-командный пункт,1-6 номер подчиненного КП.
*/ 
  COUInt8 SubIndex;

/*! \var COUInt32 x;
\brief x точки высветки
*/
  COInt32 x;

/*! \var COUInt32 y;
\brief y точки высветки
*/
  COInt32 y;

/*! \var COUInt8 signVid_KO;
\brief признак выдачи КО.
*/
  COUInt8 signVid_KO;  
  enum
  {   
   INFO_KO_Del = 1   // Снять выдачу КО
  };

 /*! \var COUInt8 signComRep;
\brief признак выдачи команды(донесения)общего типа.
*/
  COUInt8 signComRep;  
  enum
  {
   INFO_KO = 0,   //  КО
   INFO_DKO = 1,   //  ДКО
   INFO_Q = 32	//kvitanciya
  };


/*! \var COUInt8 comrep;
\brief Код команды(донесения)общего типа
*/
  COUInt8 com;
  enum
  {
	HIGHLY_READY = 1,
	USUAL_READY = 2,
   	//Боевой.
	FIGHT_OFF = 3,
	//Дежурный.
	DUTY_OFF = 4,		
	//Тренаж.
	TRAIN_OFF = 6,	
	//Контроль
	CONTR_OFF = 7,	
	//режим пусковой установки
   	RPU_OFF = 14, 
    	RPU_ON  = 94,
	//режим чужого подсвета
   	CHP_OFF = 15,
    	CHP_ON  = 95,
	//режим триангуляции
    	TRG_OFF = 16,
    	TRG_ON  = 96,
	//режим управления излучением
    	RAD_OFF = 20,
    	RAD_ON  = 19	
  };
  COUInt8 rep;
  COUInt8 par;
};

struct CPMsg005C
{	
/*! \var COUInt8 numAbonFromTo;
  \brief номер абонента приславшего/получающего сообщение
*/
 // COUInt8 numAbon_VKP;
 COUInt8 numAbonFromTo;
  
/*! \var COUInt8 SubIndexAbonFromTo;
\brief номер подабонента приславшего/получающего сообщение: 0-командный пункт,1-6 номер подабонента .
*/ 
//  COUInt8 SubIndex;  
  COUInt8 SubIndexAbonFromTo;

/*! \var COUInt8 numAbonAbout;
  \brief номер абонента, о котором прислана информация
*/
  //COUInt8 numAbon;
	COUInt8 numAbonAbout;
 
/*! \var COUInt8 SubIndexAbonAbout;
\brief номер подабонента, о котором прислана информация: 0-командный пункт,1-6 номер подабонента .
*/ 
  //COUInt8 SubIndexAbon;
	COUInt8 SubIndexAbonAbout;

/*! \var COUInt8 gttFreeTC;
  \brief свободные целевые каналы.
*/
	COUInt8 gttFreeTC;

/*! \var COUInt16 gttTC;
  \brief боеготовые целевые каналы.
*/
	COUInt8 gttTC;
};

struct CPMsg005V
{
	CPMsg005V(void)
	{	
		memset( this, 0, sizeof(CPMsg005V) );
	}

/*! \var COUInt8 typeTK;
  \brief тип пусковой установки.
*/
	COUInt16 typeTK;
	 
/*! \var COUInt16 gttRct;
  \brief количество ракет на пусковой установке.
*/
	COUInt16 qttRct;	
};

struct CPMsg005 : public varmsg<CPMsg005C, COUInt16, CPMsg005V, GFqttTypeTK>
{
	enum { TYPE = 5 };		
  
	CPMsg005( void ) :
		varmsg<CPMsg005C, COUInt16, CPMsg005V, GFqttTypeTK> (TYPE)
		{ }

		enum{
			Type_TK_P = 21,
			Type_TK_K = 22
		};

};

struct CPMsg008 : public COMMMsg
{
  enum { TYPE = 8 };
					
  CPMsg008( void ) :
  COMMMsg(TYPE, sizeof(CPMsg008),GFnumOurCP) {
	reserv = 0;
	}
/*! \var COUInt8 numAbon;
  \brief Number of the Abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SudIndex;
\brief Индекс подразделения: 0-командный пункт,1-6 номер подчиненного КП.
*/ 
  COUInt8 SubIndex;
  
/*! \var COUInt8 ;
  \brief Спецификация информации.
*/
   COUInt8 Sign;
   enum{
	   INFO_SignP = 1,	//признак полушария
	   INFO_SignU = 1 << 1,	//признак удаления
	   INFO_SignM = 1 << 2,	//признак меридиана
	   INFO_SignY = 1 << 3,  //признак Y
	   INFO_SignX = 1 << 4   //признак X
   };   
 
   COUInt8 reserv;

/*! \var COUInt8 nz;
\brief  Номер зоны.
*/
  COUInt8 nz;

/*! \var COUInt16 H;
\brief  Высота.
*/  
  COUInt16 H;

/*! \var COUInt32 X;
\brief  Координата X.
*/
  COUInt32 X;

/*! \var COUInt32 Y;
\brief  Координата Y.
*/
  COUInt32 Y;
};

//*****************************************
//*		Точка стояния абонента            *
//*****************************************
/*! \struct CPMsg009
\brief Message 9
 (relating "position of abonents" relatively fixed point command post).
*/

struct CPMsg009 : public COMMMsg
{
  enum { TYPE = 9 }; 
  
  CPMsg009( void ) : COMMMsg(TYPE, sizeof(CPMsg009),GFnumOurCP){} 

/*! \var COUInt8 numAbon;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief Индекс подразделения: 0-командный пункт,1-6 номер подчиненного КП.
*/ 
  COUInt8 SubIndex;

/*! \var COInt32 x;
\brief x точки стояния
*/
  COInt32 x;

/*! \var COInt32 y;
\brief y точки стояния
*/
  COInt32 y;

/*! \var COUInt32 h;
\brief h точки стояния
*/
   COUInt32 h;  
};

//*****************************************
//*		Сквозной контроль связи           *
//*****************************************
/*! \struct CPMsg013
\brief Message 13 
*/
#if !defined(KABINA_K9) & !defined(PROTOK_5N83) & !defined(PROTOK_5N63)
struct CPMsg013 : public COMMMsg
{
  enum { TYPE = 13 }; 
  
  CPMsg013( void ) : COMMMsg(TYPE, sizeof(CPMsg013),GFnumOurCP){} 

/*! \var COUInt8 numAbon;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
/\brief Индекс подразделения: 0-командный пункт,1-6 номер подчиненного КП.
*/ 
  COUInt8 SubIndex;

/*! \var COInt32 x;
\brief x 
*/
  COInt32 x;

/*! \var COInt32 y;
\brief y 
*/
 COInt32 y;
};
#endif
//***************************************
//*	  Донесение о боеготовности С-300П	*
//***************************************
/*! \struct CPMsg014
\brief Message 14 
*/

struct CPMsg014 : public COMMMsg
{
  enum { TYPE = 14 }; 
  
  CPMsg014( void ) : COMMMsg(TYPE, sizeof(CPMsg014),GFnumOurCP){} 

/*! \var COUInt8 numAbon;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief Индекс подразделения: 0-командный пункт,1-6 номер подчиненного КП.
*/ 
  COUInt8 SubIndex;

  struct Alert_C300P
  {	
	COUInt8 regulation;	
	COUInt8 gttTC;		//BCK
  };
  Alert_C300P arrAlert[6];
};

//*****************************************************
//*	  Донесение об ограничениях на разворот РПН С-300П*
//*****************************************************
/*! \struct CPMsg015
\brief Message 15 
*/

struct CPMsg015 : public COMMMsg
{
  enum { TYPE = 15 }; 
  
  CPMsg015( void ) : COMMMsg(TYPE, sizeof(CPMsg015),GFnumOurCP){}	  

/*! \var COUInt8 numAbon;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief Индекс подразделения: 0-командный пункт,1-6 номер подчиненного КП.
*/ 
  COUInt8 SubIndex;

  struct Azim
	{	
		COFloat32 Azimut;		
	};
  Azim arrAzim[6];

  struct Limit
	{				
		COUInt8 KO;	//признак ограничения по развороту сек. РПН 
	};
  Limit arrLimit[6];
};

//**********************************************************
//*	  Донесение о режимах работы и боеготовности ЗРК С-300П*
//**********************************************************
/*! \struct CPMsg016
\brief Message 16 
*/

struct CPMsg016 : public COMMMsg
{
  enum { TYPE = 16 }; 
  
  CPMsg016( void ) : COMMMsg(TYPE, sizeof(CPMsg016),GFnumOurCP){} 

/*! \var COUInt8 numAbon;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief Индекс подразделения: 0-командный пункт,1-6 номер подчиненного КП.
*/ 
  COUInt8 SubIndex;

/*! \var COUInt8 rezerv;
\brief rezerv.
*/
  COUInt8 rezerv;

/*! \var COUInt8 SignS;
\brief Признаки работы ЗРК.
*/
  COUInt8 Signs;
  enum{
	   INFO_BETTA = 1,	//ручное управление(следуй за бетта)
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

//*************************************
//*	  Донесение о текущих режимах СОУ *
//*************************************
/*! \struct CPMsg017
\brief Message 17 
*/

struct CPMsg017 : public COMMMsg
{
  enum { TYPE = 17 }; 
  
  CPMsg017( void ) : COMMMsg(TYPE, sizeof(CPMsg017),GFnumOurCP){} 

/*! \var COUInt8 numAbon;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief Индекс подразделения: 0-командный пункт,1-6 номер подчиненного КП.
*/ 
  COUInt8 SubIndex;

/*! \var COUInt8 Regim_work;;
\brief режим работы СОУ.
*/
  COUInt8 Regim_work;

/*! \var COUInt8 Regim_current;
\brief специальный режим работы СОУ.
*/
  COUInt8 Regim_current;

/*! \var COUInt8 Regim_target;
\brief режим работы по целям.
*/
  COUInt8 Regim_target;
};

//***********************************
//*	  Выделение целевых каналов		*
//***********************************
/*! \struct CPMsg023
\brief Message 23 
*/

struct CPMsg023 : public COMMMsg
{
  enum { TYPE = 23 }; 
  
  CPMsg023( void ) : COMMMsg(TYPE, sizeof(CPMsg023),GFnumOurCP){} 

/*! \var COUInt8 numAbon;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief Индекс подразделения: 0-командный пункт,1-6 номер подчиненного КП.
*/ 
  COUInt8 SubIndex;

/*! \var COUInt8 com;
\brief код команды общего типа1.
*/
  COUInt8 com;

/*! \var COUInt8 TK;
\brief тип пусковой установки.
*/
  COUInt8 TK;

/*! \var COUInt8 gttTC;
\brief БЦК для самостоятельных действий.
*/
  COUInt8 gttTC;
};

//***********************************
//*	  Управление ренжимами РПН		*
//***********************************
/*! \struct CPMsg024
\brief Message 24 
*/

struct CPMsg024 : public COMMMsg
{
  enum { TYPE = 24 };

  CPMsg024( void ) : COMMMsg(TYPE, sizeof(CPMsg024),GFnumOurCP), 
Sign(0),
numAbon(1),
SubIndex(0),
com_RegWork(0),
com_Trevoga(CPMsg024::NOT_Trevoga),
regulation(0),
com_Izluch(0),
Azimut_RPH(0.0),
Azimut_ANTICH(0.0)
{}

/*! \var COUInt8 numAbon;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief Индекс подразделения: 0-командный пункт,1-6 номер подчиненного КП.
*/ 
  COUInt8 SubIndex;

/*! \var COUInt16 Sign;
\brief Sign.
*/
  COUInt16 Sign;
  enum{	  
	  INFO_BETTA = 1,    //дистанционное
	  INFO_ANTICH = 1 << 1   // признак антишпл	
  };
  
/*! \var COUInt8 com_RegWork;
\brief режим работы РПН.
*/
  COUInt8 com_RegWork;
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
/*! \var COUInt8 com_Trevoga;
\brief команда управления.
*/
  COUInt8 com_Trevoga;
  enum{
		NOT_Trevoga = 1,		
		YES_Trevoga = 2	  
  };  
/*! \var COUInt8 regulation;
\brief регламент.
*/
  COUInt8 regulation;
  
/*! \var COUInt8 com_Izluch;
\brief команда включения режимов излучения.
*/
  COUInt8 com_Izluch;
  enum{
		IZL_full_radiation = 3,	//отсутствие запретов
		IZL_not_radiation  = 5,	//запрет излучения
		IZL_low_radiation  = 6  //изл. с мал. мощностью
  };	

/*! \var COUInt32 Azimut_RPH;
\brief азимут биссектрисы сектора РПН (радианы).
*/
  COFloat32 Azimut_RPH;
  
/*! \var COUInt32 Azimut_ANTICH;
\brief азимут запрета захвата низколетящей цели (радианы).
*/
  COFloat32 Azimut_ANTICH;
};


//***********************************
//*	  Режимы функционирования РПН   *
//***********************************
/*! \struct CPMsg026
\brief Message 26 
*/

struct CPMsg026 : public COMMMsg
{
  enum { TYPE = 26 }; 
  
  CPMsg026( void ) : COMMMsg(TYPE, sizeof(CPMsg026),GFnumOurCP),
	  SubIndex(0),
	  Reg_Work(0),
	  N_Chanel_1(0), 
	  N_Chanel_2(0),
	  Azimut_RPH(0.0),
	  Sign_Alert(0),
	  Sign_Trevoga(RPN_not_Trevoga),
	  RPNSectorSize(0),
	  rezerv(0)
  {} 

/*! \var COUInt8 numAbon;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief Индекс подразделения: 0-командный пункт,1-6 номер подчиненного КП.
*/ 
  COUInt8 SubIndex;
  
/*! \var COUInt8 Reg_Work;
\brief режим работы РПН.
*/
  COUInt8 Reg_Work;
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
/*! \var COUInt8 Sign_Trevoga;
\brief тревога принята.
*/
  COUInt8 Sign_Trevoga;
  enum{			
		RPN_not_Trevoga = 1,		
		RPN_yes_Trevoga = 2	
  };

/*! \var COUInt8 Sign_HBO;
\brief признак работы РПН с НВО.
*/
  COUInt8 Sign_HBO;
  enum{ 			
		//Без НВО.
		RPN_not_nvo = 0,		
		//С НВО.
		RPN_yes_nvo = 1
  };
/*! \var COUInt8 Sign_Alert;
\brief признак боеготовности РПН.
*/
  COUInt8 Sign_Alert;
  enum{	 
		//не известно
		RPN_Unk = 0,
		//неисправен.
		RPN_not_ready = 1,	
		//готов.
		RPN_ready = 2
  };

/*! \var COUInt8 N_Chanel_1;
\brief номер целевого канала 1 РПН.
*/
  COUInt8 N_Chanel_1;

/*! \var COUInt8 N_Chanel_2;
\brief номер целевого канала 2 РПН.
*/
  COUInt8 N_Chanel_2;

/*! \var COUInt8 Sektor_RPH;
\brief сектор автономной работы РПН.
*/
  COUInt8 Sektor_RPH;
  
  COUInt8 rezerv;

/*! \var COUInt32 Azimut_RPH;
\brief текущий азимут биссектрисы сектора РПН.
*/
  COFloat32 Azimut_RPH;

/*! \var COUInt16 RPNSectorSize;
\brief размер рабочего сектора РПН (в градусах)
*/
  COUInt16 RPNSectorSize;
};

//********************************************
//*	  Текущее положение рабочего сектора РПН *
//*	  Боезапас ракет						 *
//********************************************
/*! \struct CPMsg027
\brief Message 27 
*/

struct CPMsg027 : public COMMMsg
{
  enum { TYPE = 27 }; 
  
  CPMsg027( void ) : COMMMsg(TYPE, sizeof(CPMsg027),GFnumOurCP),SubIndex(0),gttTC(0),gttRct_C(0),gttRct_P(0),gttRct_K(0)
  {} 

/*! \var COUInt8 numAbon;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief Индекс подразделения: 0-командный пункт,1-6 номер подчиненного КП.
*/ 
  COUInt8 SubIndex;
  
/*! \var COUInt8 gttTC;
\brief количество целевых каналов.
*/
  COUInt8 gttTC;

/*! \var COUInt8 gttRct_C;
\brief количество ракет типа С.
*/
  COUInt8 gttRct_C;

/*! \var COUInt8 gttRct_P;
\brief количество ракет типа Р.
*/
  COUInt8 gttRct_P;

/*! \var COUInt8 gttRct_K;
\brief количество ракет типа К.
*/
  COUInt8 gttRct_K;
};

//*******************************
//*	  Точка стояния РПН			*
//*******************************

/*! \struct CPMsg029
\brief Message 29 
*/

struct CPMsg029 : public COMMMsg
{
  enum { TYPE = 29 }; 
  
  CPMsg029( void ) : COMMMsg(TYPE, sizeof(CPMsg029),GFnumOurCP){} 

/*! \var COUInt8 numAbon;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief Индекс подразделения: 0-командный пункт,1-6 номер подчиненного КП.
*/ 
  COUInt8 SubIndex;
  
/*! \var COInt32 x;
\brief x точки стояния.
*/
  COInt32 x;

/*! \var COInt32 y;
\brief y точки стояния.
*/
  COInt32 y;

/*! \var COUInt32 h;
\brief h точки стояния.
*/
  COInt32 h;
};

//*******************************
//*	  Литер и барабан подсвета  *
//*******************************

/*! \struct CPMsg033
\brief Message 33 
*/

struct CPMsg033 : public COMMMsg
{
  enum { TYPE = 33 }; 
  
  CPMsg033( void ) : COMMMsg(TYPE, sizeof(CPMsg033),GFnumOurCP){} 

/*! \var COUInt8 numAbon;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief Индекс подразделения: 1-6 номер подчиненного КП.
*/ 
  COUInt8 SubIndex;
  
/*! \var COUInt8 Liter_Bar;
\brief Liter_Baraban
*/
  COUInt8 Liter_Bar;  
};

//**************************************
//*	  Донесение о готовности абонента  *
//**************************************

/*! \struct CPMsg036
\brief Message 36 
*/

struct CPMsg036 : public COMMMsg
{
  enum { TYPE = 36 }; 
  
  CPMsg036( void ) : COMMMsg(TYPE, sizeof(CPMsg036),GFnumOurCP){} 

/*! \var COUInt8 numAbon;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief Индекс подразделения: 0-командный пункт,1-6 номер подчиненного КП.
*/ 
  COUInt8 SubIndex;
  
/*! \var COUInt8 KP;
\brief боеготовность КП.
*/
  COUInt8 KP;
  	enum {
		KP_NotInfo_Alert = 0,
		KP_Not_Alert = 1,
		KP_Yes_Alert = 2
};  

/*! \var COUInt8 RLC;
\brief исправность РЛС.
*/
  COUInt8 RLC;
  	enum {
		RLC_NotInfo = 0,
		RLC_Not = 1,
		RLC_Yes = 2
};  

/*! \var COUInt8 COU;
\brief исправность СОУ.
*/
  COUInt8 COU;
  	enum {
		COU_NotInfo = 0,
		COU_Not = 1,
		COU_Yes = 2
};  

/*! \var COUInt8 PZU;
\brief исправность ПЗУ.
*/
  COUInt8 PZU;
  	enum {
		PZU_NotInfo = 0,
		PZU_Not = 1,
		PZU_Yes = 2
};  

/*! \var COUInt8 PIP;
\brief исправность ПИП.
*/
  COUInt8 PIP;
  	enum {
		PIP_NotInfo = 0,
		PIP_Not = 1,
		PIP_Yes = 2
};  
  
/*! \var COUInt8 PZK;
\brief занятость ПЗК.
*/
  COUInt8 PZK;
	 enum {
		PZK_NotInfo = 0,
		PZK_Free = 1,
		PZK_busy = 2
};   
  
/*! \var COUInt8 PPZ;
\brief признак перезапуска.
*/
  COUInt8 PPZ;
  	enum {
		PPZ_NotInfo = 0,
		PPZ_Not = 1,
		PPZ_Yes = 2	
};	
};

//******************************************
//*	  Азимут биссектрисы рабочего сектора  *
//******************************************

/*! \struct CPMsg037
\brief Message 37 
*/

struct CPMsg037 : public COMMMsg
{
  enum { TYPE = 37 }; 
  
  CPMsg037( void ) : COMMMsg(TYPE, sizeof(CPMsg037),GFnumOurCP){} 

/*! \var COUInt8 numAbon;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief Индекс подразделения: 0-командный пункт,1-6 номер подчиненного КП.
*/ 
  COUInt8 SubIndex;
  
/*! \var COUInt32 Azimut_RPH;
\brief азимут биссектрисы текущего сектора РПН.
*/
  COFloat32 Azimut_RPH;  
};


//******************************************
//*                                        *
//******************************************

/*! \struct CPMsg041
\brief Message 41 
*/

struct CPMsg041 : public COMMMsg
{
  enum { TYPE = 41 }; 
  
  CPMsg041( void ) : COMMMsg(TYPE, sizeof(CPMsg041),GFnumOurCP){} 

/*! \var COUInt8 numAbon;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief Индекс подразделения: 0-командный пункт,1-6 номер подчиненного КП.
*/ 
  COUInt8 SubIndex;

/*! \var COUInt8 Sign;
\brief Признак наличия.
*/ 
  COUInt8 Sign;
  
  enum{
	  sgn_send = 41
	  
  };
    
/*! \var COUInt8 m_lKCK;
\brief 
*/ 
  COUInt8 m_lKCK; 
};


//*************************************************
//*    Команда и донесение общего вида            * 
//*************************************************

/*! \struct CPMsg106
\brief General command and report on general command.
*/

struct CPMsg106 : public COMMMsg
{
  enum { TYPE = 106 };

  CPMsg106(void) : COMMMsg(TYPE,sizeof(CPMsg106),GFnumOurCP),
	codeC(0),
	codeR(0),
	lKCK(0)
	{
	}

/*! \var COUInt8 numAbon;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 index;
\brief Индекс подчиненного подразделения.
*/
  COUInt8 SubIndex;

/*! \var COInt32 x;
\brief x относительно реперной точки.
*/
  COInt32 x;

/*! \var COInt32 y;
\brief y относительно реперной точки.
*/
  COInt32 y;

/*! \var COUInt8 info;
\brief Type of transmitted information.
*/
  COUInt8 info;  
  enum
  {
   COMMtoAB     = 0x01,  // команда на абонент
   DEL_COMMtoAB = 0x81,  // delete command too abonent
   REPORTfromAB = 0x02,  // донесение от абонента
   COMMfromAB   = 0x04,  // команда от абонента
   DEL_COMMfromAB = 0x84,// delete command from abonent  
   REPORTtoAB   = 0x08,  // донесение на абонент
   COMMCONTR    = 0x10,  // контроль канала
   REPCONTR     = 0x20,  // донесение на сооб. о контроле канала 
   PREP_ROCKET  = 0x35,  // установить число каналов для непрерывной подготовки ракет
   ABOLCONTR    = 0x40,  // отмена выдачи сооб. о контроле канала 
   REP_CONDITION = 0x80  // донесение о состоянии
  };

/*! \var COUInt8 codeC;
\brief Код команды общего типа
*/
  COUInt8 codeC;
  enum{
		com_fighting_trim  = 0x03, // боевой
		com_on_duty        = 0x04, // дежурный
		com_training =       0x06, // тренаж
		com_control =       0x07, // контроль
		com_not_radiation  = 0x17, // запрет излучения
		com_full_radiation = 0x18, // отмена зап. излучения
		com_low_radiation  = 0x23, // изл. с мал. мощностью
		com_yes_trevoga    = 0x34, // тревога
		com_not_trevoga    = 0x92  // отмена тревоги
  };

/*! \var COUInt8 codeR;
\brief Код донесения на команду общего типа
*/
  COUInt8 codeR;
  enum{
		rep_fighting_trim = 0x03, // боевой
		rep_on_duty       = 0x04, // дежурный
		rep_training      = 0x06, // тренаж
		rep_control      = 0x07, // контроль		
		rep_nvo           = 0x33, // НВО
		rep_yes_trevoga   = 0x34, // тревога
		rep_not_trevoga   = 0x92, // отсутствие тревоги
		rep_not_nvo       = 0x93  // без НВО
  };
  
  //число каналов для непрерывной подготовки ракет (К9МБ)
  // номер реперной точки. (поляна для 9С470МБ)
  COUInt8 lKCK;
};

//**********************************************
//*	Сообщение о реперной точке КП или абонента *
//*                                            *
//**********************************************
/*! \struct CPMsg111
\brief Message 111 (relating  "fixed point")
*/

struct CPMsg111 : public COMMMsg
{
  enum { TYPE = 111 };
		 			
  CPMsg111( void ) :
  COMMMsg(TYPE, sizeof(CPMsg111),GFnumOurCP) {}
  
/*! \var COUInt8 numAbon;
  \brief Number of the Abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 sINF;
  \brief Sign information:01(основная реперная точка)- basic, 
  \                      :02(дополнительная реперная точка)-additional.
*/
  COUInt8 sINF;
  enum { O_FIXP = 01,
         D_FIXP = 02 };  

 /*! \var COUInt8 sh;
  \brief sign hemisphere(признак полушария):0-северное,1-южное.
*/
  COUInt8 sh;

/*! \var COUInt8 nz;
\brief nz = 1-60.
*/
  COUInt8 nz;

/*! \var COUInt16 h;
  \brief height fixed point.
*/
  COUInt16 h;  

/*! \var COUInt32 x;
\brief X.
*/
  COUInt32 x;
    
/*! \var COUInt32 Y;
\brief Y.
*/
  COUInt32 y;
};

struct CPMsg112C
{	
/*! \var COUInt8 numAbon;
  \brief Number of the Abonent.
*/
  COUInt8 numAbon;
  
/*! \var COUInt8 SudIndex;
\brief Индекс подразделения: 0-командный пункт,1-6 номер подчиненного КП.
*/ 
  COUInt8 SubIndex;  

/*! \var COUInt8 regulation;
  \brief регламент.
*/  
  COUInt8 regulation;

/*! \var COUInt8 gttFreeTC;
  \brief свободные целевые каналы.
*/
	COUInt8 gttFreeTC;

/*! \var COUInt16 gttTC;
  \brief боеготовые целевые каналы.
*/
	COUInt16 gttTC;
};

struct CPMsg112V
{
	CPMsg112V(void)
	{	
		memset( this, 0, sizeof(CPMsg112V) );			
	}

/*! \var COUInt8 typeTK;
  \brief тип пусковой установки.
*/
	COUInt16 typeTK;
	 
/*! \var COUInt16 gttRct;
  \brief количество ракет на пусковой установке.
*/
	COUInt16 qttRct;	
};

struct CPMsg112 : public varmsg<CPMsg112C, COUInt16, CPMsg112V, GFqttTypeTK>
{
  enum { TYPE = 112 };		
  
  CPMsg112( void ) :
		varmsg<CPMsg112C, COUInt16, CPMsg112V, GFqttTypeTK> (TYPE)
		{			
		}
};

//****************************************************
//*    Информация о положении КП, положении абонента * 
//****************************************************

/*! \struct CPMsg113
\brief Coordinates of abonents position.
*/

struct CPMsg113 : public COMMMsg
{
  enum { TYPE = 113 };

  CPMsg113(void) : COMMMsg(TYPE,sizeof(CPMsg113),GFnumOurCP){}
  
/*! \var COUInt8 numAb;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief признак командного пункта(КП).
*/
  COUInt8 SubIndex;

/*! \var COInt32 x;
\brief Coordinate X of abonent position.	
*/ 
  COInt32 x;

/*! \var COInt32 y;
\brief Coordinate Y of abonent position.
*/
  COInt32 y;

/*! \var COInt32 h;
\brief Coordinate H of abonent position.
*/
  COInt32 h;
};

//****************************************************
//*    Текущее положение рабочего сектора			 * 
//****************************************************

/*! \struct CPMsg135
\brief Message 135
*/

struct CPMsg135 : public COMMMsg
{
  enum { TYPE = 135 };

  CPMsg135(void) : COMMMsg(TYPE,sizeof(CPMsg135),GFnumOurCP){
	  Azimut_RPH = 0.0; m_half_sector = 0.0; rezerv = 0; Sign_Zoni = 0;
  }
  
/*! \var COUInt8 numAb;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief признак командного пункта(КП).
*/
  COUInt8 SubIndex;

/*! \var COUInt32 Azimut_RPH;
\brief азимут биссектрисы сектора ответственности.
*/
  COFloat32 Azimut_RPH;

  // half size of sector.
  COFloat32 m_half_sector;
  
/*! \var COUInt8 Sign_Zoni;
\brief признак зоны поиска по углу места.
*/
  COUInt8 Sign_Zoni; 

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
  
/*! \var COUInt8 rezerv;
\brief резерв.
*/
  COUInt8 rezerv; 
};
 
//****************************
//*    Литер частот			 * 
//****************************

/*! \struct CPMsg136
\brief Message 136
*/

struct CPMsg136 : public COMMMsg
{
  enum { TYPE = 136 };

  CPMsg136(void) : COMMMsg(TYPE,sizeof(CPMsg136),GFnumOurCP){}
  
/*! \var COUInt8 numAb;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief признак командного пункта(КП).
*/
  COUInt8 SubIndex;

/*! \var COUInt8 Liter_Bar;
\brief литер и барабан передатчика подсвета.
*/
  COUInt8 Liter_Bar;
  
/*! \var COUInt8 Sign_Inf;
\brief источник информации.
*/
  COUInt8 Sign_Inf; 
  enum{
	  INFO_ARM = 1,  //оператор АРМ
	  INFO_COY = 2   //СОУ
  };
};

//********************************************
//*    Донесение о режимах боевой работы РПН * 
//********************************************

/*! \struct CPMsg139
\brief Message 139
*/

struct CPMsg139 : public COMMMsg
{
  enum { TYPE = 139 };

  CPMsg139(void) : COMMMsg(TYPE,sizeof(CPMsg139),GFnumOurCP),
  	Betta_MUP(0),
	RC(0),
	ACFI(0),
	ALKP(0),
	PEL(0),
	ZR(0)
  	{
  	}
  
/*! \var COUInt8 numAb;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief признак командного пункта(КП).
*/
  COUInt8 SubIndex;

/*! \var COUInt8 Betta_MUP;
\brief способ управления рабочим сектором.
*/
  COUInt8 Betta_MUP;

/*! \var COUInt8 PC;
\brief ручное сопровождение.
*/
  COUInt8 RC;

/*! \var COUInt8 ACFI;
\brief сопровождение цели по угловым координатам.
*/
  COUInt8 ACFI;

/*! \var COUInt8 ALKP;
\brief алгоритм компенсации помех.
*/
  COUInt8 ALKP;

/*! \var COUInt8 PEL;
\brief боевые действия по пеленгу.
*/
  COUInt8 PEL;
  
/*! \var COUInt8 ZR;
\brief автоматическое распределение.
*/
  COUInt8 ZR;

};

//**************************************************
//*    Управление специальными режимами работы СОУ * 
//**************************************************

/*! \struct CPMsg140
\brief Message 140
*/

struct CPMsg140 : public COMMMsg
{
  enum { TYPE = 140 };

  CPMsg140(void) : COMMMsg(TYPE,sizeof(CPMsg140),GFnumOurCP){
	  rezerv = 0;
  }
  
/*! \var COUInt8 numAb;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief признак командного пункта(КП).
*/
  COUInt8 SubIndex;
  
/*! \var COUInt8 Regim;
\brief специальные режимы.
*/
  COUInt8 Mode;  

/*! \var COUInt8 Sign;
\brief признак установки режима.
*/
  COUInt8 Sign;
  enum{
	  MODE_CANCEL = 0,  //режим отменен
	  MODE_SETTING = 1  //режим установлен
  };
/*! \var COUInt8 rezerv;
\brief rezerv.
*/
  COUInt8 rezerv;
};

//******************************************
//*    Группирование СОУ для парной работы * 
//******************************************

/*! \struct CPMsg141
\brief Message 141
*/

struct CPMsg141 : public COMMMsg
{
  enum { TYPE = 141 };

  CPMsg141(void) : COMMMsg(TYPE,sizeof(CPMsg141),GFnumOurCP){
	  rezerv = 0;
  }
  
/*! \var COUInt8 numAb;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex1;
\brief признак командного пункта(КП)1.
*/
  COUInt8 SubIndex1;

/*! \var COUInt8 SubIndex2;
\brief признак командного пункта(КП)2.
*/
  COUInt8 SubIndex2;

/*! \var COUInt8 Regim;
\brief режим.
*/
  COUInt8 Regim;

/*! \var COUInt8 Sign_Gr;
\brief признак группирования.
*/
  COUInt8 Sign_Gr;
  
/*! \var COUInt8 rezerv;
\brief резерв.
*/
  COUInt8 rezerv;
};

//*******************************************
//*    Команда и донесение "Боевая тревога" * 
//*******************************************

/*! \struct CPMsg142
\brief Message 142
*/

struct CPMsg142 : public COMMMsg
{
  enum { TYPE = 142 };

  CPMsg142(void) : COMMMsg(TYPE,sizeof(CPMsg142),GFnumOurCP){}
  
/*! \var COUInt8 numAb;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief признак командного пункта(КП).
*/
  COUInt8 SubIndex;

/*! \var COUInt8 Sign_info;
\brief признак информации.
*/
  COUInt8 Sign_info;
  enum{
		COMMtoAB     = 0x01,  // команда на абонент
		REPORTfromAB = 0x02  // донесение от абонента
  };

/*! \var COUInt8 com;
\brief команда.
*/
  COUInt8 com;

/*! \var COUInt8 rep;
\brief донесение.
*/
  COUInt8 rep;
  
/*! \var COUInt8 rezerv;
\brief резерв.
*/
  COUInt8 rezerv;
};

//*******************************************
//*    Донесение о режимах работы СОУ	    * 
//*******************************************

/*! \struct CPMsg143
\brief Message 143
*/

struct CPMsg143 : public COMMMsg
{
  enum { TYPE = 143 };

  CPMsg143(void) : COMMMsg(TYPE,sizeof(CPMsg143),GFnumOurCP){
	  rezerv = 0;
  }
  
/*! \var COUInt8 numAb;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief признак командного пункта(КП).
*/
  COUInt8 SubIndex;

/*! \var COUInt8 Regim_PP;
\brief текущий режим.
*/
  COUInt8 Regim_PP; 

/*! \var COUInt8 Regim_CPP;
\brief специальный режим.
*/
  COUInt8 Regim_CPP;

/*! \var COUInt8 Regim_PPZ;
\brief режим работы по целям.
*/
  COUInt8 Regim_PPZ;
  
/*! \var COUInt8 rezerv;
\brief резерв.
*/
  COUInt8 rezerv;
};

//***********************************************
//*    Донесение о режимах функционирования РПН * 
//***********************************************

/*! \struct CPMsg144
\brief Message 144
*/

struct CPMsg144 : public COMMMsg
{
  enum { TYPE = 144 };

  CPMsg144(void) : COMMMsg(TYPE,sizeof(CPMsg144),GFnumOurCP){}
  
/*! \var COUInt8 numAb;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief признак командного пункта(КП).
*/
  COUInt8 SubIndex;

/*! \var COUInt8 Regim_work;
\brief текущий режим.
*/
  COUInt8 Regim_work; 

/*! \var COUInt8 Sign_work;
\brief признак работы РПН с низковыс. целями.
*/
  COUInt8 Sign_NBO;
	enum{
		//Нет информации о НВО.
		NVO_not_info = 0,			
		//Без НВО.
		NVO_not = 1,		
		//С НВО.
		NVO_yes = 2
  };
};

//***************************************
//*    Донесение о готовности абонента  * 
//***************************************

/*! \struct CPMsg148
\brief Message 148
*/

struct CPMsg148 : public COMMMsg
{
  enum { TYPE = 148 };

  CPMsg148(void) : COMMMsg(TYPE,sizeof(CPMsg148),GFnumOurCP),
	  Alert_CP(0),Alert_RLO(Alert_RLO_NotInfo),Work_COU(0),Work_PZU(0),Work_PIP(0),Work_PPZ(CPMsg148::Work_PPZ_NotInfo){}
  
/*! \var COUInt8 numAb;
\brief Number of abonent.
*/
  COUInt8 numAbon;

/*! \var COUInt8 SubIndex;
\brief признак командного пункта(КП).
*/
  COUInt8 SubIndex;

/*! \var COUInt8 Alert_CP;
\brief признак боеготовности КП.
*/
  COUInt8 Alert_CP;
	enum {
		Alert_CP_NotInfo = 0, //нет информации
		Alert_CP_Not = 1,     //КП не боеготов
		Alert_CP_Yes = 2      //КП боеготов
	};  

/*! \var COUInt8 Alert_RLO;
\brief признак исправности РЛС.
*/
  COUInt8 Alert_RLO;
  	enum {
  		Alert_RLO_NotInfo = 0, //нет информации
		Alert_RLO_Not = 1,     //РЛС неисправна
		Alert_RLO_Yes = 2      //РЛС исправна
  	};
/*! \var COUInt8 Work_COU;
\brief признак исправности СОУ.
*/
  COUInt8 Work_COU;
  	enum {
  		Work_COU_NotInfo = 0, //нет информации
		Work_COU_Not = 1,     //СОУ неисправна
		Work_COU_Yes = 2      //СОУ исправна
  	};

/*! \var COUInt8 Work_PZU;
\brief признак исправности ПЗУ.
*/
  COUInt8 Work_PZU;
  	enum {
  		Work_PZU_NotInfo = 0, //нет информации
		Work_PZU_Not = 1,     //ПЗУ неисправна 
		Work_PZU_Yes = 2      //ПЗУ исправна
  	};

/*! \var COUInt8 Work_PIP;
\brief признак исправности ПИП.
*/
  COUInt8 Work_PIP;
  	enum {		
  		Work_PIP_NotInfo = 0,//нет информации
		Work_PIP_Not = 1,    //передатчик подсвета неисправен
		Work_PIP_Yes = 2     //передатчик подсвета исправенЮ
  	};

/*! \var COUInt8 Work_PPZ;
\brief признак перезапуска.
*/
  COUInt8 Work_PPZ;  
  	enum{		
		Work_PPZ_NotInfo = 0,//Нет информации		
		Work_PPZ_Not = 1,    //Нет перезапуска		
		Work_PPZ_Yes = 2     //Перезапуск
  };
};

//********************************************
//*    Команда на выделение целевых каналов  * 
//********************************************

/*! \struct CPMsg149
\brief Message 149
*/

struct CPMsg149 : public COMMMsg
{
  enum { TYPE = 149 };

  CPMsg149(void) : COMMMsg(TYPE,sizeof(CPMsg149),GFnumOurCP){}
  
/*! \var COUInt8 typeTK;
\brief тип целевого канала.
*/
  COUInt8 typeTK; 

/*! \var COUInt8 gtt_TC;
\brief количество выделенных целевых каналов.
*/
  COUInt8 gtt_TC;
};

#pragma pack (pop)
#endif //_CPGFMsg_h_
