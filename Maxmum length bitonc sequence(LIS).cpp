//Bitonic subsequence= The subsequence that first increasing then decreasing

#include<bits/stdc++.h>
using namespace std;

int LIS(int a[],int n)
{
	int lis[n];
	lis[0]=1;
	for(int i=1;i<n;i++)
	{
		lis[i]=1;
		for(int j=0;j<i;j++)
		{
			if(a[i]>a[j])
			{
				lis[i]=max(lis[i],1+lis[j]);
			}
		}
	}
	int lds[n]; // longest decreasing subsequence
	lds[n-1]=1;
	for(int i=n-2;i>=0;i--)
	{
		lds[i]=1;
		for(int j=n-1;j>i;j--)
		{
			if(a[i]>a[j])
			{
				lds[i]=max(lds[i],1+lds[j]);
			}
		}
	}
	// Now find maximum from array of lis an lds;
	int mx=INT_MIN;
	for(int i=0;i<n;i++)
	{
		mx=max(mx,lis[i]+lds[i]-1);
	}
	return mx;
}
int main()
{
	int a[]={1,11,2,10,4,5,2,1};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"The maximum length bitonic sequence is "<<LIS(a,n)<<endl;
	return 0;
}

// Time complexity O(n^2)
