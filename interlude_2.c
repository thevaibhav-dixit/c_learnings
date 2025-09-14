#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
  int fd = open("./temp_file_to_write.txt", O_CREAT|O_WRONLY| S_IRWXU);

  if(fd < 0) {
    fprintf(stderr, "open failed\n");
    exit(1);
  }

  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0) {
    write(fd, "hello\n", 6);
    close(fd);
  }
  else {
    write(fd, "goodbye\n", 8);
    close(fd);
  }
}
