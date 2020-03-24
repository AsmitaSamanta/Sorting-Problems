#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int merge(int *a,int l,int m,int u,int r,int max)
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
	r++;
}
while(i<=m)
{
	a[k]=a[k]+(a[i]%max)*max;
	i++;
	k++;
	//r++;
}
while(j<=u)
{
	a[k]=a[k]+(a[j]%max)*max;
	j++;
	k++;
	//r++;
}
for(i=l;i<=u;i++)
{
	a[i]=a[i]/max;
	//r++;
}
return(r);
}


int mergesort(int *a,int l,int u,int r,int max)
{
int m,i;
if(l<u)
{
	m=l+(u-l)/2;
	r=mergesort(a,l,m,r,max);
	r=mergesort(a,m+1,u,r,max);
	r=merge(a,l,m,u,r,max);
}
return(r);
}


int main()
{
int *a,i,r,n,t,b[100],max,min,s,maxim;
float avg;
FILE *g;
srand(time(0));
g=fopen("Merge_Sort_inspace_time_complexity(compare only).xlsx","w+");
for(n=1000;n<=3000;n=n+100)
{
	s=0;
	for(t=0;t<100;t++)
	{
		a=(int *)malloc(n*(sizeof(int)));
		for(i=0;i<n;i++)
			a[i]=rand();
		r=0;
		maxim=a[0];
		for(i=1;i<n;i++)
		{
			if(maxim<a[i])
				maxim=a[i];
		}
		r=mergesort(a,0,n-1,r,maxim);
		b[t]=r;
		s=s+b[t];
	}
	min=b[0];
	max=b[0];
	for(t=1;t<100;t++)
	{
		if(b[t]<min)
			min=b[t];
		if(b[t]>max)
			max=b[t];
	}
	avg=(s*1.0)/100;
	fprintf(g,"%d\t%f\t%f\t%f\n",n,(min*1.0)/(n*log2(n)),(max*1.0)/(n*log2(n)),avg/(n*log2(n)));
}
fclose(g);
}
