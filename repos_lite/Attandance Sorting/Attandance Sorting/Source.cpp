#include<iostream>
#include<sstream>
#include<fstream>
#include<conio.h>
#include<direct.h>
#include<vector>
#include<string>
#include<algorithm>

typedef unsigned long long ULL;

int main() {
	int tmp = 0;
	std::fstream inputProcessingFile,outputFile;
	std::stringstream strBuff;
	std::string buf,dir;
	std::vector<int> rollnumbers;
	ULL num;
	char cDir[1024];

	pTmp = _getcwd(cDir, 1024);
	dir = cDir;
	inputProcessingFile.open(dir + "\\inputProcessing.txt", std::ios::in);
	outputFile.open(dir + "\\outputFile.txt", std::ios::out | std::ios::trunc);
	
	std::cout << "Present (1 - 50)\n";

	while(inputProcessingFile >> buf) {
		if (std::find_if(buf.begin(), buf.end(), [](char c) {return !(c >= '0' && c <= '9'); }) == buf.end())
		{
			strBuff = std::stringstream(buf);
			strBuff >> num;
			if (num > 52010000) {
				num -= 52010000;
				std::cout << num << "(" << buf << ")" << ", ";
			}
			rollnumbers.push_back(num);
			std::cout << buf << ", ";
		}
	}
	std::cout << std::endl;
	std::sort(rollnumbers.begin(), rollnumbers.end());
	for (auto i : rollnumbers)
		std::cout << i << ", ";
	rollnumbers.resize(std::distance(rollnumbers.begin(), std::unique(rollnumbers.begin(), rollnumbers.end())));
	for (auto i : rollnumbers) {
		outputFile << i << ", ";
	}
	outputFile.close();
	inputProcessingFile.close();
	tmp = _getch();
	return 0;
}
