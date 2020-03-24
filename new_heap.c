#include<stdio.h>
#include<stdlib.h>

/*int heap(int *a,int i,int l)
{
int m,p,c=0;
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
}
return(c);
}*/

/*int maxheap(int *a,int l,int r)
{
int i,node,m,p;
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
		r=r+2;
		node=m;
	}
	else
		break;
}
return(r);
}*/

/*int build_heap(int *a,int l,int k)
{
int i,c;
for(i=0;i<=l;i++)
{
	c=heap(a,i,l);
	k=k+2;
	while(i!=0 && c==1)
	{
		i=(i-1)/2;
		c=heap(a,i,l);
		k=k+2;
	}
}
for(i=0;i<=l;i++)
	printf("%d  ",a[i]);
printf("\n");
return(k);
}*/


int main()
{
int *a,i,n,p,k=0,r,node,c,l,m;
printf("Please enter the number of elements : ");
scanf("%d",&n);
a=(int *)malloc(n*(sizeof(int)));
printf("\nPlease enter the elements one by one :\n");
for(i=0;i<n;i++)
	scanf("%d",&a[i]);

l=n-1;
for(i=0;i<=n-1;i++)
{
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
	}
	k=k+2;
	while(i!=0 && c==1)
	{
		i=(i-1)/2;
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
		}
		k=k+2;
	}
}

printf("\nAfter making heap we get :\n");
for(i=0;i<=l;i++)
	printf("%d  ",a[i]);
printf("\n\nTime for heap building :\t%d\n\n",k);


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
			r=r+2;
			node=m;
		}
		else
			break;
	}
	p=a[i];
	a[i]=a[0];
	a[0]=p;
}
printf("The sorted array is :\n");
for(i=0;i<n;i++)
	printf("%d  ",a[i]);
printf("\n\nTime for sorting :\t%d\n\n",r);
}
