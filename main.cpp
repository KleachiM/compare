#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/*
int GetDifferenceLine(ifstream& file1, ifstream& file2)
{
	string lineOfFile1, lineOfFile2;
	unsigned int lineNum = 0;
	bool comparing = true;

	//TODO без этих if?
	if (!getline(file1, lineOfFile1))
	{
		comparing = false; // file1 is empty
		lineNum = 1;
	}
	if (!getline(file2, lineOfFile2))
	{
		comparing = false; // file2 is empty
		lineNum = 1;
	}

	while (comparing)
	{
		lineNum++;
		if (lineOfFile1 != lineOfFile2)
		{
			return lineNum; // files are different in lineNum
		}
		else
		{
			if (!getline(file1, lineOfFile1))
			{
				comparing = false; // end of file 1
			}
			if (!getline(file2, lineOfFile2))
			{
				comparing = false; // end of file 2
			}
		}
	}
	//TODO тоже лишнее
	if (lineOfFile1 == lineOfFile2)
	{
		return 0;
	}
	else
	{
		return lineNum;
	}
}
*/

int GetDifferenceLine(ifstream& file1, ifstream& file2)
{
	string lineOfFile1, lineOfFile2;
	unsigned int lineNum = 0;

	while (true)
	{
		++lineNum;
		if (lineOfFile1 != lineOfFile2)	return lineNum; // files are different in lineNum
		if (!file1.eof())
		{
			getline(file1, lineOfFile1);
			if (!file2.eof()) getline(file2, lineOfFile2);
			else return lineNum; // not eof file1, eof file2
		}
		else
		{
			if (!file2.eof()) return lineNum; // eof file1, not eof file2
			return 0; // eof file1, eof file2, no diff
		}
	}
}


enum class ErrorCode
{
	SUCCESS,
	FILE_OPENING_ERROR,
	NOT_VALID_ARGS_COUNT
};

int CompareFiles(char *argv[], ErrorCode& errorCode)
{
	errorCode = ErrorCode::SUCCESS;
	ifstream file1(argv[1]);
	if (!file1.is_open())
	{
		errorCode = ErrorCode::FILE_OPENING_ERROR;
		return 1;
	}

	ifstream file2(argv[2]);
	if (!file2.is_open())
	{
		errorCode = ErrorCode::FILE_OPENING_ERROR;
		return 2;
	}

	return GetDifferenceLine(file1, file2);
}

void PrintResult(const int& filesComparingResult, const ErrorCode& errorCode, char *argv[])
{
	if (errorCode == ErrorCode::SUCCESS)
	{
		if (filesComparingResult == 0)
		{
			cout << "Files are equal\n";
			return;
		}
		cout << "Files are different. Line number is " << filesComparingResult << "\n";
		return;
	}
	if (errorCode == ErrorCode::FILE_OPENING_ERROR)
	{
		cout << "Unable to open " << argv[filesComparingResult] << "\n";
	}
}

ErrorCode IsValidArgsCount(const int& argsCount)
{
	return (argsCount == 3) ? ErrorCode::SUCCESS : ErrorCode::NOT_VALID_ARGS_COUNT;
}

int main(int argc, char* argv[])
{
	ErrorCode errorCode = IsValidArgsCount(argc);

	if (errorCode == ErrorCode::NOT_VALID_ARGS_COUNT)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: compare.exe <file1> <file2>\n";
		return 1;
	}

	int comparingResult = CompareFiles(argv, errorCode);
	PrintResult(comparingResult, errorCode, argv);

	if ((errorCode == ErrorCode::FILE_OPENING_ERROR) || (comparingResult > 0)) return 1;
	return 0;
}
