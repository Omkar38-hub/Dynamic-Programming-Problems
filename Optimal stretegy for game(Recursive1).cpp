#include<bits/stdc++.h>
using namespace std;
int Sol(int a[],int i,int j,int sum)
{
	if(i+1==j)
	  return max(a[i],a[j]);
	return max(sum-Sol(a,i+1,j,sum-a[i]),sum-Sol(a,i,j-1,sum-a[j]));
}
int mainSol(int a[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	  sum+=a[i];
	return Sol(a,0,n-1,sum);
}
int main()
{
	int a[]={2,3,15,7};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"The values collected by Player1 "<<mainSol(a,n)<<"\n";
	return 0;
}
