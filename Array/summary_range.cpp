#include<iostream>
#include <string>
#include<vector>
using namespace std;

vector<string> summaryRanges(vector<int> &range){
  vector<string> result;

  if(range.size() == 0){
    return result;
  }

  int start = range[0];

  // traverse the range vector
  for(int i = 1; i < range.size(); i++){

    // if the current element is not consecutive to the previous element
    if(range[i] != range[i-1] + 1){

      // if the range has only one element
      if(range[i-1] == start){
        result.push_back(to_string(start));
      }else{
        result.push_back(to_string(start) + "->" + to_string(range[i-1]));
      }
      start = range[i];
    }
  }

  // if the last element is consecutive to the previous element
  if(range[range.size()-1] == start){
    result.push_back(to_string(start));
  }else{
    result.push_back(to_string(start) + "->" + to_string(range[range.size()-1]));
  }

  return result;
}

int main() {
  vector<int> range = {0,1,2,4,5,7};
  vector<string> result = summaryRanges(range);

  for(int i = 0; i < result.size(); i++){
    cout << result[i] << " ";
  }
  
  return 0;
}