#include<iostream>
#include<vector>
using namespace std;

vector<int> merge_array (vector<int> &vec1, vector<int> &vec2){
  vector<int> res;
  int n1 = vec1.size();
  int n2 = vec2.size();

  int i=0, j=0;

  while(i < n1 && j < n2){
    if(vec1[i] < vec2[j]){
      res.push_back(vec1[i++]);
    } else {
      res.push_back(vec2[j++]);
    }
  }

  while(i < n1){
    res.push_back(vec1[i++]);
  }

  while(j < n2){
    res.push_back(vec2[j++]);
  }

  return res;
}

double median_array (vector<int> &vec1, vector<int> &vec2){
  vector<int> merged_array = merge_array(vec1, vec2);

  int n = merged_array.size();

  if(n % 2 == 0){
    int mid1 = (n-1)/2;
    int mid2 = n/2;
    double res = (merged_array[mid1] + merged_array[mid2])/2.0;
    return res;
  } else {
    int mid = n/2;
    double res = merged_array[mid];
    return res;
  }
}

int main() {
  vector<int> vec1 = { 900 };
  vector<int> vec2 = { 5, 8, 10, 20 };

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