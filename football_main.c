#include "football.h"
#include <stdio.h>

int main() {
    int score;

    while (1) {
        printf("\nEnter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) break; // STOP if 0 or 1

        printf("\nPossible combinations of scoring plays (Enter 0 to stop):\n");
        print_combinations(score); 
    }

    return 0;
}
