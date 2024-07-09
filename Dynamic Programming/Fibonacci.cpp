#include<iostream>
#include<vector>
using namespace std;

// Top Down Approach
int fib(int n, vector<int> &dp){
  if(n==0 || n==1) {
    return n;
  }

  if(dp[n] != -1) {
    return dp[n];
  }

  dp[n] = fib(n-1, dp) + fib(n-2, dp);

  return dp[n];
}

// Bottom Up Approach
int fib_bot_up(int n){
  vector<int> dp(n+1);
  dp[0] = 0;
  dp[1] = 1;

  for(int i=2; i<=n; i++){
    dp[i] = dp[i-1] + dp[i-2];
  }

  return dp[n];
}

int main() {
  int n;
  cin>>n;

  vector<int> dp(n+1, -1);

  cout<<"Top Down Approach: ";
  cout<<fib(n, dp)<<endl;

  cout<<"Bottom Up Approach: ";
  cout<<fib_bot_up(n)<<endl;
  return 0;
}