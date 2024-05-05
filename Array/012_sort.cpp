#include<iostream>
#include<vector>
using namespace std;

void sort012(vector<int> &vec, int n){
  int l = 0;
  int r = n-1;

  for(int i=0; i<n && i<=r;){
    if(vec[i] == 0){
      swap(vec[i], vec[l]);
      l++;
      i++;
    } else if(vec[i] == 2){
      swap(vec[i], vec[r]);
      r--;
    } else {
      i++;
    }
  }
}

int main() {
  vector<int> vec = {2, 1, 0, 0, 1, 2, 2, 1};

  cout<<"Original array: ";
  for(auto i: vec){
    cout<<i<<" ";
  }cout<<endl;

  int n = vec.size();

  cout<<"Sorted array: ";
  sort012(vec, n);

  for(auto i: vec){
    cout<<i<<" ";
  }cout<<endl;

  return 0;
}