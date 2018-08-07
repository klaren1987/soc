#include "COMMMsg.h"

#include <time.h>
#include<stdint.h>



inline
int64_t COMMMsg::time( const void* pMsg )
{
  // Message may be unaligned!
  int64_t t;
  const uint8_t* p = (const uint8_t*)(pMsg);
  memcpy(&t, p+4, sizeof(t));
  return t;
}

inline
void COMMMsg::time(void* pMsg, int64_t time)
{
   uint8_t* p = (uint8_t* )(pMsg);
   memcpy(&p[4], &time, sizeof(time));
}

inline
int COMMMsg::size( const void* pMsg )
{
  // Message may be unaligned!
  uint16_t sz;
  const uint8_t* p = (const uint8_t*)(pMsg);
  memcpy(&sz, p + 2, sizeof(sz));
  return sz;
}


inline
int COMMMsg::srcid( const void* pMsg )
{
  const uint8_t* p = (const uint8_t*)(pMsg);
  return p[0];
}

inline
int COMMMsg::dstid( const void* pMsg )
{
  const uint8_t* p = (const uint8_t*)(pMsg);
  return p[1];
}


inline
int COMMMsg::type( const void* pMsg )
{
	uint16_t ty;
	const uint8_t* p = (const uint8_t*)(pMsg);
	memcpy(&ty, p + 12, sizeof(ty));
	return ty;
}




inline
uint32_t COMMBackupMsg::address( const void* pMsg )
{
  uint32_t t;
  const uint8_t* p = (const uint8_t*)(pMsg);
  memcpy(&t, p+sizeof(COMMMsg), sizeof(t));
  return t;
}

inline
uint8_t COMMBackupMsg::task_ID( const void* pMsg )
{
	uint8_t t;
  const uint8_t* p = (const uint8_t*)(pMsg);
  memcpy( &t, p + sizeof(COMMMsg) + sizeof(uint32_t), sizeof(t) );
  return t;
}
