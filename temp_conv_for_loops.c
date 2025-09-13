#include <stdio.h>

// symbolic constants
#define LOWER 0
#define UPPER 300
#define STEP 20


int main() {
    for (int fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        float celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3d %6.1f\n", fahr, celsius);
    }

}
