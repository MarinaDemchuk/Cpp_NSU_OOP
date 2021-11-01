#include "sortWords.h"
namespace Module2 {
	Sort::Sort(std::map<std::wstring, int> value) {
		myMap = value;
	}

	bool Sort::comp::operator()(std::pair<std::wstring, int> a, std::pair<std::wstring, int> b)
	{
		return a.second > b.second;
	}
	void Sort::create() {
		for (auto it = myMap.begin(); it != myMap.end(); ++it) {
			frequency.push_back(make_pair(it->first, it->second));
		}
		Sort::comp compForSort;
		sort(frequency.begin(), frequency.end(), compForSort);
	}
	std::vector <std::pair<std::wstring, int>> Sort::Getvector() {
		return frequency;
	}
}