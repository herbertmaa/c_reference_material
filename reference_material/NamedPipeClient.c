#define FIFO1 "/tmp/fifo1"
#define FIFO2 "/tmp/fifo2"

#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>

#define MSG "Hello World!\n"

int main() {
	int ifd, ofd, nbytes;
	char buffer[PIPE_BUF];
	
	if((ofd = open(FIFO1, O_WRONLY)) < 0)
		exit(1);
	write(ofd, MSG, strlen(MSG));
	close(ofd);

	if((ifd = open(FIFO2, O_WRONLY)) < 0)
		exit(1);
	while((nbytes = read(ifd, buffer, PIPE_BUF)) > 0)
		write(STDOUT_FILENO, buffer, nbytes);
	close(ifd);

	return 0;
}


