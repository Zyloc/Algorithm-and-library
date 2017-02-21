/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define zyloc() lli t;cin>>t;while(t--)
#define pb(n) push_back(n)
#define lli long long int 
#define debug() cout<<"######"<<endl 
const lli MAX = 1000002;
const lli MOD = 1000000007;
class ColorfulRoad{
public:
	lli dp[16];
	int magicBox(string road,lli index){
		if(index == road.length()-1){
			return 0;
		}
		if(dp[index]!=1e10){
			return dp[index];
		}
		if(road[index]=='R'){
			for(lli i=index+1;i<road.length();i++){
				if(road[i]=='G'){
					dp[index] = min(dp[index],(i-index)*(i-index)+magicBox(road,i));	
				}
			}
		}
		if(road[index]=='G'){
			for(lli i=index+1;i<road.length();i++){
				if(road[i]=='B'){
					dp[index] = min(dp[index],(i-index)*(i-index)+magicBox(road,i));	
				}
			}	
		}
		if(road[index]=='B'){
			for(lli i=index+1;i<road.length();i++){
				if(road[i]=='R'){
					dp[index] = min(dp[index],(i-index)*(i-index)+magicBox(road,i));	
				}
			}	
		}
		return dp[index];
	}
	int getMin(string road){
		lli len(road.length());
		if(road[len-1] == 'B'){
			bool flag(false);
			for(lli i=0;i<len;i++){
				if(road[i]=='G'){
					flag = true;
					break;
				}
			}
			if(!flag){
				return -1;
			}			
		}
		else if(road[len-1] == 'R'){
			bool flag(false);
			for(lli i=0;i<len;i++){
				if(road[i]=='G'){
					for(lli j=i+1;j<len;j++){
						if(road[j]=='B'){
							flag = true;
							break;
						}
					}
				}
				if(flag){
					break;
				}
			}
			if(!flag){
				return -1;
			}
		}
		for(lli i=0;i<16;i++){
			dp[i] = 1e10;
		}
		magicBox(road,0);
		return dp[0];
	}
};
int main(){
	string s;
	cin>>s;
	ColorfulRoad obj;
	cout<<obj.getMin(s)<<endl;
}