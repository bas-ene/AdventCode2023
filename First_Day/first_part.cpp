#include <fstream>
#include <iostream>
#include <string>
int main() {
  long long sum = 0;

  std::ifstream fin = std::ifstream("input.txt");
  std::ofstream fout = std::ofstream("output.txt");
  std::string line;
  while (!fin.eof()) {
    char fc = 'a';
    char lc = 'a';
    std::getline(fin, line);
    for (int i = 0; i < line.length(); i++) {
      if (std::isdigit(line[i])) {
        if (fc == 'a')
          fc = line[i];
        lc = line[i];
      }
    }
    std::cout << fc << lc << '\n';
    sum += std::stoi(std::string({fc, lc}));
  }
  fout << sum;
}
