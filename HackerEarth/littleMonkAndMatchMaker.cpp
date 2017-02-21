/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
struct dataType{
	string name;
	lli value;
};
class Compare
{
public:
    bool operator() (dataType left, dataType right){
    	if(left.value > right.value){
    		return true;
    	}
    	return false;
    }
};
int main(){
	lli t;
	cin>>t;
	while(t--){
	    lli n,k;
	    string s;
	    cin>>n>>k;
	    priority_queue<dataType,vector<dataType>,Compare > q;
	    while(n--){
	        cin>>s;
	        string copyS(s);
	        lli count(0);
	        set<char>st;
	        for(lli i=0;i<s.length();i++){
	            s[i] = tolower(s[i]);
	            if(s[i]=='l' or s[i]=='i' or s[i]=='t' or s[i]=='e' or s[i]=='j' or s[i]=='h' or s[i]=='o'){
	                if(st.find(s[i])==st.end()){
	                    count++;    
	                }
	                st.insert(s[i]);  
	            }
	        }
	        if(q.size()<k){
	            dataType temp;
	            temp.name = copyS;
	            temp.value = count;
	            q.push(temp);
	        }
	        else if(q.size() == k){
	            dataType temp = q.top();
	            if(temp.value > count){
	                q.pop();
	                temp.name = copyS;
	                temp.value = count;
	                q.push(temp);
	            }
	        }
	        vector<string> v;
	        while(!q.empty()){
	            dataType temp;
	            temp = q.top();
	            v.push_back(temp.name);
	            q.pop();
	        }
	        for(auto x:v){
	            cout<<x<<" ";
	        }
	        cout<<endl;
	    }
	    
	}
	return 0;
}