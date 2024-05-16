#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int> &vec, vector<int> &temp, int left, int mid, int right){
  int inversion_count = 0;

  int i=left;
  int j=mid;
  int k=left;

  while((i<=mid-1) && (j<=right)){
    if(vec[i] <= vec[j]){
      temp[k++] = vec[i++];
    } else {
      temp[k++] = vec[j++];
      inversion_count += (mid - i);
    }
  }

  while(i<=mid-1){
    temp[k++] = vec[i++];
  }

  while(j<=right){
    temp[k++] = vec[j++];
  }

  for(i=left; i<=right; i++){
    vec[i] = temp[i];
  }

  return inversion_count;
}

int mergeSort(vector<int> &vec, vector<int> &temp, int left, int right){
  int inversion_count = 0;

  if(left < right){
    int mid = (left + right)/2;

    inversion_count += mergeSort(vec, temp, left, mid);
    inversion_count += mergeSort(vec, temp, mid+1, right);

    inversion_count += merge(vec, temp, left, mid+1, right);
  }

  return inversion_count;
}

int inversion_count(vector<int> &vec){
  int n = vec.size();
  vector<int> temp(n);

  return mergeSort(vec, temp, 0, n-1);
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