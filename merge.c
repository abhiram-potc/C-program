#include<stdio.h>
#include<stdlib.h>
int main()
{
 //reading 1st arr
 int i,j,n,s,t;
 system("clear");
 printf("Enter limit(1st arr): ");
 scanf("%d",&n);
 int a[n];
 printf("Enter the elements:\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 
 //reading 2nd array
 int k,m,r,q;
 printf("Enter the limit(2nd arr): ");
 scanf("%d",&m);
 int b[m];
 printf("Enter the elements:\n");
 for(k=0;k<m;k++)
 {
  scanf("%d",&b[k]);
 }
 
 //displaying array
 printf("\n1st array:\n");
 for(i=0;i<n;i++)
 {
  printf("%d  ",a[i]);
 }
 
 printf("\n2nd array:\n");
 for(k=0;k<m;k++)
 {
  printf("%d  ",b[k]);
 }
 
 //sorting 1st array 
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
  if(i!=s)
  {
   t=a[s];
   a[s]=a[i];
   a[i]=t;
  }
 }


 //sorting 2nd array
 for(k=0;k<m;k++)
 {
  r=k;
  for(q=k+1;q<m;q++)
  {
   if(b[r]>b[q])
   {
    r=q;
   }
  }
  if(k!=r)
  {
   t=b[r];
   b[r]=b[k];
   b[k]=t;
  }
 }
 
 //listing sorted arrays
 printf("\nSorted array(1st):\n");
 for(i=0;i<n;i++)
 {
  printf("%d  ",a[i]);
 }
 //printf("\n");
 
 printf("\nSorted array(2nd):\n");
 for(k=0;k<m;k++)
 {
  printf("%d  ",b[k]);
 }
 printf("\n");
 
 //merging
 int p,u;
 p=n+m;
 int c[p];
 for(i=0;i<n;i++)
 {
  c[u++]=a[i];
 }
 for(k=0;k<m;k++)
 {
  c[u++]=b[k];
 }
 printf("Merged array:\n");
 for(u=0;u<p;u++)
 {
  printf("%d  ",c[u]);
 }
 printf("\n");
 return 0;
}