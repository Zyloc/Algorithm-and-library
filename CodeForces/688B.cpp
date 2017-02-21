/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s,copyS;
	cin>>s;
	copyS = s;
	reverse(copyS.begin(),copyS.end());
	s = s+ copyS;
	cout<<s;
	return 0;
}