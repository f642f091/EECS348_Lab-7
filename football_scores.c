#include <stdio.h> // std input/output

int scores[] = {8, 7, 6, 3, 2}; // possible scores
const char* labels[] = {"TD+2", "TD+1", "TD", "FG", "Safety"}; // col names
int num_options = 5; // # of scoring types

// print one combination
void print_combination(int counts[]) {
    for (int i = 0; i < num_options; i++) {
        printf("%6d", counts[i]); // print each column
    }
    printf("\n");
}

// recursive printing
void find_combinations(int target, int index, int current_sum, int counts[]) {
    if (current_sum > target) return; // skip if over

    if (index == num_options) { // base case
        if (current_sum == target) print_combination(counts); // exact match
        return;
    }

    for (int i = 0; i <= target / scores[index]; i++) { // try all counts
        counts[index] = i; // store current count
        find_combinations(target, index + 1, current_sum + i * scores[index], counts); // next type
    }
}

// recursive counting
int count_helper(int score, int index, int current_sum) {
    if (current_sum > score) return 0; // skip if over
    if (index == num_options) return current_sum == score ? 1 : 0; // base case

    int count = 0; // local total
    for (int i = 0; i <= score / scores[index]; i++) { // try all counts
        count += count_helper(score, index + 1, current_sum + i * scores[index]); // recurse
    }
    return count;
}

// required by test
int count_combinations(int score) {
    return count_helper(score, 0, 0); // start from 0
}

int main() {
    int score; // input from user
    printf("Enter the NFL score: ");
    scanf("%d", &score); // read score

    if (score < 2) {
        printf("Invalid score. Must be 2 or higher.\n"); // invalid input
        return 1;
    }

    printf("\nPossible combinations of scoring plays:\n");
    for (int i = 0; i < num_options; i++) {
        printf("%6s", labels[i]); // print labels
    }
    printf("\n");

    int counts[5] = {0}; // track scoring type counts
    find_combinations(score, 0, 0, counts); // start recursion

    return 0; // done
}
