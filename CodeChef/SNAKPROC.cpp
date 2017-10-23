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
		lli n;
		cin>>n;
		string s,newString;
		cin>>s;
		lli index(0);
		while(index < n){
			if(s[index]!='.'){
				newString+=s[index];
			}
			index++;
		}
		if(newString.length()&1){
			cout<<"Invalid"<<endl;
			continue;
		}
		else{
			index = 0;
			bool flag(false);
			while(index < newString.length()){
				if(newString[index] != 'H' or newString[index+1]!='T'){
					cout<<"Invalid"<<endl;
					flag = true;
					break;
				}
				index+=2;
			}
			if(!flag){
				cout<<"Valid"<<endl;
			}
		}
	}
	return 0;
}