#include<bits/stdc++.h>
using namespace std;
int KnapsackImplementation(int *party,int*val,int *P,int N){
	int **dp = new int *[N+1];
	for(int i=0;i<=N;i++){
		dp[i] = new int[P+1];
	}
	for(int i=0;i<=N;i++){
		dp[i][0] = 0;
	}
	for(int j=0;j<=P;j++){
		dp[0][j] = 0;
	}
	for(int i=1;i<=N;i++){
		for(int p=1;p<=P;p++){
			
			dp[i][p] = dp[i-1][p];
			if(party[i-1]<=p){
				dp[i][p] = max(dp[i-1][p],(dp[i-1][p-party[i-1]]+val[i-1]));
			}
		}
	}
	int ans = dp[N][P];
	for(int i=0;i<=N;i++){
		delete [] dp[i];
	}
	return ans;
}
int main(){
	int P,N;
	cin>>P>>N;
	int *val = new int [N];
	int *prty = new int [P];
	//while(P!=0 && N!=0){
		for(int i=0;i<N;i++){
			cin>>prty[i]>>val[i];
		}
		int output = KnapsackImplementation(prty,val,&P,N);
		cout<<output<<endl;
	//}
}
