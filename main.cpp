#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3)
    {
        cout << "Invalid arguments count\n"
             << "Usage: copyfile.exe <input file> <output file>\n";
        return 1;
    }

	if (argv[1] == argv[2])
	{
		cout << "Files are equal\n";
		return 0;
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

	string lineOfFile1, lineOfFile2;
	unsigned int lineNum = 0;
	bool comparing = true;

	if (!getline(file1, lineOfFile1))
	{
		comparing = false; // file1 is empty
	}
	if (!getline(file2, lineOfFile2))
	{
		comparing = false; // file2 is empty
	}

	while (comparing)
	{
		lineNum++;
		if (lineOfFile1 != lineOfFile2)
		{
			cout << "Files are different. Line number is " << lineNum << "\n";
			return 1;
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


	if (lineOfFile1 == lineOfFile2)
	{
		cout << "Files are equal\n";
	}
	else
	{
		cout << "Files are different. Line number is " << lineNum << "\n";
		return 1;
	}

    return 0;
}
