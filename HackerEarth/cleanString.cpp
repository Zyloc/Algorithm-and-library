/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	cin>>n;
	string s;
	cin>>s;
	lli ans(0);
	for(int i=0;i<(1<<n);i++){
	    string dummy;
	    for(int j=n-1;j>=0;j--){
	        if(i&(1<<j)){
	            dummy+=s[j];
	        }
	    }
	    // last vowel
	    lli lastVowel(0);
	    for(int j=0;j<dummy.length();j++){
	        if(tolower(dummy[j])=='a' or tolower(dummy[j])=='e' or tolower(dummy[j])=='i' or tolower(dummy[j])=='o' or tolower(dummy[j])=='u'){
	            lastVowel = j;
	        }
	    }
	    bool inValid(false);
	    for(int j=0;j<=lastVowel;j++){
	        if(!(tolower(dummy[j])=='a' or tolower(dummy[j])=='e' or tolower(dummy[j])=='i' or tolower(dummy[j])=='o' or tolower(dummy[j])=='u')){
	                inValid = true;
	                break;  
	        }
	    }
	    if(!inValid){
	    	//cout<<dummy<<endl;
	        ans = max(ans,(lli)dummy.length());
	    }
	}
	cout<<ans<<endl;
	return 0;
}