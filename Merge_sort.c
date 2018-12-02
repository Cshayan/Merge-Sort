#include <stdio.h>
#include <stdlib.h>

/*merge two arrays :- arr[low....mid] and arr[mid+1....high]*/
void merge(int arr[], int low, int mid, int high)
{
    int m=(mid - low)+1;
    int n=(high - mid);  //high-(mid+1)+1= high- mid

    int left[m], right[n];  // two temporary arrays

    int i, j, k;
    // copy the data to temporary arrays
    for(i=0; i<m; i++)
    {
        left[i]= arr[low+i];
    }
    for(i=0; i<n; i++)
    {
        right[i]= arr[mid+1+i];
    }
    i=0; j=0; k=low;

    while(i<m && j<n)
    {
        if(left[i] <= right[j] )
        {
            arr[k++]=left[i++];
        }
        else
        {
            arr[k++]=right[j++];
        }
    }
    while(i< m)
    {
        arr[k++]= left[i++];
    }
    while(j< n)
    {
        arr[k++]= right[j++];
    }

}
void merge_sort(int arr[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid= (low+high)/2;

        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);

        merge(arr, low, mid, high);
    }

}
int main()
{
    int *arr;
    int n, i, low, high;
    printf("\nEnter the size of the array:- ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    printf("\nEnter the array to be sorted:- \n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    low = 0; high = n-1;
    merge_sort(arr, low, high);
    printf("\nAfter sorting :-\n ");
    for(i=0; i< n; i++)
        printf("%d\t", arr[i]);

        printf("\n");
}
