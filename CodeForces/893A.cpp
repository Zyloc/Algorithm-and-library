/*
 * Satyam Swarnkar(Zyloc) , NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,x,spectator(3);
	cin>>n;
	for(int i(0);i<n;i++){
		cin>>x;
		if(x == spectator){
			cout<<"NO";
			return 0;
		}
		for(int j(1);j<=3;j++){
			if(j!=x and j!=spectator){
				spectator = j;
				break;
			}
		}
	}
	cout<<"YES";
	return 0;
}
