/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e5);
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,q;
	cin>>n>>q;
	cout<<n<<" "<<q<<endl;
	vector<lli> first,second;
	for(int i(1);i<=n;i++){
		second.push_back(i);
	}
	lli temp(rand()%second.size()),temp2;
	first.push_back(second[temp]);
	second.erase(second.begin()+temp);
	for(int i(0);i<n-1;i++){
		temp = rand()%second.size();
		temp2 = rand()%first.size();
		cout<<second[temp]<<" "<<first[temp2]<<endl;
		first.push_back(second[temp]);
		second.erase(second.begin()+temp);
	}
	for(int i(0);i<n;i++){
		if(i == n-1){
			cout<<rand()%MAX+1<<endl;
		}
		else{
			cout<<rand()%MAX+1<<" ";
		}
	}
	for(int i(0);i<q;i++){
		cout<<rand()%n+1<<" "<<rand()%n+1<<" "<<rand()%MAX+1<<endl;
	}
	return 0;
}
