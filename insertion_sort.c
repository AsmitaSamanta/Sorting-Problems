#include<stdio.h>
#include<stdlib.h>
int main()
{
int *a,i,j,c,n;
printf("\nPlease enter the number of elements : ");
scanf("%d",&n);
a=(int *)malloc(n*(sizeof(int)));
printf("\nNow enter the elements one by one :\n");
for(i=0;i<n;i++)
	scanf("%d",&a[i]);
for(i=0;i<n;i++)
{
	c=a[i];
	j=i-1;
	while(j>=0 && a[j]>c)
	{
		a[j+1]=a[j];
		j=j-1;
	}
	a[j+1]=c;
}
printf("The sorted array is :\n");
for(i=0;i<n;i++)
	printf("%d ",a[i]);
printf("\n\n");
}
