#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
  ifstream input ("data");
  int answer = 0,
      work;
  string inputData;

  if (input.is_open()) {
    while (getline(input, inputData)) {
      if (!inputData.size()) {
        answer = answer > work ? answer : work;
        work = 0;
      } else {
        work += stoi(inputData);
      }
    }
  }

  cout << endl << endl << answer;
  return 0;
}
