#include<bits/stdc++.h>
using namespace std;
int Sol(int a[],int n)
{
	int dp[n][n];
	for(int i=0;i<n-1;i++)
	   dp[i][i+1]=max(a[i],a[i+1]);
	for(int gap=3;gap<n;gap++)
	{
		for(int i=0;i+gap<n;i++)
		{
			int j=i+gap;
			dp[i][j]=max(a[i]+min(dp[i+2][j],dp[i+1][j-1]),a[j]+min(dp[i+1][j-1],dp[i][j-2]));
		}
	}
	return dp[0][n-1];
}

int main()
{
	int a[]={20,5,4,6,8,3};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"The values collected by Player1 "<<Sol(a,n)<<"\n";
	return 0;
}
// time complexity =O(n^2)
// spacecomplexity =O(n^2)
