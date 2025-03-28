#include <stdio.h>

// List of scoring options and their values
int scores[] = {8, 7, 6, 3, 2};
const char* labels[] = {"TD+2", "TD+1", "TD", "FG", "Safety"}; // col names
int num_options = 5; // # of columns

// Helper function to print a combination
void print_combination(int counts[]) {
    for (int i = 0; i < num_options; i++) {
        printf("%6d", counts[i]);
    }
    printf("\n");
}

// Recursive backtracking function
void find_combinations(int target, int index, int current_sum, int counts[]) {
    if (current_sum > target) return; // return if we pass the score

    if (index == num_options) { // considered all scoring types then it means that its the end and we should return
        if (current_sum == target) {
            print_combination(counts);
        }
        return;
    }

    // Try all possible counts of this scoring option
    /*For each count we add the points to curren_sum, sotre it in counts[index] and finally recurse to try the nex scoring type*/
    for (int i = 0; i <= target / scores[index]; i++) {
        counts[index] = i;
        find_combinations(target, index + 1, current_sum + i * scores[index], counts);
    }
}

int main() {
    int score;
    printf("Enter the NFL score: ");
    scanf("%d", &score); // get the input and store it in score

    if (score < 2) { // invalid input
        printf("Invalid score. Must be 2 or higher.\n");
        return 1;
    }

    printf("\nPossible combinations of scoring plays:\n");
    for (int i = 0; i < num_options; i++) {
        printf("%6s", labels[i]);
    }
    printf("\n");

    int counts[5] = {0};
    find_combinations(score, 0, 0, counts);

    return 0;
}
