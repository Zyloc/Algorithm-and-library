#include <bits/stdc++.h>
#include <cstring>
#include <algorithm>
#define s(n) scanf("%d", &n)
#define lli  int
using namespace std;

struct node {
	node *left;
	node *right;
	int label;
};


void _makeTree(node *root,int lleft[1024],int rright[1024]) {

	int num = root->label;

	if(lleft[num] == -1 && rright[num] == -1) return;

	if(lleft[num] != -1) {
		node *leftNode = new node;
		leftNode->label =  lleft[num];
		leftNode->left = NULL;
		leftNode->right = NULL;
		_makeTree(leftNode,lleft,rright);
		root->left = leftNode;
	}

	if(rright[num] != -1) {
		node *rightNode = new node;
		rightNode->label =  rright[num];
		rightNode->left = NULL;
		rightNode->right = NULL;
		_makeTree(rightNode,lleft,rright);
		root->right = rightNode;
	}

}

void _deleteNode(node *root) {
	if(root == NULL) return;

	_deleteNode(root->left);
	_deleteNode(root->right);
	delete root;
}
int ansLabel,ansHeight,ansLeft,ansRight;
node* pointerToBest;
int dfs(node* root,int level){
	if(root->left ==NULL and root->right==NULL){
		return level;
	}	
	int leftHeight(0),rightHeight(0);
	if(root->left!=NULL){
		leftHeight =  dfs(root->left,level+1);
	}
	if(root->right!=NULL){
		rightHeight = dfs(root->right,level+1);
	}
	if(leftHeight+rightHeight > ansHeight){
		ansHeight = leftHeight+rightHeight;
		ansLabel = root->label;
		ansLeft = leftHeight;
		ansRight = rightHeight;
		pointerToBest = root;
	}
	return 1+max(leftHeight,rightHeight);
}
lli dfsLeft(node* root,lli pick){
	if(pick == 0){
		return root->label;
	}
	return dfsLeft(root->left,pick-1);
}
lli dfsRight(node* root,lli pick){
	if(pick == 0){
		return root->label;
	}
	return dfsRight(root->right,pick-1);
}
int getRootWhichMinimizesFurthestLeafDistance(node *root) {
	ansLabel = INT_MAX;
	ansHeight = 0;
	ansLeft = 0;
	ansRight = 0;
	if(root == NULL){
		return 0;
	}
	dfs(root,0);
	if(ansLeft == ansRight){
		return ansLabel;
	}
	ansHeight++;
	if(ansHeight&1){
		lli index((ansLeft+ansRight)/2);
		if(ansLeft >= ansRight){
			return dfsLeft(pointerToBest,ansLeft-index);
		}
		else{
			return dfsRight(pointerToBest,ansRight-index);
		}
	}
	else{
		if(ansLeft > ansHeight){
			lli moves((ansHeight+1)/2-ansLeft);
			return min(dfsLeft(pointerToBest,moves),dfsLeft(pointerToBest,moves+1));
		}
		else{
			lli moves((ansHeight+1)/2-ansRight);
			return min(dfsRight(pointerToBest,moves),dfsRight(pointerToBest,moves+1));
		}
	}
	return 0;
}

int main() {

	int runs, nodeNo, nodeLeft, nodeRight, rootLabel;
	s(runs);
	while(runs-- > 0) {
		int n;
		int lleft[1024];
		int rright[1024];
		for(int i=0;i<1024;i++)
			lleft[i] = rright[i] = -1;

		s(n); s(rootLabel);
		for(int i=0;i<n;i++) {
			s(nodeNo); s(nodeLeft); s(nodeRight);
			lleft[nodeNo] = nodeLeft;
			rright[nodeNo] = nodeRight;
		}

		node *root = new node;
		root->label = rootLabel;
		root->left = NULL;
		root->right = NULL;
		_makeTree(root,lleft,rright);
		int answer = getRootWhichMinimizesFurthestLeafDistance(root);
		cout << answer << endl;
		_deleteNode(root);
	}

	return 0;
}
