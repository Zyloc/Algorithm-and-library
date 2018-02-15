/*
 * Author: Satyam Swarnkar (14-1-5-027) , Aniket Raj(14-1-5-017)
 * Huffman coding (Encoder)
 * Huffman is gready  
*/
#include <bits/stdc++.h>
#define lli int
using namespace std;

struct node{
	string data;
	lli frequency;
	node *left,*right;
	node(string data,lli frequency){
		this->data = data;
		this->frequency = frequency;
		left = NULL;
		right = NULL;
	}
};

struct compare{
	bool operator()(node* left,node* right){
		return left->frequency > right->frequency;
	}
};

void getCode(node* currentNode,string codeSoFar,map<string,string> &code){
	if(currentNode->data != "#"){
		code[currentNode->data] = codeSoFar;
	}
	else{
		getCode(currentNode->left,codeSoFar+'0',code);
		getCode(currentNode->right,codeSoFar+'1',code);
	}
}

map<string,string> calculateCode(map<string,lli> &inputString){
	priority_queue<node*,vector<node*>,compare > pq;
	
	for(auto x:inputString){
		pq.push(new node(x.first,x.second));
	}
	
	while(pq.size()!=1){
		node* left(pq.top());
		pq.pop();
		node* right(pq.top());
		pq.pop();
		node* temp(new node("#",left->frequency+right->frequency));
		temp->left = left;
		temp->right = right;
		pq.push(temp);
	}
	map<string,string> code;
	getCode(pq.top(),"",code);
	return code;
}

map<string,lli> takeInput(){
	map<string,lli> frequency;
	string s;
	ifstream infile;
	infile.open("input.txt");
	while(!infile.eof()){
		infile>>s;
		frequency[s]++;
	}
	return frequency;
}

int main(){
	
	// read input
	map<string,lli> input;
	input = takeInput();
	// calculate code
	map<string,string> finalCode;
	finalCode = calculateCode(input);
	for(auto x:finalCode){
		cout<<x.first<<" "<<x.second<<endl;
	}

	// print Huffman code
	return 0;
}
