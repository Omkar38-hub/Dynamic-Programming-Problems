#include<bits/stdc++.h>
using namespace std;

int eggDrop(int e,int f)
{
	if(f==1 ||f==0)
	  return f;
	if(e==1)
	  return f;
	int mn=INT_MAX;
	for(int x=1;x<=f;x++)
	{
		mn=min(mn,max(eggDrop(e-1,x-1),eggDrop(e,f-x)));
	}
	return mn+1;
}
int main()
{
	int f=3,e=2;
	cout<<"The minimum number of trail required is "<<eggDrop(e,f)<<"\n";
	return 0;
}
