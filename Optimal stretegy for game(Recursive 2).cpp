#include<bits/stdc++.h>
using namespace std;
int Sol(int a[],int i,int j)
{
	if(i+1==j)
	  return max(a[i],a[j]);
	return max(a[i]+min(Sol(a,i+2,j),Sol(a,i+1,j-1)),
	           a[j]+min(Sol(a,i+1,j-1),Sol(a,i,j-2)));
}

int main()
{
	int a[]={2,3,15,7};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"The values collected by Player1 "<<Sol(a,0,n-1)<<"\n";
	return 0;
}
