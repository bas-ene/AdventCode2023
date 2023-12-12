#include <fstream>
#include <map>
#include <string>
#include <utility>
#include <vector>

int main(int argc, char *argv[]) {
  std::vector<bool> directions = std::vector<bool>();
  std::map<std::string, std::pair<std::string, std::string>> graph =
      std::map<std::string, std::pair<std::string, std::string>>();

  std::ifstream fin = std::ifstream("input.txt");
  std::ofstream fout = std::ofstream("output.txt");

  std::string input_line;
  std::getline(fin, input_line);
  // get the left right sequence
  for (int i = 0; i < input_line.size(); i++) {
    directions.push_back(input_line[i] == 'L');
  }
  std::string current_pos = "";
  while (std::getline(fin, input_line)) {
    if (input_line == "")
      continue;
    // find the comma, then read 3 chars left, three chars right
    std::string left = input_line.substr(input_line.find(',') - 3, 3);
    std::string right = input_line.substr(input_line.find(',' + 1, 3));
    std::string node = input_line.substr(0, 3);

    if (current_pos == "")
      current_pos = node;

    graph.insert({node, {left, right}});
  }
  long long passi = 0;
  while (current_pos != "ZZZ") {
    current_pos = directions[passi % directions.size()]
                      ? graph.at(current_pos).first
                      : graph.at(current_pos).second;
    passi++;
  }
  fout << passi;
  return 0;
}
