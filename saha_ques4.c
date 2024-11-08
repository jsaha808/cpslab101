#include <stdio.h>

int main() {
    int arr[10];
    int *ptr;
    int i, max;

    // Reading 10 integers from the user
    printf("Enter 10 integers: \n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Initializing the pointer to the array
    ptr = arr;
    
    // Initializing max with the first element of the array
    max = *ptr;

    // Finding the maximum using pointers
    for (i = 1; i < 10; i++) {
        if (*(ptr + i) > max) {
            max = *(ptr + i);
        }
    }

    // Printing the maximum value
    printf("The maximum value among the entered integers is: %d\n", max);

    return 0;
}