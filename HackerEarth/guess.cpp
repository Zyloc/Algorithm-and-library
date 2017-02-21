/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i,start,end) for (lli i=start;i<=end;i++)
#define pool(i,start,end) for(lli i=start;i>=end;i--)
#define zyloc() lli t;cin>>t;while(t--)
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define fill(a,value) memset(a,value,sizeof(a)) 
#define MOD 1000000007
#define PI  3.14159265358979323846
#define MAX 1000002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
lli prefixSum[MAX];
void seive(){
	bool prime[MAX];
	memset(prime,true,sizeof prime);
	prime[1]=false;
	prime[0]=false;
	loop(i,0,MAX-2){
		if (prime[i]){
			for(lli j=i*i;j<MAX;j=j+i){
				prime[j]=false;
			}
		}
	}
	loop(i,0,MAX-2){
		if(prime[i]){
			prefixSum[i]=prefixSum[i-1]+i;
		}
		else{
			prefixSum[i] = prefixSum[i-1];
		}
	}
}

int main(){
	seive();
	lli a,b;
	while(scanf("%lld %lld",&a,&b)!=EOF){
		if (a==0){
			a++;
		}
		if (b==0){
			b++;
		}
		if (a==0){
			a++;
		}
		if (b==0){
			b++;
		}
		cout<<prefixSum[b]-prefixSum[a-1]<<endl;
	}	
	return 0;
}	