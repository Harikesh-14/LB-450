#include<iostream>
#include<vector>
using namespace std;

vector<int> merge_array(vector<int> &vec1, vector<int> &vec2){
  vector<int> res;
  int n1 = vec1.size();
  int n2 = vec2.size();

  int i=0, j=0;

  while(i < n1 && j < n2){
    if(vec1[i] < vec2[j]){
      res.push_back(vec1[i]);
      i++;
    } else{
      res.push_back(vec2[j]);
      j++;
    }
  }

  while(i < n1){
    res.push_back(vec1[i]);
    i++;
  }

  while(j < n2){
    res.push_back(vec2[j]);
    j++;
  }

  return res;
}

int main() {
  vector<int> vec1 = {1, 3, 5, 7, 9};
  vector<int> vec2 = {2, 4, 6, 8};

  cout<<"Array 1: ";
  for(auto num: vec1){
    cout<<num<<" ";
  }cout<<endl;

  cout<<"Array 2: ";
  for(auto num: vec2){
    cout<<num<<" ";
  }cout<<endl;

  vector<int> res = merge_array(vec1, vec2);

  cout<<"Merged sorted array: ";
  for(auto num: res){
    cout<<num<<" ";
  } cout<<endl;

  return 0;
}