#include<bits/stdc++.h>
using namespace std;
#define lli long long int
const int MAX(65540);
vector < string > bank;
string start,en;
map<string,lli> stringToNumber;
map<lli,string> numberToString;
vector <lli> graph[MAX];
bool visited[MAX];
set<string> availableGenes;

lli getDifference(string s){
	lli ans(0);
	for(int i(0);i<8;i++){
		if(s[i]!=start[i]){
			ans++;
		}
	}
	return ans;
}

int findMutationDistance(string s, string e, vector < string > b) {
	start = s;
	queue<pair<string,lli>  > q ;
	q.push({e,0});
	for(auto x:b){
		availableGenes.insert(x);
	}
	string genes("ACTG");
	while(!q.empty()){
		pair<string,lli> processing(q.front());
		if(processing.first == s){
			return processing.second;
		}
		if(getDifference(processing.first) == 1){
			return processing.second+1;
		}
		for(int i(0);i<8;i++){
			for(auto x:genes){
				string current(processing.first);
				current[i] = x;
				if(availableGenes.find(current) != availableGenes.end()){
					q.push({current,processing.second+1});
					availableGenes.erase(current);
				}
			}
		}
		q.pop();
	}
	return -1;
}

int main() {
	ofstream fout(getenv("OUTPUT_PATH"));
	int res;
	string _start;
	getline(cin, _start);
	
	string _end;
	getline(cin, _end);
	
	
	int _bank_size = 0;
	cin >> _bank_size;
	cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
	vector<string> _bank;
	string _bank_item;
	for(int _bank_i=0; _bank_i<_bank_size; _bank_i++) {
		getline(cin, _bank_item);
		_bank.push_back(_bank_item);
	}
	
	res = findMutationDistance(_start, _end, _bank);
	fout << res << endl;
	
	fout.close();
	return 0;
}