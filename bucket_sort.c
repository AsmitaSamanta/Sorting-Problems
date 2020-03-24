#include<stdio.h>
#include<stdlib.h>
int main()
{
int *a,*b,i,j,n,max;
printf("\nEnter the array size : ");
scanf("%d",&n);
a=(int *)malloc(n*(sizeof(int)));
printf("\nEnter the array elements one by one : ");
scanf("%d",&a[0]);
max=a[0];
for(i=1;i<n;i++)
{
	scanf("%d",&a[i]);
	if(max<a[i])
		max=a[i];
}
b=(int *)malloc((max+1)*(sizeof(int)));
for(i=0;i<=max;i++)
	b[i]=0;
for(i=0;i<n;i++)
	b[a[i]]=b[a[i]]+1;
printf("\nThe sorted array is :\n");
for(i=0;i<=max;i++)
	if(b[i]!=0)
		for(j=1;j<=b[i];j++)
			printf("%d  ",i);
printf("\n\n");
}
