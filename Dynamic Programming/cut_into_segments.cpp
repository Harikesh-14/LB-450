#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// top down approach
int cut_into_segments(int n, int x, int y, int z, vector<int> &dp){
  if(n == 0){
    return 0;
  }

  if(n < 0){
    return INT_MIN;
  }

  if(dp[n] != -1){
    return dp[n];
  }

  int a = 1 + cut_into_segments(n - x, x, y, z, dp);
  int b = 1 + cut_into_segments(n - y, x, y, z, dp);
  int c = 1 + cut_into_segments(n - z, x, y, z, dp);

  int ans = max(a, max(b, c));

	return dp[n] = ans;
}

// bottom up approach
int cut_into_segments2(int n, int x, int y, int z){
  vector<int> dp(n+1, INT_MIN);

  dp[0] = 0;

  for(int i=1; i<=n; i++){
    if(i-x >= 0){
      dp[i] = max(dp[i], dp[i-x] + 1);
    }

    if(i-y >= 0){
      dp[i] = max(dp[i], dp[i-y] + 1);
    }

    if(i-z >= 0){
      dp[i] = max(dp[i], dp[i-z] + 1);
    }
  }

  if(dp[n] < 0){
    return 0;
  } else {
    return dp[n];
  }
}

int main() {
  int n = 8;
  vector<int> nums = {n, 1, 4, 4};
  vector<int> dp(n + 1, -1);

  cout<<"Top Down Approach"<<endl;
  int ans = cut_into_segments(nums[0], nums[1], nums[2], nums[3], dp);

  if(ans < 0){
    cout << "0" <<endl;
  } else {
    cout << ans << endl;
  }

  cout<<"Bottom Up Approach"<<endl;
  cout<<cut_into_segments2(nums[0], nums[1], nums[2], nums[3])<<endl;

  return 0;
}