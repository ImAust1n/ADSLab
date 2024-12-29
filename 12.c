#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of Elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int key;
    printf("Enter element to search for: ");
    scanf("%d", &key);

    int l = 0, h = n - 1, mid;
    while (l <= h)
    {
        mid = (l + h) / 2;

        if (arr[mid] == key)
        {
            printf("Element found at %dth index.\n", mid);
            return 0;
        }
        else if (arr[mid] > key)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("Element not found!\n");
    return 0;
}