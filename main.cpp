#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Cat.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Name of CSV file not provided" << std::endl;
    return 0;
  }

  std::ifstream catsFile(argv[1]);

  if ( !catsFile.is_open() ) {
    std::cout << "File was not opened" << std::endl;
    return 0;
  }

  std::vector<Cat> cats;
  std::vector<std::string> catRow;

  std::string fileLine;

  std::cout << "File was opened" << std::endl;

  bool firstLineRead = false;
  
  while ( catsFile ) {
    catRow.clear();

    std::getline(catsFile, fileLine);

    if (!firstLineRead) {
      firstLineRead = true;
      continue;
    }

    std::string linePart;
    std::stringstream lineStream(fileLine);

    while(std::getline(lineStream, linePart, ',')) {
      catRow.push_back(linePart);
    }

    if (catRow.size() >= 3) {
      cats.push_back(Cat(catRow.at(0), catRow.at(1), std::stoi(catRow.at(2))));
    } else {
      std::cout << "Read line is invalid" << std::endl;
    }
  }

  std::ofstream outputFile("cats-output.txt");

  for (std::vector<Cat>::iterator catsIter {cats.end()}; catsIter != cats.begin(); ++catsIter) {
    outputFile << *catsIter << std::endl;
  }

  outputFile.close();
}
