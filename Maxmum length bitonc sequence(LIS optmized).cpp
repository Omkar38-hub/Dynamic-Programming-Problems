#include<bits/stdc++.h>
using namespace std;

int ceilIndex(int arr[],int l,int r,int x)
{
	while(l<r)
	{
	   int mid = l + (r - l) / 2;
       if (arr[mid] >= x)
          r=mid;
        else
          l=mid+1;
	}
    return r;
}
void reverse(int a[],int n)
{
	int i=0,j=n-1;
	while(i<j)
	{
		swap(a[i++],a[j--]);
	}
}
int FindBT(int a[],int n)
{
	int tail[n];
	tail[0]=a[0];
	int len=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]>tail[len-1])
		{
			tail[len]=a[i];
			len++;
		}
		else
		{
			int index=ceilIndex(tail,0,len-1,a[i]);
			tail[index]=a[i];
		}
	}
	for(int i=0;i<n;i++)
	   cout<<tail[i]<<" ";
	reverse(a,n);
	int tail1[n];
	tail1[0]=a[0];
	int len1=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]>tail1[len1-1])
		{
			tail1[len1]=a[i];
			len1++;
		}
		else
		{
			int index=ceilIndex(tail1,0,len1-1,a[i]);
			tail1[index]=a[i];
		}
	}
	reverse(a,n);
	reverse(tail1,n);
	int ans = 0;
    for (int i = 0; i < n; i++)
    {
		if (ans < (tail1[i] + tail[i] - 1))
            ans = (tail1[i] + tail[i] - 1);
	}    
    return ans;
}
int main()
{
	int a[]={3,10,20,4,6,7};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"The length of longest increasing subsequence is "<<FindBT(a,n)<<endl;
	return 0;
}

// time complexity =O(n*log(n))
