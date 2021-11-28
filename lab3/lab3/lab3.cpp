#include <iostream>
#include <fstream>
#include "ParserWorkFlow.h"
#include <list>
#include <vector>
#include "Exception.h"
#include "WorkFlowExit.h"
#include "WorkFlowFaild.h"
#include "Сonstants.h"
int main(int argc, char* argv[])
{
	if (argc != Constants::MAX_ARGC) {
		std::cout << "eror" << std::endl;
		return Constants::END_PROFGRAM;
	}
	try {
		WorkFlow::WorkFlowExecutor file("workflow.txt");
		file.execute();
		std::list <std::pair<std::string, std::vector<std::string>>> text = file.get_list();
		std::vector <std::string> my_vector = file.get_command();
		Exit::WorkFlowExit my_exit(my_vector, text);
		my_exit.DoWorkFlow();
	} 
	catch (Exception::WorkFlowFaild& my_error) {
		std::cout << my_error.what() << std::endl;
		return 1;
	}
	return 0;
}