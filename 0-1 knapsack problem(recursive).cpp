#include<bits/stdc++.h>
using namespace std;

int knapSack(int W,int wt[],int val[],int n)
{
	if(n==0 || W==0)
	  return 0;
	int res=INT_MIN;
	if(wt[n-1]>W)
	{
		return knapSack(W,wt,val,n-1);
	}
	else
	{
		return max(knapSack(W,wt,val,n-1),val[n-1]+knapSack(W-wt[n-1],wt,val,n-1));
	}
}

int main()
{
	int val[]={10,40,30,50};
	int wt[]={5,4,6,3};
	int W=10;
	int n=sizeof(val)/sizeof(val[0]);
	cout<<"The maximum value picked in the kanpsack of capacity "<<W<<endl;
	cout<<knapSack(W,wt,val,n);
	return 0;
}

// time complexity=O(2^n)
// time complextiy=O(n);
