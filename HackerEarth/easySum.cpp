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
lli phi[MAX];
vector<lli> divi[MAX];
void computeTotient(){
    for (lli i=1; i<MAX; i++)
        phi[i] = i; 
    for (int p=2; p<MAX; p++){
        if (phi[p] == p){
            phi[p] = p-1;
 			for (int i = 2*p; i<MAX; i += p){
               phi[i] = (phi[i]/p) * (p-1);
            }
        }
    }
}
void divisors(){
	for(lli i=1;i<MAX;i++){
		for(lli j=i;j<MAX;j=j+i){
			divi[j].pb(i);
		}
	}
}
void preCompute(){
	computeTotient();
	divisors();
}
int main(){
	preCompute();
	lli n,q,x,l,r;
	cin>>n>>q;
	vi(v);
	lli prefix[n+1];
	memset(prefix,0,sizeof prefix);
	loop(i,0,n-1){
		cin>>x;
		for(lli j=0;j<divi[x].size();j++){
			prefix[i+1] += phi[divi[x][j]];
		}
		prefix[i+1] += prefix[i];
	}
	loop(i,0,q-1){
		cin>>l>>r;
		cout<<prefix[r] - prefix[r-1]<<endl;;
	}
	return 0;
}	