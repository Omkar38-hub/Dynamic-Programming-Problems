#include<bits/stdc++.h>
using namespace std;
int knapSack(int W, int wt[], int val[], int n) 
    { 
       int dp[n+1][W+1];
       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=W;j++)
           {
               if(i==0 || j==0)
                  dp[i][j]=0;
               else if(wt[i-1]<=j)
               {
                   dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
               }
               else
                  dp[i][j]=dp[i-1][j];
           }
       }
       return dp[n][W];
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


// time complexity=O(n*W)
// time complextiy=O(n*W);
