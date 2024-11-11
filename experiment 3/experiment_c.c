#include <stdio.h>

int search(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main() {
    int n, x, i;
    
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter element to search: ");
    scanf("%d", &x);
    
    int result = search(arr, n, x);

    if (result == -1)
        printf("Element is not present in array\n");
    else
        printf("Element is present at index: %d\n", result);

    return 0;
}
