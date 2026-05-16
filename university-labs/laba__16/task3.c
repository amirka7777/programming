#include <stdio.h>

// ???
// y + 1 * y + 1 = (5 + 5 + 1)
#define SQR(x) ((x) * (x))

int main() {
    int y = 5;
    int z = SQR(y + 1);
    printf("z = %d\n", z);
    return 0;
}