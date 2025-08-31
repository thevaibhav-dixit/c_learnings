#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

  int rc = fork(); 
  if(rc < 0) {
    printf("Fork failed\n");
    exit(1);

  }
  else if (rc == 0) {
    printf("I am child (pid: %d)\n", (int) getpid());

    char *argv[] = { "ls", "-l", NULL };
    execvp("ls", argv);
  }
  else {
    printf("I am parent of %d (pid:%d)\n", rc, (int) getpid());
  }
}
