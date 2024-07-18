#include<iostream>
#include<vector>
using namespace std;

vector<int> spiral_matrix(vector<vector<int>> matrix){
  vector<int> result;
  if(matrix.empty() || matrix[0].empty()) return result;

  int m = matrix.size();
  int n = matrix[0].size();

  int left = 0, right = n-1, top = 0, bottom = m-1;

  while(left <=right && top <= bottom){
    for(int i=left; i<=right; i++){
      result.push_back(matrix[top][i]);
    }
    top++;

    for(int i=top; i<=bottom; i++){
      result.push_back(matrix[i][right]);
    }
    right--;

    if(left <= right){
      for(int i=right; i>=left; i--){
        result.push_back(matrix[bottom][i]);
      }
      bottom--;
    }

    if(top <= bottom){
      for(int i=bottom; i>=top; i--){
        result.push_back(matrix[i][left]);
      }
      left++;
    }
  }
  
  return result;
}

int main() {
  vector<vector<int>> matrix = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
  };

  vector<int> result = spiral_matrix(matrix);

  for(int i=0; i<result.size(); i++){
    cout<<result[i]<<" ";
  } cout<<endl;  

  return 0;
}