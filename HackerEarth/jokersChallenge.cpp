/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX = 1e6+1;
bool isPrime[MAX];
const int MOD = 1e9+7;
vector<lli> primeNumber;
lli fast_expo(lli base, lli expo,lli MODE){
	lli res=1;
	while(expo>0){
		if(expo%2==1){
			res=(res*base)%MODE;
		}
		base=(base*base)%MODE;
		expo/=2;
	}
	return res%MODE;
}
lli modulo(lli a,lli b,lli c){
    lli x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c;
        b /= 2;
    }
    return x%c;
}
lli mulmod(lli a,lli b,lli c){
    lli x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
bool miller(long long p,int iteration){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}
void seive(){
	for(int i=2;i<MAX;i++){
		if(!isPrime[i]){
			primeNumber.push_back(i);
			for(int j=2*i;j<MAX;j+=i){
				isPrime[j]=  true;
			}
		}
	}
}
lli countDivisors(lli n){
	lli ans(1);
	for(auto p:primeNumber){
		if(p*p*p > n){
			break;
		}
		lli count(1);
		while(n%p == 0){
			count++;
			n = n/p;
		}
		ans = (ans*count)%MOD;
	}
	lli squareRoot(sqrt(n));
	if(miller(n,4)){
		ans = (ans*2)%MOD;
	}
	else if(squareRoot * squareRoot == n and miller(squareRoot,1)){
		ans = (ans*3)%MOD;
	}
	else if (n!=1){
		ans = (ans*4)%MOD;
	}
	return ans%MOD;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	seive();
	lli t;
	cin>>t;
	while(t--){
		lli x,a,b;
		cin>>x>>a>>b;
		lli n((x*x)+a*x+b);
		lli divi(countDivisors(n));
		if(divi&1){
			lli sq(sqrt(n));
			cout<<(fast_expo(n%MOD,divi/2,MOD)*sq)%MOD<<endl;
		}
		else{
			cout<<(fast_expo(n%MOD,divi/2,MOD))<<endl;
		}
	}
	return 0;
}