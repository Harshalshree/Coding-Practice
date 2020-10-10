#include <bits/stdc++.h>
using namespace std;

int dp[1002][1002];


int knapsack(int wt[], int v[], int W, int N){
    if(N == 0 || W == 0){
        return 0;
    }
    if(dp[N][W] != -1){
        return dp[N][W];
    }
    if(wt[N-1] <= W){
        return dp[N][W] = max(v[N-1]  + knapsack(wt, v, W - wt[N-1], N-1), knapsack(wt, v, W, N-1));
    }
    else if(wt[N-1] > W){
        return dp[N][W] = knapsack(wt, v, W, N-1);
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof(dp[0][0]) * 1002 * 1002); 
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
        cout << knapsack(wt, v, W, N) << endl;
    }
	return 0;
}