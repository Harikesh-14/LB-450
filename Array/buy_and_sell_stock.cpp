#include<iostream>
#include<climits>
#include<vector>
#include<unordered_map>
using namespace std;

pair<int, int> smallest_elem(const vector<int> &vec) {
  int min_element = vec[0];
  int min_index = 0;

  for (int i = 1; i < vec.size(); ++i) {
    if (vec[i] < min_element) {
      min_element = vec[i];
      min_index = i;
    }
  }

  return make_pair(min_element, min_index);
}

int maxProfit(vector<int> &vec){
  int profit = INT_MIN;
  int size = vec.size();
  int elem, index, max_cost = INT_MIN;

  pair<int, int> min_elem = smallest_elem(vec);

  elem = min_elem.first;
  index = min_elem.second;

  for(int i=index; i<size; i++){
    max_cost = max(max_cost, vec[i]);
  }

  return max_cost - elem;
}

int main() {
  vector<int> vec = {7, 6, 4, 3, 1};

  cout<<"Original array: ";
  for(auto num: vec){
    cout<<num<<" ";
  }cout<<endl;

  int profit = maxProfit(vec);
  cout<<"Max profit: "<<profit<<endl;

  return 0;
}