#include "reader.h"

#include <codecvt>

namespace Module1 {

	File::File(std::string name) {

		const std::locale utf8_locale = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>());
		input.open(name);
		input.imbue(utf8_locale);

	}

	int File::open_file() {

		if (!input.is_open()) {

			return Module4::FILE_FAILED;

		}

	}

	void File::count_words() {

		word = L"";

		while (!input.eof()) {

			getline(input, str);

			for (int i = 0; i <= str.length(); ++i) {

				if ((str[i] >= Module4::START_LITTLE_ENGLISH && str[i] <= Module4::END_LITTLE_ENGLISH) || (str[i] >= Module4::START_NUMBER && str[i] <= Module4::END_NUMBER) ||
					(str[i] >= Module4::START_LITTLE_RUSSIAN && str[i] <= Module4::END_LITTLE_RUSSIAN) || (str[i] >= Module4::START_BIG_RUSSIAN && str[i] <= Module4::END_BIG_RUSSIAN) ||
					(str[i] >= Module4::START_BIG_ENGLISH && str[i] <= Module4::END_BIG_ENGLISH)) {
					word += str[i];

				}

				else {

					++count;

					if (word.length() > Module4::NULL_WORD) {

						++mapOfWords[word];

					}

					word = L"";

				}


			}

		}

	}

	std::map <std::wstring, int> File::Getmap() {
		return mapOfWords;

	}

	int File::Getcount() {

		return count;

	}

	File::~File() {

		input.close();

	}

}