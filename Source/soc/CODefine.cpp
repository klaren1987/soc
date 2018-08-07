#include "CODefine.h"
#include <string.h>

void app_printf( const char *fmt, ... )
{
try{
#ifndef ENABLE_SCREEN_PRINT
	return;
#endif

	char buf[MAX_BUFFER_LEN_FOR_PRINT];
	int nLength;

	va_list args;

	::memset( buf, 0, MAX_BUFFER_LEN_FOR_PRINT);

	va_start( args, fmt );
	nLength = vsnprintf( buf, MAX_BUFFER_LEN_FOR_PRINT, fmt, args );
	va_end( args );

	printf( buf );

	}
	catch(...)
	{
		assert(0);
	}
}

void app_fprintf( FILE* fd, const char *fmt, ... )
{
try{
#ifndef ENABLE_FILE_PRINT
	return;
#endif

	char buf[MAX_BUFFER_LEN_FOR_PRINT];
	int nLength;

	va_list args;

	::memset( buf, 0, MAX_BUFFER_LEN_FOR_PRINT);

	va_start( args, fmt );
	nLength = vsnprintf( buf, MAX_BUFFER_LEN_FOR_PRINT, fmt, args );
	va_end( args );

	if( fd )
	{
		fprintf( fd, buf );
		fflush(fd);
	}
	else
	{
		return;
		printf( buf );
	}

	}
	catch(...)
	{
		assert(0);
	}
}

void app_fclose( FILE* fd )
{
	try
	{
		if (fd)
			fclose(fd);
	}
	catch(...)
	{
		assert(0);
	}
}