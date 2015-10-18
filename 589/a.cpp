#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

inline string to_lower_case(string &addr) {
  string new_addr;
  for (int i = 0, n = addr.length(); i < n; ++i) {
    if (addr[i] >= 'A' && addr[i] <= 'Z') {
      new_addr += addr[i] + ('a' - 'A');
    } else {
      new_addr += addr[i];
    }
  }
  return new_addr;
}

inline string get_server(string &addr) {
  string server;
  for (int i = 0, n = addr.length(); i < n; ++i) {
    if (addr[i] == '@') {
      server = addr.substr(i + 1);
      break;
    }
  }
  return server;
}

inline string normalize(string &addr) {
  string clear = to_lower_case(addr);
  if (get_server(clear) == "bmail.com") {
    string new_clear;
    for (int i = 0, n = clear.length(); i < n; ++i) {
      if (clear[i] == '@' || clear[i] == '+') {
        break;
      }
      if (clear[i] != '.') {
        new_clear += clear[i];
      }
    }
    return new_clear + "@bmail.com";
  }
  return clear;
}

int main() {
  int n;
  string addr;
  vector<string> addrs;
  map<string, bool> off;
  map<string, vector<string>/**/> groups;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> addr;
    addrs.push_back(addr);
    string clear = normalize(addr);
    off[clear] = false;
    groups[clear].push_back(addr);
  }
  cout << groups.size() << endl;
  for (int i = 0; i < n; ++i) {
    addr = normalize(addrs[i]);
    if ( ! off[addr]) {
      off[addr] = true;
      cout << groups[addr].size();
      for (int j = 0, m = groups[addr].size(); j < m; ++j) {
        cout << ' ' << groups[addr][j];
      }
      cout << endl;
    }
  }
  return 0;
}
