/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const lli zero = 0;
const lli one= 1; 
struct node{
	map<lli,node*> child;
};
struct node* getNode(){
	return new node();
}
void insert(node* trie,lli x,lli position){	
	if(position < 0){
		return ;
	}
	bool set(x&(1LL<<position));
	if(set){
		if(trie->child[one]==NULL){
			trie->child[one] = getNode();	
		}
		return insert(trie->child[one],x,position-1);	
	}
	else{
		if(trie->child[zero] == NULL){
			trie->child[zero] = getNode();
		}
		return insert(trie->child[zero],x,position-1);
	}
}
lli query(node* trie,lli q,lli ansSoFar,lli position){
	if(position < 0){
		return ansSoFar;
	}
	bool set(q&(1LL<<position));
	if(set){
		if(trie->child[zero]!=NULL){
			ansSoFar |= (1LL<<position);
			return query(trie->child[zero],q,ansSoFar,position-1); 
		}
		return query(trie->child[one],q,ansSoFar,position-1);
	}	
	else{
		if(trie->child[one]!=NULL){
			ansSoFar |= (1LL<<position);
			return query(trie->child[one],q,ansSoFar,position-1); 
		}
		return query(trie->child[zero],q,ansSoFar,position-1);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	node* head=getNode();
	lli n,l,r;
	cin>>n>>l>>r;
	if(l>r){
		swap(l,r);
	}
	lli input[n];
	for(int i=0;i<n;i++){
		cin>>input[i];
	}
	lli andSoFar(1),ans(0);
	for(int i=0;i<n;i++){
		ansSoFar &= input[i];
		insert(head,ansSoFar,32);
		lli dummy(query(head,andSoFar,0,31));
		if(dummy >=l and dummy <= r){
			ans++;
		} 
	}
	cout<<ans<<endl;
	/*insert(head,2,31);
	insert(head,5,31);
	cout<<query(head,8,0,31);*/
	/*int row,col;
	cin>>row>>col;
	lli input[row][col],temp[row];
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			cin>>input[i][j];
	lli ans(input[0][0]);
	for(int i=0;i<col;i++){
		node* head=getNode();
		memset(temp,0,sizeof temp);
		for(int j=i;j<col;j++){
			for(int z=0;z<row;z++){
				temp[z] ^= input[z][j]; 
			}
			lli xorSoFar(0);
			for(int z=0;z<row;z++){
				 xorSoFar ^= temp[z];
				  insert(head,xorSoFar,31);
				 ans = max(ans,query(head,xorSoFar,0,31)); 	
			}
		}
	}
	cout<<ans<<endl;*/	
	return 0;
}