#include "finding.h"
#include <codecvt>
namespace Module3 {
	OutWords::OutWords(std::string name) {
		const std::locale utf8_locale = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>());
		out.open(name);
		out.imbue(utf8_locale);
	}
	int OutWords::open_out() {
		if (!out.is_open()) {
			return Module4::FILE_FAILED;
		}
	}
	void OutWords::write_to_file(std::vector <std::pair<std::wstring, int>> array, int count) {
		for (auto i = array.begin(); i < array.end(); ++i) {
			out << i->first << ";" << i->second << ";" << (double)i->second / (double)count * Module4::MAX_PROCENT << std::endl;
		}
	}
	OutWords::~OutWords() {
		out.close();
	}
}