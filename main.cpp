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
  cout << "Error: Cannot open. File not found." << endl;
  return 1;
  }

for (int i = 0; i < SIZE; i++) {
  if (!(inFile >> students[i].name >> students[i].score)) {
  break;
  }
}

inFile.close();

cout << "---- Todays Quiz Scores ----" << endl;

displayData(students, SIZE);

int highestIndex = 0;
int lowestIndex = 0;

findMinMax(students, SIZE, highestIndex, lowestIndex);

cout << "--- Class Stats ---" << endl;
cout << "Highest Score: " << students[highestIndex].score 
     << " (Student: " << students[highestIndex].name << " ) " << endl;
cout << "Lowest Score: " << students[lowestIndex].score
     << " (Student: " << students[lowestIndex].name << " ) " << endl;

return 0;

}

void displayData(Class students[], int size) {

  cout << left << setw(15) << "Name" << "Score" << endl;
    for (int i = 0; i < size; i++) {
      cout << left << setw(15) << students[i].name << students[i].score << endl;
    }
}
void findMinMax(Class students[], int size, int& maxIdx, int& minIdx) {

  maxIdx = 0;
  minIdx = 0;

for (int i = 1; i < size; i++) {
    if (students[i].score > students[maxIdx].score) {
        maxIdx = i;
    }
    if (students[i].score < students[minIdx].score) {
        minIdx = i;
    }
  }
}




