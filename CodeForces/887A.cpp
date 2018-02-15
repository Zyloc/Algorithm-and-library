/*
 * I felt , I felled and I failed :(
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	reverse(s.begin(),s.end());
	lli prefix[101]={0};
	for(int i(1);i<=s.length();i++){
		prefix[i] = prefix[i-1]+(s[i-1]=='0'?1:0);
	}
	for(int i(s.length());i>0;i--){
		if(s[i-1]=='1' and prefix[i]>=6){
			cout<<"yes";
			return 0;
		}
	}
	cout<<"no";
	return 0;
}
