#include<bits/stdc++.h>
using namespace std;

int eggDrop(int e,int f)
{
	int dp[f+1][e+1];
	// e=0 is invalid
	for(int i=1;i<=e;i++)
	{
		dp[0][i]=0;
		dp[1][i]=1;
	}
	for(int j=1;j<=f;j++)// only 1 egg
	   dp[j][1]=j;
	for(int i=2;i<=f;i++)
	{
		for(int j=2;j<=e;j++)
		{
			dp[i][j]=INT_MAX;
			for(int x=1;x<=f;x++)
			{
				dp[i][j]=min(dp[i][j],1+max(dp[x-1][j-1],dp[i-x][j]));
			}
		}
	}
	return dp[f][e];
}
int main()
{
	int f=3,e=2;
	cout<<"The minimum number of trail required is "<<eggDrop(e,f)<<"\n";
	return 0;
}
// time complexity= O(e*f^2)
// space complexity =O(e*f)
