#include<stdio.h>
#include<stdlib.h>
int main()
{
int *a,i,j,c,n,f;
printf("\nPlease enter the number of elements : ");
scanf("%d",&n);
a=(int *)malloc(n*(sizeof(int)));
printf("\nNow enter the elements one by one :\n");
for(i=0;i<n;i++)
	scanf("%d",&a[i]);
for(i=n-1;i>0;i--)
{
	f=1;
	for(j=0;j<i;j++)
	{
		if(a[j]>a[j+1])
		{
			c=a[j];
			a[j]=a[j+1];
			a[j+1]=c;
			f=f*0;
		}
	}
	if(f==1)
		break;
}
printf("The sorted array is :\n");
for(i=0;i<n;i++)
	printf("%d ",a[i]);
printf("\n\n");
}
