//CPGF_msg_ab_conf.h

#ifndef _CPGF_msg_ab_conf_h_
#define _CPGF_msg_ab_conf_h_

#include <memory.h>
#include "COMMMsg.h"
#include "GFconst.h"
#include "CODefine.h"

#pragma pack (push, 1)

const int g_qtt_mpd_chnl = 13;
const int g_qtt_all_ab = 10;//4; Alex 2017.06.06

//состояние канала связи МПД.
struct GF_mpd_ch_state{

	GF_mpd_ch_state(){
		memset( this, 0, sizeof(GF_mpd_ch_state) );
	}

	enum{
		//Аккорд-СС-ПС (2С06)
		TDT_2S06_0 = 0,
		//Аккорд-СС-ПД (2С07)
		TDT_2S07_0 = 1,
		//Арагва (2С07)


		TDT_2S07_1 = 2,
		//СТС
		TDT_STS_0 = 3,
		//СТС
		TDT_STS_1 = 4,
		//СТС
		TDT_STS_2 = 5,
		//СТС
		TDT_STS_3 = 6
	};
	enum{
		//абонент не инициализирован
		AC_not_init = 0,
		//абонент инициализирован
		AC_init = 1
	};
	enum{
		//канал связи с абонентом по приему готов.
		CDCHR_ready = 0,
		//канал связи с абонентом по приему не готов.
		CDCHR_not_ready = 1
	};
	enum{
		//канал связи с абонентом по передаче готов.
		CDCHT_ready = 0,
		//канал связи с абонентом по передаче не готов.
		CDCHT_not_ready = 1
	};
	enum{
		//канал контролируется.
		CDCH_not_check = 0,
		//канал не контролируется
		CDCH_check = 1
	};

	//Abonent number.
	//Номер абонента
	GFabonentID m_ab_ID;

	//Номер канала МПД с абонентом  по приему(Data Receiving).
	COUInt8 m_nch_dr;

	//Номер канала МПД с абонентом  по передаче(Data Transmitting).
	COUInt8 m_nch_dt;

	COUInt8 m_tAPD;
	COUInt8 m_iAPD;
	
	//Тип АПД(Data Transmitter)
	COUInt8 m_type_DT;

	//готовность канала связи ( 0-"нет связи", 1-99% ).
	COUInt8 m_dch_ready_pcnt;
	
	COUInt8	m_modulation;	// вид модуляции
	COUInt8	m_LevelIn;	// уровень принимаемого сигнала
	COUInt8	m_LevelOut;	// уровень выходного сигнала
	COUInt8	m_sh_sig;		// соотношение шум/сигнал
	COUInt8	m_Speed;		// скорость в канале связи
	COUInt8	m_isLoop;		// шлейф/работа
	COUInt8	m_isPortOpened;	// порт открыт / не открыт
	COUInt8 m_prKK;
	COUInt8 m_Recv_Send_state;
	COUInt8 m_access;

	//	Состояние канала связи и абонента:
	/*	контроль канала:	КК						1BIT,1
	- контролируется					1
	- не контролируется					0
	*/
	COUInt8 m_ch_ctrl	: 1;

	/*	состояние канала по выдаче:	СК вых			1BIT,1
	- готов								0
	- не готов							1
	*/
	COUInt8 m_ch_st_dt	: 1;

	/*	состояние канала по приему:	СК вх			1BIT,1
	- готов								0
	- не готов							1
	*/
	COUInt8 m_ch_st_dr	: 1;

	/*	состояние настройки абонента в МПД 	СН		1BIT,1
	- абонент проинициализирован и ему выделен канал связи 1
	- абонент не проинициализирован				0
	*/
	COUInt8 m_ab_init	: 1;

	COUInt8				: 1;

	/*	признак участия абонента в тренаже:	ПР ТР	2BIT,2	
	- не участвует						00
	- участвует реальный абонент		01
	- участвует имитированный абонент	10
	*/
	COUInt8 m_ab_train	: 2;

	/*	состояние абонента:	С АБ					1BIT,1	
	- включен в состав абонентов		1
	- исключен из состава абонентов		0
	*/
	COUInt8 m_ab_cndtn	: 1;
};

struct CPMsg1250 : public COMMMsg
{
	enum{
		TYPE = 1250
	};

	CPMsg1250( void ) :
		COMMMsg( TYPE, sizeof(CPMsg1250), GFnumOurCP ),
		m_latitude(0.0),
		m_longitude(0.0),
		m_height(0)
	{
		;
	}
	float m_latitude;

	float m_longitude;

	COUInt16 m_height;
};

struct _CPMsg1254
{
	_CPMsg1254( void )
	{
		memset( this, 0, sizeof(*this) );
	}
	COUInt8 m_nAb;
	COUInt8 m_nSubAb;
	COUInt8 m_condition;
	enum {
		AB_ready = 1,
		AB_not_ready = 2,
		AB_off = 3,
		AB_unk = 4
	};
};

struct CPMsg1254 : public COMMMsg
{
	enum{
		TYPE = 1254
	};

	CPMsg1254( void ) :
		COMMMsg( TYPE, sizeof(CPMsg1254), GFnumOurCP ), m_cnt_cell(0)
	{
		;
	}

	COUInt8 m_cnt_cell;

	_CPMsg1254* operator[]( int cell ){
		if( cell < 0 || cell >= SRC_COUNT )
		{
			G_ASSERT(0);
			return 0L;
		}
		return &(m_l[cell]);
	}
	const _CPMsg1254* operator[]( int cell )const{
		if( cell < 0 || cell >= SRC_COUNT )
		{
			G_ASSERT(0);
			return 0L;
		}
		return &(m_l[cell]);
	}

private:
	_CPMsg1254 m_l[SRC_COUNT];
};

//////////////////////////////\
///////////////////////////////
//////////////////           //
/////////////////\
//////////////////////////////\
///////////////////////////////
///////////////////////////////
///////////////////////////////
////////////
////////////
////////////                //\
////////////               ////
///////////////////////////////
///////////////////////////////
///////////////////////////////

////////////////////////////////////////////////
////////////////////////////////////////////////
//                                            //
//   MM       MM    PPPPPPPPP      DDDDDDD    //
//   MM       MM    PP     PP      DD   DD    //
//   MMM     MMM    PP     PP      DD   DD    //
//   MMMM   MMMM    PP     PP      DD   DD    //
//   MMMM   MMMM    PP     PP      DD   DD    //
//   MM MM MM MM    PP     PP      DD   DD    //
//   MM MM MM MM    PP     PP     DD    DD    //
//   MM  MMM  MM    PP     PP    DD     DD    //
//   MM  MMM  MM    PP     PP   DDDDDDDDDDD   //
//   MM   M   MM    PP     PP   DD       DD   //
//   MM   M   MM    PP     PP   DD       DD   //
//                                            //
////////////////////////////////////////////////
////////////////////////////////////////////////

struct _CPMsg080{
	_CPMsg080(){
		memset( this, 0, sizeof(_CPMsg080) );
	}

	//
	GFabonentID m_numAb;

	//Тип КСА абонента.
	COUInt8 m_KSA;

	//Уровень подчиненности(subordination) абонента.
	COUInt8 m_sub_l;

	/*	Текущий режим работы абонента(working mode).
	0 - режим не установлен
	1 - боевой режим 
	2 - дежурный режим
	3 - режим тренажа
	4 - режим функционального контроля
	*/
	COUInt8 m_working_mode;

	//Резерв(reserve).
	COUInt8				: 5;
	
	/*	Признак участия абонента в тренаже(training sign)
	0 - не участвует
	1 - реальный
	2 - имитированный
	*/
	COUInt8 m_train_sgn	: 2;
	
	/*	Состояние абонента(abonent condition).
	1 - включен в состав группировки
	0 - исключен из состава группировки
	*/
	COUInt8 m_conditn	: 1;
};

//СООБЩЕНИЕ О СОСТАВЕ АБОНЕНТОВ
struct CPMsg080 : public COMMMsg
{
	enum{
		TYPE = 80
	};

	CPMsg080( void ) :
		COMMMsg( TYPE, sizeof(CPMsg080), GFnumOurCP ),
		m_reserve_05920433251(0)
	{}

	COUInt8 m_reserve_05920433251;

	//Тип КСА своего КП
	//0 - абонент ненастроен;
	//(1-254) - тип КСА определяется;
	//255 - абонент не имеет КСА;
	//COUInt8 m_KSA_CP;
	//количество записей в сообщении.
	COUInt8 m_cnt_cell;

	_CPMsg080* operator[]( int cell ){
		if( cell < 0 || cell >= g_qtt_all_ab ){
			G_ASSERT(0);
			return 0L;
		}
		return &(m_l[cell]);
	}
	const _CPMsg080* operator[]( int cell )const{
		if( cell < 0 || cell >= g_qtt_all_ab ){
			G_ASSERT(0);
			return 0L;
		}
		return &(m_l[cell]);
	}

private:
	_CPMsg080 m_l[g_qtt_all_ab];
};

struct _CPMsg081{
	_CPMsg081(){
		memset( this, 0, sizeof(_CPMsg081) );
	}

	COUInt8 m_numAb;
	COUInt8 m_numAb_sub;

	/*	Признак участия в тренаже абонента
	0 - абонент не участвует(not included)
	1 - участвует реальный абонент(real abonent)
	2 - участвует имитированный абонент(imitated abonent)
	*/
	COUInt8 m_train_sgn;
};

//const int GF_cnt_chnl_in_81 = 22;

//СООБЩЕНИЕ О НАСТРОЙКЕ АБОНЕНТОВ ПРИ ПРОВЕДЕНИИ ТРЕНИРОВКИ.
struct CPMsg081 : public COMMMsg
{
	enum{
		TYPE = 81
	};
	enum{
		//не настроен.
		CSU_not_adjustment = 0,
		//настроен.
		CSU_adjustment = 1
	};
	CPMsg081( void ) :
		COMMMsg( TYPE, sizeof(CPMsg081), GFnumOurCP )
	{ m_cnt_cell = 0; m_cnt_chngd = 0; }


	//резерв.
	COUInt8 m_cnt_chngd;

	//Количество записей в сообщении.
	COUInt8 m_cnt_cell;

	_CPMsg081* operator[]( int cell ){
		if( cell < 0 || cell >= g_qtt_all_ab ){
			G_ASSERT(0);
			return 0L;
		}
		return &(m_l[cell]);
	}
	const _CPMsg081* operator[]( int cell ) const{
		if( cell < 0 || cell >= g_qtt_all_ab ){
			G_ASSERT(0);
			return 0L;
		}
		return &(m_l[cell]);
	}

private:
	_CPMsg081 m_l[g_qtt_all_ab];
};

//СОСТОЯНИЕ КАНАЛОВ СВЯЗИ.
struct CPMsg084 : public COMMMsg{
	enum{
		TYPE = 84
	};
	CPMsg084( void ) :
		COMMMsg( TYPE, sizeof(CPMsg084), GFnumOurCP )
	{}

	//номер МПД
	COUInt8 m_numMTD;

	//Количество записей в сообщении
	COUInt8 m_cnt_cell;

	GF_mpd_ch_state* operator[]( int cell ){
		if( cell < 0 || cell >= g_qtt_mpd_chnl ){
			G_ASSERT(0);
			return 0L;
		}
		return &(m_StCh[cell]);
	}
	const GF_mpd_ch_state* operator[]( int cell ) const{
		if( cell < 0 || cell >= g_qtt_mpd_chnl ){
			G_ASSERT(0);
			return 0L;
		}
		return &(m_StCh[cell]);
	}

private:
	GF_mpd_ch_state m_StCh[g_qtt_mpd_chnl];
};

////////////////////////////////////////////////
////////////////////////////////////////////////
//                                            //
//       A         RRRRRRR     MM       MM    //
//      AAA        RR    RR    MM       MM    //
//      AAA        RR     RR   MMM     MMM    //
//     AA AA       RR     RR   MMMM   MMMM    //
//    AA   AA      RR    RR    MMMM   MMMM    //
//    AA   AA      RRRRRRR     MM MM MM MM    //
//   AA     AA     RR          MM MM MM MM    //
//   AAAAAAAAA     RR          MM  MMM  MM    //
//  AA       AA    RR          MM  MMM  MM    //
//  AA       AA    RR          MM   M   MM    //
//  AA       AA    RR          MM   M   MM    //
//                                            //
////////////////////////////////////////////////
////////////////////////////////////////////////

struct _CPMsg082{
	_CPMsg082(){
		memset( this, 0, sizeof(_CPMsg082) );
	}

	//Номер абонента.
	GFabonentID m_numAb;

	//Тип КСА абонента.
	COUInt8 m_typeKSA;

	COUInt8 chan_state[26];
	
};

//Сообщение о состоянии каналов связи абонентов
struct CPMsg082 : public COMMMsg{
	enum{
		TYPE = 82
	};
	CPMsg082( void ) :
		COMMMsg( TYPE, sizeof(CPMsg082), GFnumOurCP )/*,
		m_reserv(0)*/
	{ }

	_CPMsg082* operator[]( int cell ){
		if( cell < 0 || cell >= g_qtt_all_ab ){
			G_ASSERT(0);
			return 0L;
		}
		return &(m_l[cell]);
	}
	const _CPMsg082* operator[]( int cell ) const{
		if( cell < 0 || cell >= g_qtt_all_ab ){
			G_ASSERT(0);
			return 0L;
		}
		return &(m_l[cell]);
	}

	//COUInt8 m_reserv;
	COUInt8 m_cnt_cell;

private:
	_CPMsg082 m_l[g_qtt_all_ab];
};

//Сообщение о состоянии каналов связи абонентов
struct CPMsg083 : public COMMMsg
{
	enum{
		TYPE = 83
	};
	CPMsg083( void ) :
		COMMMsg( TYPE, sizeof(CPMsg083), GFnumOurCP )
	{
		memset( m_pwd, 0, sizeof(m_pwd) );
	}
	COUInt8 m_num_AB; // Номер абонента
	COUInt8 m_num_sub_AB; // Индекс подразделения BYTE, 8
	COUInt32 m_numID; //
	COUInt8 m_pwd[6]; // Пароль Строка символов 6-CHAR(KOI8-R)
};

struct CPMsg219 : public COMMMsg
{
	enum{
		TYPE = 219
	};
	CPMsg219( void ) :
		COMMMsg( TYPE, sizeof(CPMsg219), GFnumOurCP ),
		m_command(0)
	{}
	GFabonentID m_abID;
	COUInt8 m_command;
};


struct CPMsg1253 : public COMMMsg
{
	enum{
		TYPE = 1253
	};
	CPMsg1253( void ) : COMMMsg( TYPE, sizeof(CPMsg1253), GFnumOurCP )
	{
		memset( this, 0, sizeof(CPMsg1253) );
	}

	COUInt8		Command;	// команда
		enum{
			cmd_request = 0,	// запрос времени на МПД
			cmd_answer = 1,		// ответ от МПД
			cmd_error = 2		// сообщение об ошибке, код ошибки в ErrCode
		};

	COUInt8		AbNum;		// номер абонента для запроса времени / от кого время получено
	COUInt64	time;		// время в мс от 01.01.1970
	COUInt8		ErrCode;	// код ошибки
		enum{
			err_no = 0,
			err_abonent_absent = 1,
			err_timeout = 2,
			err_abonent_no_channel = 3
		};
};

#pragma pack (pop)

#endif //_CPGF_msg_ab_conf_h_

//
