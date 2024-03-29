#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int answer = 0;
  ifstream file ("data");
  string input;

  // rock   A X
  // paper  B Y
  // scisor C Z
  if (file.is_open()) {
    while (getline(file, input)) {
      //cout << input[0] << " - " << input[2] << endl;
      switch (input[2]) {
        case 'X':
          answer += 1;
          switch (input[0]) {
            case 'A':
              answer += 3;
              break;
            case 'C':
              answer += 6;
              break;
          }
          break;
        case 'Y':
          answer += 2;
          switch (input[0]) {
            case 'B':
              answer += 3;
              break;
            case 'A':
              answer += 6;
              break;
          }
          break;
        case 'Z':
          answer += 3;
          switch (input[0]) {
            case 'C':
              answer += 3;
              break;
            case 'B':
              answer += 6;
              break;
          }
          break;
      }
    }
  }


  cout << endl << endl << answer;
  return 0;
}
