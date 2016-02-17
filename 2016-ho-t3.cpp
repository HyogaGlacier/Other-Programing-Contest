#include <bits/stdc++.h>
using namespace std;
int r[200010],rev[200010];
int dp[100010],out[100010];
int angry[200010];
int main(){
	int n,m,q;	cin>>n>>m>>q;
	vector<int> to[n],num[n];
	for(int i=0;i<m;i++){
		int u,v;	cin>>u>>v;	u--;	v--;
		to[u].push_back(v);	num[u].push_back(i);
		to[v].push_back(u);	num[v].push_back(i);
	}
	for(int i=0;i<m;i++)	rev[i]=INT_MAX;
	for(int i=0;i<q;i++){
		cin>>r[i];	r[i]--;
		rev[r[i]]=i;
	}
	for(int i=0;i<n;i++)	dp[i]=out[i]=INT_MAX;
	dp[0]=0;
	priority_queue<pair<int,int> > pq;
	pq.push(make_pair(-0,0));
	while(!pq.empty()){
		auto it=pq.top();	pq.pop();
		int cost=-it.first,cur=it.second;
		if(cost>dp[cur])	continue;
		cost++;
		for(int i=0;i<(int)to[cur].size();i++){
			int t=to[cur][i];
			int end=min(out[cur],rev[num[cur][i]]);
			if(dp[t]>cost){
				dp[t]=cost;
				out[t]=end;
				pq.push(make_pair(-cost,t));
			}
			else if(dp[t]==cost){
				out[t]=max(out[t],end);
			}
		}
	}
	for(int i=1;i<n;i++){
		if(out[i]==INT_MAX)	continue;
		angry[out[i]]++;
	}
	int sum=0;
	for(int i=0;i<q;i++){
		sum+=angry[i];
		cout<<sum<<endl;
	}
	return 0;
}
