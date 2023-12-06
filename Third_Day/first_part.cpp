#include <cctype>
#include <iostream>
#include <string>
#include <vector>

void mark_valid(bool (&map)[140][140], int i, int j) {
  for (int k = i - 1; k <= i + 1; k++) {
    for (int l = j - 1; l <= j + 1; l++) {
      if (k >= 0 && k < 140 && j >= 0 && j < 140)
        map[k][l] = true;
    }
  }
}

int get_num(char map[][140], int i, int j) {
  std::string num_chars = std::string();
  // left foot slide
  for (int k = j - 1; k >= 0; k--) {
    if (std::isdigit(map[i][k])) {
      num_chars.insert(num_chars.begin(), map[i][k]);
    } else {
      break;
    }
  }
  for (int k = j; k < 140; k++) {
    if (std::isdigit(map[i][k])) {
      num_chars.push_back(map[i][k]);
    } else {
      break;
    }
    // right foot slide
  }
  return std::stoi(num_chars);
}
int main() {
  // se preferisci leggere e scrivere da file
  // ti basta decommentare le seguenti due righe:

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  long long solution = 0;
  char chars[140][140];
  bool map[140][140];
  for (int i = 0; i < 140; i++) {
    for (int j = 0; j < 140; j++) {
      char c;
      std::cin >> c;
      chars[i][j] = c;
      if (!std::isdigit(c) && c != '.') {
        mark_valid(map, i, j);
      }
    }
  }
  // print values of map
  // for (int i = 0; i < 140; i++) {
  //   for (int j = 0; j < 140; j++) {
  //     std::cout << " " << map[i][j];
  //   }
  //   std::cout << '\n';
  // }
  for (int i = 0; i < 140; i++) {
    for (int j = 0; j < 140; j++) {
      if (map[i][j] && std::isdigit(chars[i][j])) {
        int num = get_num(chars, i, j);
        while (++j < 140 && std::isdigit(chars[i][j])) {
        }
        solution += num;
      }
    }
  }
  std::cout << solution;
  return 0;
}
