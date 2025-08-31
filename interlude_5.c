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
    // The child process has nothing to wait for, so
    // wait_res will be -1 because the child has no children
    int wait_res = wait(NULL);
    printf("I am child (pid: %d)\n", (int) getpid());
    printf("%d\n", wait_res);
  }
  else {
    int res = wait(NULL);
    printf("I am parent of %d (pid:%d)\n", rc, (int) getpid());
    printf("%d\n", res);
  }
}
