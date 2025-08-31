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
    close(STDOUT_FILENO);
    // NOTHING GETS PRINTED SINCE WE CLOSED STDOUT
    printf("I am child (pid: %d)\n", (int) getpid());
  }
  else {
    wait(NULL); 
    printf("I am parent of %d (pid:%d)\n", rc, (int) getpid());
  }
}
