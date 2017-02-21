/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6+1;
const long long int MAXVALUE = 1e18;
#define lli long long int
vector<lli> v;
map<lli,lli> mp;
bool IsPrime(lli number){
    if (number == 2LL || number == 3LL)
        return true;

    if (number % 2LL == 0 || number % 3LL == 0)
        return false;

    lli divisor = 6LL;
    while (divisor * divisor - 2LL * divisor + 1LL <= number){
        if (number % (divisor - 1LL) == 0)
            return false;

        if (number % (divisor + 1LL) == 0)
            return false;

        divisor += 6LL;
    }
    return true;
}    
int main(){
	v.push_back(0);
	for(int i=1;i<MAX;i++){
		ans.push_back(1);
	}
	for(int i=1;i<MAX;i++){
		for(int j=i;j<MAX;j+=i){
			v[j] *= i;
			if(v[j] > MAXVALUE or v[j] < 0){
				v[j] = 0;
			}
		}
	}
	for(int i=2;j<MAX;j++){
		if(mp.find(v[i]) == mp.end()){
			mp[v[i]] = i;
		}
	}	
	lli t;
	cin>>t;
	while(t--){
		lli n;
		cin>>n;
		lli root(sqrt(n));
		bool flag(false);
		if(root * root == n){
			flag = true;
		}
		if(mp.find(n)!=mp.end()){
			cout<<mp[n]<<endl;
		}
		else{
		    if(flag){
				if(IsPrime(root)){
					cout<<root<<endl;
				}
				else{
					cout<<-1<<endl;
				}
			}
			else{
				cout<<-1<<endl;
			}
		}
	}
}