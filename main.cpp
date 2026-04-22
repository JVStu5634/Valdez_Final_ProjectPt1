// Joseph Valdez
// 4/21/2026
// This program reads and displays the daily quiz scores of each student. The program then displays 
// the highest and lowest scores overall.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Class {
string name;
int score;
};

void displayData(Class students[], int size);
void findMinMax(Class students[], int size, int& maxIdx, int& minIdx);

int main() {

const int SIZE = 10;
Class students[SIZE];
ifstream inFile;

inFile.open("Input.txt");

if (!inFile) {
  cout << "Error: Cannot open input file "Input.txt" << endl;
  return 1;
  }

for (int i = 0; i < SIZE; i++) {
  if (!inFile >> students[i].name >> students[i].score)) {
  break;
  }
}

inFile.close();






