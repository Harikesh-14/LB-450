#include<iostream>
#include<vector>
using namespace std;

int lengthOfLongestSubstring(string s){
  vector<int> charIndex (256, -1);
  int max_common = 0, left = 0;

  // Iterate through the string
  for(int right = 0; right < s.length(); right++){
    // If the character is already present in the substring
    if(charIndex[s[right]] >= left){
      left = charIndex[s[right]] + 1; // Move the left pointer to the next character
    }

    // Update the index of the character
    charIndex[s[right]] = right;
    max_common = max(max_common, right - left + 1);
  }

  return max_common;
}

int main() {
  string s = "abcabcbb";
  cout << lengthOfLongestSubstring(s) << endl;

  return 0;
}