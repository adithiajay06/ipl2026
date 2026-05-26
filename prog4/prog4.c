#include <stdio.h>

// Define a structure with bitfields
struct Bitfield {
    unsigned int firstbit : 1;   // only 1 bit
    unsigned int secondbit : 2;  // 2 bits
    unsigned int thirdbit : 3;   // 3 bits
};

int main() {
    struct Bitfield a;

    // Assign values
    a.firstbit = 1;   // fits in 1 bit
    a.secondbit = 2;  // fits in 2 bits (max 3)
    a.thirdbit = 5;   // fits in 3 bits (max 7)

    // Print results
    printf("firstbit = %u\n", a.firstbit);
    printf("secondbit = %u\n", a.secondbit);
    printf("thirdbit = %u\n", a.thirdbit);

    // Show how overflow works
    a.secondbit = 5;  // 5 cannot fit in 2 bits → wraps
    printf("secondbit after overflow = %u\n", a.secondbit);

    return 0;
}
