#pragma once
#include <vector>
#include "Trit.h"
#include <unordered_map>
typedef unsigned int uint;
class TritSet {
private:
	std::vector <uint> my_vector;
	int false_count;
	int tru_count;
	int last_not_unknow_index;
	int last_trit_index;
public:
	explicit TritSet(uint size);
	uint size;
	class Proxy {
	private:
		TritSet *set;
		size_t index;
		Trit value;
	public:
		Proxy(TritSet *_set, size_t _index);
		Proxy& operator=(Trit new_value);
		operator Trit() const;
		Proxy& operator = (Proxy&& new_value) noexcept;
		Proxy& operator = (const Proxy& new_value);

	};
	void trit_count(Trit value, uint index);
	void shrink();
	uint compacity_trit();
	size_t cardinality(Trit value);
	Proxy operator[] (size_t i);
	void fix_size(TritSet& a, TritSet& b);
    TritSet operator& (TritSet set);
	TritSet operator| (TritSet set);
	TritSet operator~();
	struct TritHash {
		size_t operator()(Trit t) const;
	};
	std::unordered_map<Trit, int, TritSet::TritHash> cardinality();
	size_t lenght();
	void trim(size_t lastindex);
};