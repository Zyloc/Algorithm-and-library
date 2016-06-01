#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10000000]={0};
ll b[10000000]={0};
#define MOD 1000000007
int main()
{
	ll i,n,j,k,t,m,l,g=0;
for(i=3;i<3163;i=i+2)
{
    if(a[i]==0)
    {
        for(j=2*i;j<10000000;j=j+i)
        {
            k=j;
            if(k%i==0 && k!=i)
            {
                a[j]++;
            }
        }
    }
}
b[g]=2;
g++;
for(i=3;i<10000001;i=i+2){
	if(a[i]==0){
		b[g]=i%MOD;
		g++;
	}
}
cin>>t;
while(t--){
    scanf("%lld %lld ",&n,&m);
    /*for(i=n;i<=m;i++){
        cout<<b[b[i-1]-1]<<" ";
    }*/
    l=((b[b[n-1]-1])*(b[b[m-1]-1]))%MOD;
    printf("%lld\n",l);
}
}