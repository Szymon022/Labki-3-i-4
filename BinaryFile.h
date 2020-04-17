#pragma once
#include "IFile.h"
#include <fstream>
#include <vector>
#include "Point.h"
#include "FileError.h"

class BinaryFile : public IFile
{

public:
	BinaryFile(const std::string, const std::string);
	~BinaryFile();

	Error Write(const std::vector<Point>&);
	Error Read(std::vector<Point>&);
	Error Read(Point&, const int);
};
