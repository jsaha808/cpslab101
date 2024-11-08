#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 20  // Number of students

// Function prototypes
void read_scores(const char *filename, int scores[], int size);
double calculate_mean(int scores[], int size);
int calculate_mode(int scores[], int size);
double calculate_standard_deviation(int scores[], int size, double mean);

int main() {
    int scores[SIZE];
    const char *filename = "scores-data.txt";

    // Read scores from the file
    read_scores(filename, scores, SIZE);

    // Calculate mean
    double mean = calculate_mean(scores, SIZE);
    printf("Mean: %.2f\n", mean);

    // Calculate mode
    int mode = calculate_mode(scores, SIZE);
    printf("Mode: %d\n", mode);

    // Calculate standard deviation
    double standard_deviation = calculate_standard_deviation(scores, SIZE, mean);
    printf("Standard Deviation: %.2f\n", standard_deviation);

    return 0;
}

void read_scores(const char *filename, int scores[], int size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < size; i++) {
        if (fscanf(file, "%d", &scores[i]) != 1) {
            fprintf(stderr, "Error reading score at index %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
}

double calculate_mean(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return (double)sum / size;
}

int calculate_mode(int scores[], int size) {
    int max_count = 0;
    int mode = scores[0];

    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (scores[j] == scores[i]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            mode = scores[i];
        }
    }
    return mode;
}

double calculate_standard_deviation(int scores[], int size, double mean) {
    double sum_squared_diff = 0.0;
    for (int i = 0; i < size; i++) {
        sum_squared_diff += pow(scores[i] - mean, 2);
    }
    return sqrt(sum_squared_diff / size);
}