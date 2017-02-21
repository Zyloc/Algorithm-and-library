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
lli sumOfPrimeDivisors[MAX],numberOfprimeDivisors[MAX];
vector<lli> primeDivisors[MAX];
lli phi[MAX];
void computeTotient(){
	for (lli i=1; i<MAX; i++)
		phi[i] = i; 
	for (lli p=2; p<MAX; p++){
		if (phi[p] == p){
			phi[p] = p-1;
			for (lli i = 2*p; i<MAX; i += p){
				phi[i] = (phi[i]/p) * (p-1);
			}
		}
	}
}
void seive(){
	bool prime[MAX];
	memset(prime,true,sizeof prime);
	loop(i,2,MAX-2){
		if(prime[i]){
			primeDivisors[i].pb(i);
			sumOfPrimeDivisors[i] = i;
			numberOfprimeDivisors[i] = 1;
			for(lli j=i*2;j<MAX;j++){
				primeDivisors[j].pb(i);
				prime[j]=false;
				sumOfPrimeDivisors[j]+=i;
				numberOfprimeDivisors[j]++;
			}	
		}
		
	}
}
void precompute(){
	computeTotient();
	seive();
}
int main(){
	precompute();
	zyloc(){
		lli n,k;
		cin>>n>>k;
		lli q(sumOfPrimeDivisors[n]),s(numberOfprimeDivisors[n]),p(0);
		if(primeDivisors[n].size()>0){
			loop(i,0,primeDivisors[n].size()-1){
				p+=phi[primeDivisors[n][i]];
			}
		}
		cout<<n+k-p+q-s<<endl;
	}
	return 0;
}	