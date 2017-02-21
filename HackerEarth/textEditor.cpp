/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i,start,end) for (lli i=start;i<=end;i++)
#define pool(i,start,end) for(lli i=start;i>=end;i--)
#define zyloc() lli t;cin>>t;while(t--)
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define fill(a,value) memset(a,value,sizeof(a)) 
#define MOD 1000000007
#define PI  3.14159265358979323846
#define MAX 1000002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
struct node{
	char c;
	node* next;	
	node(){
		next=NULL;
	}
};
node* getNode(){
	return new node();
}
node* insertUtil(char c,node* start){
	node* temp(getNode());
	temp->c=c;
	start->next=temp;
	return temp;
}
node* insert(string s,node* start){
	loop(i,0,s.length()-1){
		start = insertUtil(s[i],start);
	}
	return start;
}
void printString(node* start){
	cout<<start->c;
	if(start->next == NULL){
		return;
	}
	printString(start->next);
}
void insertChar(char c, string s,node* start){
	if(start->next==NULL){
		return;
	}
	if(start->c == c){
		node* remainingList(start->next);
		node* endList(insert(s,start));
		start->c='-';
		endList->next = remainingList;
	}
	insertChar(c,s,start->next);
}

int main(){
	node* head(getNode());
	lli n,q1,q2;
	cin>>n>>q1>>q2;
	string s;
	char c;
	cin>>s;
	insert(s,head);
	while(q1--){
		cin>>c>>s;
		insertChar(c,s,head);
	}
	return 0;
}	