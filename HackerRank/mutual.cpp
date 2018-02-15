/*
 * I felt , I felled and I failed :(
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e4+1);
bool dp[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
    cin>>t;
    while(t--){
        memset(dp,false ,sizeof dp);
        lli a,b,x;
        cin>>a>>b>>x;
        vector<lli> answer;
        for(int i(b);i>=a;i--){
            bool flag(false);
            for(int j(i);j<=b;j+=i){
                if(dp[j]){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                answer.push_back(i);
                dp[i] = true;
                if(answer.size() == x){
                    break;
                }
            }
        }
        if(answer.size() == x){
            for(auto it:answer){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}
