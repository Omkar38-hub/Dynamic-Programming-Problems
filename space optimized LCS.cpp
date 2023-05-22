// using linear space for this O(n)
#include<bits/stdc++.h>
using namespace std;
	int lcs(string str1,string str2)
	{
	    int n=str1.length();
	    int m=str2.length();
	    int mp[2][m+1];
	    bool b;
	    for(int i=0;i<=n;i++)
	    {
	    	b=i&1;
	        for(int j=0;j<=m;j++)
	        {
	        	if(i==0 || j==0)
	        	   mp[b][j]=0;
	            else if(str1[i-1]==str2[j-1])
	               mp[b][j]=1+mp[1-b][j-1];
	            else
	            {
	                if(mp[b][j-1]>mp[1-b][j])
	                  mp[b][j]=mp[b][j-1];
	                else
	                  mp[b][j]=mp[1-b][j];
	            }
	        }
	    }
	   return mp[b][m];
	}
int main()
{
	string str1="axyz";
	string str2="baz";
	cout<<"the length of longest common subsequence of "<<str1<<" and "<<str2<<endl;
	cout<<"is "<<lcs(str1,str2)<<" \n";
	return 0;
}

// time complexity O(m*n)
 // space complexity O(n)
