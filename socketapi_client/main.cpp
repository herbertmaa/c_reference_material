#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>

#define SIZE 1024

using namespace std;

void send_file_name(int sock, char *file_name) {
    if (send(sock, file_name, sizeof(file_name), 0) == -1) {
        perror("[-] Error in sending data");
    }
}

int main(int argc, char **argv) {

    char buffer[SIZE];
    stringstream iss;
    int sock;
    struct sockaddr_in server;
    struct hostent *hp;
    int n;
    char *filename = argv[1]; // The name of our file is in our arguments
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("opening stream socket");
    }

    printf("[+] Client socket created. \n");

    bzero(&server, sizeof(server));
    hp = gethostbyname("localhost");
    bcopy((char *) hp->h_addr, (char *) &server.sin_addr, hp->h_length);
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("connecting");
    } else {
        printf("[+] Connected to server. \n");
    }
    send_file_name(sock, filename);
    n = recv(sock, buffer, SIZE, 0); // n is the length of the message we received from the client
    if (n < 0) {
        perror("failed to recieve a message");
    } else {
        printf("[+] Server sent a response. \n");
        for (int i = 0; i < n; i++) {
            iss << buffer[i];
        }
        cout << iss.str();
    }

}
