#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h> //required to define some C macro constants
#include <sys/socket.h>  //prototype of socketpair(2) function


int main(int argc, char **argv)
{
	int z;  //status return code
	int s[2]; //pair of sockey
	
	z = socketpair(AF_LOCAL, SOCK_STREAM, 0, s);

	if ( z == -1 ) {
		fprintf(stderr, "%s: socketpair(AF_LOCAL, SOCK_STREAM, 0)\n", strerror(errno));
		return 1; /* Failed*/
	}

	/*
	* Report the socket file descriptors returned:
	*/

	system("netstat --unix -p");

	return 0;

}
