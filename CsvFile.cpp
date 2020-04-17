#include "CsvFile.h"

CsvFile::CsvFile(const std::string filePath, const std::string mode) : IFile::IFile(filePath, mode) {}

CsvFile::~CsvFile()
{
	file.close();
}

void CsvFile::WriteLine(Point point)
{
	file << point.x << "," << point.y << "," << point.z << "\n";
}

std::vector<std::string> CsvFile::Split(std::string str, char delim)
{
	std::vector<std::string> result;
	std::stringstream ss(str);
	std::string item;
	while (getline(ss, item, delim))
	{
		result.push_back(item);
	}
	return result;
}
//123, 6, -1

IFile::Error CsvFile::Write(const std::vector<Point>& v)
{
	Error retVal = Error(ACCESS_DENIED);

	if (openMode & std::fstream::out)
	{
		int i = 0;
		while (i < v.size())
		{
			WriteLine(v[i]);
			i++;
		}

		retVal = Error(SUCCESS);
	}
	return retVal;
}

IFile::Error CsvFile::Read(std::vector<Point>& v)
{
	Error retVal = Error(ACCESS_DENIED);

	if (openMode & std::fstream::in)
	{
		v.clear();
		file.seekg(0, std::fstream::beg);

		std::vector<std::string> str_vec;
		std::string str;

		while (getline(file, str))
		{
			str_vec = Split(str, ',');
			Point point;
			point.x = std::stod(str_vec[0]);
			point.y = std::stod(str_vec[1]);
			point.z = std::stod(str_vec[2]);


			v.push_back(point);
		}
		retVal = Error(SUCCESS);
	}
	return retVal;
}

IFile::Error CsvFile::Read(Point & p, const int idx)
{
	Error retVal = Error(ACCESS_DENIED);

	std::vector<std::string> str_vec;
    std::string str;

    int i = 0;

	while(getline(file, str))
    {
        if(i == idx)
        {
            str_vec = Split(str, ',');
            p.x = std::stod(str_vec[0]);
            p.y = std::stod(str_vec[1]);
            p.z = std::stod(str_vec[2]);
            retVal = Error(SUCCESS);
            break;
        }
        i++;
    }
    if(i != idx)
        retVal = Error(OUT_OF_BOUNDS);

	return retVal;
}
