#include<bits/stdc++.h>
using namespace std;

int Sum(int a[],int n)
{
	int prev_prev=a[0];
	int prev=max(a[0],a[1]);
	int res=prev;
	for(int i=3;i<=n;i++)
	{
	   res=max(prev,prev_prev+a[i-1]);
	   prev_prev=prev;
	   prev=res;
	}   
	return res;
}
int main()
{
	int a[]={10,5,15,20,2,30};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"The maximum sum is "<<Sum(a,n);
	return 0;
}

// time complexity O(n)
// space complexity O(1)
