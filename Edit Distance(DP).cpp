#include<bits/stdc++.h>
using namespace std;

int Ed(string str1,string str2,int m,int n)
{
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++)
	   dp[i][0]=i;
	for(int j=0;j<=n;j++)
	   dp[0][j]=j;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(str1[i-1]==str2[j-1])
			   dp[i][j]=dp[i-1][j-1];
			else
			{
				dp[i][j]=1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]}); // inserting element in last position,
	                               //deleting last element of str1,replace last element of str1
			}
		}
	}
	return dp[m][n];
}
int main()
{
	string str1="cat";
	string str2="cut";
	int n=str2.length();
	int m=str1.length();
	cout<<"The length of edited distance  is "<<Ed(str1,str2,m,n);
	return 0;
}

// time complexity is O(m*n)
