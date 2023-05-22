#include<bits/stdc++.h>
using namespace std;

int getMin(int a[],int n,int val)
{
	if(val==0)
	   return 0;
	int res=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(a[i]<=val)
		{
			int sub=getMin(a,n,val-a[i]);
			if(sub!=INT_MAX)
			    res=min(res,sub+1);
		}
	}
	return res;
}
int main()
{
	int a[]={25,10,5};
	int val=30;
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"The minimum coins required to make value "<<val<<" is "<<getMin(a,n,val);
	return 0;
}
