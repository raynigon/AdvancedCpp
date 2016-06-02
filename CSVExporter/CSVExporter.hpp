#pragma once
#include <string>
#include <fstream>


class CSVExporter
{
private:
	std::string fileName;
public:
	CSVExporter() = default;
	~CSVExporter() = default;
	bool open(const std::string& filename);
	template<typename Table>
	bool exportTable(const Table& table);
};

template <typename Table>
bool CSVExporter::exportTable(const Table& table)
{
	std::ofstream os(fileName);
	size_t width = table.getWidth();
	size_t height = table.getHeight();
	if (!os.is_open())
		return false;
	for (size_t i = 0; i < height; ++i)
	{
		for (size_t j = 0; j < width;++j)
		{
			os << table(i, j);
			if(j + 1 == width) 
				continue;
			os << ';';
		}
		os << std::endl;
	}
	return true;
}
