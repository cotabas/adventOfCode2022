#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  ifstream input ("data");
  int answer = 0,
      work;
  string inputData;
  vector<int> set;

  if (input.is_open()) {
    while (getline(input, inputData)) {
      if (!inputData.size()) {
        set.push_back(work);
        work = 0;
      } else {
        work += stoi(inputData);
      }
    }
  }

  sort(set.begin(), set.end());
  
  for (int i = 1; i <= 3; i++) {
    cout << i << " - " << set[set.size() - i] << endl;
    answer += set[set.size() - i];
  }

  cout << endl << endl << answer;
  return 0;
}
