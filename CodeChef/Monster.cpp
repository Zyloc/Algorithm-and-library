/*
 * Satyam Swarnkar(Zyloc) , NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
struct node{
	map<char,node*> next;
	bool end;
	lli value;
	string rep;
	node(){
		end = false;
		value = -1;
	}
};
node* head;
lli total;
string make32Bits(string s){
	string temp(32-s.length(),'0');
	return temp+s;
}

node* getNode(){
	return new node();
}
node* insertUtil(node* current,char c){
	if(current->next[c]!=NULL){
		return current->next[c];
	}
	node* temp(getNode());
	current->next[c] = temp;
	return temp; 
}
void insertNode(string s,lli value){
	node* current(head);
	for(int i(0);i<s.length();i++){
		current = insertUtil(current,s[i]);
	}
	current->end = true;
	current->value = value;
	current->rep = s;
}
void traverse(node* head,lli index,string &pattern,lli y){
	if(head->end){
		if(head->value > 0){
			head->value-= y;
			if(head->value <= 0){
				total--;
			}
		}
		return;
	}
	if(pattern[index] == '0'){
		if(head->next['0']!=NULL){
			traverse(head->next['0'],index+1,pattern,y);
		}
	}
	else{
		if(head->next['0']!=NULL){
			traverse(head->next['0'],index+1,pattern,y);
		}
		if(head->next['1']!=NULL){
			traverse(head->next['1'],index+1,pattern,y);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,q,x,y;
	cin>>n;
	vector<string> binary;
	vector<lli> health;
	string temp;
	temp = "0";
	binary.push_back(temp);
	temp = "1";
	binary.push_back(temp);
	for(int i(2);i<n;i++){
		binary.push_back(binary[i/2]+(i%2?"1":"0"));
	}
	for(int i(0);i<n;i++){
		binary[i] = make32Bits(binary[i]);
	}
	head = getNode();
	for(int i(0);i<n;i++){
		cin>>x;
		insertNode(binary[i],x);
	}
	cin>>q;
	total = n;
	for(int i(0);i<q;i++){
		cin>>x>>y;
		temp = "";
		while(x){
			if(x&1){
				temp += "1";
			}
			else{
				temp += "0";
			}
			x/= 2;
		}
		reverse(temp.begin(),temp.end());
		temp = make32Bits(temp);
		traverse(head,0,temp,y);
		cout<<total<<endl;
	}
	return 0;
}
