

#include <OBDIICommunication.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define strerror_r(_errnum,_buf,_buflen)  strerror_s((_buf),(_buflen),(_errnum))
#else
#endif

int main(void)
{
	// Talk to the engine ECU (transfer ID 0x7E0, receive ID 0x7E8) on can0 interface
	OBDIISocket s;
	
	if (OBDIIOpenSocket(&s, "can0", 0x7E0, 0x7E8, 0) < 0) {
		char vcErrBuffer[1024];
		strerror_r(errno, vcErrBuffer,1023);
		printf("Error opening socket: %s\n", vcErrBuffer);
		exit(EXIT_FAILURE);
	}

	return 0;
}
