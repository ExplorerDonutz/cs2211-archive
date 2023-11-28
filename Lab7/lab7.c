#include <stdio.h>

#define LEN 3

int sum_array(const int *a, int size) {
    int i, sum = 0;
    for (i = 0; i < size; i++) {
        sum += *a;
        a++;
    }
    return sum;
}

int sum_two_dimensional_array(const int a[][LEN], int size) {
    int sum = 0;
    const int *ptr = &a[0][0];  // Initialize a pointer to the beginning of the array

    for (int i = 0; i < size * LEN; i++) {
        sum += *ptr;  // Add the value pointed to by ptr to the sum
        ptr++;       // Move the pointer to the next element
    }

    return sum;
}

int main(void) {
    int a[] = {1, 2, 3};
    printf("Sum of array: %d\n", sum_array(a, 3));

    int array[][LEN] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    int size = 3; // The number of rows in the array

    int result = sum_two_dimensional_array(array, size);

    printf("Sum of the 2D array: %d\n", result);

    return 0;
}
