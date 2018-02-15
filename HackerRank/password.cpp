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
	string numbers = "0123456789";
	string lower_case = "abcdefghijklmnopqrstuvwxyz";
	string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string special_characters = "!@#$%^&*()-+";
	lli n;
	string input;
	cin>>n;
	cin>>input;
	lli countNumbers(0);
	lli countLowerCase(0);
	lli countUpperCase(0);
	lli countSpecialChars(0);
	for(auto x:input){
		for(auto y:numbers){
			if(x == y){
				countNumbers++;
			}
		}
	}
	for(auto x:input){
		for(auto y:lower_case){
			if(x == y){
				countLowerCase++;
			}
		}
	}
	for(auto x:input){
		for(auto y:upper_case){
			if(x == y){
				countUpperCase++;
			}
		}
	}
	for(auto x:input){
		for(auto y:special_characters){
			if(x == y){
				//cout<<x<<endl;
				countSpecialChars++;
			}
		}
	}
	lli ans(0);
	if(countNumbers == 0){
		ans++;
	}
	if(countLowerCase == 0){
		ans++;
	}
	if(countUpperCase == 0){
		ans++;
	}
	if(countSpecialChars == 0){
		ans++;
	}
	if(ans+n >= 6){
		cout<<ans<<endl;
	}
	else{
		cout<<6-n<<endl;
	}
	return 0;
}
