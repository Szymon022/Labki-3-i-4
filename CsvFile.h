#pragma once
#include "IFile.h"
#include <sstream>
#include "FileError.h"
#include <iostream>

class CsvFile : public IFile
{
private:
	void WriteLine(Point);
	std::vector<std::string> Split(std::string str, char delim);

public:
	CsvFile(const std::string, const std::string);
	~CsvFile();

	Error Write(const std::vector<Point>&);
	Error Read(std::vector<Point>&);
	Error Read(Point&, const int);
};
