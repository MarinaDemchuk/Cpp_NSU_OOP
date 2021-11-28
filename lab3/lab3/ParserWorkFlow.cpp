#include "ParserWorkFlow.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Exception.h"
#include "WorkFlowFaild.h"
#include "Ñonstants.h"
namespace WorkFlow {

	WorkFlowExecutor::WorkFlowExecutor(std::string file_name) {
		input.open(file_name);
		if (!input.is_open()) {
			throw p;
		}
	}
	void WorkFlowExecutor::execute()
	{
		int f = Constants::NULL_WORD;
		while (!input.eof())
		{
			getline(input, str);
			if (str == "desc") {continue;}
			else
				if (str == "csed")
				{
					f = 1;
					continue;
				}
			if (f == Constants::FLAG) {
				int j = Constants::NULL_WORD;
				std::string word = "";
				//command_sequence.push_back("");
				for (int i = 0; i <= str.length(); ++i) {
					if (str[i] >= Constants::START_NUMBER && str[i] <= Constants::END_NUMBER) {
						word += str[i];
						j = Constants::FLAG;
						//command_sequence[j] += str[i];
					}
					if (str[i] == ' ' && j == Constants::FLAG) {
						command_sequence.push_back(word);
						word = "";
						j = Constants::NULL_WORD;
					}
				}
				command_sequence.push_back(word);
			}
			else {
				if (f != 1) {
					std::string word = "";
					std::string word1 = "";
					int j = Constants::NULL_WORD;
					std::vector<std::string> my_vector;
					//my_vector.push_back("");
					int flag = Constants::NULL_WORD;
					for (int i = 0; i <= str.length(); ++i) {
						if (str[i] == '=') {
							flag = Constants::FLAG;
							continue;
						}
						if (flag == Constants::NULL_WORD) {
							if (str[i] >= Constants::START_NUMBER && str[i] <= Constants::END_NUMBER) {

								word += str[i];
							}
						}
						if (flag == Constants::FLAG) {
							if (str[i] != ' ')
							{
								//my_vector[j] += str[i];
								if ((str[i] >= Constants::START_LITTLE_ENGLISH && str[i] <= Constants::END_LITTLE_ENGLISH) || (str[i] == Constants::DOT_IN_WORD))
								word1 += str[i];
								j = Constants::FLAG;
							}
							else {
								if (j == Constants::FLAG) {
									my_vector.push_back(word1);
									word1 = "";
									j = Constants::NULL_WORD;
								}
							}

						}
					}
					my_vector.push_back(word1);
					manual.push_back(make_pair(word, my_vector));
				}
			}
		}
	}
	std::list <std::pair<std::string, std::vector<std::string>>>  WorkFlowExecutor::get_list()
	{
		return manual;
	}
	std::vector<std::string> WorkFlowExecutor::get_command()
	{
		return command_sequence;
	}
}