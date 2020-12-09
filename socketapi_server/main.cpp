#include <sys/socket.h>
#include <sys/types.h>
#include <resolv.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>

#define SIZE 1024
using namespace std;

void print_file(int sock) {

    string line;
    int n;
    char buffer[SIZE];
    stringstream iss;
    stringstream oss;
    n = recv(sock, buffer, SIZE, 0); // n is the length of the message we received from the client
    if (n < 0) {
        perror("failed to recieve a message");
    } else {
        for(int i = 0; i < n; i++){
            iss << buffer[i];
        }
    }

    /* Read from the directory of our project */
    ifstream file("../" + iss.str());

    if(!file){
        perror("failed to open file");
    }

    /* Read until the end of the file */
    while(getline(file, line)){
        oss << line << endl;
    }

    string file_contents = oss.str();

    if(send(sock, file_contents.c_str(), strlen(file_contents.c_str()), 0) == -1) {
        perror("[-] Error in sending data");
    }
    /* Close the socket */
    printf("[+] Client socket closed. \n");
    close(sock);

    /* Close the file */
    file.close();

}


int main() {
    int sock, length;
    struct sockaddr_in server;
    int msgsock;
    char buf[SIZE];
    int rval;
    int i;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("opening stream socket");
    }

    printf("[+] Server socket created. \n");

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    if (bind(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("binding stream socket");
        exit(1);
    }
    printf("[+] Binding successful. \n");

    i = listen(sock, 5);
    if (i == 0) {
        printf("[+] Listening... \n");
    } else {
        perror("[-] Error in listening \n");
    }
    while(1){
        // Now we can accept a connection.
        msgsock = accept(sock, (struct sockaddr *) 0, (socklen_t *) 0);
        if (msgsock == -1) {
            perror("accept");
        }

        // Fork our process
        pid_t pid = fork();

        if(pid < 0){
            perror("Fork failed");
            exit(1);
        }

        if(pid == 0){
            printf("[+] Child process handling request... \n");
            print_file(msgsock);
            exit(0);
        }
    }


}
