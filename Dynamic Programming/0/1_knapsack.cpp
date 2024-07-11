#include<iostream>
#include<vector>
using namespace std;

int solveMemo(vector<int> weight, vector<int> value, int index, int capacity, vector<vector<int>> &dp){
  if(index == 0){
    if (weight[index] <= capacity){
      return value[index];
    } else {
      return 0;
    }
  }

  if(dp[index][capacity] != -1){
    return dp[index][capacity];
  }

  int include = 0;
  if(weight[index] <= capacity){
    include = value[index] + solveMemo(weight, value, index-1, capacity - weight[index], dp);
  }

  int exclude = solveMemo(weight, value, index-1, capacity, dp);

  return dp[index][capacity] = max(include, exclude);
}

int main() {
  vector<int> weight = {1, 2, 4, 5};
  vector<int> value = {5, 4, 8, 6};
  int capacity = 5;
  int index = weight.size() - 1;

  vector<vector<int>> dp(weight.size(), vector<int> (capacity+1, -1));

  cout<<"Top Down Approach: ";
  cout << solveMemo(weight, value, index, capacity, dp) << endl;

  return 0;
}