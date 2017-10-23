/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		lli countCooking(0),countEating(0),countSleeping(0),index(0);
		while(s[index] == 'C' and index < s.length()){
			index++;
			countCooking++;
		}
		while(s[index] == 'E' and index < s.length()){
			index++;
			countEating++;
		}
		while(s[index] == 'S' and index < s.length()){
			index++;
			countSleeping++;
		}
		if(index == s.length()){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}	