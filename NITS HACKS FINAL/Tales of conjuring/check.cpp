lli lca(getLCA(x,y));
			if(getTotalWeight(y)-getTotalWeight(parent[lca])){
				lli current(y);
				//cout<<lca<<endl;
				while(current!=lca){
					lli currentWeight(weight[current]);
					lli newWeight(currentWeight/z);
					lli changeInWeight(newWeight- currentWeight);
					update(eulerStart[current],changeInWeight);
					update(eulerEnd[current]+1,-changeInWeight);
					weight[current] /= z;
					current = parent[current];
				}
			}
			if(getTotalWeight(x)-getTotalWeight(parent[lca])){
				lli current(x);
				while(current!=lca){
					lli currentWeight(weight[current]);
					lli newWeight(currentWeight/z);
					lli changeInWeight(newWeight- currentWeight);
					//cout<<newWeight<<endl;
					update(eulerStart[current],changeInWeight);
					update(eulerEnd[current]+1,-changeInWeight);
					weight[current] /= z;
					current = parent[current];
				}
			}
			