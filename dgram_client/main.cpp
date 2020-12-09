#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <sstream>

using std::stringstream;

int main() {
    int sock;
    struct sockaddr_in server;
    int msgsock;
    char buf[1024];
    struct hostent *hp;
    char *host = "142.232.132.163";
    hp = gethostbyname("localhost");

    int rval;

    sock = socket (AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("opening stream socket");
    }

    bzero(&server, sizeof(server));
    bcopy((char*)hp->h_addr, (char*)&server.sin_addr, hp->h_length);
    server.sin_family = AF_INET;
    server.sin_port = htons(8889);

    stringstream payload;
    payload << host;
    payload << ": this is a test";

    strcpy(buf,payload.str().c_str());
    if ((rval = sendto(sock, buf, sizeof (buf),0,(struct sockaddr *)&server, sizeof server)) < 0){
        perror("writing socket");
    }
    close (sock);
}
