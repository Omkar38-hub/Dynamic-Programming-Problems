#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int low,int high)
{
	while(low<high)
	{
		if(s[low]==s[high])
		{
			low++;
			high--;
		}
		else
		  return false;
	}
	return true;
}
int partition(string s)
{
	int n=s.length();
	int dp[n][n];
	for(int i=0;i<n;i++)
	  dp[i][i]=0;
	for(int gap=1;gap<n;gap++)
	{
		for(int i=0;i+gap<n;i++)
		{
			int j=i+gap;
			if(isPalindrome(s,i,j))
			  dp[i][j]=0;
			else
			{
				dp[i][j]=INT_MAX;
				for(int k=i;k<j;k++)
				{
					dp[i][j]=min(dp[i][j],1+dp[i-1][k]+dp[k+1][j]);
				}
			}
		}
	}
	return dp[0][n-1];
}
int main()
{
	string str="abbabbc";
	cout<<"The number of Palindromic partition is "<<partition(str);
	return 0;
}
// time complexity is O(n^3)
