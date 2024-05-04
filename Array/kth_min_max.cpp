#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int kth_max(vector<int> &vec, int k){
  sort(vec.begin(), vec.end());
  int len = vec.size();
  int counter = 1;
  int res;

  for(int i=len-1; i>=0; i--){
    if(counter == k){
      res = vec[i];
    }
    counter++;
  }

  // instead of the for loop, we can simply write:
  // return vec[vec.size() - k];

  return res;
}

int kth_min(vector<int> &vec, int k){
  sort(vec.begin(), vec.end());
  int len = vec.size();
  int counter = 1;
  int res;

  for(int i=0; i<len; i++){
    if(counter == k){
      res = vec[i];
    }
    counter++;
  }

  // instead of the for loop, we can simply write:
  // return vec[vec.size() - k];

  return res;
}

int main() {
  vector<int> vec = {3, 5, 7, 9, 1, 4};

  cout<<"Original array: ";
  for(auto i: vec){
    cout<<i<<" ";
  }cout<<endl;

  int k;
  cout<<"Enter the value of k: ";
  cin>>k;

  if(k > vec.size()){
    cout<<"Out of bound"<<endl;
  } else {
    int max_res = kth_max(vec, k);
    cout<<max_res<<endl;

    int min_res = kth_min(vec, k);
    cout<<min_res<<endl;
  }

  return 0;
}