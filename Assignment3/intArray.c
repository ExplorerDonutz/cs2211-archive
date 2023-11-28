/**
 * @author Michael Quick (251287228)
 * @date 26/10/2023
 * Prints a variety of functions completed on an integer array given by the user
 */
#include <stdio.h>

/**
 * Prints the array of integers selected by the user
 * @param nums the array of integers to be used
 * @param num the total number of integers
 */
void printArray(int nums[], int num) {
    // Print all the integers from index 0 to index num - 2 with a comma and space at the end
    for (int i = 0; i < num - 1; i++) {
        printf("[%d] = %d, ", i, nums[i]);
    }

    // Print last index (num - 1) without a comma or space and add a new line
    printf("[%d] = %d\n", num - 1, nums[num - 1]);
}

/**
 * Prints the array of integers in reverse order
 * @param nums the array of integers to be used
 * @param num the total number of integers
 */
void printArrayReversed(int nums[], int num) {
    // Print all the integers from index num - 1 to 1 with a comma and space at the end
    for (int i = num - 1; i > 0; i--) {
        printf("[%d] = %d, ", i, nums[i]);
    }

    // Print integer at index 0 without a comma or space and add a new line
    printf("[%d] = %d\n", 0, nums[0]);
}

/**
 * Finds and prints all the even integers in the given array
 * @param nums the array of integers to be used
 * @param num the total number of integers
 */
void printEvens(int nums[], int num) {
    int even = 0;
    // Check if the remainder of the integer at index i is 0
    for (int i = 0; i < num; i++) {
        if (nums[i] % 2 == 0) {
            // If the remainder is 0, then this is an even number
            even++;
        }
    }

    int evens[even];
    int curr = 0;

    // Copy all the even numbers to the even array
    for (int i = 0; i < num; i++) {
        if (nums[i] % 2 == 0) {
            evens[curr] = nums[i];
            curr++;
        }
    }

    // Print the even array
    printArray(evens, even);
}

/**
 * Gets and prints a sum of all the integers in the given array
 * @param nums the array of integers to be used
 * @param num the total number of integers
 */
void arraySum(int nums[], int num) {
    int sum = 0;
    // Add all the integer values in the array
    for (int i = 0; i < num; i++) {
        sum += nums[i];
    }

    // Print the sum of the addition
    printf("The sum of all the values in your array is: %d", sum);
}

/**
 * Prints the given array in order
 * @param nums the array of integers to be used
 * @param num the total number of integers
 */
void printOrdered(int nums[], int num) {
    int indexes[num];
    int ordered[num];

    // Copy the original array to the array to be ordered
    for (int i = 0; i < num; i++) {
        ordered[i] = nums[i];
    }

    // Order the array by swapping each integer with any smaller integers that come after it in the array
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (ordered[i] > ordered[j]) {
                int temp = ordered[i];
                ordered[i] = ordered[j];
                ordered[j] = temp;
            }
        }
    }

    // Get each index from the original array for use in printing
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (ordered[i] == nums[j]) {
                indexes[i] = j;
            }
        }
    }

    // Print the ordered array with the indexes from the original array, which are now stored in indexes[]
    for (int i = 0; i < num - 1; i++) {
        printf("[%d] = %d, ", indexes[i], ordered[i]);
    }

    // Print last index without a comma or space and add a new line
    printf("[%d] = %d\n", indexes[num - 1], ordered[num - 1]);

}

/**
 * Prints the given array with the first and last values swapped
 * @param nums the integer array to be used
 * @param num  the total number of integers
 */
void firstLastSwap(int nums[], int num) {
    // Print the integer at index num - 1 (last value)
    printf("[%d] = %d, ", num - 1, nums[num - 1]);

    // Print integers from index 1 to index num - 2
    for (int i = 1; i < num - 1; i++) {
        printf("[%d] = %d, ", i, nums[i]);
    }

    // Print the integer at index 0 (first value)
    printf("[%d] = %d\n", 0, nums[0]);
}


int main(void) {
    int num = 0;

    // Get the number of integers that will be in the array (5-12)
    while (5 > num || num > 12) {
        printf("Please enter the number of integers to process: ");
        scanf("%d", &num);

        // If user puts an invalid number, prompt them
        if (5 > num || num > 12) {
            printf("Invalid input, please select a number between 5 and 12\n");
        }
    }
    
    int nums[num];

    printf("    There is enough room in your array for %d integers (%lu bytes)\n", num, sizeof(nums));
    printf("Please enter your integers separated by spaces: ");
    for (int i = 0; i < num; i++) {
        scanf("%d", &nums[i]);
    }

    // Print what function is about to be completed and perform said function (parts 1 - 6)
    printf("\nPart 1:\n   Your array is: ");
    printArray(nums, num);

    printf("Part 2:\n   Your array in reverse is: ");
    printArrayReversed(nums, num);

    printf("Part 3:\n   The even elements in the array is:");
    printEvens(nums, num);

    printf("Part 4:\n   The sum of all the values in your array is: ");
    arraySum(nums, num);

    printf("\nPart 5:\n   Your array in sorted order is: ");
    printOrdered(nums, num);

    printf("Part 6:\n   Your array with first and last element switched is: ");
    firstLastSwap(nums, num);

    return 0;
}
