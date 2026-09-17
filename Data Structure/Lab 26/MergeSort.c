//WAP to implement Merge sort using array.

#include <stdio.h>
#define MAX 1000

int a[MAX];
int b[MAX];

void Merge(int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i = i + 1;
        } else {
            b[k] = a[j];
            j = j + 1;
        }
        k = k + 1;
    }

    while (i <= mid) {
        b[k] = a[i];
        i = i + 1;
        k = k + 1;
    }

    while (j <= high) {
        b[k] = a[j];
        j = j + 1;
        k = k + 1;
    }

    for (int x = low; x <= high; x++) {
        a[x] = b[x];
    }
}

void MergeSort(int low, int high) {
    if (low < high) {

        int mid = (low + high) / 2;

        MergeSort(low, mid);
        MergeSort(mid + 1, high);
        Merge(low, mid, high);
    }
}

void main() { 
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid size!\n");
        return;
    }

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    MergeSort(0, n - 1);

    printf("Sorted array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }\

    printf("\n");
}
