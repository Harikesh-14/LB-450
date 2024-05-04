#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int max_num(vector<int> vec){
  int len = vec.size();
  int res = INT_MIN;

  for(auto i: vec){
    if(i > res){
      res = i;
    }
  }

  return res;
}

int min_num(vector<int> vec) {
  int len = vec.size();
  int res = INT_MAX;

  for(auto i: vec){
    if(i < res){
      res = i;
    }
  }

  return res;
}

int main(){
  vector<int> vec = {3, 5, 7, 9, 1, 4};

  cout<<"Original array: ";
  for(auto i: vec){
    cout<<i<<" ";
  }cout<<endl;

  cout<<"Greatest element: "<<max_num(vec)<<endl;
  cout<<"Smallest element: "<<min_num(vec)<<endl;

  return 0;
}