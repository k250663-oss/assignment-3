#include <stdio.h>

struct Book {
    int id;
    int pop;
    int lastused;
    int valid;
};

int main() {
    int capacity, Q;
    scanf("%d %d", &capacity, &Q);

    struct Book shelf[capacity];
    for (int i = 0; i < capacity; i++) {
        shelf[i].valid = 0;
    }

    int time = 0;

    for (int j = 0; j < Q; j++) {
        char op;
        printf("enter A/a for ADD and C/c for ACCESS: ");
        scanf(" %c", &op);

        if (op == 'A' || op == 'a') {
            int x, y;
            scanf("%d %d", &x, &y);
            time++;

            int found = -1;
            for (int k = 0; k < capacity; k++) {
                if (shelf[k].valid && shelf[k].id == x) {
                    found = k;
                    break;
                }
            }

            // Update existing book
            if (found != -1) {
                shelf[found].pop = y;
                shelf[found].lastused = time;
            }
            else {
                // Find empty slot
                int empty = -1;
                for (int a = 0; a < capacity; a++) {
                    if (!shelf[a].valid) {
                        empty = a;
                        break;
                    }
                }

                // Insert new in empty slot
                if (empty != -1) {
                    shelf[empty].id = x;
                    shelf[empty].pop = y;
                    shelf[empty].lastused = time;
                    shelf[empty].valid = 1;
                }
                else {
                    // No empty slot → remove LRU
                    int leastIndex = 0;
                    int leastTime = shelf[0].lastused;

                    for (int b = 1; b < capacity; b++) {
                        if (shelf[b].valid && shelf[b].lastused < leastTime) {
                            leastTime = shelf[b].lastused;
                            leastIndex = b;
                        }
                    }

                    shelf[leastIndex].id = x;
                    shelf[leastIndex].pop = y;
                    shelf[leastIndex].lastused = time;
                }
            }
        }

        else if (op == 'C' || op == 'c') {
            int x;
            scanf("%d", &x);
            time++;

            int found = -1;

            for (int i = 0; i < capacity; i++) {
                if (shelf[i].valid && shelf[i].id == x) {
                    found = i;
                    break;
                }
            }

            if (found != -1) {
                shelf[found].lastused = time;
                printf("%d\n", shelf[found].pop);
            } else {
                printf("-1\n");
            }
        }

        else {
            printf("wrong input");
            break;
        }
    }
    return 0;
}
