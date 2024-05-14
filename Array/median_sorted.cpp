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
    } else {
      res.push_back(vec2[j]);
      j++;
    }
  }

  while(i<n1){
    res.push_back(vec1[i]);
    i++;
  }

  while(j<n2){
    res.push_back(vec2[j]);
    j++;
  }

  return res;
}

double median_array(vector<int> &vec1, vector<int> &vec2){
  vector<int> merged_array = merge_array(vec1, vec2);
  int n = merged_array.size();

  int mid1 = (n-1)/2;
  int mid2 = n/2;

  return (merged_array[mid1] + merged_array[mid2]) / 2.0;
}

int main() {
  vector<int> vec1 = {10, 20, 30, 40};
  vector<int> vec2 = {15, 25, 35, 45};

  cout<<"Original array 1: ";
  for(auto num: vec1){
    cout<<num<<" ";
  } cout<<endl;

  cout<<"Original array 2: ";
  for(auto num: vec2){
    cout<<num<<" ";
  } cout<<endl;

  vector<int> merged_arr = merge_array(vec1, vec2);
  cout<<"Merge array: ";
  for(auto num: merged_arr){
    cout<<num<<" ";
  } cout<<endl;

  double median = median_array(vec1, vec2);
  cout<<"Median of the two array is: "<<median<<endl;

  return 0;
}