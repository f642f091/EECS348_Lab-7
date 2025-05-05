#include "football.h"
#include <stdio.h>

int scores[] = {8, 7, 6, 3, 2};
const char* labels[] = {"TD+2", "TD+1", "TD", "FG", "Safety"};
int num_options = 5;

void print_combination(int counts[]) {
    for (int i = 0; i < num_options; i++) {
        printf("%6d", counts[i]);
    }
    printf("\n");
}

void find_combinations(int target, int index, int current_sum, int counts[]) {
    if (current_sum > target) return;

    if (index == num_options) {
        if (current_sum == target) print_combination(counts);
        return;
    }

    for (int i = 0; i <= target / scores[index]; i++) {
        counts[index] = i;
        find_combinations(target, index + 1, current_sum + i * scores[index], counts);
    }
}

int count_helper(int score, int index, int current_sum) {
    if (current_sum > score) return 0;
    if (index == num_options) return current_sum == score ? 1 : 0;

    int count = 0;
    for (int i = 0; i <= score / scores[index]; i++) {
        count += count_helper(score, index + 1, current_sum + i * scores[index]);
    }
    return count;
}

int count_combinations(int score) {
    return count_helper(score, 0, 0);
}


void print_combinations(int score) {
    int counts[5] = {0};
    find_combinations(score, 0, 0, counts);
}
