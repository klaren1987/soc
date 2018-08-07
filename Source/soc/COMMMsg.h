
#ifndef _COMMMsg_h_
#define _COMMMsg_h_

//#include "COcxx.h"

#include "COTypes.h"
#include "GLTime.h"
#include "CODefine.h"
#include<stdint.h>
#include <stdio.h>
#include <string.h>
enum{ TASK_CPM=0,
 TASK_AIR=101,
 TASK_TD=102,
 MISK=103,
 TASK_NOTIFY=104,
 TASK_RSLT=105
};

#pragma pack(push, 1)

/*! \struct COMMMsg COMMMsg.h
\brief Common part of all messages (i.e. header).
*/
struct COMMMsg
{
  /*! \fn COMMMsg( int type );
  \brief Structure constructor.
  \param type Type of message.
  \param size Size of message.
  \param src Source of message.
  */
	COMMMsg(int type, int size, int src = 0) :
		msgsrcID((uint8_t)(src)),
		msgsize((uint16_t)(size)),
		msgtime(GLTime()),
		msgtype((uint16_t)(type)) {};

  /*!
  \return Creation time of the message.  */
  static int64_t time( const void* pMsg );

  static void time(void* pMsg, int64_t time);

  /*! \fn static int size( const void* pMsg );
  \brief Determines size of a message.
  \param pMsg Pointer to the message.
  \return Size of the message.
  */
  static int size( const void* pMsg );


  /*! \fn static int srcid( const void* pMsg );
  \brief Determines source of a message.
  \param pMsg Pointer to the message.
  \return Source of the message.
  */
  static int srcid( const void* pMsg );

  /*! \fn static int dstid( const void* pMsg );
  \brief Determines destination of a message.
  \param pMsg Pointer to the message.
  \return Destination of the message.
  */
  static int dstid( const void* pMsg );

  /*! \fn static int type( const void* pMsg );
  \brief Determines type of a message.
  \param pMsg Pointer to the message.
  \return Type of the message.
  */
  static int type( const void* pMsg );



  /*! \fn static bool verify( const void* pMsg );
  \brief Verifies header of a message.
  \param pMsg Pointer to message to verify.
  \return true if the message passed verification, false
  if verification failed.
  */
  /*bool verify( const void* pMsg ) {
	  int sz = size(pMsg);
	  int ty = type(pMsg);
	  if (sz > 0 && ty > 0) return true;
	  else return false;
  };*/

  uint8_t msgsrcID;

  uint8_t msgdstID;

  /*! \var uint16_t msgsize;
  \brief Size of message (including header).
  */
  uint16_t msgsize;

  /*! \var int64_t msgtime;
  \brief Creation time.
  */
  int64_t msgtime;


  /*! \var uint8_t msgtype;
  \var Type of message.
  */
  uint16_t msgtype;

 /*! \var uint8_t msgsrc;
  \brief Source of message.
  */
  //uint8_t msgsrc;
};

struct COMMMsg_ab : public COMMMsg{
	COMMMsg_ab( void ) : COMMMsg(0,0,0){
	}
	GFabonentID m_ID;
};

struct COMMBackupMsg : public COMMMsg
{
	COMMBackupMsg( int type, int size, int src = 0 ) :
		COMMMsg( type, size, /*src*/GFnumOurCP ),
		m_task_ID( src )
	{}

	/*! \fn static uint32_t address( const void* pMsg );
	\brief Determines address of a message.
	\param pMsg Pointer to the message.
	\return Address of the message.
	*/
	static uint32_t address( const void* pMsg );

	static uint8_t task_ID( const void* pMsg );

	uint32_t msgaddr;

	uint8_t m_task_ID;
};

#pragma pack (pop)

//#include "COMMMsg.inl"

#endif //_COMMMsg_h_
