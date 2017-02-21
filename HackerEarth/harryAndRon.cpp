/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
int chessBoard[9][9];
bool visited[9][9];
int a,b,c,d;
void magicBox(int x,int y){
	if(x>8 or y>8){
		return;
	}
	if(x-2 > 0 and y-1 > 0){
		if(chessBoard[x][y]+1 < chessBoard[x-2][y-1]){
			chessBoard[x-2][y-1] = chessBoard[x][y]+1;        
			magicBox(x-2,y-1);
		}
	}
	if(x-2 > 0 and y+1 < 9){
		if(chessBoard[x][y]+1 < chessBoard[x-2][y+1]){
			chessBoard[x-2][y+1] = chessBoard[x][y]+1;
			magicBox(x-2,y+1);
		}
	}
	if(x+2 > 0 and y-1 > 0){
		if(chessBoard[x][y]+1 < chessBoard[x+2][y-1]){
			chessBoard[x+2][y-1] = chessBoard[x][y]+1;
			magicBox(x+2,y-1);
		}
	}
	if(x+2 > 0 and y+1 > 0){
		if(chessBoard[x][y]+1 < chessBoard[x+2][y+1]){
			chessBoard[x+2][y+1] = chessBoard[x][y]+1;
			magicBox(x+2,y+1);
		}
	}
	if(y-2>0 and x-1>0){
		if(chessBoard[x][y]+1 < chessBoard[x-1][y-2]){
			chessBoard[x-1][y-2] = chessBoard[x][y]+1;
			magicBox(x-1,y-2);
		}
	}
	if(y-2>0 and x+1>0){
		if(chessBoard[x][y]+1 < chessBoard[x+1][y-2]){
			chessBoard[x+1][y-2] = chessBoard[x][y]+1;
			magicBox(x+1,y-2);
		}
	}
	if(y+2>0 and x-1>0){
		if(chessBoard[x][y]+1 < chessBoard[x-1][y+2]){
			chessBoard[x-1][y+2] = chessBoard[x][y]+1;
			magicBox(x-1,y+2);
		}
	}
	if(y+2>0 and x+1>0){
		if(chessBoard[x][y]+1 < chessBoard[x+1][y+2]){
			chessBoard[x+1][y+2] = chessBoard[x][y]+1;
			magicBox(x+1,y+2);
		}
	}
}
int main(){
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			chessBoard[i][j] = INT_MAX;
	cin>>a>>b>>c>>d;
	chessBoard[a][b] = 0;
	magicBox(a,b);
	cout<<chessBoard[c][d];	
	return 0;
}