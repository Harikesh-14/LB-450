#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int max_product(vector<int> &vec){
  int size = vec.size();
  int MAX_PROD = INT_MIN;
  int CURR_MAX = 1;
  
  for(int i=0; i<size; i++){
    CURR_MAX = max(vec[i], vec[i] * CURR_MAX);
    MAX_PROD = max(MAX_PROD, CURR_MAX);
  }

  return MAX_PROD;
}

int main() {
  vector<int> vec = {2, -1, 3, 4, 2, -2, 5, 4}; 

  cout<<"Original array: ";
  for(auto num: vec){
    cout<<num<<" ";
  }cout<<endl;

  int product = max_product(vec);

  cout<<"Maximum product: "<<product<<endl;

  return 0;
}