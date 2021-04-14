#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int length[n];
    int price[n];
    for(int i = 0; i < n; i++){
        cin >> price[i];
        length[i] = i+1;
    }
    int dp[n+1][n+1];
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < n+1; j++){
            if(i==0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            if(length[i-1] <= j){
                dp[i][j] = max(price[i-1] + dp[i][j - length[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][n] << endl;
}