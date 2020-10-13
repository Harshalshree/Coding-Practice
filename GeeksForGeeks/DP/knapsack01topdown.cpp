#include <bits/stdc++.h>
using namespace std;

int dp[1002][1002];

int main() {
    int t;
    cin >> t;
    while(t--){
        // memset(dp, -1, sizeof(dp[0][0]) * 1002 * 1002); 
        int N;
        cin >> N;
        int W;
        cin >> W;
        int wt[N];
        int v[N];
        for(int i = 0; i < N; i++){
            cin >> v[i];
        }
        for(int i = 0; i < N; i++){
            cin >> wt[i];
        }
        for(int i = 0; i < N+1; i++){
            for(int j = 0; j < W+1; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 1; i < N+1; i++){
            for(int j = 1; j < W+1; j++){
                if(wt[i-1] <= j){
                    dp[i][j] = max(v[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j]);
                }
                else if(wt[i-1] > j){
                    dp[i][j] = dp[i-1][j];   
                }
            }
        }
        cout << dp[N][W] << endl;
    }
	return 0;
}
