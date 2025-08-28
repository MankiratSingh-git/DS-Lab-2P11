#include <stdio.h>
int main() {
    int arr[100], size, i;
    printf("enter number of elements: ");
    scanf("%d", &size);
    printf("enter elements: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("reversed array: ");
    for (i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    return 0;
}