/*
 * Satyam Swarnkar(Zyloc) , NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
bool check(lli n){
	string s;
	while(n){
		s+=to_string(n%2);
		n/=2;
	}
	reverse(s.begin(),s.end());
	lli length1(0),length2(0);
	for(int i(0);i<s.length();i++){
		if(s[i] == '1'){
			length1++;
		}
		else{
			break;
		}
	}
	for(int i(length1);i<s.length();i++){
		if(s[i] == '0'){
			length2++;
		}
		else{
			break;
		}
	}
	return length1-1 == length2;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	cin>>n;
	lli iterator(1),ans(0);
	while(((1LL<<iterator)-1)*(1LL<<(iterator-1)) <= n){
		lli temp(((1LL<<iterator)-1)*(1LL<<(iterator-1)));
		if(n%temp == 0){
			ans = ((1LL<<iterator)-1)*(1LL<<(iterator-1));
		}

		iterator++;
	}
	cout<<ans<<endl;
	return 0;
}
