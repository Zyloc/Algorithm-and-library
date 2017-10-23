/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string sherlock,moriarty;
	lli n;
	cin>>n;
	cin>>sherlock>>moriarty;
	sort(sherlock.begin(),sherlock.end());
	sort(moriarty.begin(),moriarty.end());
	map<char,lli> minimum;
	for(int i=0;i<moriarty.length();i++){
		minimum[moriarty[i]]++;
	}
	
	return 0;
}