/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int i=max(b,d);i<1e7;i++){
		if((i-b)%a == 0 and (i-d)%c == 0){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}	