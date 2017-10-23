/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli gcd(lli a,lli b){
    return b==0?a:gcd(b,a%b);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<pair<lli,lli> > X_axis,Y_axis,input;
    lli n,k,x,y;
    cin>>n>>k;
    lli ans(0);
    for(int i(0);i<n;i++){
        cin>>x>>y;
        if(x == 0){
            Y_axis.push_back({x,y});    
        }
        else{
            X_axis.push_back({x,y});
        }
        ans = max(ans,max(x,y));
    }
    for(int i(0);i<k;i++){
        cin>>x>>y;
        input.push_back({x,y});
    }
    
    for(int i(0);i<X_axis.size();i++){
        for(int j(0);j<input.size();j++){
            lli x(abs(X_axis[i].first-input[j].first));
            lli y(abs(X_axis[i].second-input[j].second));
            ans = max(ans,gcd(x,y));
        }
    }
    for(int i(0);i<Y_axis.size();i++){
        for(int j(0);j<input.size();j++){
            lli x(abs(Y_axis[i].first-input[j].first));
            lli y(abs(Y_axis[i].second-input[j].second));
            ans = max(ans,gcd(x,y));
        }
    }
    cout<<ans+1<<endl;
	return 0;
}	