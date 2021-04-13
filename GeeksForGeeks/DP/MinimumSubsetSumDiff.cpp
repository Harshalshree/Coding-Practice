#include <bits/stdc++.h>
using namespace std;

bool dp[100][100];

int main(){
    int n;
    cin >> n;
    int arr[n];
    int sum = 0;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum = sum + arr[i];
    }

    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < sum+1; j++){
            if(i == 0){
                dp[i][j] = false;
            }
            if(j == 0){
                dp[i][j] = true;
            }
        }
    }

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < sum+1; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= sum; j++)
          printf ("%4d", dp[i][j]);
       printf("\n");
     }


    int ans = INT_MAX;
    for(int i = 0; i <= sum/2; i++){
        if(dp[n][i] == true){
            ans = min(ans, sum - 2 * i);
        }
    }
    cout << ans << endl;
}
