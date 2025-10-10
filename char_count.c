#include <stdio.h> 

int main() {
	int nc = 0; 
	char c; 
 while((c = getchar()) != EOF) {
  if(c != '\n') {
			++nc; 
		}
	}
	printf("%d\n", nc); 
  return 0;
}
