#include<bits/stdc++.h>
using namespace std;
	int lcs(string str1,string str2)
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
	    return mp[n][m];
	}
	int minOperations(string str1, string str2) 
	{ 
	    int x=lcs(str1,str2);
	    int res=str1.length()+str2.length()-2*x;
	    return res;
	} 
int main()
{
	string str1="heap";
	string str2="pea";
	cout<<"the minimum insertion and deletion toconvert "<<str1<<" to  "<<str2<<endl;
	cout<<minOperations(str1,str2)<<" \n";
	return 0;
}
