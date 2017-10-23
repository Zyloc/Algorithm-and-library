/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
string magicBox(char grd[128][128],int m,int n,char word[32],string wordSoFar,int x,int y){
	if(x>0 and y>0 and !visited[x-1][y-1]){
		
	}
}
bool findWordInAGrid(char grid[128][128], int m, int n, char word[32]){
	for(int i(0);word[i]!='\0';i++){
		for(int x(0);x<m;x++){
			for(int y(0);y<n;y++){	
				if(word[i]==grid[x][y]){
					bool visited[128][128];
					memset(visited,false,sizeof visited);
					string wordFormed;
					wordFormed = magicBox(grid,m,n,word,wordFormed,x,y);
					if(wordFormed == givenWord){
						return true;
					}
				}
			}
		}
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}
