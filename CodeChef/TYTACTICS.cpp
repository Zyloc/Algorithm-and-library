/*
 * Team: De_Dana_Dan,  NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
    lli t;
    cin>>t;
    while(t--){
        double sigma,n;
        cin>>n>>sigma;
        if(n == 1){
            if(sigma == 0){
                cout<<5<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
        else{
            double value((sigma*n)/sqrt(n-1));
            lli upto(n);
            for(int i(0);i<upto-1;i++) {
                cout<<0<< " ";
            }
            printf("%.15f",value);
            cout<<endl;
        }
    }
    return 0;
}
