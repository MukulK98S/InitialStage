#include<iostream>
#include<fstream>
#include<algorithm>
#include<windows.h>
#include<conio.h>

typedef unsigned long long ULL;

const ULL COUNTLIMIT = 729;/*531441*/

//using namespace std;// ::cout;
//using namespace std::cin;

int main() {
	ULL i, n;
	int remainder;
	std::string tmp;
	std::string password = "",
				sevenZDir = "C:\\Program Files\\7-Zip\\7z.exe",
				commandAdd = " a archive.zip \"C:\\Users\\mukul\\desktop\\NetworkInfo.txt\" -pA@@",
				commandExtract = " e archive.zip -o\"C:\\Users\\mukul\\desktop\\text\" -p";

	SHELLEXECUTEINFOA ShExecInfo = { 0 };
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFOA);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = sevenZDir.c_str();
	ShExecInfo.lpParameters = (commandExtract + password).c_str();
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE;
	ShExecInfo.hInstApp = NULL;

	std::ifstream inputFile("C:\\Users\\mukul\\desktop\\text\\NetworkInfo.txt",std::ifstream::binary);
	inputFile.seekg(0, inputFile.end);
	if(inputFile.good() && inputFile.tellg() != 0)
		std::cout<<"file exists\n";
	else
		std::cout << "file does not exist or has a 0 file size\n";
	inputFile.close();

	//system(" cd \"C:\\Users\\mukul\\desktop\" ");

	//system(" \"C:\\Program Files\\7-Zip\\7z\" a archive.zip \"C:\\Users\\mukul\\desktop\\NetworkInfo.txt\" ");
	//"C:\Program Files\7-Zip\7z" a archive.zip "C:\Users\mukul\desktop\NetworkInfo.txt"
	//system(" \"C:\\Program Files\\7-Zip\\7z.exe\" ");

	ShellExecuteA(NULL, NULL, sevenZDir.c_str(), commandAdd.c_str(), NULL, SW_SHOWDEFAULT);
	for (i = 0; i <= COUNTLIMIT; i++) {
		n = i;
		//n = 28;
		while (n)
		{
			remainder = n % 27;
			tmp = (char)(remainder + 64);
			n -= remainder;
			n /= 27;
			password.insert(0, tmp);
		}

		ShExecInfo.lpFile = sevenZDir.c_str();
		ShExecInfo.lpParameters = (commandExtract + password).c_str();

		ShellExecuteExA(&ShExecInfo);
		WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
		CloseHandle(ShExecInfo.hProcess);
		//ShellExecuteA(NULL, NULL, sevenZDir.c_str(), (commandExtract + password).c_str(), NULL, SW_HIDE);

		//Sleep(10);

		inputFile.open("C:\\Users\\mukul\\desktop\\text\\NetworkInfo.txt",std::ifstream::binary);
		inputFile.seekg(0,inputFile.end);
		std::cout << password << " - " << inputFile.tellg() << std::endl;
		if (inputFile.good() && inputFile.tellg() != 0) {

			std::cout<< inputFile.tellg() << "\nfile extracted successfully\npassword: " << password.c_str();
			break;
		}
		inputFile.close();
		password.clear();
		//break;
	}
	inputFile.close();
	if (i == COUNTLIMIT)
		std::cout << "Could not locate the password...";
	return EXIT_SUCCESS;
}