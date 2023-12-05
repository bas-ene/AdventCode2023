#include <fstream>
#include <iostream>
#include <string>
int main() {
  long long sum = 0;
  std::string numbers[] = {"one", "two",   "three", "four", "five",
                           "six", "seven", "eight", "nine"};
  std::ifstream fin = std::ifstream("input.txt");
  std::ofstream fout = std::ofstream("output.txt");
  std::string line;
  while (!fin.eof()) {
    short fc = 100;
    short lc = 100;
    std::getline(fin, line);
    if (line == "")
      break;
    for (int i = 0; i < line.length(); i++) {
      if (std::isdigit(line[i])) {
        if (fc == 100)
          fc = line[i] - 0x30;
        lc = line[i] - 0x30;
      } else {
        // parse word if possible
        for (int j = 0; j < 9; j++) {
          if (numbers[j] == line.substr(i, numbers[j].length())) {
            if (fc == 100) {
              fc = j + 1;
              // std::cout << "message" << std::endl;
            }
            lc = j + 1;
            // std::cout << "ppkre" << j << std::endl;
            break;
          }
        }
      }
    }
    sum += fc * 10 + lc;
    std::cout << fc * 10 + lc << '\n';
  }
  fout << sum;
}
