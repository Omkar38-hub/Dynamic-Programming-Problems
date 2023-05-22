#include<bits/stdc++.h>
using namespace std;

int Ed(string str1,string str2,int m,int n)
{
	if(m==0)
	  return n;
	if(n==0)
	  return m;
	if(str1[m-1]==str2[n-1])
	  return Ed(str1,str2,m-1,n-1);
	else
	  return 1+min({Ed(str1,str2,m,n-1),Ed(str1,str2,m-1,n),Ed(str1,str2,m-1,n-1)});// inserting element in last position,
	                               //deleting last element of str1,replace last element of str1
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
// time complexity is exponential
