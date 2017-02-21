/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n;
	cin>>n;
	lli t20[n],odi[n],test[n];
	priority_queue<int,vector<int>,greater<int> > pq1;
	for(int i=0;i<n;i++){
	    cin>>t20[i];
	}
	for(int i=0;i<n;i++){
	    cin>>odi[i];
	    odi[i]+=t20[i];
	}
	for(int i=0;i<n;i++){
	    cin>>test[i];
	    test[i]+=odi[i];
	    pq1.push(test[i]);
	}
	//cout<<pq1.top();
	lli q,x;
	cin>>q;
	for(int i=0;i<q;i++){
	    cin>>x;
	    if(x <= pq1.size()){
	        priority_queue<int> pq2;
	        while(pq2.size()!=x){
	            pq2.push(pq1.top());
	            pq1.pop();
	        }
	        if(pq2.size() > 0){
	            cout<<pq2.top()<<endl; 
	            pq2.pop();   
	        }
	        else{
	            cout<<-1<<endl;
	        }
	        while(!pq2.empty()){
	            pq1.push(pq2.top());
	            pq2.pop();
	        }
	    }
	    else{
	        cout<<-1<<endl;
	    }
	}
	return 0;
}