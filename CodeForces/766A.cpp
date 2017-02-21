/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s1,s2;
	cin>>s1>>s2;
	if(s1 == s2){
		cout<<-1;
		return 0;
	}
	else{
		cout<<max(s1.length(),s2.length());
	}
	return 0;
}