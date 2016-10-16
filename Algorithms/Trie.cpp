/*
 * Satyam Swarnkar (Zyloc), Nit Silchar
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <functional>
#include <limits.h>
#include <list>  
using namespace std;
#define loop(i,start,end) for (int i=start;i<=end;i++)
#define pool(i,start,end) for(int i=start;i>=end;i--)
#define zyloc() lli t;cin>>t;while(t--)
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define fill(a,value) memset(a,value,sizeof(a)) 
#define MOD 1000000007
#define PI  3.14159265358979323846
#define MAX 100008
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
lli hash[MAX]={0};
struct TrieNode{
	map<char,TrieNode*> children;
	bool end;
	TrieNode(){
		end = false;
	}
};
struct TrieNode* getTrieNode(){
	return new TrieNode();
}
class Trie{
	TrieNode* head;
	struct TrieNode* insertUtil(char c,struct TrieNode* start);
	struct TrieNode* prefixSearchingUtil(struct TrieNode* start,char c);
public:
	Trie(){
		head = new TrieNode();
		head->end = false;
	}
	void insert(string word);
	void printTrie();
	bool findWord(string word);
	bool prefixSearching(string word);
};
struct TrieNode* Trie::insertUtil(char c,struct TrieNode* start){
	if (start->children[c]!=NULL){
		return start->children[c];
	}
	else{
		struct TrieNode* newTrieNode = getTrieNode();
		start->children[c] = newTrieNode;
		return newTrieNode;
	}
}
void Trie::insert(string word){
	TrieNode* start(head);
	loop(i,0,word.length()-1){
		start = insertUtil(word[i],start);
	}
	start->end = true;
}
bool Trie::findWord(string word){
	TrieNode* start(head);
	loop(i,0,word.length()-1){
		if (start->children[word[i]]!=NULL){
			start = start->children[word[i]];
		}	
		else {
			return false;
		}
	}
	return true;	
}
struct TrieNode* Trie::prefixSearchingUtil(struct TrieNode* start,char c){
	return start->children[c];
}
bool Trie::prefixSearching(string word){
	struct TrieNode* start(head);
	loop(i,0,word.length()-1){
		start = prefixSearchingUtil(start,word[i]);
		if(start==NULL){
			return false;
		}
	}
	return true;
}

string tobinary(lli x,lli lengthOfString){
	string generate;
	while(x>0){
		generate += char(x%2)+'0';
		x /= 2;
	}
	loop(i,generate.length(),lengthOfString-1){
		generate+='0';
	}
	reverse(generate.begin(),generate.end());
	return generate;
}	

int main(){
	Trie t;
	lli n,x;
	string s;
	cin>>n;
	loop(i,0,n-1){
		cin>>x;
		s = tobinary(x,15);
		t.insert(s);
	}

    return 0;
}	