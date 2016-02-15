#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2][1010];
ll a[2][1010],b[2][1010];
int main(){
	ll n,m,k;	cin>>n>>m>>k;
	vector<ll> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<m;j++){
			dp[i][j]=LLONG_MAX;
			a[i][j]=INT_MIN;	b[i][j]=INT_MAX;
		}
	}
	dp[0][0]=k;	a[0][0]=b[0][0]=v[0];
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			if(dp[0][j]==LLONG_MAX)	continue;
			//その箱に追加する場合
			if(j+1<m){
				dp[1][j+1]=dp[0][j];
				a[1][j+1]=max((ll)a[0][j],v[i]);
				b[1][j+1]=min((ll)b[0][j],v[i]);
			}
			//新しく箱を作る場合
			ll num=k+dp[0][j];
			num+=(a[0][j]-b[0][j])*(j+1);
			dp[1][0]=min(dp[1][0],num);
			a[1][0]=b[1][0]=v[i];
		}
		for(int j=0;j<m;j++){
			dp[0][j]=dp[1][j];	dp[1][j]=LLONG_MAX;
			a[0][j]=a[1][j];	a[1][j]=INT_MIN;
			b[0][j]=b[1][j];	b[1][j]=INT_MAX;
		}
	}
	ll ans=LLONG_MAX;
	for(int i=0;i<m;i++){
		ll num=dp[0][i];
		num+=(a[0][i]-b[0][i])*(i+1);
		ans=min(ans,num);
	}
	cout<<ans<<endl;
	return 0;
}
