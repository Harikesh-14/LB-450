#include<iostream>
#include<vector>
using namespace std;

vector<int> rotate_arr(vector<int> &vec){
  vector<int> res;
  int len = vec.size();
  int last_elem = vec[len-1];

  res.push_back(last_elem);

  for(int i=0; i<len-1; i++){
    res.push_back(vec[i]);
  }

  return res;
}

int main() {
  vector<int> vec = {1, 2, 3, 4, 5, 6};

  cout<<"Original array: ";
  for(auto num: vec){
    cout<<num<<" ";
  }cout<<endl;

  cout<<"Rotated array: ";
  vector<int> res = rotate_arr(vec);
  for(auto num: res){
    cout<<num<<" ";
  }cout<<endl;

  return 0;
}