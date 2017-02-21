/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
map<lli,lli> mp;
void magicBox(lli shift,lli x){
    string s;
    while(x){
        if(x&1){
            s+='1';
        }
        else{
            s+='0';
        }
        x=x/2;
    }
    for(int j=0;j<s.length();j++){
        if(s[j] == '1'){
            mp[shift+j]++;
        }
    }
}
bool check(){
    for(auto x:mp){
        if(x.second > 1){
            return false;
        }
    }
    return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    lli t;
    cin>>t;
    while(t--){
        lli n,x;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x;
            magicBox(i,x);
        }
        while(!check()){
            for(auto x:mp){
                if(x.second > 1){
                	lli shift(x.first),value(x.second);
                	mp.erase(x.first);	
                    magicBox(shift,value);
                }
            }
        }
        lli ans(0);
        for(auto x:mp){
            ans+=x.second;
        }
        cout<<ans<<endl;
        mp.clear();
    }
	return 0;
}