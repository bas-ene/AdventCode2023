#include <fstream>
#include <string>
#include <vector>
#define MAX_RED = 12 
#define MAX_GREEN = 13 
#define MAX_BLUE = 14 

std::vector<std::string> splitBy(const std::string* str, const char* delimeter, int del_length) {
	int off = 0;
	int next = 0;
	auto  fields = std::vector<std::string>();
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
	//foreach set
	while (!fin.eof())
	{
		std::getline(fin, line);
		//parse input (8 is the length of "Game x: ")
		line.erase(0, 8);
		auto sets = splitBy(&line, "; ", 2);
		//for each set
		int a = 0;
		//get the number of red, blue and green cubes
		//if one of them is over its max than the game is not possible
	}
	fout << solution;
}
