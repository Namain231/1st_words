#include <stdio.h>

int main() {
    char current, previous;
    int max_count = 1, current_count = 1;
    int first = 1; 

    while (scanf("%c", &current) == 1 && current != '\n') {
        if (first) {
            previous = current;
            first = 0;
            continue;
        }

        if (current == previous) {
            current_count++;
            if (current_count > max_count) {
                max_count = current_count;
            }
        } else {
            current_count = 1;
            previous = current;
        }
    }

    printf("%d\n", max_count);
    return 0;
}
