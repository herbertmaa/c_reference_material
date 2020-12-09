#include <sys/socket.h>
#include <sys/types.h>
#include <resolv.h>
#include <unistd.h>
#include <stdio.h>

/* this is a socket program that uses fork() to create multi-client server*/
main() {
  int sock, length;
  struct sockaddr_in server;
  int msgsock;
  char buf[1024];
  int rval;
  int i;
  
  sock = socket (AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("opening stream socket");
  }

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = 8888;
  
  if (bind (sock, (struct sockaddr *)&server, sizeof server) < 0) {
    perror ("binding stream socket");
  }
  listen (sock, 5);
  while(1){
    msgsock = accept(sock, (struct sockaddr *)0, (socklen_t *)0);
    if (msgsock == -1) {
      perror("accept");
    }
    if (fork() == 0) {
      if ((rval = read(msgsock, buf, 1024)) < 0){
	perror("reading socket");
      }else  {
	printf("%s\n",buf);
      }
      close (msgsock);
    }
  }
}
