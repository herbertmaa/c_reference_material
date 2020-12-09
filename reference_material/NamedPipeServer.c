#define FIFO1 "/tmp/fifo1"
#define FIFO2 "/tmp/fifo2"

#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <ctype.h>

#define PERM (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main() {
	int ifd, ofd, i, nbytes;
	char buffer[PIPE_BUF];

	if(mkfifo(FIFO1, PERM) < 0 && errno != EEXIST) {
		perror("mkfifo");
		exit(1);
	}

	if(mkfifo(FIFO2, PERM) < 0 && errno != EEXIST) {
		perror("mkfifo");
		unlink(FIFO1);
		exit(1);
	}

	if((ifd = open(FIFO1, O_RDONLY)) < 0)
		exit(3);
	if((ifd = open(FIFO2, O_RDONLY)) < 0)
		exit(4);

	while((nbytes = read(ifd, buffer, PIPE_BUF)) > 0) {
		for (i = 0; i < nbytes; i++)
			buffer[i] = toupper(buffer[i]);
		write(ofd, buffer, nbytes);
	}

	close(ifd);
	close(ofd);
	return 0;
}
