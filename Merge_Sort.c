

	#include<stdio.h>
	#include<stdlib.h>
	int p=1,n;
	void merge(int *a,int l,int m,int u)
	{
		int i,j,k,*R,*S;
		R=(int *)malloc((m-l+1)*(sizeof(int)));
		S=(int *)malloc((u-m)*(sizeof(int)));
		for(i=0;i<(m-l+1);i++)
			R[i]=a[i+l];
		for(j=0;j<(u-m);j++)
			S[j]=a[j+m+1];
		i=0;
		j=0;
		k=l;
		while(i<m-l+1 && j<u-m)
		{
			if(R[i]<=S[j])
			{
				a[k]=R[i];
				i++;
				k++;
			}
			else
			{
				a[k]=S[j];
				j++;
				k++;
			}
		}

		while(i<m-l+1)
		{
			a[k]=R[i];
			i++;
			k++;
		}
		while(j<u-m)
		{
			a[k]=S[j];
			j++;
			k++;
		}
	}


	void mergesort(int *a,int l,int u)
	{
		int m,i;
		if(l<u)
		{
			m=l+(u-l)/2;
			printf("\nSTEP %d :\t",p);
			p++;

			for(i=l;i<=u;i++)
				printf("%d  ",a[i]);
			mergesort(a,l,m);
			printf("\nSTEP %d :\t",p);
			p++;
			
			for(i=l;i<=m;i++)
				printf("%d  ",a[i]);
			mergesort(a,m+1,u);
			printf("\nSTEP %d :\t",p);
			p++;
			
			for(i=m+1;i<=u;i++)
				printf("%d  ",a[i]);
			merge(a,l,m,u);
			printf("\nSTEP %d :\t",p);
			p++;
			
			for(i=l;i<=u;i++)
				printf("%d  ",a[i]);
		}
	}

	int main()
	{
		int *a,i;
		printf("\nPlease enter the number of elements : ");
		scanf("%d",&n);
		a=(int *)malloc(n*(sizeof(int)));
		printf("\nNow enter the elements one by one :\n");

		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		mergesort(a,0,n-1);

		printf("\nThe sorted array is :\n");
		for(i=0;i<n;i++)
			printf("%d  ",a[i]);
		printf("\n\n");
	}






