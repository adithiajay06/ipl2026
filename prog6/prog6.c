#include <stdio.h>
#include <math.h>

#define SIZE 40   // buffer size (rows and columns)

// Structure for Circle
struct Circle {
    int x;       // center x
    int y;       // center y
    int radius;  // radius
};

// Function 1: Initialize buffer
void initBuffer(char buffer[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            buffer[i][j] = ' '; // fill with spaces
        }
    }
}

// Function 2: Draw circle into buffer
void drawCircle(struct Circle c, char buffer[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int dx = j - c.x;
            int dy = i - c.y;
            double distance = sqrt(dx*dx + dy*dy);

            // if distance is close to radius, mark '*'
            if (fabs(distance - c.radius) < 0.5) {
                buffer[i][j] = '*';
            }
        }
    }
}

// Function 3: Print buffer
void printBuffer(char buffer[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c", buffer[i][j]);
        }
        printf("\n");
    }
}

// Function 4: Test circle drawing
void testCircle() {
    char buffer[SIZE][SIZE];
    struct Circle c = {SIZE/2, SIZE/2, 10}; // center and radius

    initBuffer(buffer);
    drawCircle(c, buffer);
    printBuffer(buffer);
}

int main() {
    testCircle();
    return 0;
}
