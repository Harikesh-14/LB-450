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

int main() {
  int n;
  cin>>n;

  vector<int> dp(n+1, -1);

  cout<<"Top down approach: ";
  int ans = countDistinctWays(n, 0, dp);
  cout<<ans<<endl;

  return 0;
}