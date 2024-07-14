#include<iostream>
#include<string>
using namespace std;

string binary_addition(string a, string b){
  string result = "";
  int carry = 0;
  int i = a.size() - 1;
  int j = b.size() - 1;

  while(i >= 0 || j >= 0){
    int sum = carry;
    if(i >= 0){
      sum += a[i] - '0';
      i--;
    }
    if(j >= 0){
      sum += b[j] - '0';
      j--;
    }

    result = to_string(sum % 2) + result;
    carry = sum / 2;
  }

  if(carry){
    result = to_string(carry) + result;
  }

  return result;
}

int main() {
  string a = "1010";
  string b = "1011";

  cout << binary_addition(a, b) << endl;

  return 0;
}