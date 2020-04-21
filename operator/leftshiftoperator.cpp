#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
  string in, sub;
  cin >> in >> sub;
  unordered_map<char, int> char_count;
  queue<char> char_order;
  unordered_set<char> chars;
  for (int i = 0; i < sub.size(); ++i) chars.insert(sub[i]);
  int min_l = in.size();
  int start_pos = 0;
  for (int i = 0; i < in.size(); ++i) {
    const char ch = in[i];
    char_order.push(ch);
    auto it = char_count.find(ch);
    if (it != char_count.end()) {
      it->second++;
    } else if (chars.count(ch) > 0) {
      char_count[ch] = 1;
    }
    if (char_count.size() == chars.size()) {
      while (char_count.size() == chars.size()) {
        char top = char_order.front();
        char_order.pop();
        auto it = char_count.find(top);
        if (it != char_count.end()) {
          it->second--;
          if (it->second == 0) {
            char_count.erase(it);
          }
        }
      }
      if (min_l > char_order.size() + 1) {
        min_l = char_order.size() + 1;
        start_pos = i - min_l + 1;
      }
    }
  }
  cout << in.substr(start_pos, min_l) << endl;
  return 0;
}
