#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int x = 100;
  printf("before fork: x = %d\n", x);

  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0) {
    x = 200;
  printf("from the child fork: x = %d\n", x);
  }
  else {
    x = 300;
  printf("from the parent fork: x = %d\n", x);
  }

}
