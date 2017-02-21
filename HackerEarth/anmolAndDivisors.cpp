#include<bits/stdc++.h>
using namespace std;
 
typedef int ll;
#define int long long
#define ff first
#define ss second
 
typedef pair<int,int>Pair;
 
bool vis[10000050];
vector<int>prime,fact,divi;
map<int,int>freq;
 
void seave()
{
	prime.push_back(2);
	for (int i=4 ; i<=10000050 ; i+=2)
		vis[i]=1;
 
	for (int i=3 ; i<=10000050 ; i++)
	{
		if(vis[i]==0)
		{
			prime.push_back(i);
			for (int j=i ; j<=10000050 ; j+=i)
				vis[j]=1;
		}
	}
}
 
void factor(int n)
{
	fact.clear();
	freq.clear();
	for (int i=0 ; prime[i]<=sqrt(n) ; i++)
	{
		int cnt=0;
		while (n%prime[i]==0)
		{
			cnt++;
			n/=prime[i];
		}
		if(cnt)
		{
			fact.push_back(prime[i]);
			freq[prime[i]]=cnt;
		}
	}
	if(n!=1)
	{
		fact.push_back(n);
		freq[n]=1;
	}
}
 
void divisor()
{
	divi.clear();
	int num=fact[0];
	for (int i=0 ; i<freq[fact[0]] ; i++)
	{
		divi.push_back(num);
		num*=fact[0];
	}
 
	for (int i=1 ; i<fact.size() ; i++)
	{
 
		/*for (int j=0; j<divi.size() ; j++)
			cout<<divi[j]<<" ";
		cout<<endl;*/
		num=fact[i];
		int b=divi.size();
		for (int j=0 ; j<freq[fact[i]] ; j++)
		{
			divi.push_back(num);
			num*=fact[i];
		}
 
		int s=divi.size();
		for (int j=b ; j<s ; j++)
		{
			for (int k=0 ; k<b ; k++)
			{
				// cout<<divi[j]<<"    "<<divi[k]<<" "<<divi[j]*divi[k]<<endl;
				divi.push_back(divi[j]*divi[k]);
			}
		}
	}
}
ll main()
{
	
	for(int i=1;i<1000;i++){
		cout<<100000000000000<<endl;
	}
}