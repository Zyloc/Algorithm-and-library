#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int n;
    for(int io=0;io<t;io++)
    {
    	cin>>n;
    	int ar[n];
    	for(int i=0;i<n;i++)
    		cin>>ar[i];
    	int c1=count(ar,ar+n,1);
    	int c2=count(ar,ar+n,2);
    	int c3=count(ar,ar+n,3);
    	int c4=count(ar,ar+n,4);
    	//cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<endl;
    	int cnt=0;
    	cnt+=c4;
    	if(c1==c3)
    	{
    		cnt+=c3;
    		c1=0;
    		c3=0;
    	}
    	else if(c3<c1)
    	{
    		cnt+=c3;
    		c1-=c3;
    		c3=0;
    	}
    	else
    	{
    		cnt+=c1;
    		c3-=c1;
    		cnt+=c3;
    		c1=0;
    		c3=0;
    	}
    	
    	if(c2%2==0)
    	{
    		cnt+=(c2/2);
    	}
    	else
    	{
    		cnt+=(c2/2);
    		c2=c2%2;
    	}
    	
    	if(c2==1)
    	{
    		cnt+=1;
    		c1-=2;
    	}
    	
    	cnt+=(c1/4);
    	c1=c1%4;
    	if(c1>0)
    	cnt+=1;
    	cout<<cnt<<endl;
    	
    	
    }
    return 0;
}
