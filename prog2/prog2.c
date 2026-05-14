#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

// Write array of structures to ASCII file
void writeRecords(Student students[], int n, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d %s %.2f\n", students[i].id, students[i].name, students[i].marks);
    }
    fclose(fp);
}

// Create array of seek positions
long* createSeekPositions(const char *filename, int n) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file!\n");
        return NULL;
    }

    long *positions = (long*) malloc(n * sizeof(long));
    if (!positions) {
        printf("Memory allocation failed!\n");
        fclose(fp);
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        positions[i] = ftell(fp);   // store current position
        char buffer[200];
        fgets(buffer, sizeof(buffer), fp); // move to next line
    }

    fclose(fp);
    return positions;
}

// Display record given position
void displayRecord(const char *filename, long pos) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    fseek(fp, pos, SEEK_SET);
    char buffer[200];
    if (fgets(buffer, sizeof(buffer), fp)) {
        printf("Record: %s", buffer);
    } else {
        printf("Could not read record at position %ld\n", pos);
    }

    fclose(fp);
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    Student students[n];
    for (int i = 0; i < n; i++) {
        printf("Enter ID, Name, Marks for student %d: ", i+1);
        scanf("%d %s %f", &students[i].id, students[i].name, &students[i].marks);
    }

    const char *filename = "students.txt";
    writeRecords(students, n, filename);

    long *positions = createSeekPositions(filename, n);
    if (positions) {
        int choice;
        printf("Enter record number to display (1-%d): ", n);
        scanf("%d", &choice);

        if (choice >= 1 && choice <= n) {
            displayRecord(filename, positions[choice-1]);
        } else {
            printf("Invalid record number!\n");
        }

        free(positions);
    }

    return 0;
}
