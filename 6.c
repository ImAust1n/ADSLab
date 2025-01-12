#include <stdio.h>

void TOH(int n, char F, char T, char A) {
    if (n == 1) {
        printf("Move Disk 1 from %c to %c\n", F, T);
        return;
    }

    TOH(n - 1, F, A, T);
    printf("Move Disk %d from %c to %c\n", n, F, T);
    TOH(n - 1, A, T, F);
}

int main() {
    TOH(3, 'A', 'C', 'B');
    return 0;
}