#include<iostream>
#include<vector>
using namespace std;

int inversion_count(vector<int> &vec){
  int n = vec.size();
  int inversion_count = 0;

  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(vec[i] > vec[j]){
        inversion_count++;
      }
    }
  }

  return inversion_count;
}

int main() {
  vector<int> vec = {8, 4, 2, 1};

  cout<<"Original array: ";
  for(auto num: vec){
    cout<<num<<" ";
  }cout<<endl;

  int res = inversion_count(vec);
  cout<<"Inversion count: "<<res<<endl;

  return 0;
}