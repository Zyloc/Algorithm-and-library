#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define loop(i,n) for (int i=0;i<n;i++)
#define pool(i,n) for(int i=n;i>=1;i--)
#define MOD 1000000007
vector <lli> v;
vector <lli> fctrl;
lli factorial(lli n){
	int i=1;
	lli fact=1;
	fctrl.push_back(1);
	for(i;i<=n;i++){
		fact=(fact*i)%MOD;
		fctrl.push_back(fact);
	}
	return fact;	
}
lli genrateCoeff(lli n,lli k){
		//cout<<fctrl[n+k-1]<<endl;
		return ((fctrl[n+k-1]%MOD)/(fctrl[n]*fctrl[k-1]))%MOD;
	//cout<<((fctrl[n+k-1]%MOD)/(fctrl[n]*fctrl[k-1]))%MOD<<endl;
	//return 1;
}
int main(){
	//cout<<lli<<endl;
	int test;
	//cin>>test;
	scanf("%lld",&test);
	loop(z,test){
		lli n,x,m,number;
		cin>>n>>x>>m;
		v.push_back(0);
		loop(i,n){
			scanf("%lld",&number);
			//cin>>number;
			v.push_back(number);
		}
		factorial(x+m);
		lli answer=v[x];
		lli k=1;
		pool(j,x-1){
			//genrateCoeff(1,3);
			//cout<<genrateCoeff(j,m)<<endl;
			answer+= (genrateCoeff(j,m)*v[k])%MOD;
			//cout<<genrateCoeff(j,m)*v[k]<<endl;
			k++;
		}
		//cout<<answer<<endl;
		printf("%llu \n",answer);
		v.clear();
		fctrl.clear();
	}
	return 0;
}