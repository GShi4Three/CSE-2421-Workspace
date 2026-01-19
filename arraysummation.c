#include <stdio.h>

int main()
{
    int arr[] = {5, 10, 15, 20, 25};
    int length = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += arr[i];
    }

    printf("Sum of array elements: %d\n", sum);

    return 0;
}
