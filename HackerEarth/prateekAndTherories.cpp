/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
bool cmp(lli x,pair<lli,lli> p){
	return x <=p.first;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
	    lli n,x,y;
	    cin>>n;
	    vector<pair<lli,lli> > v;
	    for(int i=0;i<n;i++){
	        cin>>x>>y;
	        v.push_back(make_pair(x,y));
	    }
	    sort(v.begin(),v.end());
	    lli index(0),ans(0);
	    while(index < n){
	        lli search(v[index].second);
	        lli  low(index+1),high(n-1),found(-1);
	        while(low <= high){
	        	lli mid((low+high)/2);
	        	if(v[mid].first >= v[index].second){
	        		high = mid-1;
	        	}
	        	else{
	        		low = mid + 1;
	        		found = mid;	
	        	}
	        }
	        if(found != -1){
	        	ans = max(ans,found-index+1);
	        }
	        index++;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}