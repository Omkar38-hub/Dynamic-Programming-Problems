#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
	int mem[n+1];
	mem[0]=0;
	mem[1]=1;
	for(int i=2;i<=n;i++)
	   mem[i]=mem[i-1]+mem[i-2];
	return mem[n];
}
int main()
{
	int n;
	cout<<"Enter the number ";
	cin>>n;
	cout<<"The factorial of "<<n<<" is "<<fact(n);
	return 0;
}
