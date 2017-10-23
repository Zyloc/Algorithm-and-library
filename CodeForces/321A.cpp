/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli position[101][2];
lli length;
lli a,b,endX,endY,c;
bool isValid(lli a,lli b){

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>endX>>endY>>s;
	for(int i(0);i<s.length();i++){
		if(s[i] == 'U'){
			b++;
		}
		else if(s[i] == 'D'){
			b--;
		}
		else if(s[i] == 'R'){
			a++;
		}
		else{
			a--;
		}
		position[i][0] = a;
		position[i][1] = b;
	}
	length = s.length()-1;
	if(isValid(a,a-0,b,b-0)){
		cout<<"Yes";
		return 0;
	}
	for(int i(0);i<s.length();i++){
		if(isValid(a,)){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}
