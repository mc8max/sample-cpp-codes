#include <iostream>
#include <fstream>
#include <vector>
#include  <iomanip>

using namespace std;

#define BUFFER_LENGTH 8

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		cout << "Please provide an input file" << endl;
		return 0;
	}

	ifstream file;
	file.open(argv[1], ios::binary);
	if (file.is_open())
	{
		file.seekg(0, file.end);
		int length = file.tellg();
		file.seekg(0, file.beg);

		vector<char> buffer(BUFFER_LENGTH);
		while (length > 0)
		{
			int size = (length < BUFFER_LENGTH) ? length : BUFFER_LENGTH;
			file.read(&buffer[0], size);
			for (int i = 0; i < size; i++)
			{
				cout << "0x" << setfill('0') << setw(2) << right << hex << (buffer[i] & 0xFF) << " ";
			}
			cout << endl;
			length -= size;
		}
		file.close();
	}
	return 0;
}