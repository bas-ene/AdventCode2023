#include <fstream>
#include <string>
#include <vector>
#include <iostream>
const int MAX_RED = 12;
const int MAX_GREEN = 13;
const int MAX_BLUE = 14;

std::string ReplaceString(std::string subject, const std::string& search,
	const std::string& replace) {
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != std::string::npos) {
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return subject;
}
std::vector<std::string> splitBy(const std::string* str, const char* delimeter,
	int del_length) {
	int off = 0;
	int next = str->find(*delimeter, off);
	std::vector<std::string> fields = std::vector<std::string>();
	while (next != std::string::npos) {
		std::string s = (str->substr(off, next - off));
		if (s.find(*delimeter) != std::string::npos)
			s.erase(s.find(*delimeter), del_length);
		fields.push_back(s);
		off = next + del_length;
		next = str->find(*delimeter, off);
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
	while (std::getline(fin, line)) {
		// parse input (8 is the length of "Game x: ")
		line = ReplaceString(line, "  ", " ");
		line.erase(0, 8);
		auto sets = splitBy(&line, "; ", 2);
		int rm = 0, gm = 0, bm = 0;
		// for each set
		for (std::string set : sets) {
			std::vector<std::string> cards = splitBy(&set, ", ", 2);
			for (std::string card : cards) {
				std::vector<std::string> play = splitBy(&card, " ", 1);
				std::remove(play.begin(), play.end(), "");
				std::remove(play.begin(), play.end(), ":");
				int nCub = std::stoi(play[0]);
				switch (play[1][0]) {
				case 'r':
					rm = std::max(rm, nCub);
					break;
				case 'g':
					gm = std::max(gm, nCub);
					break;
				case 'b':
					bm = std::max(bm, nCub);
					break;
				}
			}
		}
		solution += (rm * bm * gm);
		// get the number of red, blue and green cubes
		// if one of them is over its max than the game is not possible
	}
	fout << solution;
}