#include <unistd.h>

#include <sys/types.h>

#include <stdio.h>

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    int fd[2];
    // fd[0] - write end
    // fd[1] - read end
    pid_t pid;

    if (argc != 2) {
        fprintf(stderr, "Must specify exactly 1 file\n");
        exit(0);
    }

    if (pipe(fd) < 0) {
        printf("[-] An error occurred with opening the pipe \n");
        exit(1);
    }
    pid = fork();

    switch (pid) {
        case -1:
            exit(1);
        case 0:
            /* We are in the child process */
            close(fd[1]);

            if (fd[0] != STDIN_FILENO) {
                if (dup2(fd[0], STDIN_FILENO) != STDIN_FILENO){
                    exit(3);
                }
                close(fd[0]);
            }

            /* Run this command in the child process, makes all characters in the output buffer uppercase*/
            if (execlp("tr", "tr", "[a-z]", "[A-Z]", (char *) 0) < 0){
                exit(4);
            }
            break;

        default:
            /* The parent process prints out the modified file */
            close(fd[0]);
            if (fd[1] != STDOUT_FILENO) {
                if (dup2(fd[1], STDOUT_FILENO) != STDOUT_FILENO)
                    exit(5);
                close(fd[1]);
            }

            /* Run this command in the parent process, print out the contents of the file */
            if (execlp("cat", "cat", argv[1], (char *) 0) < 0){
                exit(4);
            }
            break;
    }
    return 0;
}
