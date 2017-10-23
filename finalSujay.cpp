#include <bits/stdc++.h>
using namespace std;
map<char,char> mp;
map<char,bool> cache;
char solve(char c){
    if(cache.find(c)!= cache.end()){
        return '0';
    }
    if(mp.find(c) == mp.end()){
        return '*';
    }
    if(mp[c] >= '0' and mp[c]<='9'){
    	return mp[c];
    }
    cache[c] = true;
    return solve(mp[c]);
}
int main(){
    int t,dummy(1);
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char x,y;
        mp.clear();
        cache.clear();
        for(int i(0);i<n;i++){
            cin>>x>>y;
            mp[x] = y;
        }
        int q;
        cin>>q;
        cout<<"#"<<dummy<<endl;
        string test;
        for(int i(0);i<q;i++){
            cin>>test;
            string answer;
            bool check(false);
            for (int j = 0; j <test.length(); ++j) {
                cache.clear();
                string temp="";
                temp+=(solve(test[j]));
                if(temp == "*"){
                    cout<<-1<<endl;
                    check = true;
                    break;
                }
                else{
                    answer +=  temp;
                }
            }
            if(!check){
                cout<<answer<<endl;
            }
        }
        dummy++;
            
    }
    return 0;
}