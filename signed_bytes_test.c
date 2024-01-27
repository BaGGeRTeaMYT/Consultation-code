#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int little_a = -1000;
    printf("Little: %d\n%08x\n", little_a, little_a);
    int big_a = 0;
    for (int i = 0; i < 4; ++i) {
        big_a <<= 8;
        big_a += (little_a & 0xff);
        little_a >>= 8;
    }
    printf("In big endian: %d\n%08x\n", big_a, big_a);
    little_a = big_a;
    big_a = 0;
    for (int i = 0; i < 4; ++i) {
        big_a <<= 8;
        big_a += (little_a & 0xff);
        little_a >>= 8;
    }
    printf("After function (again): %d\n%08x", big_a, big_a);
    return 0;
}