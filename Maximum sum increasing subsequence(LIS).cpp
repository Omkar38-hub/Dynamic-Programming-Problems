#include<bits/stdc++.h>
using namespace std;

int LIS(int a[],int n)
{
	int lis[n];
	lis[0]=a[0];
	for(int i=1;i<n;i++)
	{
		lis[i]=a[i];
		for(int j=0;j<i;j++)
		{
			if(a[i]>a[j])
			{
				lis[i]=max(lis[i],a[i]+lis[j]);
			}
		}
	}
	// Now find maximum from array of lis;
	int result=lis[0];
	for(int i=1;i<n;i++)
	   result=max(result,lis[i]);
	return result;
}
int main()
{
	int a[]={3,20,4,6,7,30};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"The maximum sum increasing sequence is "<<LIS(a,n)<<endl;
	return 0;
}

// Time complexity O(n^2)
