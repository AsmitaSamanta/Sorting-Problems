#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int merge(int *a,int l,int m,int u,int r)
{
int *b,*c,s1,s2,i,j,k;
s1=m-l+1;
s2=u-m;

}


int mergesort(int *a,int l,int u,int r)
{
int m,i;
if(l<u)
{
	m=l+(u-l)/2;
	mergesort(a,l,m,r);
	mergesort(a,m+1,u,r);
	r=merge(a,l,m,u,r);
}
return(r);
}


int main()
{
int *a,i,r,n,t,b[100],max,min,s;
float avg;
FILE *g;
srand(time(0));
g=fopen("Merge_Sort_time_complexity.xlsx","w+");
for(n=1000;n<=3000;n=n+100)
{
	s=0;
	for(t=0;t<100;t++)
	{
		a=(int *)malloc(n*(sizeof(int)));
		for(i=0;i<n;i++)
			a[i]=rand();
		r=0;
		r=mergesort(a,0,n-1,r);
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
