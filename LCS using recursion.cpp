#include<bits/stdc++.h>
using namespace std;
int lcs(string str1,string str2,int n,int m)
{
	if(n==0 || m==0)
	  return 0;
	if(str1[n-1]==str2[m-1])
	{
		return 1+lcs(str1,str2,n-1,m-1);
	}
	else
	   return max(lcs(str1,str2,n,m-1),lcs(str1,str2,n-1,m));
}
int main()
{
	string str1="axyz";
	string str2="baz";
	cout<<"the length of longest common subsequence of "<<str1<<" and "<<str2<<endl;
	int n=str1.length();
	int m=str2.length();
	cout<<lcs(str1,str2,n,m)<<" \n";
	return 0;
}
