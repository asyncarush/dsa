#include <iostream>
using namespace std;

string reverseIt(string s, int start, int end) {
  string result = "";
  for(int i = end; i>=start; i--) {
    result += s[i];
  }
  return result;
}

string reverseTheString(string s) {
  int start = 0, end=0;
  string result = "";

  for(int i=0; i<s.length(); i++) {
    if(s[i] == ' ' || i == s.length()-1) {
        result += reverseIt(s, start, i);
        if(end != s.length()-1) result += " ";
        start = i+1;
    }
  }
  return result;
}

int main() {

  cout << reverseTheString("hello world");
  return 0;
}