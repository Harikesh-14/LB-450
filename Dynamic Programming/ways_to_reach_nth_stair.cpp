#include<iostream>
#include<vector>

#define MOD 1000000007;

using namespace std;

// Top down approach
int countDistinctWays(int stairs, int i, vector<int> &dp){
  if(stairs == i){
    return 1;
  }

  if(stairs < i){
    return 0;
  }

  if(dp[i] != -1){
    return dp[i];
  }

  return dp[i] = (countDistinctWays(stairs, i+1, dp) + countDistinctWays(stairs, i+2, dp)) % MOD;
}

// Bottom up approach
int countWays(int stairs){
  vector<int> dp(stairs + 1);

  dp[0] = 1;
  dp[1] = 1;

  for(int i=2; i<=stairs; i++){
    dp[i] = (dp[i-1] + dp[i-2]) % MOD;
  }

  return dp[stairs];
}

// space optimized approach
int countWaysOptimized(int stairs){
  if(stairs == 0 || stairs == 1){
    return 1;
  }

  int a = 1, b = 1, c;

  for(int i=2; i<=stairs; i++){
    c = (a + b) % MOD;
    a = b;
    b = c;
  }

  return c;
}

int main() {
  int n;
  cin>>n;

  vector<int> dp(n+1, -1);

  cout<<"Top down approach: ";
  int ans = countDistinctWays(n, 0, dp);
  cout<<ans<<endl;

  cout<<"Bottom up approach: ";
  cout<<countWays(n)<<endl;

  return 0;
}