#include<iostream>
#include<string>
using namespace std;

string reverse_string(string &word){
  string new_word;
  int size = word.size();

  for(int i=size-1; i>=0; i--){
    new_word = new_word + word[i];
  }

  return new_word;
}

int main() {
  string word = "Harikesh";
  
  cout<<"Original word: "<<word<<endl;

  string rev_word = reverse_string(word);
  cout<<"Reversed string: "<<rev_word<<endl;

  return 0;
}