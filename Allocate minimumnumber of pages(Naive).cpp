#include<bits/stdc++.h>
using namespace std;

int sum(int a[],int i,int j)
{
	int sum=0;
	for(int k=i;k<=j;k++)
	   sum+=a[k];
	return sum;
}
int minPages(int a[],int n,int k)
{
	if(k==1)
	  return sum(a,0,n-1);
	if(n==0)
	   return 0;
	int res=INT_MAX;
	for(int i=1;i<n;i++)
	  res=min(res,max(minPages(a,i,k-1),sum(a,i,n-1)));
	return res;
}
int main()
{
	int a[]={10,5,30,1,2,5,10,10};
	int k=3;
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"The minimum pages to the student is "<<minPages(a,n,k);
	return 0;
}

// time complexity is exponential
