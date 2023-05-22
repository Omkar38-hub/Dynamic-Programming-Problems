// Here given one string you have to find the longest palindrome of that
// concept used is LCs

//another string would be the reverse of that string

#include<bits/stdc++.h>
using namespace std;
void lcs(string str1,string str2)
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
	    cout<<"the length of palindrome is "<<len<<"\n";
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
	   cout<<lcsStr<<endl;
	}
int main()
{
	string str1="geeksforgeeks";
	string str2=str1;
	cout<<" The given string is "<<str1<<"\n";
	reverse(str2.begin(),str2.end());
	cout<<"So the other string for applying LCS idea is reeverse of first is "<<str2<<"\n\n";
	cout<<"The palindrome string is\n";
	lcs(str1,str2);
	return 0;
}
