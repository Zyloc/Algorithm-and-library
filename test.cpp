/*
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
	lli index(0);
	while(index!=s.length()){
		cout<<s[index];
		index++;
		if(index%50 == 0){
			cout<<endl;
		}
	}
	return 0;
}