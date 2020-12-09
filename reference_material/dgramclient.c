#include <sys/socket.h>
#include <sys/types.h>
#include <resolv.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>

main() {
  int sock;
  struct sockaddr_in server;
  int msgsock;
  char buf[1024];
  struct hostent *hp;
  char *host = "142.232.132.163";
  int rval;

  sock = socket (AF_INET, SOCK_DGRAM, 0);
  if (sock < 0) {
    perror("opening stream socket");
  }

  bzero(&server, sizeof(server));
  hp = gethostbyname("localhost");
  bcopy((char*)hp->h_addr, (char*)&server.sin_addr, hp->h_length);
  server.sin_family = AF_INET;
  server.sin_port = 8889;
  
  strcpy(buf,"this is a test\n");
  if ((rval = sendto(sock, buf, sizeof (buf),0,(struct sockaddr *)&server, sizeof server)) < 0){
    perror("writing socket");
  }
  close (sock);
}
