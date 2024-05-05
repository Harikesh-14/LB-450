#include<iostream>
#include<vector>
using namespace std;

void sort_negative(vector<int> &vec, int n){
  int l = 0;
  int r = n-1;

  while(l <= r) {
    if(vec[l] > 0){
      if(vec[r] < 0){
        swap(vec[l], vec[r]);
        l++;
        r--;
      } else {
        r--;
      }
    } else {
      l++;
    }
  }
}

int main() {
  vector<int> vec = {-23, 4, 56, -12, -11, 34, -2};

  cout<<"Original array: ";
  for(auto i: vec){
    cout<<i<<" ";
  }cout<<endl;

  int n = vec.size();

  cout<<"Sorted array: ";
  sort_negative(vec, n);

  for(auto i: vec){
    cout<<i<<" ";
  }cout<<endl;

  return 0;
}