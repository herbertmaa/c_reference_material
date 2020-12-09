#include <sys/socket.h>
#include <sys/types.h>
#include <resolv.h>
#include <unistd.h>
#include <stdio.h>

/* this is a socket program that uses fork() to create multi-client server*/
int main() {
    int sock, length;
    struct sockaddr_in server;
    int msgsock;
    char buf[1024];
    socklen_t len_t;
    int rval;
    int i;

    sock = socket (AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("opening stream socket");
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8889);

    if (bind (sock, (struct sockaddr *)&server, sizeof server) < 0) {
        perror ("binding stream socket");
    }

    if ((rval = recvfrom(sock, buf, sizeof (buf), 0, (struct sockaddr *)&server, &len_t)) < 0){
        perror("reading socket");
    }else  {
        printf("%s\n",buf);
    }
    close (sock);


}
