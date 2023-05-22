#include<bits/stdc++.h>
using namespace std;

int ceilIndex(int tail[],int l,int r,int x)
{
	while(r>l)
	{
		int m=l+(r-l)/2;
		if(tail[m]>=x)
	  		r=m;
		else
	  		l=m+1;
	}
	return r;
}
int LIS(int a[],int n)
{
	int tail[n];
	tail[0]=a[0];
	int len=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]>tail[len-1])
		{
			tail[len]=a[i];
			len++;
		}
		else
		{
			int index=ceilIndex(tail,0,len-1,a[i]);
			tail[index]=a[i];
		}
	}
	return len;
}
int main()
{
	int a[]={3,10,20,4,6,7};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"The length of longest increasing subsequence is "<<LIS(a,n)<<endl;
	return 0;
}

// time complexity =O(n*log(n))
