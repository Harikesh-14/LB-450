#include<iostream>
#include<vector>
using namespace std;

bool binary_search(vector<vector<int>> matrix, int target){
  int row = matrix.size();
  int col = matrix[0].size();

  int start = 0, end = row*col-1;
  int mid = start + (end-start)/2;

  while(start <= end){
    int element = matrix[mid/col][mid%col];

    if (element == target){
      return true;
    } else if (element < target){
      start = mid + 1;
    } else {
      end = mid - 1;
    }

    mid = start + (end-start)/2;
  }

  return false;

}

int main() {
  vector<vector<int>> matrix = {
    {1, 3, 5, 7},
    {10, 11, 16, 20},
    {23, 30, 34, 60}
  };

  int target = 3;

  if(binary_search(matrix, target)){
    cout<<"Found"<<endl;
  } else {
    cout<<"Not Found"<<endl;
  }

  return 0;
}