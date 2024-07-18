#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

bool valid_sudoku(vector<vector<char>> board){
  vector<unordered_set<char>> row(9);
  vector<unordered_set<char>> col(9);
  vector<unordered_set<char>> box(9);

  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      char num = board[i][j];
      if(num == '.') continue;

      if(row[i].find(num) != row[i].end()) return false;
      row[i].insert(num);

      if(col[j].find(num) != col[j].end()) return false;
      col[j].insert(num);

      int boxIndex = (i/3)*3 + j/3;
      if(box[boxIndex].find(num) != box[boxIndex].end()) return false;
      box[boxIndex].insert(num);
    }
  }

  return true;
}

int main() {
  vector<vector<char>> board1 = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
  };

  vector<vector<char>> board2 = {
    {'8','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
  };

  if(valid_sudoku(board1)) cout<<"Valid Sudoku"<<endl;
  else cout<<"Invalid Sudoku"<<endl;
  
  if(valid_sudoku(board2)) cout<<"Valid Sudoku"<<endl;
  else cout<<"Invalid Sudoku"<<endl;

  return 0;
}