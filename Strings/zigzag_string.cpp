#include<iostream>
#include<vector>
using namespace std;

string zigzag_conversion(string s, int numRows){
  if (numRows == 0){
    return s;
  }

  vector<string> rows(numRows);

  int current_rows = 0;
  bool going_down = false;

  for(char c: s){
    rows[current_rows] += c;

    if(current_rows == 0 || current_rows == numRows - 1){
      going_down = !going_down;
    }

    if(going_down){
      current_rows += 1;
    } else{
      current_rows -= 1;
    }
  }

  string result;
  for(string row: rows){
    result += row;
  }

  return result;
}

int main() {
  string s = "PAYPALISHIRING";

  cout << zigzag_conversion(s, 4) << endl;

  return 0;
}