#include <stdio.h>
#include <stdint.h>

// Function to print bits of an integer
void printBits(unsigned int n) {
    for (int i = sizeof(n)*8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

// Function to count number of 1 bits
int countBits(unsigned int n) {
    int count = 0;
    while (n) {
        n &= (n - 1); // Brian Kernighan’s algorithm
        count++;
    }
    return count;
}

// Function to check endianness
void checkEndianness() {
    unsigned int x = 0x12345678;
    unsigned char *p = (unsigned char*)&x;

    printf("Stored bytes: ");
    for (int i = 0; i < sizeof(x); i++) {
        printf("%02X ", p[i]);
    }
    printf("\n");

    if (p[0] == 0x78)
        printf("Little Endian\n");
    else
        printf("Big Endian\n");
}

// Function to show bits of a negative integer
void showNegativeInt(int n) {
    printf("Bits of %d: ", n);
    for (int i = sizeof(n)*8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

// Function to show bits of a float
void showFloatBits(float f) {
    unsigned int *p = (unsigned int*)&f;
    printf("Bits of %f: ", f);
    printBits(*p);
}

// Function to show bits of a negative float
void showNegativeFloat(float f) {
    unsigned int *p = (unsigned int*)&f;
    printf("Bits of %f: ", f);
    printBits(*p);
}

int main() {
    unsigned int num = 29;
    int negInt = -5;
    float posFloat = 5.75f;
    float negFloat = -5.75f;

    printf("Bits of %u: ", num);
    printBits(num);

    printf("Number of 1 bits in %u: %d\n", num, countBits(num));

    checkEndianness();

    showNegativeInt(negInt);

    showFloatBits(posFloat);
    showNegativeFloat(negFloat);

    return 0;
}
