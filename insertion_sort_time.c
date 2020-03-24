#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
int *a,i,j,r,c,n,t,b[100],max,min,s;
float avg;
FILE *f;
srand(time(0));
f=fopen("Insertion_Sort_time_complexity.xlsx","w+");
for(n=100;n<=1000;n=n+100)
{
	s=0;
	for(t=0;t<100;t++)
	{
		a=(int *)malloc(n*(sizeof(int)));
		for(i=0;i<n;i++)
			a[i]=rand();
		r=0;
		for(i=0;i<n;i++)
		{
			c=a[i];
			j=i-1;
			while(j>=0 && a[j]>c)
			{
				a[j+1]=a[j];
				j=j-1;
				r++;
			}
			a[j+1]=c;
		}
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
	fprintf(f,"%d\t%f\t%f\t%f\n",n,(min*1.0)/(n*n),(max*1.0)/(n*n),avg/(n*n));
}
fclose(f);
}
