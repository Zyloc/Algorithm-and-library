/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
const int MAX_SIZE = 1e5+1;
struct query{
	int l,r,index;
	string s;
};
string s[MAX_SIZE],dummy;
int n,q,BLOCK_SIZE;
vector<string> v;
unordered_map<string,int> mp;
int ans[MAX_SIZE];
vector<query> Query;
bool cmp(query lhs,query rhs){
	if(lhs.l/BLOCK_SIZE != rhs.l/BLOCK_SIZE){
		return lhs.l < rhs.l;
	}
	return lhs.r < rhs.r;
}
void add(int index){
	mp[s[index]]++;
}
void remove(int index){
	mp[s[index]]--;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	BLOCK_SIZE = sqrt(n)+1;
	for(int i=0;i<n;i++){
		cin>>s[i];
		mp[s[i]] = 0;
	}
	cin>>q;
	query temp;
	int l,r;
	for(int i=0;i<q;i++){
		cin>>l>>r>>dummy;
		l--;
		r--;
		temp.l = l;
		temp.r = r;
		temp.s = dummy;
		temp.index = i;
		Query.push_back(temp);
	}
	sort(Query.begin(),Query.end(),cmp);
	int mo_left(0),mo_right(-1);
	for(int i=0;i<q;i++){
		int left(Query[i].l),right(Query[i].r); 
		while(mo_right < right){
			mo_right++;
			add(mo_right);
		}
		while(mo_right > right){
			remove(mo_right);
			mo_right--;
		}
		while(mo_left < left){
			remove(mo_left);
			mo_left++;
		}
		while(mo_left > left){
			mo_left--;
			add(mo_left);
		}
		ans[Query[i].index] = mp[Query[i].s];
	}
	for(int i=0;i<q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}