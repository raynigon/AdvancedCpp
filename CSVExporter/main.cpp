

#include <string>
#include "CSVExporter.hpp"
#include <set>

class MyTable
{
public:
	size_t getWidth() const { return 10; };
	size_t getHeight() const { return 3; };
	const std::string& operator() (size_t i, size_t j) const { return "Hallo " + std::to_string(i) + " Welt"; };
};

class NoTable
{
public:
	size_t getWidth() const { return 10; };
	size_t getHeight() const { return 3; };
	const std::set<int>& operator() (size_t i, size_t j) const { return std::set<int>(); };
};

int main()
{
	CSVExporter csv_exporter;
	csv_exporter.open("mydat.csv");
	std::string text = "HALLO WELT";

	//csv_exporter.exportTable(MyTable());

	csv_exporter.exportTable(NoTable());
}
