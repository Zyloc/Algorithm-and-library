/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;

int getNext(int index){
	return index+(index & -index);
}
int getParent(int index){
	return index - (index & -index);
}
void updateTree(vector<int> &binaryIndexTree,int value,int index){
	while(index < binaryIndexTree.size()){
		binaryIndexTree[index] += value;
		index = getNext(index);
	}

}
int getSum(vector<int> &binaryIndexTree,int index){
	index += 1;
	int ans(0);
	while(index){
		ans += binaryIndexTree[index];
		index = getParent(index); 
	}
	return ans;
}
void createBinaryTree(vector<int> &input,vector<int> &binaryIndexTree){
	for(int i=1;i<=input.size();i++){
		updateTree(binaryIndexTree,input[i-1],i);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x;
	cin>>n;
	vector<int> input,binaryIndexTree(n+1,0);
	for(int i=0;i<n;i++){
		cin>>x;
		input.push_back(x);
	}
	createBinaryTree(input,binaryIndexTree);
	for(int i=0;i<n;i++){
		cout<<getSum(binaryIndexTree,i)<<endl;
	}
	return 0;
}