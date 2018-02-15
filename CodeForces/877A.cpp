/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
string s;
lli countString(string check){
	lli count = 0;
    size_t nPos = s.find(check, 0); // fist occurrence
    while(nPos != string::npos)
    {
        count++;
        nPos = s.find(check, nPos+1);
    }	
    return count;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>s;
	lli a = countString("Danil");
	lli b = countString("Olya");
	lli c = countString("Slava");
	lli d = countString("Ann");
	lli e = countString("Nikita");
	if(a + b +c +d+e == 1){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
	return 0;
}
