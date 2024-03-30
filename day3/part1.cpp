#include <cctype>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  int answer = 0;
  ifstream input (argv[1]);
  string data;

  if (input.is_open()) {
next_line:
    while (getline(input, data)) {
      for (int i = 0; i < (data.length() / 2); i++) {
        for (int j = (data.length() / 2); j < data.length(); j++) {
          if (data[i] == data[j]) {
            if (isupper(data[i])) {
              answer += data[i] - 38;
            } else {
              answer += data[i] - 96;
            }
            goto next_line;
            //i = data.length();
            //break;
          }
        }
      }
    }
  }


  cout << answer;
  return 0;
}
