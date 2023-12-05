#include <fstream>
#include <string>
#include <vector>
const int MAX_RED = 12;
const int MAX_GREEN = 13;
const int MAX_BLUE = 14;

std::vector<std::string> splitBy(const std::string *str, const char *delimeter,
                                 int del_length) {
  int off = 0;
  int next = 0;
  auto fields = std::vector<std::string>();
  int a = 0;
  while ((next = str->find(*delimeter, off)) != std::string::npos) {
    std::string s = (str->substr(off, next - off));
    if (s.find(*delimeter) != std::string::npos)
      s.erase(s.find(*delimeter), del_length);
    fields.push_back(s);
    off = next + del_length;
  }
  fields.push_back(str->substr(off));
  return fields;
}
int main() {
  long long solution = 0;

  std::ifstream fin = std::ifstream("input.txt");
  std::ofstream fout = std::ofstream("output.txt");
  std::string line;
  int game_id = 1;
  // foreach set
  while (!fin.eof()) {
    std::getline(fin, line);
    // parse input (8 is the length of "Game x: ")
    line.erase(0, 8);
    auto sets = splitBy(&line, "; ", 2);
    bool game_valid = true;
    // for each set
    for (std::string set : sets) {
      auto cards = splitBy(&set, ", ", 2);
      for (std::string card : cards) {
        auto play = splitBy(&card, " ", 1);
        switch (play[1][0]) {
        case 'r':
          game_valid = (MAX_RED >= std::stoi(play[0]));
          break;
        case 'g':
          game_valid = MAX_GREEN >= std::stoi(play[0]);
          break;
        case 'b':
          game_valid = MAX_BLUE >= std::stoi(play[0]);
          break;
        }
        if (!game_valid)
          break;
      }
      if (!game_valid)
        break;
    }
    if (game_valid)
      solution += game_id;
    game_id++;
    // get the number of red, blue and green cubes
    // if one of them is over its max than the game is not possible
  }
  fout << solution;
}
