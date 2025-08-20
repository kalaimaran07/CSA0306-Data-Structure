#include <stdio.h>
int main() {
    int arr[100], n, i, pos, val, choice;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    while(1) {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        scanf("%d", &choice);
        if(choice == 1) { 
            printf("Enter position (1-%d) and value: ", n+1);
            scanf("%d%d", &pos, &val);
            for(i = n; i >= pos; i--)
                arr[i] = arr[i-1];
            arr[pos-1] = val;
            n++;
        }
        else if(choice == 2) { // Delete
            printf("Enter position (1-%d): ", n);
            scanf("%d", &pos);
            for(i = pos-1; i < n-1; i++)
                arr[i] = arr[i+1];
            n--;
        }
        else if(choice == 3) { 
            for(i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n");
        }
        else if(choice == 4)  
            break;
    }
    return 0;
}

