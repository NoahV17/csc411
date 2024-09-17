#include <stdio.h>
unsigned int isPowerOfTwo(unsigned int num) {
    return (num != 0) && ((num & (num - 1)) == 0);
}

int main() {
    unsigned int testValues[] = {0, 1, 2, 3, 4, 5, 16, 18};
    int numTests = sizeof(testValues) / sizeof(testValues[0]);

    for (int i = 0; i < numTests; i++) {
        unsigned int num = testValues[i];
        printf("isPowerOfTwo(%u) = %u\n", num, isPowerOfTwo(num));
    }

    return 0;
}