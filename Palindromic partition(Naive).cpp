#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int low,int high)
{
	high=high-1;
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
int partition(string s,int i,int j)
{
	if(isPalindrome(s,i,j))
	   return 0;
    int res=INT_MAX;
	for(int k=i;k<j;k++)
	{
		res=min(res,1+partition(s,i,k)+partition(s,k+1,j));
	}
	return res;
}
int main()
{
	string str="abbabbc";
	cout<<"The number of Palindromic partition is "<<partition(str,0,str.length());
	return 0;
}
