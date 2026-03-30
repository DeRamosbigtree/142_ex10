#include <stdio.h>

#define N 4

int main() {
    int nopts[N + 2];          // array of tops of stacks
    int option[N + 2][N + 2];  // array of stacks of options
    int start, move, i, candidate;

    move = start = 0;
    nopts[start] = 1;

    while (nopts[start] > 0) {              // while dummy stack is not empty
        if (nopts[move] > 0) {              // if current stack is not empty
            move++;
            nopts[move] = 0;                // initialize new move

            if (move > N) {                 // solution found
                for (i = 1; i < move; i++) {
                    printf("%2d ", option[i][nopts[i]]);
                }
                printf("\n");
            } else {                        // find candidates
                // consider N down to 1 as valid candidates
                for (candidate = N; candidate >= 1; candidate--) {
                    // check for duplicates
                    last = option[move - 1][nopts[move - 1]];
					for (candidate = N; candidate > last; candidate--) {
                    last = option[move - 1][nopts[move - 1]];
for (candidate = N; candidate > last; candidate--) {
    option[move][++nopts[move]] = candidate;
}    
                }
            }
        } else {
            move--;                         // backtrack
            nopts[move]--;                  // pop current choice from previous move
        }
    }

    return 0;
}
