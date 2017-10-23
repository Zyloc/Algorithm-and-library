/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e7+2);
bool isPrime[MAX];
void seive(){
    isPrime[0] = true;
    for(int i(2);i<MAX;i++){
        if(!isPrime[i]){
            for(int j(i*2);j<MAX;j+=i){
                isPrime[j] = true;
            }
        }
    }
}
lli getInteger(string s){
    if(s == ""){
        return 0;
    }
    return stoi(s);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	seive();
	lli n;
	cin>>n;
	while(n--){
	    string s;
	    cin>>s;
	    lli count(0),maxPrime(-1);
	    string temp;
	    for(int i(0);i<s.length();i++){
	        if(s[i] >= '0' and s[i] <= '9'){
	            temp+=s[i];
	        }
	        else{
	            lli dummy(getInteger(temp));
	            if(!isPrime[dummy]){
	                count++;
	                maxPrime = max(maxPrime,dummy);
	            }
	            temp = "";
	        }
	    }
	    lli dummy(getInteger(temp));
		if(!isPrime[dummy]){
		    count++;
		    maxPrime = max(maxPrime,dummy);
		}
	    cout<<count<<" "<<maxPrime<<endl;
	}
	return 0;
}	