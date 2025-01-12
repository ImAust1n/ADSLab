#include <stdio.h>
#define MAX 25

int arr[MAX], n = 0;

void display() {
    printf("Elements are: ");
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void create() {
    printf("Enter size: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    display();
}

void insert() {
    int pos, item;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos > n) {
        printf("Position not found!");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &item);

    for (int i = n; i > pos; i++) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = item;
    n++;
}

void delete() {
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos > n - 1) {
        printf("Position not found!");
        return;
    }

    for (int i = pos; i < n; i++) {
        arr[i] = arr[i + 1];
    }

    n--;
}

int main() {
    int choice;
    create();
    printf("1. Insert a number");
    printf("\n2. Delete a number");
    printf("\n3. Display the array");
    printf("\n4. Exit\n");
    do {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice");
        }
    } while(1);
}
