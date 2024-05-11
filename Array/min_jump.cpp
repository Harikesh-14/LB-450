#include<iostream>
#include<vector>
using namespace std;

int min_jump_count(vector<int> &vec){
  int size = vec.size();

  if(size <= 0){
    return 0;
  }

  if(vec[0] == 0){
    return -1;
  }

  int step = vec[0];
  int maxReach = vec[0];
  int jump = 1;

  for(int i=0; i<size; i++){
    if(i >= size-1){
      return jump;
    }

    maxReach = max(maxReach, vec[i] + 1);
    step--;

    if(step == 0){
      jump++;

      if(i >= maxReach){
        return -1;
      }

      step = maxReach - i;
    }
  }

  return -1;
}

int main() {
  vector<int> vec = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};

  cout<<"Original array: ";
  for(auto i: vec){
    cout<<i<<" ";
  }cout<<endl;

  cout<<"Minimum jump: "<<min_jump_count(vec)<<endl;

  return 0;
}