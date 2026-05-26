#include <stdio.h>

// Define union with bitfields
union decision {
    unsigned char flags;   // raw 8-bit storage
    struct field {
        unsigned int your_choice:1;
        unsigned int your_mothers_choice:1;
        unsigned int your_fathers_choice:1;
        unsigned int socially_acceptable:1;
        unsigned int financially_viable:1;
        unsigned int do_you_aptitude:1;
        unsigned int do_you_likeit:1;
        unsigned int decision:1; // final computed decision
    } bits;
};

// Input function (for demo, we hardcode values)
union decision input() {
    union decision d;
    d.flags = 0; // clear all bits

    d.bits.your_choice = 1;
    d.bits.your_mothers_choice = 0;
    d.bits.your_fathers_choice = 1;
    d.bits.socially_acceptable = 1;
    d.bits.financially_viable = 1;
    d.bits.do_you_aptitude = 1;
    d.bits.do_you_likeit = 1;

    return d;
}

// Compute decision based on conditions
void make_decision(union decision *d) {
    // Example rule: decision is 1 if you like it AND it’s viable
    d->bits.decision = (d->bits.do_you_likeit && d->bits.financially_viable);
}

// Print a narrative
void print_decision(union decision d) {
    printf("Narrative:\n");
    if (d.bits.your_choice) printf("- You want to do it.\n");
    if (d.bits.your_mothers_choice) printf("- Your mother agrees.\n");
    if (d.bits.your_fathers_choice) printf("- Your father agrees.\n");
    if (d.bits.socially_acceptable) printf("- Society finds it acceptable.\n");
    if (d.bits.financially_viable) printf("- It is financially viable.\n");
    if (d.bits.do_you_aptitude) printf("- You have the aptitude.\n");
    if (d.bits.do_you_likeit) printf("- You like it.\n");

    printf("Final decision = %d\n", d.bits.decision);
}

// Interpret flags as a number
void print_conclusion_based_on_flags(union decision d) {
    printf("Flags value = %u\n", d.flags);

    // Example interpretation: count set bits
    int count = 0;
    unsigned char temp = d.flags;
    while (temp) {
        count += temp & 1;
        temp >>= 1;
    }
    printf("Interpretation: %d positive factors out of 8.\n", count);
}

int main() {
    union decision d = input();
    make_decision(&d);
    print_decision(d);
    print_conclusion_based_on_flags(d);
    return 0;
}
