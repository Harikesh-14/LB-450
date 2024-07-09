#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Top-down approach
int minimum_element(vector<int> arr, int target, vector<int> &dp){
  // Base case
  if(target == 0){
    return 0;
  }

  if(target < 0){
    return INT_MAX;
  }

  if(dp[target] != -1){
    return dp[target];
  }

  int mini = INT_MAX;

  for(int i=0; i<arr.size(); i++){
    // Recursive call
    int ans = minimum_element(arr, target - arr[i], dp);

    // If the answer is not INT_MAX, then add 1 to the answer
    if(ans != INT_MAX){
      mini = min(mini, ans + 1); // +1 because we are adding the current element
    }
  }

  return dp[target] = mini;
}

// Bottom-up approach
int solve2(vector<int> arr, int target){
  vector<int> dp(target+1, INT_MAX);
  dp[0] = 0;

  for(int i=1; i<=target; i++){
    for(int j=0; j<arr.size(); j++){
      if(i - arr[j] >= 0){
        dp[i] = min(dp[i], dp[i - arr[j]] + 1);
      }
    }
  }

  return dp[target];
}

int main() {
  vector<int> arr = {1, 2, 3};
  int target = 7;

  vector<int> dp(target+1, -1);

  cout<<"Top-down approach"<<endl;
  int ans = minimum_element(arr, target, dp);

  if(ans == INT_MAX){
    cout << "No possible solution" << endl;
  } else {
    cout << "Minimum number of elements required: " << ans << endl;
  }

  cout<<"Bottom-up approach"<<endl;
  int ans2 = solve2(arr, target);

  if(ans2 == INT_MAX){
    cout << "No possible solution" << endl;
  } else {
    cout << "Minimum number of elements required: " << ans2 << endl;
  }

  return 0;
}