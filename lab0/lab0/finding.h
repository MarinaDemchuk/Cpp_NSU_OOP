#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "nameConst.h"
namespace Module3 {
	class OutWords {
	private:
		std::wofstream out;
		std::string name;
	public:
		int open_out();
		OutWords(std::string name);
		~OutWords();
		void write_to_file(std::vector<std::pair<std::wstring, int>> array, int count);
	};
}
