#include<bits/stdc++.h>
using namespace std;
	string lcs(string str1,string str2)
	{
	    int n=str1.length();
	    int m=str2.length();
	    int mp[n+1][m+1];
	    for(int i=0;i<=n;i++)
	      mp[i][0]=0;
	    for(int j=0;j<=m;j++)
	       mp[0][j]=0;
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=m;j++)
	        {
	            if(str1[i-1]==str2[j-1])
	               mp[i][j]=1+mp[i-1][j-1];
	            else
	            {
	                if(mp[i][j-1]>mp[i-1][j])
	                  mp[i][j]=mp[i][j-1];
	                else
	                  mp[i][j]=mp[i-1][j];
	            }
	        }
	    }
	    int len= mp[n][m];
	    cout<<"the length of LCS is "<<len<<"\n";
	   int i=n,j=m;
	   string lcsStr="";
	   while(i>0 && j>0)
	   {
		if(str1[i-1]==str2[j-1])
		{
			lcsStr=str1[i-1]+lcsStr;
			i--;
			j--;
		}
		else if(mp[i-1][j]>mp[i][j-1])
		  i--;
		else
		   j--;
	   }
	   return lcsStr;
	}
int main()
{
	string str1="axyz";
	string str2="baz";
	cout<<"the longest common subsequence of "<<str1<<" and "<<str2<<endl;
	cout<<"is "<<lcs(str1,str2)<<" \n";
	return 0;
}

// time complexity O(m*n)
 // space complexity O(m*n)
