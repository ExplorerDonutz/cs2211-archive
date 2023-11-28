
#include <stdio.h>

int main(void) {
    int days;
    int start;

    printf("Enter number of days in month: ");
    scanf("%d", &days);

    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &start);

    for (int i = 0; i < start - 1; i++) {
        printf("   ");
    }

    for (int i = 1; i <= days; i++) {
	printf("%2d ", i);
	
	if ((i + start - 1) % 7 == 0) {
	    printf("\n");
	}
    }

    printf("\n");

    return 0;
}
