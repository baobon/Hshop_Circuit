/*
 * test.c:
 * Copyright (c) 2014-2017 Rtrobot. <admin@rtrobot.org>
 *  <http://rtrobot.org>
 ***********************************************************************
*  1.Inatall wiringPi at <http://wiringpi.com/>
*  2. Connect to board via usb
*  3.build:
*       gcc -o test test.c -lwiringPi
*  4.run to test:
*       ./test
 ***********************************************************************
 */


#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <wiringSerial.h>

void wait_serial_return_ok(int fd)
{
	int num=0;
	while(1)
    {
		char c[16];
		c[num]=serialGetchar(fd);
		if(c[num-1]=='O'&&c[num]=='K')
			break;
		num++;
		if(num>=15)
			num=0;
    }
}

int main(int argc, char *argv[])
{
	int fd;
	if ((fd = serialOpen("/dev/ttyACM0", 115200)) < 0)
    {
		fprintf(stderr, "Unable to open serial device: %s\n", strerror(errno));
		return 1 ;
    }

	serialPuts(fd, "#1P2000T1000D100\r\n");
	wait_serial_return_ok(fd);
	serialPuts(fd, "#1P1000T1000D2333\r\n");
	wait_serial_return_ok(fd);
	serialClose(fd);
	return 0;
}

