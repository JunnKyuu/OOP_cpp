#include <algorithm>
#include <iostream>
#include <map>
#include <string>


using namespace std;


int main() {
  int count = 1; // 단어개수 1로 초기화
  string str; // 문자열
  map<string,int> words_map; // 단어, 단어개수 저장할 map

  while(cin >> str) {
    for(int i = 0; i<str.size(); i++) {
      str[i] = tolower(str[i]);
    } // 모두 소문자로 변경

    auto p = words_map.insert(make_pair(str,count));

    if(p.second == false) {
      ++p.first->second;
      // 단어가 중복되면 개수 증가
    } else {
      // empty
    } 
  }

  for(map<string,int>::const_iterator it = words_map.cbegin(); it != words_map.cend(); it++) {
    cout << it->first << " " << it->second << endl;
  }

  // for(map<string,int>::const_iterator rit = words_map.rbegin(); rit != words_map.rend(); rit++) {
  //   cout << rit->first << " " << rit->second << endl;
  // }
}