#include <stdio.h>

int main(void) {
    int nums[4];

    printf("Enter four integers: ");
    scanf("%d %d %d %d", &nums[0], &nums[1], &nums[2], &nums[3]);

    int largest = nums[0];
    int smallest = nums[0];

    for (int i = 1; i < 4; i++) {
        if (nums[i] > largest) {
            largest = nums[i];
        }

        if (nums[i] < smallest) {
            smallest = nums[i];
        }
    }

    printf("\nLargest: %d\n", largest);
    printf("Smallest: %d\n", smallest);
    return 0;
}
