#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> merge_intervals(vector<vector<int>> &vec){
  if (vec.empty()){
    return {};
  }

  sort(vec.begin(), vec.end());

  vector<vector<int>> res;
  res.push_back(vec[0]);

  for(int i=1; i<vec.size(); i++){
    vector<int> &prev = res.back();
    vector<int> &current = vec[i];

    if(current[0] <= prev[1]){
      prev[1] = max(prev[1], current[1]);
    } else {
      res.push_back(current);
    }
  }

  return res;
}

int main() {
  vector<vector<int>> intervals1 = {{1, 3}, {2, 4}, {6, 8}, {9, 10}};
  vector<vector<int>> intervals2 = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};

  cout << "Merged intervals 1: ";
  auto merged1 = merge_intervals(intervals1);
  for (auto interval : merged1) {
      cout << "[" << interval[0] << ", " << interval[1] << "] ";
  }
  cout << endl;

  cout << "Merged intervals 2: ";
  auto merged2 = merge_intervals(intervals2);
  for (auto interval : merged2) {
      cout << "[" << interval[0] << ", " << interval[1] << "] ";
  }
  cout << endl;

  return 0;
}