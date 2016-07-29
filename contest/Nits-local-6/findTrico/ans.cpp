#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(i=a;i<b;i++)
int main(){
    ll t,L,R,T,D,X1,Y1,X2,Y2,g1,g2;
    cin>>t;
    while(t--){
        cin>>X1>>Y1>>X2>>Y2;
        cin>>T>>R>>D>>L;
        g1=__gcd(-L,R);
        g2=__gcd(T,-D);
        if((X2-X1)%g1==0 && (Y2-Y1)%g2==0){

            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

}
}
