#include "Demo.hpp"
#include <vector>
#include <string>

template<typename T>
using ValueType = typename T::value_type;

bool contains(const Range& range, Equality_comparable<ValueType<Range>> value)
{
	for(auto tmp : range){
		if(tmp==value)
			return true;
	}
	return false;
}

void StartDemo_Range()
{
	std::vector<std::string> vec = {"ABC", "DEF", "GHI"};
	contains(vec, "ABC");	
	
}