#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int n,a,last=0;
    cin>>n;
    vector <int> v;
    vector <int> sume;
    
    for (int i=0;i<n;i++){
    	cin>>a;
    	v.push_back(a);
        if(i!=0)
        sume.push_back(sume[i-1]+a);
        else
            sume.push_back(a);
    	//last=a;
        //cout<<v[i];
    }
    int q;
    cin>>q;
    int q1,q2;
    for(int j=0;j<q;j++){
        cin>>q1>>q2;
        if (q1!=1)
    	cout<<sume[q2-1]-sume[q1-2]<<endl;
        else{
            cout<<sume[q2-1]<<endl;
        }
    }
    return 0;
}