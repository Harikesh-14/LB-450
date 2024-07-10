#include<iostream>
#include<vector>
using namespace std;

// Top down approach
int tribonacci(int n, vector<int> &dp){
  if (n == 0) return 0;
  if (n == 1 || n == 2) return 1;

  if (dp[n] != -1) return dp[n];

  dp[n] = tribonacci(n-1, dp) + tribonacci(n-2, dp) + tribonacci(n-3, dp);

  return dp[n];
}

// Bottom up approach
int tribonacci(int n){
  vector<int> dp(n+1, -1);
  dp[0] = 0;
  dp[1] = dp[2] = 1;

  for(int i=3; i<=n; i++){
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
  }

  return dp[n];
}

int main() {
  int n;
  cin >> n;

  vector<int> dp(n+1, -1);

  cout << "Top down approach: ";
  int ans = tribonacci(n, dp);
  cout << ans << endl;

  cout << "Bottom up approach: ";
  ans = tribonacci(n);
  cout << ans << endl;

  return 0;
}