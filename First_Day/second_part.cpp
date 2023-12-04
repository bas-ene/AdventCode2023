#include <fstream>
#include <string>
int main() {
	long long sum = 0;
	std::string[] numbers = {"zero","one","two","three","four","five","six","seven","eight","nine"}
	std::ifstream fin = std::ifstream("input.txt");
	std::ofstream fout = std::ofstream("output.txt");
	std::string line;
	while (!fin.eof())
	{
		short fc = 100;
		short lc = 100;
		std::getline(fin, line);
		for (int i = 0; i < line.length(); i++)
		{
			if (std::isdigit(line[i])) {
				if (fc == 100)
					fc = line[i];
				lc = line[i];
			}
       else{
			//parse word if possible
			for (int i = 0; i < 10; i++) {
				if(numbers[i] == line.substr(i,numbers[i].length())){
						fc
					}
			}
			}
		}
		sum += std::stoi(std::string({ fc,lc }));

	}
	fout << sum;
}
