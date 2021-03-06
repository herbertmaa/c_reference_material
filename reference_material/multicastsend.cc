/*Application that generates multicast messages*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <stdio.h>


main(int argc)
{
   struct sockaddr_in addr;
   int addrlen, sock, status;
   struct ip_mreq mreq;
   char buf[50];
   time_t t;

   /* set up socket */
   sock = socket(AF_INET, SOCK_DGRAM, 0);
   if (sock < 0) {
     perror("socket");
     exit(1);
   }
   bzero((char *)&addr, sizeof(addr));
   addr.sin_family = AF_INET;
   /*addr.sin_addr.s_addr = htonl(INADDR_ANY);*/
   addr.sin_port = htons(4447);
   addrlen = sizeof(addr);
   addr.sin_addr.s_addr = inet_addr("230.0.0.1");

   while (1) {
     t = time(0);
     sprintf(buf, "time is %-24.24s", ctime(&t));
     status = sendto(sock, buf, sizeof(buf), 0,
		 (struct sockaddr *) &addr, addrlen);
     if (status < 0) {
 	    perror("sendto");
	    exit(1);
     }
     sleep(5);
   }
   
}

