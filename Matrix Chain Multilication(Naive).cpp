#include<bits/stdc++.h>
using namespace std;

int mChain(int a[],int i,int j)
{
	if(i==j-1)
	  return 0;
	int res=INT_MAX;
	for(int k=i+1;k<j;k++)
	{
		res=min(res,mChain(a,i,k)+mChain(a,k,j)+(a[i]*a[k]*a[j]));
	}
	return res;
}
int main()
{
	int arr[]={20,10,30,40};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"The number of multiplication is "<<mChain(arr,0,n-1)<<"\n";//20000
	return 0;
}
//Time complexity is exponential
