#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int answer = 0;
  ifstream file ("data");
  string input;

  // rock   A X 1
  // paper  B Y 2
  // scisor C Z 3
  // lose X
  // draw Y
  // win  Z
  if (file.is_open()) {
    while (getline(file, input)) {
      //cout << input[0] << " - " << input[2] << endl;
      switch (input[0]) {
        case 'A':
          switch (input[2]) {
            case 'X':
              answer += 3;
              break;
            case 'Y':
              answer += 4;
              break;
            case 'Z':
              answer += 8;
              break;
          }
          break;
        case 'B':
          switch (input[2]) {
            case 'X':
              answer += 1;
              break;
            case 'Y':
              answer += 5;
              break;
            case 'Z':
              answer += 9;
              break;
          }
          break;
        case 'C':
          switch (input[2]) {
            case 'X':
              answer += 2;
              break;
            case 'Y':
              answer += 6;
              break;
            case 'Z':
              answer += 7;
              break;
          }
          break;
      }
    }
  }


  cout << endl << endl << answer;
  return 0;
}
