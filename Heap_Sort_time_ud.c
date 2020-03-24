#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>


int main()
{
int *a,i,j,r,p,n,t,c,l,m,node,k,b[100],d[100],maxr,minr,maxk,mink,sr,sk;
float avgr,avgk;
FILE *g;
srand(time(0));
g=fopen("Heap_Sort_time_complexity_up_combined.xlsx","w+");
for(n=1000;n<=2000;n=n+100)
{
	sr=0;
	sk=0;
	for(t=0;t<100;t++)
	{
		a=(int *)malloc(n*(sizeof(int)));
		for(i=0;i<n;i++)
			a[i]=rand();
		r=0;
		k=0;
		l=n-1;
		for(j=n-1;j>=0;j--)
		{
			i=(j-1)/2;
			c=0;
			if((2*i+1)<=l)
			{
				if((2*i+2)<=l && a[2*i+1]<a[2*i+2])
					m=2*i+2;
				else
					m=2*i+1;
				if(a[m]>a[i] && m<=l)
				{
					p=a[m];
					a[m]=a[i];
					a[i]=p;
					c=1;	
				}
				k=k+1;
			}
			i=m;
			while(i<=(n/2-1) && c==1)
			{
				//i=(i-1)/2;
				c=0;
				if((2*i+1)<=l)
				{
					if((2*i+2)<=l && a[2*i+1]<a[2*i+2])
						m=2*i+2;
					else
						m=2*i+1;
					if(a[m]>a[i] && m<=l)
					{
						p=a[m];
						a[m]=a[i];
						a[i]=p;
						c=1;
					}
					k=k+1;
				}
				i=m;	
			}
		}
		r=k;
		p=a[n-1];
		a[n-1]=a[0];
		a[0]=p;
		for(i=n-2;i>0;i--)
		{
			l=i;
			node=0;
			while(node<=(l-1)/2)
			{
				if((2*node+2)<=l && a[2*node+1]<a[2*node+2])
					m=2*node+2;
				else
					m=2*node+1;
				if(a[m]>a[node])
				{
					p=a[m];
					a[m]=a[node];
					a[node]=p;
					r=r+1;
					node=m;
				}
				else
					break;
			}
			p=a[i];
			a[i]=a[0];
			a[0]=p;
		}
		b[t]=r;
		d[t]=k;
		//printf("\n%d\t%d\t%d\n",n,r,k);
		sr=sr+r;
		sk=sk+k;
	}
	minr=b[0];
	maxr=b[0];
	for(t=1;t<100;t++)
	{
		if(b[t]<minr)
			minr=b[t];
		if(b[t]>maxr)
			maxr=b[t];
	}
	avgr=(sr*1.0)/100;

	mink=d[0];
	maxk=d[0];
	for(t=1;t<100;t++)
	{
		if(d[t]<mink)
			mink=d[t];
		if(d[t]>maxk)
			maxk=d[t];
	}
	avgk=(sk*1.0)/100;


	//fprintf(g,"%d\t%f\t%f\t%f\t\t\t%d\t%f\t%f\t%f\n",n,(minr*1.0)/(n*log2(n)),(maxr*1.0)/(n*log2(n)),avgr/(n*log2(n)),n,(mink*1.0)/(n*log2(n)),(maxk*1.0)/(n*log2(n)),avgk/(n*log2(n)));
	fprintf(g,"%d\t%f\t%f\t%f\t\t\t%f\t%f\t%f\n",n,(mink*1.0)/n,(maxk*1.0)/n,avgk/(n),(minr*1.0)/(n*log2(n)),(maxr*1.0)/(n*log2(n)),avgr/(n*log2(n)));
}
fclose(g);
}
