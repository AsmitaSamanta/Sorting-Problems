#include<stdio.h>
#include<stdlib.h>

void merge(int *a,int l,int m,int u,int max)
{
int i,j,k;
i=l;
j=m+1;
k=l;
while(i<=m && j<=u)
{
	if((a[i]%max)<(a[j]%max))
	{
		a[k]=a[k]+(a[i]%max)*max;
		i++;
		k++;
	}
	else
	{
		a[k]=a[k]+(a[j]%max)*max;
		j++;
		k++;
	}
}
while(i<=m)
{
	a[k]=a[k]+(a[i]%max)*max;
	i++;
	k++;
}
while(j<=u)
{
	a[k]=a[k]+(a[j]%max)*max;
	j++;
	k++;
}
for(i=l;i<=u;i++)
	a[i]=a[i]/max;
}


void mergesort(int *a,int l,int u,int max)
{
int m,i;
if(l<u)
{
	m=l+(u-l)/2;
	mergesort(a,l,m,max);
	mergesort(a,m+1,u,max);
	merge(a,l,m,u,max);
}
}

int main()
{
int *a,i,n,max;
printf("\nPlease enter the number of elements : ");
scanf("%d",&n);
a=(int *)malloc(n*(sizeof(int)));
printf("\nNow enter the elements one by one :\n");
for(i=0;i<n;i++)
	scanf("%d",&a[i]);
max=a[0];
for(i=1;i<n;i++)
{
	if(max<a[i])
		max=a[i];
}

max=max+5;
mergesort(a,0,n-1,max);

printf("\nThe sorted array is :\n");
for(i=0;i<n;i++)
	printf("%d  ",a[i]);
printf("\n\n");
}






