#include <iostream>
#include <fstream>
#include "FileUtils.h"

std::string FileUtils::read_file(std::string filepath)
{
	// Create file streaming object called "ifile"
	std::fstream ifile(filepath, std::fstream::in | std::fstream::ate);

	// Open the file
	if (!ifile.is_open())
	{
		std::cout << std::endl << "File could not be opened: " << filepath << std::endl;
		return 0;
	}

	else
	{
		// Gets size of ifile
		ifile.seekg(0, ifile.end);
		int ifile_size = ifile.tellg();
		ifile.seekg(0, ifile.beg);
		// Creates a char pointer called contents containing an array of chars the size of ifile_size
		char *contents = new char[ifile_size];
		// Sets memory value of contents to zero, then to ifile_size to compensate for artifacts
		memset(contents, 0, ifile_size);
		// Puts the contents of ifile into array char array pointer contents, the size of length
		ifile.read(contents, ifile_size);
		// Closes ifile
		ifile.close();
		// Creates a string called result containing contents
		std::string result(contents);
		// Outputs contents to console to confirm
		// std::cout.write(contents, ifile_size);
		// std::cout << std::endl;
		// Deletes contents array from memory
		delete[] contents;
		// Returns contents as a string called result
		return result;
	}
}