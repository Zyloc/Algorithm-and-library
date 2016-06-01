#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(i=a;i<b;i++)
int main(){
    ll t,n,i,x1,y1,x2,y2,k,l1,l2,x,y,z,z1,j;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<pair<int,int>,int> >v1;
        vector<pair<pair<int,int>,int> >v2;
        loop(i,0,n){
        cin>>x1>>y1>>x2>>y2;
        k=0;
        if(x1==x2){
            v1.push_back(make_pair(make_pair(y1,y2),x1));
        }
        else if(y1==y2){
            v2.push_back(make_pair(make_pair(x1,x2),y1));
        }
        }
        l1=v1.size();
        l2=v2.size();
        loop(i,0,l1){
        z=v1[i].second;
        loop(j,0,l2){
            z1=v2[j].second;
        if(z>=v2[j].first.first && z<=v2[j].first.second && z1>=v1[i].first.first && z1<=v1[i].first.second)
            {
                k++;
            }
        }
        }
        cout<<k<<endl;
    }
    return 0;
}
Language: C++