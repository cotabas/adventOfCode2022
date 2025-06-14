#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

const int MAX_ROWS = 400;
const int MAX_NAME_CHARS = 25;
const int MAX_ORIGIN_CHARS = 10;

char name[MAX_ROWS][MAX_NAME_CHARS + 1] = {0};
float mpg[MAX_ROWS];
int cylinders[MAX_ROWS];
float displacement[MAX_ROWS];
float horsepower[MAX_ROWS];
float weight[MAX_ROWS];
float acceleration[MAX_ROWS];
float model_year[MAX_ROWS];
char origin[MAX_ROWS][MAX_ORIGIN_CHARS + 1] = {0};

bool load_data(int &count);

void print_header_row();
void print_all(int count);
void print_automobile_record(int index);

int main() {
  int count = 0;

  // Fail Fast - removes anything that could go wrong before proceeding
  if (!load_data(count)) {
    cout << "Failed to load data :(" << endl;
    return 1;
  }
  cout << "COUNT: " << count << endl;
  print_header_row();
  print_all(count);

  return 0;
}

bool load_data(int &count) {
  ifstream fin("Automobile.csv");
  if (!fin) {
    return false;
  }

  // ignore header line
  fin.ignore(numeric_limits<streamsize>::max(), '\n');

  // Use this, not getline from string library
  // https://en.cppreference.com/w/cpp/io/basic_istream/getline
  char temp[255] = {0};
  while (fin.getline(temp, 255, ',') && !fin.eof()) {
    // https://en.cppreference.com/w/
    //cout << temp << endl;
    strncpy(name[count], temp, MAX_NAME_CHARS);
    //cout << name[count] << endl;
    fin >> mpg[count];
    fin.get();
    fin >> cylinders[count];
    fin.get();
    fin >> displacement[count];
    fin.get();
    fin >> horsepower[count];
    fin.get();
    fin >> weight[count];
    fin.get();
    fin >> acceleration[count];
    fin.get();
    fin >> model_year[count];
    fin.get();
    fin.getline(origin[count], MAX_ORIGIN_CHARS, '\n');
    count++;
  }
  cout << temp << endl;

  fin.close();
  return true;
}

void print_header_row() {
  cout << setw(MAX_NAME_CHARS + 2) << left << "NAME";
  cout << setw(7) << right << "MPG";
  cout << setw(5) << right << "CYL";
  cout << setw(5) << right << "DSP";
  cout << setw(5) << right << "HP";
  cout << setw(7) << right << "WT";
  cout << setw(7) << right << "ACCEL";
  cout << setw(6) << right << "YEAR";
  cout << setw(MAX_ORIGIN_CHARS+2) << right << "ORIGIN" << endl;
}

void print_automobile_record(int n) {
  // name,mpg,cylinders,displacement,horsepower,weight,acceleration,model_year,origin
  cout << setw(MAX_NAME_CHARS + 2) << left << name[n];
  cout << setw(7) << right << mpg[n];
  cout << setw(5) << right << cylinders[n];
  cout << setw(5) << right << displacement[n];
  cout << setw(5) << right << horsepower[n];
  cout << setw(7) << right << weight[n];
  cout << setw(7) << right << acceleration[n];
  cout << setw(6) << right << model_year[n];
  cout << setw(MAX_ORIGIN_CHARS +2) << right << origin[n] << endl;
}

void print_all(int count) {
  for (int i = 0; i < count; i++) {
    print_automobile_record(i);
  }
}
