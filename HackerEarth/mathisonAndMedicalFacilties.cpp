/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli n,k,m;
vector<pair<lli,lli> > input[2001];
lli ans[501],maxAns;
vector<lli> costOfBuilding;
const int MAXCOUNTER(10e6);
clock_t c_start;
lli universalCounter;
lli rateOfLearning;
void printAns(){	
	for(int i(0);i<n;i++){
		if(ans[i]){
			cout<<i+1<<" ";
		}
	}
}
bool manageTime(){
	clock_t c_end(clock());
	double tme(((c_end-c_start)*1.0)/(CLOCKS_PER_SEC*1.0));
	if(tme >= 1.9 ){
		printAns();
		exit(0);
	}
	return true;
}

void printBitSet(bitset<501> &visited){
	for(int i(0);i<n;i++){
		if(visited[i]){
			cout<<i<<" ";
		}
	}
	cout<<endl;
}
void calculateAns(bitset<501> &visited){
	vector<lli> dummy;
	lli dummyAns[m+1];
	if(universalCounter >= MAXCOUNTER){
		return ;
	}
	for(int i(0);i<m;i++){
		universalCounter++;
		dummyAns[i] = INT_MAX;
	}
	for(int i(0);i<n;i++){
		if(visited[i]){
			universalCounter++;
			dummy.push_back(i);
		}
	}
	for(auto x:dummy){
		for(int i(0);i<m;i++){
			universalCounter++;
			dummyAns[i] = min(dummyAns[i],input[i][x]);
		}
	}
	lli temp(0);
	for(int i(0);i<m;i++){
		universalCounter++;
		temp += dummyAns[i];
	}
	for(auto x:dummy){
		universalCounter++;
		temp -= costOfBuilding[x];
	}
	if(temp > maxAns){
		maxAns = temp;
		for(int i(0);i<n;i++){
			universalCounter++;
			ans[i] = visited[i];
		}
	}
}
string toString(set<lli> dummy){
	string s;
	for(auto x:dummy){
		universalCounter++;
		s+= to_string(x);
	}
	return s;
}
void magicBox(set<lli> &initialSet){
	unordered_set<string> st;
	bitset<501> temp;
	for(auto x:initialSet){
		manageTime();
		temp.set(x,1);
	}
	calculateAns(temp);
	while(manageTime()){
		set<lli> dummy;
		for(auto x:initialSet){
			if(dummy.size() == rateOfLearning){
				break;
			}
			dummy.insert(x);
		}
		for(int i(0);i<dummy.size();i++){
			initialSet.erase(initialSet.begin());
		}
		while(initialSet.size()!=k){
			manageTime();
			initialSet.insert((rand()%n*7)%n);
		}
		string tempString(toString(initialSet));
		if(st.find(tempString) == st.end()){
			st.insert(tempString);
			bitset<501> temp;
			for(auto x:initialSet){
				manageTime();
				temp.set(x,1);
			}
			calculateAns(temp);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	c_start = clock();
	cin>>n>>k>>m;
	rateOfLearning = min(k,max(1LL,(3*k)/10));
	memset(ans,-1,sizeof ans);
	for(int i(0);i<m;i++){
		lli x;
		for(int j(0);j<n;j++){
			cin>>x;
			input[i].push_back({x,j});
		}
		sort(input[i].begin(),input[i].end());
	}
	lli x;
	vector<pair<lli,lli> > csb;
	for(int i(0);i<n;i++){
		cin>>x;
		csb.push_back({x,i});
		costOfBuilding.push_back(x);
	}
	magicBox();
	printAns();
	return 0;
}