#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> vec_union(vector<int> &vec1, vector<int> &vec2){
  if(vec1.size() == 0 && vec2.size() == 0) {
    return {};
  }

  if(vec1.size() == 0){
    return vec2;
  }

  if (vec2.size() == 0){
    return vec1;
  }

  vector<int> res;
  set<int> temp;

  for(auto num: vec1){
    temp.insert(num);
  }

  for(auto num: vec2){
    temp.insert(num);
  }

  for(auto num: temp){
    res.push_back(num);
  }

  return res;
}

vector<int> vec_intersection(vector<int> &vec1, vector<int> &vec2){
  if(vec1.size() == 0 && vec2.size() == 0) {
    return {};
  }

  if(vec1.size() == 0){
    return vec2;
  }

  if (vec2.size() == 0){
    return vec1;
  }

  set<int> temp;
  vector<int> res;

  // inserting vector 1 in set
  for(auto num: vec1){
    temp.insert(num);
  }

  for(auto num: vec2){
    if(temp.find(num) != temp.end()){
      res.push_back(num);
    }
  }

  return res;
}

int main() {
  vector<int> vec1 = {3, 7, 9, 12, 15, 21, 23};
  vector<int> vec2 = {3, 7, 11, 15, 18, 21, 24, 29};

  cout<<"Array 1: ";
  for(auto i: vec1){
    cout<<i<<" ";
  }cout<<endl;

  cout<<"Array 2: ";
  for(auto i: vec2){
    cout<<i<<" ";
  }cout<<endl;

  cout<<"Union of two array: ";
  vector<int> union_res = vec_union(vec1, vec2); 
  for(auto i: union_res){
    cout<<i<<" ";
  }cout<<endl;

  cout<<"Intersection of two array: ";
  vector<int> intersection_res = vec_intersection(vec1, vec2); 
  for(auto i: intersection_res){
    cout<<i<<" ";
  }cout<<endl;

  return 0;
}