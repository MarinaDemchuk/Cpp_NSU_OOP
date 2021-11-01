#include "MagicConstants.h"
#include "TtritSet.h"
#include <iostream>
#define BBW (CHAR_BIT * 2)
#define uint_size (sizeof(unsigned int) * 4)
TritSet::TritSet(uint size) {
	TritSet::my_vector.resize(size / uint_size);
	this->tru_count = 0;
	this->false_count = 0;
	this->last_not_unknow_index = -1;
	this->last_trit_index = -1;
	this->size = size;
}
uint TritSet::compacity_trit() {
	return this->size;
}
TritSet::Proxy::Proxy(TritSet* _set, size_t _index)
{
	this->index = _index;
	this->set = _set;
	if (_index > _set->compacity_trit())
	{
		this->value = Trit::Unknow;
	}
	else
	{
		this->value = static_cast<Trit>(((this->set->my_vector[this->index / BBW]) >>
			((BBW - (this->index % BBW + Constants::ALIGMENT)) *
				Constants::WEIGHT_ONE_TRIT)) & 3u);
	}
}
TritSet::Proxy TritSet::operator[] (size_t i)
{
	return { this,i };
}
TritSet::Proxy& TritSet::Proxy::operator=(Trit new_value)
{
	if (this->index > this->set->compacity_trit() && new_value != Trit::Unknow)
	{
		this->set->my_vector.resize(this->index / uint_size);
		this->set->size = this->index;
	}
	if (this->index <= this->set->compacity_trit() && new_value != Trit::Unknow)
	{
		this->set->my_vector[(this->index / BBW)] = (this->set->my_vector[(this->index / BBW)] &
			(~(3u << ((uint_size - (this->index % BBW + Constants::ALIGMENT)) * Constants::WEIGHT_ONE_TRIT)))) |
			static_cast<uint>(new_value) << ((BBW - (this->index % BBW + Constants::ALIGMENT)) * Constants::WEIGHT_ONE_TRIT);
	}
	this->set->trit_count(new_value, index);
	return *this;
}
TritSet::Proxy::operator Trit() const
{
	return this->value;
}
void TritSet::fix_size(TritSet& a, TritSet& b)
{
	if (a.compacity_trit() > b.compacity_trit()) {
		b.my_vector.resize(a.compacity_trit() / uint_size);
	}
	else if (a.compacity_trit() < b.compacity_trit())
	{
		a.my_vector.resize(b.compacity_trit() / uint_size);
	}
}

TritSet TritSet::operator& (TritSet set)
{
	fix_size(*this, set);
	TritSet result(this->compacity_trit());
	for (size_t i = 0; i < this->compacity_trit(); ++i)
	{
		Trit a = (*this)[i];
		Trit b = set[i];
		result[i] = a & b;
		result.trit_count(a & b, i);
	}
	return result;
}
TritSet TritSet::operator|(TritSet set)
{
	fix_size(*this, set);
	TritSet result(this->compacity_trit());
	for (size_t i = 0; i < this->compacity_trit(); ++i)
	{
		Trit a = (*this)[i];
		Trit b = set[i];
		result[i] = a | b;
		result.trit_count(a | b, i);
	}
	return result;
}
TritSet TritSet::operator~()
{
	TritSet result(this->compacity_trit());
	for (size_t i = 0; i < this->compacity_trit(); ++i)
	{
		Trit a = (*this)[i];
		result[i] = ~a;
		result.trit_count(~a, i);
	}
	return result;
}

std::unordered_map<Trit, int, std::hash<int>> TritSet::cardinality()
{
	std::unordered_map<Trit, int, std::hash<int>> map_result;
	map_result[Trit::Unknow] = this->cardinality(Trit::Unknow);
	map_result[Trit::True] = this->tru_count;
	map_result[Trit::False] = this->false_count;
	return map_result;
}
size_t TritSet::lenght()
{
	return this->last_not_unknow_index + 1;
}
void TritSet::trit_count(Trit value, uint index)
{
	this->last_trit_index = index;
	if (value != Trit::Unknow)
	{
		last_not_unknow_index = index;
	}
	switch (value)
	{
	case(Trit::False):
		++this->false_count;
		break;
	case(Trit::True):
		++this->tru_count;
		break;
	}
}
size_t TritSet::cardinality(Trit value)
{
	switch (value)
	{
	case(Trit::False):
		return false_count;
		break;
	case (Trit::True):
		return tru_count;
		break;
	case (Trit::Unknow):
		return last_not_unknow_index + 1 - (tru_count + false_count);
	}
	return -1;
}
void TritSet::shrink() 
{
	this->my_vector.resize(this->last_trit_index / uint_size);
	this->size = this->last_trit_index;
}
void TritSet::trim(size_t lastindex) 
{
	this->my_vector[lastindex / uint_size] = (this->my_vector[lastindex / uint_size]) & 
		(((uint)pow(2, lastindex * 2) - 1) << 
		(Constants::SIZE_UINT_BIT - lastindex * 2));
	for (auto i = lastindex / uint_size + 1; i != this->compacity_trit() / uint_size - 1; ++i) 
	{
		this->my_vector[i] = 0;
	}
}
