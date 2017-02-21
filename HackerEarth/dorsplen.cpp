/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli input[3];
	cin>>input[0]>>input[1]>>input[2];
	sort(input,input+3);
	lli ans(0);
	ans = input[0];
	input[1]-=input[0];
	input[2]-=input[0];
	ans+=input[1]/2;
	ans+=input[2]/2;
	ans+=input[1]%2+input[2]%2;
	cout<<ans<<endl;
	return 0;
}