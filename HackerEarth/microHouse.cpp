/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli  long long int
using namespace std;
lli MAX_SET_BIT;
struct node{
	struct node* one;
	struct node* zero;
};
struct node* getNode(){
	return new node();
}
void insert(node* head,lli x){	
	for(lli i=MAX_SET_BIT;i>=0;i--){
		bool set(x&(1LL<<i));
		if(set){
			if(head->one==NULL){
				head->one = getNode();
			}
			head = head->one;
		}
		else{
			if(head->zero==NULL){
				head->zero = getNode();
			}
			head = head->zero;
		}	
	}
}
lli query(node* head,lli q){
	lli ans(0);
	for(int i= MAX_SET_BIT;i>=0;i--){
		bool set(q&(1<<i));
		if(set){
			if(head->zero!=NULL){
				ans|=(1LL<<i);
				head = head->zero;
			}
			else{
				head = head->one;
			}
		}
		else{
			if(head->one!=NULL){
				ans|= (1LL<<i);
				head = head->one;
			}
			else{
				head = head->zero; 
			}
		}
	}	
	return ans;
}
int main(){
	lli row,col,maxInput(0);
	scanf("%lld %lld",&row,&col);
	lli input[row][col],temp[row];
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			scanf("%lld",&input[i][j]);
			maxInput = max(maxInput,input[i][j]);
		}
	}
	for(int i=30;i>=0;i--){
		if(maxInput&(1LL<<i)){
			MAX_SET_BIT = i;
			break;
		}
	}	
	lli ans(input[0][0]);
	for(int i=0;i<col;i++){
		node* head=getNode();
		for(int j=i;j<col;j++){
			lli xorSoFar(0);
			for(int z=i;z<row;z++){
				if(j == i){
					temp[z] = input[z][j];
				}
				else{
					temp[z] ^= input[z][j];
				} 
			    xorSoFar ^= temp[z];
			    insert(head,xorSoFar);
				ans = max(ans,query(head,xorSoFar));
			}
		}
		delete[] head;
	}
	cout<<ans<<endl;	
	return 0;
}