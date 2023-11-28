/**
 * @name Converter
 * @author Michael Quick (251287228)
 * This program takes in user information about a conversion they would like to make and prints the desired conversion
 */

#include <stdio.h>
#include <ctype.h>

// Conversion constants
static const float POUNDS_PER_KILOGRAM = 2.20462;
static const float ACRES_PER_HECTARE = 2.47105;
static const float GALLONS_PER_LITRE = 0.264172;
static const float MILES_PER_KILOMETER = 0.621371;

float kiloToPound(float kilo) {
    return kilo * POUNDS_PER_KILOGRAM;
}

float poundToKilo(float pound) {
    return pound / POUNDS_PER_KILOGRAM;
}

float hectaresToAcres(float hectares) {
    return hectares * ACRES_PER_HECTARE;
}

float acresToHectares(float acres) {
    return acres / ACRES_PER_HECTARE;
}

float litresToGallons(float litres) {
    return litres * GALLONS_PER_LITRE;
}

float gallonsToLitres(float gallons) {
    return gallons / GALLONS_PER_LITRE;
}

float kilometresToMiles(float kilometres) {
    return kilometres * MILES_PER_KILOMETER;
}

float milesToKilometres(float miles) {
    return miles / MILES_PER_KILOMETER;
}

int main(void) {
    int choice = 0;
    float value = 0;
    float convertedValue = 0;

    // Loop until the quit option is selected
    while (choice != 5) {
        // Reset values
        choice = 0;
        value = 0;
        convertedValue = 0;

        // Loop until a valid option is selected
        while (choice < 1 || choice > 5) {
            // Print options, then get the desired option
            printf("What would you like to do?\n"
                   "1. Convert between kilograms and pounds\n"
                   "2. Convert between hectares and acres\n"
                   "3. Covert between litres and gallons\n"
                   "4. Covert between kilometres and miles\n"
                   "5. Quit\n");
            scanf("%d", &choice);

            // Invalid input, prompt user for a valid option
            if (choice < 1 || choice > 5)
                printf("Please enter a valid option\n");
        }

        char conversionType = 0;

        // Determine which conversion to use, or do nothing if the program should quit
        switch (choice) {
            case 1:
                // Loop until a valid option is selected
                while (conversionType != 'K' && conversionType != 'P') {
                    // Ask if the user wants to convert from kilograms to pounds or vice versa
                    printf("Please select which way you like to convert\n"
                           "K - Kilograms to pounds\n"
                           "P - Pounds to kilograms\n");

                    // Store the option as a char
                    scanf(" %c", &conversionType);

                    // Make the char uppercase if the user forgot to
                    conversionType = toupper(conversionType);

                    if (conversionType != 'K' && conversionType != 'P')
                        printf("Please enter a valid option\n");
                }

                // Get the initial value that is to be converted
                printf("Please enter a value...\n");
                scanf("%f", &value);

                // Determine which conversion to make and then get and display the converted value
                if (conversionType == 'K')
                    printf("Your conversion is... %f lb\n", kiloToPound(value));
                else if (conversionType == 'P')
                    printf("Your conversion is... %f kg\n", poundToKilo(value));

                break;

            case 2:
                // Loop until a valid option is selected
                while (conversionType != 'H' && conversionType != 'A') {
                    // Ask if the user wants to convert from hectares to acres or vice versa
                    printf("Please select which way you like to convert\n"
                           "H - Hectares to acres\n"
                           "A - Acres to hectares\n");

                    // Store the option as a char
                    conversionType = 0;
                    scanf(" %c", &conversionType);

                    // Make the char uppercase if the user forgot to
                    conversionType = toupper(conversionType);

                    if (conversionType != 'H' && conversionType != 'A')
                        printf("Please enter a valid option\n");
                }

                // Get the initial value that is to be converted
                printf("Please enter a value...\n");
                scanf("%f", &value);

                // Determine which conversion to make and then get and display the converted value
                if (conversionType == 'H')
                    printf("Your conversion is... %f ac\n", hectaresToAcres(value));
                else if (conversionType == 'A')
                    printf("Your conversion is... %f ha\n", acresToHectares(value));
                break;

            case 3:
                // Loop until a valid option is selected
                while (conversionType != 'L' && conversionType != 'G') {
                    // Ask if the user wants to convert from litres to gallons or vice versa
                    printf("Please select which way you like to convert\n"
                           "L - Litres to gallons\n"
                           "G - Gallons to litres\n");

                    // Store the option as a char
                    conversionType = 0;
                    scanf(" %c", &conversionType);

                    // Make the char uppercase if the user forgot to
                    conversionType = toupper(conversionType);

                    if (conversionType != 'L' && conversionType != 'G')
                        printf("Please enter a valid option\n");
                }

                // Get the initial value that is to be converted
                printf("Please enter a value...\n");
                scanf("%f", &value);

                // Determine which conversion to make and then get and display the converted value
                if (conversionType == 'L')
                    printf("Your conversion is... %f gal\n", litresToGallons(value));
                else if (conversionType == 'G')
                    printf("Your conversion is... %f L\n", gallonsToLitres(value));
                break;
            case 4:
                // Loop until a valid option is selected
                while (conversionType != 'K' && conversionType != 'M') {
                    // Ask if the user wants to convert from kilometres to miles or vice versa
                    printf("Please select which way you like to convert\n"
                           "K - Kilometres to miles\n"
                           "M - Miles to Kilometres\n");

                    // Store the option as a char
                    conversionType = 0;
                    scanf(" %c", &conversionType);

                    // Make the char uppercase if the user forgot to
                    conversionType = toupper(conversionType);

                    if (conversionType != 'K' && conversionType != 'M')
                        printf("Please enter a valid option\n");
                }

                // Get the initial value that is to be converted
                printf("Please enter a value...\n");
                scanf("%f", &value);

                // Determine which conversion to make and then get and display the converted value
                if (conversionType == 'K')
                    printf("Your conversion is... %f mi\n", kilometresToMiles(value));
                else if (conversionType == 'M')
                    printf("Your conversion is... %f km\n", milesToKilometres(value));
        }
    }

    return 0;
}