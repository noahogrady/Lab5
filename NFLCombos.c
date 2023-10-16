#include <stdio.h>

void find_combinations(int score) {
    if (score == 0) {
        printf("0 TD + 2pt, 0 TD + FG, 0 TD, 0 3pt FG, 0 Safety\n");
        return;
    }

    for (int eight = 0; eight <= (score / 8); eight++) {
        for (int seven = 0; seven <= (score / 7); seven ++) {
            for (int six = 0; six <= (score / 6); six ++) {
                for (int three = 0; three <= (score / 3); three ++) {
                    for (int two = 0; two <= (score / 2); two ++) {
                        int remainder = score-(eight * 8 + seven * 7 + six * 6 + three * 3 + two * 2);
                        if (remainder == 0) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", eight, seven, six, three, two);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter Score: ");
        scanf("%d", &score);
        
        if (score <= 1) {
            break;
        }
        
        printf("Possible combinations:\n");
        find_combinations(score);
    }

    return 0;
}


