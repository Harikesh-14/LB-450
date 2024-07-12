#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<sstream>
using namespace std;

vector<string> split(const string &s){
  vector<string> result;
  istringstream ss(s);
  string token;

  while(ss >> token){
    result.push_back(token);
  }
  return result;
}

bool wordPattern(string pattern, string s){
  vector<string> words = split(s);
  if(pattern.size() != words.size()){
    return false;
  }

  unordered_map<char, string> charToString;
  unordered_map<string, char> stringToChar;

  for(int i = 0; i < pattern.size(); i++){
    char c = pattern[i];
    string word = words[i];

    if(charToString.find(c) != charToString.end() && charToString[c] != word){
      return false;
    }

    if(stringToChar.find(word) != stringToChar.end() && stringToChar[word] != c){
      return false;
    }

    charToString[c] = word;
    stringToChar[word] = c;
  }

  return true;
}

int main() {
  string pattern = "abba";
  string s = "dog cat cat dog";

  cout << wordPattern(pattern, s) << endl;

  return 0;
}