#include<bits/stdc++.h>
using namespace std;

int Jump(int a[],int n)
{
	int dp[n];
	dp[0]=0;
	for(int i=1;i<n;i++)
	   dp[i]=INT_MAX;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(j+a[j]>=i)
			{
				if(dp[j]!=INT_MAX)
				   dp[i]=min(dp[i],dp[j]+1);
			}
		}
	}
	return dp[n-1];
}

int main()
{
	int a[]={4,1,5,3,1,3,2,1,8};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"The number of jump requred to reach end is "<<Jump(a,n);
	return 0;
}
// time complexity=O(n^2)
// time complextiy=O(n);
