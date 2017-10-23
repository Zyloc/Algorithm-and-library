/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int dp[100];
    dp[0] = 0;
    dp[1] = 4;
    for(int i(2);i<25;i++){
        if(sqrt(i)*sqrt(i) == i){
           cout<<i<<endl;
            dp[i] = dp[i-1];
        }
        else{
            dp[i] = dp[i-1]+2;
        }
        //cout<<i<<" "<<dp[i]<<endl;
    }

    return 0;
}
