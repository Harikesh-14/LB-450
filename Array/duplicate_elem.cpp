#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> duplicate_elem(vector<int> &vec){
  vector<int> res;
  stack<int> st;

  int size = vec.size();

  for(int i=0; i<size; i++){
    if((vec[i] == vec[i+1]) && (st.empty() || st.top() != vec[i])){
      st.push(vec[i]);
    }
  }

  int n = st.size();

  for(int i=0; i<n; i++){
    int num = st.top();
    res.push_back(num);
    st.pop();
  }

  return res;
}

int main() {
  vector<int> vec = {1, -3, 2, 1, 1, -3};

  cout<<"Original array: ";
  for(auto num: vec){
    cout<<num<<" ";
  }cout<<endl;

  sort(vec.begin(), vec.end());

  vector<int> res = duplicate_elem(vec);

  for(auto num: res){
    cout<<num<<" ";
  } cout<<endl;

  return 0;
}