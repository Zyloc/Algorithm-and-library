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
	for(int i=0;i<s.length();i++){
		if(s[i]=='?'){
			if(i == 0){
				if(s[1] == 'a'){
					s[i]='b';
				}
				else{
					s[i]='a';
				}
			}
			else if(i == s.length()-1){
				if(s[i-1]=='a'){
					s[i]='b';
				}
				else{
					s[i]='a';
				}
			}
			else{
				if(s[i-1]=='a'){
					s[i]='b';
				}
				else if(s[i+1]=='a'){
					s[i]='b';
				}
				else{
					s[i]='a';
				}
			}
		}
	}
	cout<<s<<endl;
	return 0;
}