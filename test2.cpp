#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long int ll;
bool comp(pair<int,int>p1,pair<int,int>p2){
	if(p1.first==p2.first && p1.second>=p2.second)
	return p1.second>=p2.second;
	else return false;
 
}
int main(){
	ll s,n;
	vector<pair<int,int> > p;
	cin>>s>>n;
	ll a[n+1];
	int a1[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>a1[i];
		p.push_back(pair<int,int>(a[i],a1[i]));
 
	}
 
	cout<<s<<endl;
	sort(p.begin(),p.end(),comp);
	vector<pair<int,int> >:: iterator it=p.begin();
	for(int i=0;i<n;i++){
 
		if(it->first>=s){
			cout<<"NO";
			return 0;
		}
		else{
			s=s+it->second;
		}
		cout<<s<<endl;
  		it++;
	}
	cout<<"YES";
 
 
}