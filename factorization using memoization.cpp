#include<bits/stdc++.h>
using namespace std;
int fact(int n,int mem[])
{
	if(mem[n]==-1)
	{
		if(n==0 ||n==1)
		  return n;
		mem[n]=fact(n-1,mem)+fact(n-2,mem);
	}
	return mem[n];
}
int main()
{
	int n;
	cout<<"Enter the number ";
	cin>>n;
	int mem[n+1];
	for(int i=0;i<=n;i++)
	  mem[i]=-1;
	cout<<"The factorial of "<<n<<" is "<<fact(n,mem);
	return 0;
}
