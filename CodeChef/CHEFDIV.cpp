/*
* Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e6+1);
bool prime[MAX];
vector<lli> primes,primeDivisors[int(1e5+1)],powers[int(1e5+1)];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli start,end,ans(0);
	cin>>start>>end;
	for(int i(2);i<MAX;i++){
		if(!prime[i]){
			primes.push_back(i);
			for(int j(2*i);j<MAX;j+=i){
				prime[j] = true;
			}
		}
	}
	for(auto x:primes){
		lli firstMultiple((start/x)*x);
		if(firstMultiple < start){
			firstMultiple += x;
		}
		for(lli i(firstMultiple);i<=end;i+=x){
			primeDivisors[i-start].push_back(x);
		}
	}
	for(int i(0);i<=end-start;i++){
		lli number(i+start);
		for(auto x:primeDivisors[i]){
			powers[i].push_back(1);
			number/=x;
			while(number%x == 0){
				number/=x;
				powers[i][powers[i].size()-1]++;
			}
		}
		if(number > 1){
			powers[i].push_back(1);
		}
	}
	for(lli i(0);i<=end-start;i++){
		if(i+start != 1 and powers[i].size() == 0){
			ans+=2;
		}
		lli product(1);
		priority_queue<lli> pq;
		for(auto x:powers[i]){
			product *= (x+1);
			pq.push(x+1);
		}
		while(!pq.empty()){
			ans+= product;
			product /= pq.top();
			lli top(pq.top());
			pq.pop();
			if(top != 2){
				pq.push(top-1); 
			} 
			product *= (top-1);
		}
	}
	cout<<ans<<endl;
	return 0;
}	