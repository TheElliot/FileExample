#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

void fileRead(string filename) {
  ifstream example_file;
  example_file.open (filename);
  cout << "\nContents of file " << filename << ":\n\n";
  if (example_file.is_open()) {
    string line;
    while ( getline (example_file,line) ) {
      cout << line << '\n';
    }
    example_file.close();
  } else {
    cout << "Unable to open INPUT file"; 
  }
}

void fileWrite(string filename) {
  ofstream example_file;
  example_file.open (filename);
  
  if (example_file.is_open()) {
    example_file << "This is a random number: ";
    example_file << (rand() % 100) << "\n";
    example_file << "This is another random number: ";
    example_file << (rand() % 100) << "\n";
    example_file.close();
  } else {
    cout << "Unable to open OUTPUT file"; 
  }
}

int main () {
  // seed random number generator
  srand (time(NULL));
  string example_text_file = "./example.txt";
  fileRead(example_text_file);
  fileWrite(example_text_file);
  fileRead(example_text_file);
  return 0;
}