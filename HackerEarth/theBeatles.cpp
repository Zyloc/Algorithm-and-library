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
#define lli unsigned long long int 
#define debug() cout<<"######"<<endl 
vector<lli> primes[MAX]; 
struct myDataType{
	lli firstMax;
	lli secondMax;
	myDataType(){
		firstMax = 0;
		secondMax = 0;
	}
};
map<lli, myDataType> maxPower;
lli lcm(lli x,lli y){
	return (x*y)/__gcd(x,y);
}

void seive(){
	bool prime[MAX];	
	memset(prime,true,sizeof(prime));
	for(lli i=2;i<MAX;i++){
		if (prime[i]){
			primes[i].pb(i);
			for(lli j=2*i;j<MAX;j=j+i){
				primes[j].pb(i);
				prime[j]=false;
			}
		}
	}
}
void updateMaxPower(lli primeNumber,lli exponent){
	if (exponent > maxPower[primeNumber].secondMax){
		if (exponent > maxPower[primeNumber].firstMax){
			maxPower[primeNumber].secondMax = maxPower[primeNumber].firstMax;
			maxPower[primeNumber].firstMax = exponent;	
		}
		else{
			maxPower[primeNumber].secondMax = exponent;
		}
	}
}
int main(){
	seive();
	lli n,x,finalLcm(1),start(0),ans(0),remainingLcm(1);
	cin>>n;
	vi(input);
	bool flag(false);
	loop(i,0,n-1){
		cin>>x;
		finalLcm = lcm(finalLcm,x);
		input.pb(x);
		map<lli,lli> tempPower;
		for(lli j=0;j<primes[x].size();j++){
			while(x > 1 and x%primes[x][j]==0){
				tempPower[primes[x][j]]++;
				x/=primes[x][j];
			}
		}
		for(auto it=tempPower.begin();it!=tempPower.end();it++){
			updateMaxPower(it->first,it->second);
		}
	}
	lli tempFinalLcm(finalLcm);
	loop(i,0,n-1){
		lli copyFinalLcm(finalLcm);
		map<lli,lli> tempPower;
		for(lli j=0;j<primes[input[i]].size();j++){
			x = input[i];
			while(x > 1 and x%primes[input[i]][j]==0){
				tempPower[primes[x][j]]++;
				x/=primes[x][j];
			}
		}
		for(auto it=tempPower.begin();it!=tempPower.end();it++){
			if (maxPower[it->first].firstMax == it->second){
				lli diff(maxPower[it->first].firstMax-maxPower[it->first].secondMax);
				for(lli j=1;j<=diff;j++){
					if(it->first!=0)
						copyFinalLcm/=it->first;
				}
			}
		}
		if (copyFinalLcm < tempFinalLcm){
			flag = true;
			tempFinalLcm = copyFinalLcm;
			ans = i+1;
		}
	}
	if (flag){
		cout<<ans<<endl;
	}
	else{
		cout<<-1<<endl;
	}
	return 0;
}	