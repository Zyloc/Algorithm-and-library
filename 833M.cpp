/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	lli ans(0);
	if(x1 == x2 or y1 == y2){
		ans+=2;
	}
	if(x1 <= x2 and y1<= y2){
		x2+=1;
		y2+=1;
		cout<<ans+(abs(x1-x2)+abs(y1-y2))*2<<endl;	
	}
	else if(x1<=x2 and y1>=y2){
		x2+=1;
		y2-=1;
		cout<<ans+(abs(x1-x2)+abs(y1-y2))*2<<endl;		
	}
	else if(x1>=x2 and y1>= y2){
		x2-=1;
		y2-=1;
		cout<<ans+(abs(x1-x2)+abs(y1-y2))*2<<endl;	
	}
	else{
		x2-=1;
		y2+=1;
		cout<<ans+(abs(x1-x2)+abs(y1-y2))*2<<endl;	
	}
	return 0;
}
