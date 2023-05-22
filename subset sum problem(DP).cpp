#include<bits/stdc++.h>
using namespace std;

int subSet(int a[],int n,int sum)
{
	int dp[n+1][sum+1];
	for(int i=0;i<=n;i++)
	    dp[i][0]=1;
	for(int j=1;j<=sum;j++)
	    dp[0][j]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(j<a[i-1])
			   dp[i][j]=dp[i-1][j];
			else
			{
				dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i-1]];
			}
		}
	}
	return dp[n][sum];
}
int main()
{
	int a[]={2,3,5};
	int sum=5;
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"The number of subset having sum "<<sum<<" from given array "<<subSet(a,n,sum);
	return 0;
}
