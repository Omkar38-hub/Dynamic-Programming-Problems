#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z)
    {
        if(n<0)
           return -1;
        if(n==0)
           return 0;
        int res=max({maximizeTheCuts(n-x,x,y,z),maximizeTheCuts(n-y,x,y,z),maximizeTheCuts(n-z,x,y,z)});
        if(res==-1)
           return res;
        return res+1;
    }
int main()
{
	int n=4;
	int x=2,y=1,z=1;
	cout<<"The maximum number of cuts can be done is "<<maximizeTheCuts(n,x,y,z)<<"\n";
	return 0;
}
