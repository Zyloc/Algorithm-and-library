/*
*
*"@NainwalArun"
*
*/
#include <bits/stdc++.h>
using namespace std ;

#define ll long long int
#define arun() int main()
#define loop(i, a, b) for(i=a; i<b; i++)
arun(){
    ll T,N,M,i;
    cin>>T;
    while(T--){
        cin>>N>>M;
        cout<<min(M/3,(N-M))<<endl;
    }
return 0;

}

