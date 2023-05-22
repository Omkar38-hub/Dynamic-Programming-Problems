#include<bits/stdc++.h>
using namespace std;
bool mycmp(pair<int,int>a,pair<int,int>b)
{
	if(a.first==b.first)
	   return a.second<b.second;
	return a.first<b.first;
}
int bridges(pair<int,int>p[],int n)
{
	sort(p,p+n,mycmp);
	int LIS[n];
	LIS[0]=1;
	for(int i=1;i<n;i++)
	{
		LIS[i]=1;
		for(int j=0;j<i;j++)
		{
			if(p[i].first>p[j].second)
			{
				LIS[i]=max(LIS[i],LIS[j]+1);
			}
		}
	}
	int ans=LIS[0];
	for(int i=1;i<n;i++)
	{
		ans=max(ans,LIS[i]);
	}
	return ans;
}
int main()
{
	int n=5;
	pair<int,int>p[n];
	p[0]=make_pair(5,24);
	p[1]=make_pair(39,60);
	p[2]=make_pair(15,28);
	p[3]=make_pair(27,40);
	p[4]=make_pair(50,90);
	cout<<"The number of bridges we can make is "<<bridges(p,n);
	return 0;
}
