#include<bits/stdc++.h>
using namespace std;

int Sum(int a[],int n)
{
	if(n==1)
	  return a[0];
	if(n==2)
	  return max(a[0],a[1]);
	else
	  return max(Sum(a,n-1),Sum(a,n-2)+a[n-1]);
}
int main()
{
	int a[]={10,5,15,20,2,30};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"The maximum sum is "<<Sum(a,n);
	return 0;
}
