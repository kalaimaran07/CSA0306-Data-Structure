#include <stdio.h>
void merge(int a[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0, temp[r - l + 1];
    while (i <= m && j <= r)
        temp[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    for (i = l, k = 0; i <= r; i++) a[i] = temp[k++];
}
void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
int main() {
    int n, a[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    mergeSort(a, 0, n - 1);
    printf("Sorted: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}
