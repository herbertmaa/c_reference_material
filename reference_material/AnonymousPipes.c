#include <unistd.h>

#include <sys/types.h>

#include <stdio.h>



#include <stdlib.h>
int main(int argc, char* argv[]) {
	int fd[2];
	pid_t pid;

	if(argc != 2) {
		fprintf(stderr, "Must be specify exactly 1 file\n");
		exit(0);
	}

	if(pipe(fd) < 0)
		exit(1); 

	pid = fork();

	switch (pid) {
		case -1:
			exit(1);
		case 0:
			close(fd[1]);
			if(fd[0] != STDIN_FILENO) {
				if(dup2(fd[0], STDIN_FILENO) != STDIN_FILENO)
					exit(3);
				close(fd[0]);
			}
			if(execlp("tr", "tr", "[a-z]", "[A-Z]", (char *) 0) < 0)
				exit(4);
			break;

		default:
			close(fd[0]);
			if(fd[1] != STDOUT_FILENO) {
				if(dup2(fd[1], STDOUT_FILENO) != STDOUT_FILENO)
					exit(5);
				close(fd[1]);
			}
			if(execlp("cat", "cat", argv[1], (char *) 0) < 0)
				exit(4);
			break;
	}
	return 0;
}
