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
  }
  else {
    int res = waitpid(rc, NULL, 0);
    printf("%d\n", res);
    printf("I am parent of %d (pid:%d)\n", rc, (int) getpid());
  }
}
