#include<stdio.h>

void main()
{
 //sorting 1st arr
 int i,j,n,s,t;
 printf("Enter lmt(1st arr): ");
 scanf("%d",&n);
 printf("Enter the elements:\n");
 int a[n];
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 printf("1st array:\n");
 for(i=0;i<n;i++)
 {
  printf("%d  ",a[i]);
 }
 for(i=0;i<n;i++)
 {
  s=i;
  for(j=i+1;j<n;j++)
  {
   if(a[s]>a[j])
   {
    s=j;
   }
  }
  if(1!=s)
  {
   t=a[s];
   a[s]=a[i];
   a[i]=t;
  }
 }
 printf("Sorted array(1st):\n");
 for(i=0;i<n;i++)
 {
  printf("%d  ",a[i]);
 }
 getch();
}