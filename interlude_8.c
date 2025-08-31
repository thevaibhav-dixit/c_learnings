#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>

int main(){
  // create two child process and pass output from one to another using pipe

  int pipefd[2];
  pipe(pipefd);
  int rc = fork();
  if(rc < 0) {
    printf("Fork failed\n");
    exit(1);
  }
  else if (rc == 0) {
    // Child process 1: Writer
    close(pipefd[0]); // Close unused read end important for avoiding deadlocks EOF errors etc 
    const char *msg = "Hello from child 1\n";
    write(pipefd[1], msg, sizeof(msg));
    close(pipefd[1]); // Close write end after writing
    exit(0);
  }
  else {
    int rc2 = fork();
    if(rc2 < 0) {
      printf("Fork failed\n");
      exit(1);
    }
    else if (rc2 == 0) {
      // Child process 2: Reader
      close(pipefd[1]); // Close unused write end
      char buffer[100];
      read(pipefd[0], buffer, sizeof(buffer));
      printf("Child 2 received: %s", buffer);
      close(pipefd[0]); // Close read end after reading
      exit(0);
    }
    else {
      // Parent process
      close(pipefd[0]);
      close(pipefd[1]);
      wait(NULL); // Wait for child 1
      wait(NULL); // Wait for child 2
      printf("I am parent of %d and %d (pid:%d)\n", rc, rc2, (int) getpid());
    }
  }
}
