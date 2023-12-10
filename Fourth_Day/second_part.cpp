#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <regex>

std::vector<std::string> splitBy(const std::string& str, const std::string& regex_str) {
	// Step 3: Create a std::regex object
	std::regex regexPattern(regex_str);

	// Step 4: Create two std::sregex_token_iterator
	std::sregex_token_iterator iter(str.begin(), str.end(), regexPattern, -1);
	std::sregex_token_iterator end;

	// Step 5: Construct a std::vector<std::string> from the two iterators
	std::vector<std::string> result(iter, end);
	return result;
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

std::vector<int> parseInts(std::string& str, const std::string& regex_str) {
	std::vector<std::string> unparsed = splitBy(str, regex_str);
	std::vector<int> parsed = std::vector<int>();
	std::transform(unparsed.begin(), unparsed.end(), std::back_inserter(parsed), [](const std::string& str) {
		return std::stoi(str); });
	return parsed;
}

int main() {
	// se preferisci leggere e scrivere da file
	// ti basta decommentare le seguenti due righe:

	std::ifstream fin = std::ifstream("input.txt");
	std::ofstream fout = std::ofstream("output.txt");
	std::string line;
	long long solution = 0;
	std::vector<int> copies(218, 0); int playing = 0;
	while (std::getline(fin, line))
	{
		line = std::regex_replace(line, std::regex("  "), " ");
		std::string cards = splitBy(line, ": ")[1];
		std::string winningCards = splitBy(cards, " \\| ")[0];
		std::string playerCards = splitBy(cards, " \\| ")[1];
		std::vector<int> wCards = parseInts(winningCards, " ");
		std::vector<int> pCards = parseInts(playerCards, " ");

		int count = std::count_if(wCards.begin(), wCards.end(), [&](int n) {
			return std::find(pCards.begin(), pCards.end(), n) != pCards.end();
			});
		for (int i = playing + 1; i <= playing + count && i < 218; i++)
		{
			copies[i] += copies[playing] + 1;
		}
		playing++;

	}

	fout << std::accumulate(copies.begin(), copies.end(), 218);

	return 0;
}
