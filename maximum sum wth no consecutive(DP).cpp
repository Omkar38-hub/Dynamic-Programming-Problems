#include<bits/stdc++.h>
using namespace std;

int Sum(int a[],int n)
{
	int dp[n+1];
	dp[0]=0;
	dp[1]=a[0];
	dp[2]=max(a[0],a[1]);
	for(int i=3;i<=n;i++)
	   dp[i]=max(dp[i-1],a[i-1]+dp[i-2]);
	return dp[n];
}
int main()
{
	int a[]={10,5,15,20,2,30};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"The maximum sum is "<<Sum(a,n);
	return 0;
}

// time complexity O(n)
// space complexity O(n)
