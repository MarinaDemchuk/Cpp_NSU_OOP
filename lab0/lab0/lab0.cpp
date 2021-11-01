#include "reader.h"
#include "sortWords.h"
#include "finding.h"
#include "nameConst.h"
int main(int argc, char* argv[])
{
	if (argc < Module4::MAX_ARGC) {
		std::cout << "error!" << std::endl;
		return Module4::END_PROFGRAM;
	}
	Module1::File x(argv[Module4::START_FILE]);
	if (x.open_file() == Module4::FILE_FAILED) {
		std::cout << "invailed file name" << std::endl;
		return Module4::END_PROFGRAM;
	}
	x.count_words();
	Module2::Sort m(x.Getmap());
	m.create();
	Module3::OutWords y(argv[Module4::END_FILE]);
	if (y.open_out() == Module4::FILE_FAILED) {
		std::cout << "output file did not open" <<std::endl;
		return Module4::END_PROFGRAM;
	}
	y.write_to_file(m.Getvector(), x.Getcount());
	return Module4::END_PROFGRAM;
}