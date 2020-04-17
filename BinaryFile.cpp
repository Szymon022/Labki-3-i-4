#include "BinaryFile.h"

BinaryFile::BinaryFile(const std::string filePath, const std::string mode) : IFile(filePath, mode) {}

BinaryFile::~BinaryFile()
{
	file.close();
}

IFile::Error BinaryFile::Write(const std::vector<Point>& v)
{
	Error retVal = Error(ACCESS_DENIED);

	if (openMode & std::fstream::out)
	{
		file.write((const char *)v.data(), v.size() * sizeof(Point));
		retVal = Error(SUCCESS);
	}

	return retVal;
}

IFile::Error BinaryFile::Read(std::vector<Point>& v)
{
	Error retVal = Error(ACCESS_DENIED);

	if (openMode & std::fstream::in)
	{
		v.clear();
		v.resize(length / sizeof(Point));
		file.seekg(0, std::fstream::beg);
		file.read((char *)v.data(), length);
		retVal = Error(SUCCESS);
	}

	return retVal;
}

IFile::Error BinaryFile::Read(Point & p, const int idx)
{
	Error retVal = Error(ACCESS_DENIED);

	if (idx * sizeof(Point) > length)
	{
		retVal = Error(OUT_OF_BOUNDS);
	}
	else if (openMode & std::fstream::in)
	{
		file.seekg(idx * sizeof(Point));
		file.read((char*)(&p), sizeof(Point));
		retVal = Error(SUCCESS);
	}

	return retVal;
}
