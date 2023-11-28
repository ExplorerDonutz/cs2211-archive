/**
 * @name intToEnglish
 * @author Michael Quick (251287228)
 * This program takes an inputted integer and turns it into its English equivalent word
 */

#include <stdio.h>

// All the ones in english
static const char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

// All the "special" tens in english
static const char *special[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
                                "seventeen", "eighteen", "nineteen"};

// All the tens excluding the special cases 10-19 in english
static const char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

/**
 * Converts the inputted value into english and prints it
 * @param value the value to be converted
 */
void intToEnglish(int value) {
    // Check if the value is greater than  or equal to 100
    if (value >= 100) {
        // Print the hundred value
        printf("%s hundred", ones[value / 100]);
        // Remove the hundreds place
        value %= 100;
        if (value > 0) {
            // If there is more digits, print and
            printf(" and ");
        } else {
            // No more digits, add a new line
            printf("\n");
            return;
        }
    }

    // Check if there is a tens value greater than or equal to 20
    if (value >= 20) {
        // Print the value
        printf("%s", tens[value / 10]);
        if (value % 10 != 0) {
            // Print the ones digit and a new line
            printf("-%s\n", ones[value % 10]);
        } else {
            // There is no remaining ones digit, only print a new line
            printf("\n");
        }
    } else if (value >= 10) {
        // Print the value of 11-19 and a new line
        printf("%s\n", special[value - 10]);
    } else if (value > 0) {
        // Print the ones value and a new line
        printf("%s\n", ones[value]);
    }
}

int main(void) {
    int value;

    // Endlessly loop until broken (value == 0)
    while (1) {
        // Prompt user for a value
        printf("Please enter a value (1-999, 0 to quit): ");
        scanf("%d", &value);

        // Value is zero, break the loop
        if (value == 0) {
            break;
        } else if (value >= 1 && value <= 999) {
            // Convert and print the value in english
            intToEnglish(value);
        } else {
            // Prompt user if they gave an invalid input
            printf("Invalid input!");
        }
    }
    return 0;
}