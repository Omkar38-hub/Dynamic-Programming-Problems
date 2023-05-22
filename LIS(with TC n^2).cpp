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
	// Now find maximum from array of lis;
	int result=lis[0];
	for(int i=1;i<n;i++)
	   result=max(result,lis[i]);
	return result;
}
int main()
{
	int a[]={3,4,2,8,10,5,1};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"The length of longest increasing subsequence is "<<LIS(a,n)<<endl;
	return 0;
}

// Time complexity O(n^2)
