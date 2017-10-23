/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
struct dataType{
    int value,frequency;  
    dataType() {
        frequency=0;
    }
};
const int MAX(1e6+1);
int value[MAX];
vector<vector<dataType> > answer;

void preCompute(){
    for(int i(1);i<MAX;i++){
        for(int j(i);j<MAX;j+=i){
            value[j]++;
        }
    }
}
void insert(int dangerValue){
    vector<dataType> dummy,final;
    int index(0);
    if(answer.size() != 0){
        dummy = answer[answer.size()-1];
    }
    dataType temp;
    while(index < dummy.size()){
        temp = dummy[index];
        if(temp.value < dangerValue){
            final.push_back(temp);
        }
        else{
            if(temp.value == dangerValue){
                temp.frequency++;
            }
            else{
                temp.value = dangerValue;
                temp.frequency = 1;
            }
            dangerValue = INT_MAX;
            final.push_back(temp);
        }
        index++;
    }
    if(dangerValue != INT_MAX){
        temp.value = dangerValue;
        temp.frequency = 1;
        final.push_back(temp);
    }
    answer.push_back(final);
}
lli query(lli start,lli end){
    lli pairs(0);
    lli leftIndex(0),rightIndex(0);
    if(start != 0){
        start--;
        while(leftIndex < answer[start].size() and rightIndex < answer[end].size()){
            if(answer[start][leftIndex].value == answer[end][rightIndex].value){
                int diff(answer[end][rightIndex].frequency - answer[start][leftIndex].frequency);
                pairs +=  (diff*(diff-1))/2;
            }
            else if(answer[start][leftIndex].value < answer[end][rightIndex].value){
                leftIndex++;
            }
            else{
                rightIndex++;
            }
        }
    }
    while(rightIndex < answer[end].size()){
        pairs+= (answer[end][rightIndex].frequency*(answer[end][rightIndex].frequency-1))/2;
        rightIndex++;
    }
    return pairs;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	preCompute();
	lli n,x,q,l,r;
	vector<lli> input;
	cin>>n;
	for(int i(0);i<n;i++){
	    cin>>x;
	    input.push_back(value[x]);
	}
	dataType temp;
	for(int i(0);i<n;i++){
	    insert(input[i]);
	}
    cin>>q;
    while(q--){
        cin>>l>>r;
        l--,r--;
        cout<<query(l,r)<<endl;
    }
	return 0;
}	