#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100010][4];
ll oi[3][100010];
ll J[100010];
ll I[100010];
ll jo[3][100010];
int main(){
	int n;	cin>>n;
	string s;	cin>>s;
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		if(s[i]=='J')	dp[i+1][1]+=dp[i][0];
		else if(s[i]=='O')	dp[i+1][2]+=dp[i][1];
		else 	dp[i+1][3]+=dp[i][2];
		for(int j=0;j<4;j++)	dp[i+1][j]+=dp[i][j];
	}
	
	jo[0][0]=1;
	for(int i=0;i<n;i++){//j&jo
		if(s[i]=='J'){
			J[i+1]++;	jo[1][i+1]+=jo[0][i];
		}
		else if(s[i]=='O')	jo[2][i+1]+=jo[1][i];
		J[i+1]+=J[i];
		jo[0][i+1]+=jo[0][i];
		jo[1][i+1]+=jo[1][i];
		jo[2][i+1]+=jo[2][i];
	}
	
	oi[0][n]=1;
	for(int i=n-1;i>=0;i--){//i&oi
		if(s[i]=='I'){
			I[i]++;	oi[1][i]+=oi[0][i+1];
		}
		else if(s[i]=='O')	oi[2][i]+=oi[1][i+1];
		I[i]+=I[i+1];
		oi[0][i]+=oi[0][i+1];
		oi[1][i]+=oi[1][i+1];
		oi[2][i]+=oi[2][i+1];
	}
	
	ll ans=max(oi[2][0],jo[2][n]);
	for(int i=1;i<n;i++){
		ll tmp=max(oi[2][i],jo[2][i]);
		ll med=max(J[i]*I[i],tmp);
		ans=max(ans,med);
	}
	cout<<ans+dp[n][3]<<endl;
	return 0;
}
