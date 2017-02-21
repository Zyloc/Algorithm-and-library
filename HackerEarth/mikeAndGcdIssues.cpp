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
#define MAX 200001
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
vector<lli> primeDivisiors[MAX],listOfNumber[MAX];
void magicBox(){
	bool prime[MAX];
	memset(prime,true,sizeof prime);
	primeDivisiors[1].pb(1);
	loop(i,2,MAX-1){
		if(prime[i]){
			primeDivisiors[i].pb(i);
			for(lli j=2*i;j<MAX;j=j+i){
				prime[j]=false;
				primeDivisiors[j].pb(i);
			}
		}
	}
}
int main(){
	magicBox();
	lli n,x;
	vi(v);
	scanf("%lld",&n);
	loop(i,0,n-1){
		scanf("%lld",&x);
		v.pb(x);
		for(auto divi:primeDivisiors[x]){
			listOfNumber[divi].pb(i);
		}	
	}
	loop(i,0,n-1){
		lli ans(INT_MAX);
		for(auto divi: primeDivisiors[v[i]]){
			if(listOfNumber[divi].size()==1){
				continue;
			}
			lli lastAns(ans);
			lli index(lower_bound(listOfNumber[divi].begin(),listOfNumber[divi].end(),i)-listOfNumber[divi].begin());
			if(index == 0){
				if(abs(listOfNumber[divi][index+1]-i) <= abs(ans-i) ){
					if(abs(listOfNumber[divi][index+1]-i) == abs(ans-i)){
						ans = min(listOfNumber[divi][index+1],ans);
					}
					else{
						ans = listOfNumber[divi][index+1];	
					}
				}
			}
			else if (index == primeDivisiors[divi].size()-1){
				if(abs(listOfNumber[divi][index-1]-i) <= abs(ans-i) ){
					if (abs(listOfNumber[divi][index-1]-i) == abs(ans-i)){
						ans = min(listOfNumber[divi][index-1],ans);
					}
					else{
						ans = listOfNumber[divi][index-1];	
					}
				}
			}
			else{
				if(abs(listOfNumber[divi][index-1]-i) <= abs(ans-i) ){
					if(abs(listOfNumber[divi][index-1]-i) == abs(ans-i)){
						ans = min(listOfNumber[divi][index-1],ans);
					}
					else{
						ans = listOfNumber[divi][index-1];	
					}
				}
				if(abs(listOfNumber[divi][index+1]-i) <= abs(ans-i) ){
					if(abs(listOfNumber[divi][index+1]-i) == abs(ans-i)){
						ans  = min(listOfNumber[divi][index+1],ans);
					}
					else{
						ans = listOfNumber[divi][index+1];	
					}
					
				}
			}
			if(__gcd(v[i],v[ans])==1){
				ans = lastAns;
			}
		}
		if(ans == INT_MAX){
			printf("-1 ");
		}
		else{
			printf("%lld ",ans+1);
		}
	}
	return 0;
}	