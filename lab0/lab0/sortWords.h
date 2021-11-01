#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
namespace Module2 {
	class Sort {
	private:
		std::vector <std::pair<std::wstring, int>> frequency;
		std::map <std::wstring, int> myMap;
		class comp {
		public:
			bool operator()(std::pair<std::wstring, int> a, std::pair<std::wstring, int> b);
		};
	public:
		Sort(std::map <std::wstring, int>);
		void create();
		std::vector<std::pair<std::wstring, int>> Getvector();
	};
}
