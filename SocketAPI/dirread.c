#include <sys/dir.h>
#include <stdio.h>

main() {

  DIR * dirp;
  struct direct *d;

  dirp = opendir("/usr/include");
  if (dirp == NULL) {
    perror("openning dir");
  }
  while (d = readdir(dirp)) {
    printf("%s\n",d->d_name);
  }
  closedir (dirp);
}
