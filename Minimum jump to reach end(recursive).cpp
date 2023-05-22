#include<bits/stdc++.h>
using namespace std;

int Jump(int a[],int n)
{
	if(n==1)
	  return 0;
	int res=INT_MAX;
	for(int i=0;i<=n-2;i++)
	{
		if(i+a[i]>=n-1)
		{
			int sub=Jump(a,i+1);
			if(sub!=INT_MAX)
			   res=min(res,sub+1);
		}
	}
	return res;
}
int main()
{
	int a[]={4,1,5,3,1,3,2,1,8};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"The number of jump requred to reach end is "<<Jump(a,n);
	return 0;
}
// time complexity=O(2^n)
// time complextiy=O(n);
