// a string which contain both the string

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
	    cout<<"the length of supersequence is "<<n+m-len<<"\n";
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
void supersequence(string str1,string str2)
{
	string res=lcs(str1,str2);
	int n=str1.length();
	int m=str2.length();
	int i=0,j=0,k=0;
	string ans="";
	while(k<res.length() && i<n && j<m)
	{
		while(str1[i]!=res[k])
		{
			ans+=str1[i];
			i++;
		} 
		while(str2[j]!=res[k])
		{
			ans+=str2[j];
			j++;
		}  
		ans+=res[k];
		i++;
		j++;
		k++; 
	}
	cout<<ans<<endl;
}
int main()
{
	string str1="AGGTAB", str2 = "GXTXAYB"; //output :- "AGGXTXAYB"
	cout<<"\n\nThe supersequence string is ";
	supersequence(str1,str2);
	return 0;
}
