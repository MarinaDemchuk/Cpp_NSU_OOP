#include "WorkFlowExit.h"
#include "Ñonstants.h"
namespace Exit {
	WorkFlowExit::WorkFlowExit(std::vector<std::string>& vector, std::list<std::pair<std::string, std::vector<std::string>>>& list1)
		: my_vector{ vector },
		text{ list1 }
	{
	}
	void WorkFlowExit::DoWorkFlow() {
		Blocks::DumpCreature* dump_creature = new Blocks::DumpCreature();
		Blocks::GrepCreature* grep_creature = new Blocks::GrepCreature();
		Blocks::ReaderCreature* reader_creature = new Blocks::ReaderCreature();
		Blocks::ReplaceCreature* replace_creature = new Blocks::ReplaceCreature();
		Blocks::SortCreature* sort_creature = new Blocks::SortCreature();
		Blocks::WriteCreature* write_creature = new Blocks::WriteCreature();
		std::vector <Blocks::Blocks*> my_blocks;
		for (auto it = 0; it != my_vector.size(); ++it) {
			for (auto i = text.begin(); i != text.end(); ++i) {
				try {
					if (my_vector[it] == i->first) {
						if (i->second[Constants::BLOCK_NAME] == "readfile") {
							my_blocks.push_back(reader_creature->createBlock());
							if (it != Constants::NULL_WORD) {
								throw faild;
							}
							my_blocks[my_blocks.size() - Constants::ALIGNMENT]->execute(my_list, i->second);
							//reader_creature->createBlock()->execute(my_list, i->second);
							break;
						}
						if (i->second[Constants::BLOCK_NAME] == "writefile") {
							my_blocks.push_back(write_creature->createBlock());
							if (it != my_vector.size() - Constants::ALIGNMENT) {
								throw faild;
							}
							my_blocks[my_blocks.size() - Constants::ALIGNMENT]->execute(my_list, i->second);
							//write_creature->createBlock()->execute(my_list, i->second);
							break;
						}
						if (i->second[Constants::BLOCK_NAME] == "grep") {
							my_blocks.push_back(grep_creature->createBlock());
							if (it == Constants::NULL_WORD || it == my_vector.size() - Constants::ALIGNMENT) {
								throw faild;
							}
							my_blocks[my_blocks.size() - Constants::ALIGNMENT]->execute(my_list, i->second);
							//grep_creature->createBlock()->execute(my_list, i->second);
							break;
						}
						if (i->second[Constants::BLOCK_NAME] == "sort") {
							my_blocks.push_back(sort_creature->createBlock());
							if (it == Constants::NULL_WORD || it == my_vector.size() - Constants::ALIGNMENT) {
								throw faild;
							}
							my_blocks[my_blocks.size() - Constants::ALIGNMENT]->execute(my_list, i->second);
							//sort_creature->createBlock()->execute(my_list, i->second);
							break;
						}
						if (i->second[Constants::BLOCK_NAME] == "replace") {
							my_blocks.push_back(replace_creature->createBlock());
							if (it == 0 || it == my_vector.size() - Constants::ALIGNMENT) {
								throw faild;
							}
							my_blocks[my_blocks.size() - Constants::ALIGNMENT]->execute(my_list, i->second);
							//replace_creature->createBlock()->execute(my_list, i->second);
							break;
						}
						if (i->second[Constants::BLOCK_NAME] == "dump") {
							my_blocks.push_back(dump_creature->createBlock());
							if (it == Constants::NULL_WORD || it == my_vector.size() - Constants::ALIGNMENT) {
								throw faild;
							}
							my_blocks[my_blocks.size() - Constants::ALIGNMENT]->execute(my_list, i->second);
							//dump_creature->createBlock()->execute(my_list, i->second);
							break;
						}

					}
				}
				catch (Exception::SubsequenceFaild& my_error) {
					std::cout << my_error.what() << std::endl;
					exit(Constants::END_PROFGRAM);
				}
				catch (Exception::ReadException& my_error) {
					std::cout << my_error.what() << std::endl;
					exit(Constants::END_PROFGRAM);
				}
				catch (Exception::WriteExceptionFaild& my_error) {
					std::cout << my_error.what() << std::endl;
					exit(Constants::END_PROFGRAM);
				}
			}
		}
		delete dump_creature;
		delete grep_creature;
		delete reader_creature;
		delete replace_creature;
		delete sort_creature;
		delete write_creature;
		for (auto i = 0; i != my_blocks.size(); ++i) {
			delete my_blocks[i];
		}
	}
}