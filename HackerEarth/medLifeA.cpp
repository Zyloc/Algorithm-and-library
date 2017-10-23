#include<bits/stdc++.h>
using namespace std;
const int MAX(1e2+1);
const int SIZE(1e4+2);
bool dp[SIZE][MAX];
int n;
bool visited[SIZE][MAX];
string input;
bool temp[SIZE];
int getInteger(char x){
    return int(x)-48;
}
void magicBox(int index,int value,int k){
    if(index == n){
        if(value!=-1){
            temp[value] = true;    
        }
        return ;
    }
    if(visited[index][value+1]){
        return;
    }
    visited[index][value+1] = true;
    magicBox(index+1,value,k);
    if(value == -1){
        magicBox(index+1,(getInteger(input[index])%k)%k,k);    
    }
    else{
        magicBox(index+1,((value%k)*(10%k)+getInteger(input[index])%k)%k,k);    
    }
}
vector<string> solve_queries (vector<int> Query, int K, string N) {
    n = N.size();
    input = N;
    magicBox(0,-1,K);
    vector<string> answer;
    for(int i(0);i<Query.size();i++){
        if(temp[Query[i]]){
            answer.push_back("YES");
        }
        else{
            answer.push_back("NO");
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string N;
    cin>>N;
    //getline(cin, N);
    int K;
    cin >> K;
    int Q;
    cin >> Q;
    vector<int> Query(Q);
    for(int i_Query=0; i_Query<Q; i_Query++)
    {
    	cin >> Query[i_Query];
    }

    vector<string> out_;
    out_ = solve_queries(Query, K, N);
    for(int i_out_=0; i_out_<out_.size(); i_out_++)
    {
    	cout << out_[i_out_] << "\n";
    }
}