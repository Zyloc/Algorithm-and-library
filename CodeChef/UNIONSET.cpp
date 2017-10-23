/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bitset<1> bit[2500];
	bit[1] = 1;
	bit[0] = 1;
	cout<<(bit[0]|bit[1])<<endl;
	return 0;
}
