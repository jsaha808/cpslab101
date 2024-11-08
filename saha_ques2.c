#include <stdio.h>
#include <math.h>

// Function to calculate the mean
double calculateMean(int arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

// Function to calculate the mode
int calculateMode(int arr[], int n) {
    int maxValue = arr[0], maxCount = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxValue = arr[i];
        }
    }
    return maxValue;
}

// Function to calculate the standard deviation
double calculateStdDev(int arr[], int n, double mean) {
    double sumOfSquares = 0;
    for (int i = 0; i < n; i++) {
        sumOfSquares += pow(arr[i] - mean, 2);
    }
    return sqrt(sumOfSquares / n);
}

int main() {
    int scores[5] = {10, 7, 5, 9, 10};
    int n = 5;

    // Calculate mean
    double mean = calculateMean(scores, n);
    
    // Calculate mode
    int mode = calculateMode(scores, n);
    
    // Calculate standard deviation
    double stdDev = calculateStdDev(scores, n, mean);
    
    // Print results
    printf("Mean: %.2lf\n", mean);
    printf("Mode: %d\n", mode);
    printf("Standard Deviation: %.2lf\n", stdDev);

    return 0;
}