/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
string magicBox(string s){
	if(s.length()&1){
		return s;
	}
	string first(magicBox(s.substr(0,s.length()/2)));
	string second(magicBox(s.substr(s.length()/2)));
	return (first<second?first+second:second+first);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a,b;
	cin>>a>>b;
	a = magicBox(a);
	b = magicBox(b);
	cout<<(a==b?"YES":"NO")<<endl;
	return 0;
}
