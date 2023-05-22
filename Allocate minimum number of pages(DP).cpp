#include<bits/stdc++.h>
using namespace std;

int sum(int a[],int i,int j)
{
	int sum=0;
	for(int k=i;k<=j;k++)
	   sum+=a[k];
	return sum;
}
int minPages(int a[],int n,int k)
{
	int dp[k+1][n+1];
	for(int i=1;i<=n;i++)
	  dp[1][i]=sum(a,0,i-1);
	for(int i=1;i<=k;i++)
	  dp[i][1]=a[0];
	for(int i=2;i<=k;i++){
        for(int j=2;j<=n;j++){
            int res=INT_MAX;
            for(int p=1;p<j;p++){
                res=min(res,max(dp[i-1][p],sum(a,p,j-1)));
            }
            dp[i][j]=res;
        }
    }
    return dp[k][n];
}
int main()
{
	int a[]={10,5,30,1,2,5,10,10};
	int k=3;
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"The minimum pages to the student is "<<minPages(a,n,k);
	return 0;
}

// time complexity is O(n^3*k)
