#include <sys/socket.h>
#include <sys/dir.h>
#include <sys/types.h>
#include <resolv.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
static void *doit(void *);
main() {
  int sock, length;
  struct sockaddr_in server;
  int msgsock;
  int i;
  pthread_t tid;
  
  sock = socket (AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("opening stream socket");
  }

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = 8888;
  
  if (bind (sock, (struct sockaddr *)&server, sizeof server) < 0)  {    perror ("binding stream socket");
  }
  listen (sock, 5);
  while(1){
    msgsock = accept(sock, (struct sockaddr *)0, (socklen_t *)0);
    if (msgsock == -1) {
      perror("accept");
    }
    printf("before thread create\n");
    pthread_create(&tid, NULL, doit, (void*) msgsock);
    printf("after thread create\n");  
 }
     
}
 static void * doit(void * arg) {
  DIR * dirp;
  struct direct *d;
  char buf1[80];
  char buf2[102400];
  
  int rval;
  int clientsock;
  printf("before assignment\n");
  clientsock = (int) (arg);
  printf("after assignment\n");
  /* pthread_detach(pthread_self());*/
  if ((rval = read(clientsock, buf1, 80)) < 0){
	perror("reading socket");
  }
  printf("%s\n",buf1);
  dirp = opendir(buf1); 
  if (dirp == NULL) {
    perror("openning dir");
    return (NULL);
  }
  
  while (d = readdir(dirp)) {
       strcpy(buf2,d->d_name);
       if ((rval = write(clientsock, buf2, 1024)) < 0){
	 perror("writing socket");
      }
  }
    closedir (dirp);
    close(clientsock);
    return (NULL);
 }
