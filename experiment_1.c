//Design, Develop and Implement a menu driven Program in C/C++ for the following Array
// operations
// a. Creating an Array of N Integer Elements
// b. Display of Array Elements with Suitable Headings
// c. Inserting an Element at a given valid Position (POS)
// d. Deleting an Element at a given valid Position(POS)
// e. Exit.
// Support the program with functions for each of the above operations

#include<stdio.h>
int a[10],n,elem,i,pos;
void create()
{
    printf("Enter the size of the array element <=9: ");
    scanf("%d",&n);
   printf("\nEnter the elements for the array:\n");
   for(i=0; i<n; i++){
    scanf("%d",&a[i]);
   }
}
void display()
{
    int i; 
    printf("\nThe array elements are:\n");
    for(i=0; i<n; i++){
     printf("%d ",a[i]);
    }
}
void insert() //inserting an element in to an array
{
printf("\nEnter the position for the new element: ");
scanf("%d",&pos);
printf("\nEnter the element to be inserted: ");
scanf("%d",&elem);
pos=pos-1;
for(i=n-1; i>=pos; i--)
{
  a[i+1] = a[i];
}
a[pos] = elem;
n = n+1;
} //end of insert()
void del() //deleting an array element
{
printf("\nEnter the position of the element to be deleted: ");
scanf("%d",&pos);
pos=pos-1;
elem = a[pos];
for(i=pos; i<n-1; i++)
{
a[i] = a[i+1];
}
n = n-1;
printf("\nThe deleted element is\n",elem);
}//end of delete()
int main()
{
int ch;
create();
display();
printf("\n\n--------Menu ----------\n");
printf("1.Insert\n 2.Delete\n 3.Exit\n");
printf(" ");
printf("\nEnter your choice: ");
scanf("%d",&ch);
switch(ch)
{
    case 1: insert();
            display();
            break;
    case 2: del();
            display();
            break;
    case 3:
            break;
    default: printf("\nInvalid choice:\n");
            break;
}
return 0;
}