#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool ransomNote(string ransomNote, string magazine){
  unordered_map<char, int > mp;

  for(char c: magazine){
    mp[c]++;
  }

  for(char c: ransomNote){
    if(mp.find(c) == mp.end() || mp[c] == 0){
      return false;
    }
  }

  return true;
}

int main() {
  string note = "aa";
  string magazine = "aab";

  cout << ransomNote(note, magazine) << endl;

  return 0;
}