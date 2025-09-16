#include <stdio.h> 

void valueOfEOF() {
  //-1
  printf("Value of EOF: %d\n", EOF);
}

int main() {
  /* int c; */
  /* c = getchar(); */
  /* while (c != EOF) { */
  /*   putchar(c); */
  /*   c = getchar(); */
  /* } */

  int res = getchar() != EOF;
  printf("getchar() != EOF: %d\n", res);
}
