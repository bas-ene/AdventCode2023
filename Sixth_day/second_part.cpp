#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <regex>
#include <iostream>

std::vector<long long> get_numbers_in_string(std::string& str) {
	std::regex regexPattern("\\d+");

	// Step 4: Create a std::sregex_iterator
	std::sregex_iterator iter(str.begin(), str.end(), regexPattern);
	std::sregex_iterator end;

	// Step 5: Iterate over the matches
	std::vector<long long> numbers;
	for (; iter != end; ++iter) {
		try {
			numbers.push_back(std::stoll(iter->str()));
		}
		catch (const std::exception& e) {
			std::cout << "Error: Could not convert '" << iter->str() << "' to an integer.\n";
		}
	}
	return numbers;
}
void replaceAll(std::string& str, const std::string& from, const std::string& to) {
	if (from.empty())
		return;
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
	}
}

int main() {
	// se preferisci leggere e scrivere da file
	// ti basta decommentare le seguenti due righe:

	std::ifstream fin = std::ifstream("input.txt");
	std::ofstream fout = std::ofstream("output.txt");
	std::string first_line;
	std::string second_line;
	long long solution = 1;
	std::getline(fin, first_line);
	std::getline(fin, second_line);
	replaceAll(first_line, " ", "");
	replaceAll(second_line, " ", "");
	std::vector<long long> time_numbers = get_numbers_in_string(first_line);
	std::vector<long long> dist_numbers = get_numbers_in_string(second_line);

	for (long long i = 0; i < time_numbers.size(); i++)
	{
		long long time = time_numbers[i];
		long long dist_r = dist_numbers[i];
		for (long long j = 1; j < time; j++) {
			long long dist = j * (time - j);
			if (dist > dist_r) {
				solution *= (time - j * 2) + 1;
				break;
			}
		}
	}


	fout << solution;
	return 0;
}
