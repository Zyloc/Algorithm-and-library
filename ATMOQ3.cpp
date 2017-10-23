/*
 * Keep breathing :D
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e6+1);
lli evenBit[MAX],oddBit[MAX],input[MAX];
lli n,x,y,z,q;
void updateOdd(lli index,lli change){
	for(int i(index);i<=n;i+=(i&-i)){
		oddBit[i]+=change;
	}
}
void updateEven(lli index,lli change){
	for(int i(index);i<=n;i+=(i&-i)){
		evenBit[i]+=change;
	}
}
lli queryOdd(lli index){
	lli ans(0);
	for(int i(index);i>0;i-=(i&-i)){
		ans+=oddBit[i];
	}
	return ans;
}
lli queryEven(lli index){
	lli ans(0);
	for(int i(index);i>0;i-=(i&-i)){
		ans+=evenBit[i];
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	for(int i(1);i<=n;i++){
		cin>>input[i];
	}
	for(int i(1);i<=n;i++){
		if(input[i]&1){
			updateOdd(i,input[i]);
		}
		else{
			updateEven(i,input[i]);
		}
	}
	for(int i(0);i<q;i++){
		cin>>x;
		if(x == 1){
			cin>>x>>y;
			if(input[x]&1){
				if(y&1){
					updateOdd(x,-input[x]);
					updateEven(x,input[x]+y);
				}
				else{
					updateOdd(x,y);
				}
			}
			else{
				if(y&1){
					updateEven(x,-input[x]);
					updateOdd(x,input[x]+y);
				}
				else{
					updateEven(x,y);
				}
			}
			input[x]+=y;
		}
		else{
			cin>>x>>y>>z;
			if(z == 1){
				cout<<queryOdd(y)-queryOdd(x-1)<<endl;
			}
			else{
				cout<<queryEven(y)-queryEven(x-1)<<endl;
			}
		}
	}
	return 0;
}
