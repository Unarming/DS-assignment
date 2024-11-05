// Design, Develop and Implement the following menu driven Programs in C/C++ using Array
// operations
// a. Write a program for Bubble Sort algorithm
// b. Write a program for Merge Sort algorithm
// c. Write a program for Radix Sort algorithm
// d. Write a program for Insertion Sort algorithm
// e. Write a program for Selection Sort algorithm


#include<stdio.h>
int main()
{
    int n, i,arr[50],j,temp;
    printf("Enter total number of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements in array:\n",n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Sorting array using bubble sort technique..\n");
    for(i=0;i<(n-1);i++)
    {
        for(j=0;j<(n-i-1);j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("Elements sorted successfully!\n");
    printf("Sorted list in ascending order:\n");
   for(i=0; i<n; i++)
   {
     printf("%d ",arr[i]);
   }
   return 0;
    
}