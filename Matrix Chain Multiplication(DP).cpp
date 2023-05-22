#include<bits/stdc++.h>
using namespace std;
int mChain(int N, int arr[])
    {
        int dp[N][N];
        for(int i=0;i<N-1;i++)
           dp[i][i+1]=0;
        for(int gap=2;gap<N;gap++)
        {
            for(int i=0;i+gap<N;i++)
            {
                int j=i+gap;
                dp[i][j]=INT_MAX;
                for(int k=i+1;k<j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+arr[i]*arr[k]*arr[j]);
                }
            }
        }
        return dp[0][N-1];
    }
int main()
{
	int arr[]={40, 20, 30, 10, 30}; //the most efficient way is (A*(B*C))*D. 
                                    //The number of operations are 20*30*10 + 40*20*10 + 40*10*30 = 26000.
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"The number of multiplication is "<<mChain(n,arr)<<"\n";//26000
	return 0;
}  
//Time complexity is O(n^3)
// Auxillary  Space is theta(n^2)
