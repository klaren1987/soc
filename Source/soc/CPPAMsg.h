#ifndef _CPPAMsg_h_
#define _CPPAMsg_h_
#include <memory.h>
#include "COcxx.h"
#include "COMMMsg.h"
#include "CPMsg.h"
#pragma pack (push, 1)



// ******* СТРУКТУРА СООБЩЕНИЙ для задачи РУ ******
//  Координаты зоны отв. и РОН
struct CPMsg109 : public COMMMsg
{
  enum { TYPE = 109 };

  CPMsg109() : COMMMsg(TYPE, sizeof(CPMsg109), GFnumOurCP) {
	  ::memset( point_xy, 0, sizeof(point_xy) );
  }

//	COUInt8 type_msg;   // тип сообщения

	COUInt8 nAbonent;   // номер абонента 
	COUInt8 SubIndex;   //  индекс подчиненного подразделения -> N ЗРК
	COInt32 lHmin;
	COInt32 lHmax;
   	COUInt8 prInf;      //!? признак информации
	COUInt8 bZone;      // номер зоны
	COUInt8 bInfo;      // тип передаваемой зоны (код команды)
	
	enum
	{
		INFO_NOTIFICATION_ZONE = 0x6,//зона оповещения
		//!? INFO_INVESTIGATION_ZONE = 0x6,//зона разведки
		//!? INFO_ALLOCATION_ZONE = 0x66,//зона ответственности (исходная для РУ)
		INFO_RECOMMENDED_ZONE = 0x07,//рекомендованная задачей зона
		INFO_SECTOR_RLO = 0x08,
		//!? INFO_CORRECTED_ZONE = 0x28,//скорректированная рекомендованная зона
		//!? INFO_SELECTION_ZONE = 0x66,//зона отбора
		INFO_ROCKET_DANGEROUS_DIRECTION = 0x70,//ракетоопасное направление (РОН)
		INFO_RESPONSIBILITY_ZONE_88 = 0x88,       //зона ответ.аб. без учета Н
		INFO_RESPONSIBILITY_ZONE_77 = 0x77,   //зона ответ. аб. c учетом H

		INFO_RESPONSIBILITY_ZONE_66 = 0x66,   //сектор ответ.аб. без учета Н
		INFO_DUTY_ZONE_80 = 0x80,             // зона дежурства
		INFO_PROHIBITED_ZONE_81 = 0x81        //зона запрета
	};

	COUInt8 nPoints;            // количество точек	
	
	COInt32 point_xy[16];	    // координаты точек
};

// Команда на отмену зоны или донесение
struct CPMsg110 : public COMMMsg
{
  enum { TYPE = 110 };

CPMsg110( int src = GFnumOurCP ) : COMMMsg(TYPE, sizeof(CPMsg110), src)
{
	nAbonent = 0;
	SubIndex = 0;
	prInf = 0;
	bZone = 0;
	bInfo = 0;
	rezerv = 0;
}
//COUInt8 type_msg;   // тип сообщения
COUInt8 nAbonent;   // номер абонента
COUInt8 SubIndex;   // индекс подчиненнного абонента -> N ЗРК

COUInt8 prInf;       // признак информации
enum
{
INFO_COMMAND_ONAB = 0x1,  // команда отмены зоны для абонента
INFO_REPORT_FROMAB = 0x2, // донесение на команду от абонента
INFO_COMMAND_FROMAB = 0x4,// команда отмены зоны от абонента
INFO_REPORT_ONAB = 0x8    // донесение на команду на абонент
};
COUInt8 bZone;      // номер зоны
COUInt8 bInfo;        // код команды (тип зоны)
enum
{
//!? APPLY_SELECTION_ZONE = 0x66,       //дон-е на к-ду уст зоны отбора
APPLY_ROCKET_DANGEROUS_DIRECTION = 0x70,//дон-е на к-ду уст РОН
APPLY_RESPONSIBILITY_ZONE_066 = 0x66,   //дон-е на к-ду уст зоны отв c учетом Н
APPLY_RESPONSIBILITY_ZONE_077 = 0x77,   //дон-е на к-ду уст сект.отв без учета Н
APPLY_RESPONSIBILITY_ZONE = 0x88,       //дон-е на к-ду уст зоны отв
APPLY_DUTY_ZONE = 0x80,                 //дон-е на к-ду уст зоны дежурства
APPLY_PROHIBITED_ZONE = 0x81,           //дон-е на к-ду уст зоны запрета

CANCEL_DUTY_ZONE = 0x90,                 //к-да отмены зоны дежурства
CANCEL_PROHIBITED_ZONE = 0x91,           //к-да отмены зоны запрета
//!? CANCEL_SELECTION_ZONE = 0x69,//дон-е или ком-да об отмене зоны отбора
CANCEL_ROCKET_DANGEROUS_DIRECTION = 0x79,//дон-е или ком-да об отмене РОН
CANCEL_SECTOR_RLO = 0x98,
CANCEL_RESPONSIBILITY_ZONE = 0x99,//дон-е или ком-да об отмене зоны отв
//!? CANCEL_POINT = 0x01,//отмена точки сведения усилий
CANCEL_NOTIFICATION_ZONE = 0x06,//отмена зоны оповещения
//!? CANCEL_INVESTIGATION_ZONE = 0x6,//отмена зоны разведки
//!? CANCEL_ALLOCATION_ZONE = 0x8,//отмена зоны ответственности (исходной для РУ)
CANCEL_RECOMMENDED_ZONE = 0x07    //отмена рекомендованной задачей зоны
//!? CANCEL_CORRECTED_ZONE = 0x28//отмена скорректированной рекомендованной зоны
}; 
COUInt8 rezerv;        
};

//  Управление задачей РУ
struct CPMsg121 : public COMMMsg
{
  enum { TYPE = 121 };

  CPMsg121( int src = GFnumOurCP ) : COMMMsg(TYPE, sizeof(CPMsg121), src) {}

//COUInt8 type_msg;
COUInt8 nAbonent;   // номер абонента


COUInt8 bMode;	    //режим решения задачи РУ
enum
{
MODE_ALLOCATE = 0x1,	//разовое решение
MODE_CANCEL = 0x2,		//сброс решения
//!? MODE_ESCAPE = 0x2, //отмена результатов
MODE_REGULAR_ON = 0x3,	//вкл регулярное решение
MODE_REGULAR_OFF = 0x4, //выкл регулярное решение
MODE_APPLY = 0x5		//утверждение рекомендованных (скорректированных) зон
};
COUInt8 bIncluded[6];	// признаки включения абонентов (ЗРК)
};

//  Результаты решения задачи РУ
struct CPMsg122 : public COMMMsg
{
  enum { TYPE = 122 };

  CPMsg122( int src = 0 ) : COMMMsg(TYPE, sizeof(CPMsg122), src) {}
//COUInt8 type_msg;
COUInt8 nAbonent;	    // номер абонента
COUInt8 SubIndex;       // индекс подчиненнного абонента -> N ЗРК

COUInt16 col_BO_Apply;   // количество отм.в зоне Apply
COUInt16 col_BO_Recom;   // количество отм.в зоне Recom
COUInt16 nObjects[10];	// кол-во т.в зонах Rec.&Apply и по диапазонам H	
};

// Зона отв.,РОН 
struct CPMsg010 : public COMMMsg   //с.3-15
{
  enum { TYPE = 10};
	

  CPMsg010( int src = 0 ) : COMMMsg(TYPE, sizeof(CPMsg010), src) {}
//COUInt8 type_msg;

COUInt8 nAbonent;	// номер абонента  
COUInt8 SubIndex;   // индекс подчиненнного абонента -> N ЗРК

COUInt8 prInf;
COUInt8 bZone;      // номер зоны
COUInt8 Rezerv;
COUInt8 bCommand;	// код команды
enum
{
INFO_ROCKET_DANGEROUS_DIRECTION = 0x70,//ракетоопасное направление (РОН)
INFO_RESPONSIBILITY_ZONE_66 = 0x66,//зона ответственности абонента
INFO_RESPONSIBILITY_ZONE_77 = 0x77,//зона ответственности абонента
INFO_RESPONSIBILITY_ZONE_88 = 0x88,//зона ответственности абонента
INFO_DUTY_ZONE_80 = 0x80,             // зона дежурства
INFO_PROHIBITED_ZONE_81 = 0x81,       //зона запрета

CANCEL_ROCKET_DANGEROUS_DIRECTION = 0x79,//дон-е или ком-да об отмене РОН
CANCEL_RESPONSIBILITY_ZONE = 0x99,       //дон-е или ком-да об отмене зоны отв
CANCEL_DUTY_ZONE = 0x90,                 // отмена зоны дежурства
CANCEL_PROHIBITED_ZONE = 0x91            // отмена зоны запрета
};    
COInt32 point_xy[8];  // координаты точек

COInt32 lHmin;
COInt32 lHmax;
COUInt8 CoordSystem; //0 - прямоугольные относительно репера; 1 - географические (enum TYPE_COORD)

};

// Донесение на команду уст.зоны отв. и РОН
struct CPMsg011 : public COMMMsg  //c.010
{
  enum { TYPE = 11};
		

  CPMsg011( int src = 0 ) : COMMMsg(TYPE, sizeof(CPMsg011), src) {}


COUInt8 nAbonent;   // номер абонента 
COUInt8 SubIndex;   // индекс подчиненнного абонента -> N ЗРК
COUInt8 bZone;      // номер зоны  
COUInt8 bCommand;	//код команды

	enum
	{
APPLY_RESPONSIBILITY_ZONE_66 = 0x66,        //дон-е на к-ду уст зоны отв
APPLY_ROCKET_DANGEROUS_DIRECTION = 0x70,    //дон-е на к-ду уст РОН
APPLY_RESPONSIBILITY_ZONE_88 = 0x88,        //дон-е на к-ду уст зоны отв
APPLY_RESPONSIBILITY_ZONE_77 = 0x77,        //дон-е на к-ду уст зоны отв
APPLY_DUTY_ZONE_80 = 0x80,                  //дон-е на к-ду уст зоны дежурства
APPLY_PROHIBITED_ZONE_81 = 0x81,            //дон-е на к-ду уст зонызона запрета

//!? CANCEL_SELECTION_ZONE = 0x69,       //дон-е или ком-да об отмене зоны отбора
CANCEL_ROCKET_DANGEROUS_DIRECTION = 0x79,//дон-е или ком-да об отмене РОН
CANCEL_RESPONSIBILITY_ZONE = 0x99,       //дон-е или ком-да об отмене зоны отв
CANCEL_DUTY_ZONE = 0x90,                 //дон-е на к-ду уст зоны дежурства
CANCEL_PROHIBITED_ZONE = 0x91            //дон-е на к-ду уст зонызона запрета

	};
COUInt8 pr_vid_check;	                  // признак выдачи квитанции

};


//DELETE
// Выдать абоненту команду или донесение о зоне отв.или РОН
/*struct CPMsg051 : public COMMMsg
{
  enum { TYPE = 051};

  CPMsg051( int src = 0 ) : COMMMsg(TYPE, sizeof(CPMsg051), src) {}
COUInt8 type_msg;
COUInt8 pr_msg;
COUInt8 col_kdg;
COUInt8 rezerv;
COUInt8 nAbonent;  // номер абонента

// kdg1-5
COUInt8 kdg[40];
// To calculate the real size of message.
  
void realSize(void)
  {
    msgsize = sizeof(COMMMsg) + 4 + col_kdg*sizeof(char);
  }; 
};

// Выдать абоненту донесение о зоне отв.,РОН
struct CPMsg052 : public COMMMsg
{
  enum { TYPE = 052};
 CPMsg052( int src = 0 ) : COMMMsg(TYPE, sizeof(CPMsg052), src) {}

COUInt8 type_msg;
COUInt8 pr_msg;
COUInt8 col_kdg;
COUInt8 rezerv;
COUInt8 nAbonent;  // номер абонента

// kdg1-5
COUInt8 kdg[40];
// To calculate the real size of message.
  
void realSize(void)
  {
    msgsize = sizeof(COMMMsg) + 4 + col_kdg*sizeof(char);
  }; 
};
//DELETE
/////////////////////*****/////////////////////
/*
struct CPMsg051C
{
	COUInt8 pr_msg;
	COUInt8 nAbonent;
	COUInt8 reserv;
};

struct CPMsg051V
{
// количество копий кдг.
	 COUInt8 gtcopyKDG;
// количество повторов кдг.
	 COUInt8 gtpovtKDG;
// тип кодограммы
	 COUInt8 typeKDG;
	 COUInt8 pr_coord;
   COUInt8 code_command;
   COUInt8 coord_1;
	 COUInt8 coord_2;
	 COUInt8 coord_3;
};

struct CPMsg051 : public varmsg<CPMsg051C, COUInt8, CPMsg051V, 0x05>
{
  enum { TYPE = 51}; 
	  
  CPMsg051( void ) :
		varmsg<CPMsg051C, COUInt8, CPMsg051V, 0x05> (TYPE)
		{
			pr_msg=07;
		}
};

// Выдать абоненту донесение о зоне отв.,РОН
struct CPMsg052C
{
	COUInt8 pr_msg;
	COUInt8 nAbonent;
	COUInt8 reserv;
};

struct CPMsg052V
{
// количество копий кдг.
	 COUInt8 gtcopyKDG;
// количество повторов кдг.
	 COUInt8 gtpovtKDG;
// тип кодограммы
	 COUInt8 typeKDG;
	 COUInt8 pr_coord;
   COUInt8 code_report;
   COUInt8 reserv_1;
	 COUInt8 reserv_2;
	 COUInt8 reserv_3;
};

 struct CPMsg052 : public varmsg<CPMsg052C, COUInt8, CPMsg052V, 0x05>
{
  enum { TYPE = 52}; 
	  
  CPMsg052( void ) :
		varmsg<CPMsg052C, COUInt8, CPMsg052V, 0x05> (TYPE)
		{
			pr_msg=07;
		}
};

////////////////////******/////////////////////
// Снять выдачу абоненту зоны ответственности
/*struct CPMsg059C
{
	COUInt8 pr_msg;
	COUInt8 nAbonent;
	COUInt8 reserv;
};

struct CPMsg059V
{

// тип кодограммы
	 COUInt8 reserv;
	 COUInt8 typeKDG;
	 COUInt8 pr_coord;
   COUInt8 code_command;
   
};

 struct CPMsg059 : public varmsg<CPMsg059C, COUInt8, CPMsg059V, 0x05>
{
  enum { TYPE = 59}; 
	  
  CPMsg059( void ) :
		varmsg<CPMsg059C, COUInt8, CPMsg059V, 0x05> (TYPE)
		{
			pr_msg=8;
		}
};
*/
///////////////////////////////////////////////
// Координаты точки маршрута полета
struct CPMsg031 : public COMMMsg  //c.031
{
  enum { TYPE = 31};
		

  CPMsg031( int src = 0 ) : COMMMsg(TYPE, sizeof(CPMsg031), src) {}


COUInt8 nAbonent;   // номер абонента 
COUInt8 SubIndex;   // индекс подчиненнного абонента -> N ЗРК
COUInt8 prInf;      // признак информации
COUInt8 Number_obj; // номер обьекта  
COUInt8 Col_point;	// количество точек
COUInt8 Number_point;
COUInt8 priznak_point;
COUInt8 rezerv;
COUInt8 Number_zone;
COUInt16 Hg;
COUInt32 Xg;
COUInt32 Yg;
COUInt16 Time_point;
	
};

struct CPMsg032 : public COMMMsg  //c.032
{
	enum { TYPE = 32};
		

	CPMsg032( int src = 0 ) : COMMMsg(TYPE, sizeof(CPMsg032), src),
		nAbonent(0),
		Subindex(0),
		azimut_left(0),
		azimut_right(0),
		elevation(0),
		priznak_zone(0),
		cmd(0)
	{
		
	}


	COUInt8 nAbonent;   // номер абонента 
	COUInt8 Subindex;


	COFloat32 azimut_left;
	COFloat32 azimut_right;

	COFloat32 elevation;

	COUInt8 priznak_zone;

	COUInt8 cmd;
};
#pragma pack (pop)

#endif //_CPPAMsg_h_
