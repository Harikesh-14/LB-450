#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int kadane(vector<int> &vec){
  int n = vec.size();
  int MAX_SUM = INT_MIN;
  int CURR_MAX = 0;

  for(int i=0; i<n; i++){
    CURR_MAX = max(vec[i], vec[i] + CURR_MAX);
    MAX_SUM = max(CURR_MAX, MAX_SUM);
  }

  return MAX_SUM;
}

int main() {
  vector<int> vec = {1, -3, 2, 1, 1, -1};

  cout<<"Original array: ";
  for(auto num: vec){
    cout<<num<<" ";
  }cout<<endl;

  cout<<"Maximum sum subarray: ";
  int sum = kadane(vec);
  cout<<sum<<endl;

  return 0;
}