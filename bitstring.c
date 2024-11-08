#include<stdio.h>
#include<stdlib.h>
#define n 10
int main()
{
    int u[n]={1,2,3,4,5,6,7,8,9,10};
    int a[]={2,3,5,9,10};
    int b[]={2,4,6,8,10};
    int us[n],sa[n],sb[n],su[n],ub[n],si[n];
    int i,j,k=0;
    int p,q,r,t;
    system("clear");
    p=sizeof(a[0]);
    q=sizeof(b[0]);
    r=p+1+q+1;

    for (i=0;i<n;i++)
    {
        printf("%d  ",u[i]);
    }
    printf(" : Universal Set\n");

    for (i=0;i<p+1;i++)
    {
        printf("%d  ",a[i]);
    }
    printf(" : Subset A\n");

    for (i=0;i<q+1;i++)
    {
        printf("%d  ",b[i]);
    }
    printf(": Subset B\n\n");

    for (i=0;i<n;i++)
    {
        if(u[i]!=-1)
        {
            us[i]=1;
            printf("%d  ",us[i]);
        }
    }
    printf(" : Union Bitstring\n");

    for(i=0;i<n;i++)
    {
        t=0;
        for(j=0;j<p+1;j++)
        {
            if (a[j]==u[i])
            {
                t=1;
                break;
            }
        }
        if (t==1)
        {
            sa[i]=1;
        }
        else
        {
            sa[i]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d  ",sa[i]);
    }
    printf(" : Bitstring A\n");

    for(i=0;i<n;i++)
    {
        t=0;
        for(j=0;j<q+1;j++)
        {
            if (b[j]==u[i])
            {
                t=1;
                break;
            }
        }
        if (t==1)
        {
            sb[i]=1;
        }
        else
        {
            sb[i]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d  ",sb[i]);
    }
    printf(" : Bitstring B\n\n");  


    for (i = 0; i < r; i++)
    {
        if ((sa[i] == 1) || (sb[i] == 1))
        {
            su[k] = u[i];
            k++;
        }
    }  
    for (i=0;i<k;i++)
    {
        printf("%d  ",su[i]);
    }
    printf(" : Union of Subset\n");

    
    for(i=0;i<r;i++)
    {
        if(sa[i]==1 || sb[i]==1)
        {
            si[i]=1;
        }
        else
        {
            si[i]=0;
        }
    }
    for (i=0;i<r;i++)
    {
        printf("%d  ",si[i]);
    }
    printf(" : Union of Subset Bitstring\n");
    
    
    
    
    
    for(i=0;i<r;i++)
    {
        if(sa[i]==1 && sb[i]==1)
        {
            si[i]=1;
        }
        else
        {
            si[i]=0;
        }
    }
    for (i=0;i<r;i++)
    {
        printf("%d  ",si[i]);
    }
    printf(" : Intersection of bitstring subset\n");

    k = 0;
    for (i = 0; i < r; i++)
    {
        if (si[i] == 1) 
        {
            si[k] = u[i];
            printf("%d  ",si[k]);
            k++;
        }
    }

    printf(" : Intersection of subset\n");
    return 0;
}
