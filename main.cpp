#include <fstream>
#include <iostream>
#include <string>

using namespace std;

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


enum class ErrorCode
{
	SUCCESS,
	FILE_OPENING_ERROR,
	/* ... */
};

ErrorCode CompareFiles(const std::string& fileName1, const std::string& fileName2, int& differenceLine)
{

}

int CompareFiles(const std::string& fileName1, const std::string& fileName2, ErrorCode& errorCode)
{
	errorCode = ErrorCode::SUCCESS;

}

int CompareFiles(const std::string& fileName1, const std::string& fileName2)
{
	throw std::runtime_error("Failed to open " + fileName1);
}

// TODO упростить main
int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: copyfile.exe <input file> <output file>\n";
		return 1;
	}

	ifstream file1(argv[1]);
	if (!file1.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	ifstream file2(argv[2]);
	if (!file2.is_open())
	{
		cout << "Failed to open " << argv[2] << " for reading\n";
		return 1;
	}

	if (argv[1] == argv[2])
	{
		cout << "Files are equal\n";
		return 0;
	}

	int comparingResult = GetDifferenceLine(file1, file2);

	if (comparingResult == 0)
	{
		cout << "Files are equal\n";
	}
	else
	{
		cout << "Files are different. Line number is " << comparingResult << "\n";
		return 1;
	}
	return 0;
}
