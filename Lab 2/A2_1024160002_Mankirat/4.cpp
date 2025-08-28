#include<iostream>
#include<string>
using namespace std;

void exchange(char& a, char& b);
string concat(string s1, string s2);
string reverse(string s);
string vovel(string s);
string sort(string s);
string caps(string s);

int main(){
  string str = "Hello";
  string concatinate = concat(str, " World");
  cout << concatinate << endl;
  string reversed  = reverse(str);
  cout << reversed << endl;
  string novovel  = vovel(str);
  cout << novovel << endl;
  string sorted = sort(str);
  cout << sorted << endl;
  string allcaps = caps(str);
  cout << allcaps << endl;
}

void exchange(char& a, char& b){
  char temp;
  temp = b;
  b = a;
  a = temp;
}

string concat(string s1, string s2){
  return s1+s2;
}

string reverse(string s){
  string rev = s;
  int n = s.length();
  for(int i  = 0 ; i < n ; i++){
    rev[i] = s[n-i-1];
  }
  return rev;
}

string vovel(string s){
  int n = s.length();
  string novov;
  int r = 0;
  for(int i = 0 ; i < n ; i++){
    if(tolower(s[i]) != 'a' && tolower(s[i]) != 'e' && tolower(s[i]) != 'i' && tolower(s[i]) != 'o' && tolower(s[i]) != 'u'){
      novov.push_back(s[i]);
    }
  }
    return novov;
}

string sort(string s){
  string sorted = s;
  
  bool flag;
  int n = s.length();
  sorted = s;
  for(int i = 1 ; i < n; i++){
    flag = 1;
    for(int j=0 ; j < n - i ; j++){
      if(tolower(sorted[j]) > tolower(sorted[j+1])){
        flag = 0;
        exchange(sorted[j], sorted[j+1]);
      }
    }
     if (flag == 1){
        break;
     }
  }
  return sorted;
}

string caps(string s){
  string caps = s;
  for(int i = 0 ; i < s.length() ; i++){
    if(caps[i] >= 'a' && caps[i] <= 'z'){
      caps[i] -= 32;
    }
  }
  return caps;
}