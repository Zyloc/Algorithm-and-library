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
#define MAX 5000001
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
vector<int> primeDivisors[MAX];
int factors[MAX];
void seive(){
	bool prime[MAX];
	memset(prime,true,sizeof(prime));
	primeDivisors[1].pb(1);
	loop(i,2,MAX-1){
		if (prime[i]){
			for(lli j=i*i;j<MAX;j=j+i){
				primeDivisors[j].pb(i); 
				prime[j] = false;
			}
		}	
	}
	factors[0] = 1;
 	factors[1] = 1;
	loop(i,2,MAX-1){
		if (primeDivisors[i].size()==0){
			factors[i] = 1;
		}
		else{
			loop(j,0,primeDivisors[i].size()-1){
				factors[i] = factors[i/primeDivisors[i][j]]+1;
			}
		}
	}
	loop(i,2,MAX-1){
		factors[i]+= factors[i-1];
	}
}
int main(){
	seive();
	zyloc(){
		lli a,b;
		scanf("%lld %lld",&a,&b);
		printf("%d\n",(factors[a]-factors[b]));
	}
	return 0;
}