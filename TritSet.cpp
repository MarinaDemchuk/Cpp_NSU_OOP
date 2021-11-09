#include "MagicConstants.h"
#include "TtritSet.h"
#include <iostream>
#define uint_size (sizeof(unsigned int) * Constants::BYTE_IN_UINT)
TritSet::TritSet(uint size) {
	TritSet::my_vector.resize(size + Constants::ALIGMENT / uint_size);
	this->tru_count = Constants::START_NULL;
	this->false_count = Constants::START_NULL;
	this->last_not_unknow_index = Constants::START_INITIALIZATION;
	this->last_trit_index = Constants::START_INITIALIZATION;
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
		this->value = Trit::Unknown;
	}
	else
	{
		this->value = static_cast<Trit>(((this->set->my_vector[this->index / uint_size]) >>
			((uint_size - (this->index % uint_size + Constants::ALIGMENT)) *
				Constants::WEIGHT_ONE_TRIT)) & Constants::TWO_BIT);
	}
}
TritSet::Proxy TritSet::operator[] (size_t i)
{
	return { this,i };
}
TritSet::Proxy& TritSet::Proxy::operator=(Proxy&& new_value) noexcept
{
	this->set->my_vector[this->index / uint_size] = (this->set->my_vector[this->index / uint_size] & 
		(~ (Constants::TWO_BIT << ((uint_size - (this->index % uint_size + Constants::ALIGMENT)) 
			* Constants::WEIGHT_ONE_TRIT))))  | ((unsigned int)new_value.value << ((uint_size - (this->index % uint_size + Constants::ALIGMENT)) 
			* Constants::WEIGHT_ONE_TRIT));
	return *this;
}
TritSet::Proxy& TritSet::Proxy::operator=(const Proxy& new_value)
{
	Trit b = static_cast<Trit>(((new_value.set->my_vector[new_value.index / uint_size]) >>
		((uint_size - (new_value.index % uint_size + Constants::ALIGMENT)) *
			Constants::WEIGHT_ONE_TRIT)) & Constants::TWO_BIT);
	this->set->my_vector[this->index / uint_size] = (this->set->my_vector[this->index / uint_size] & 
		(~(Constants::TWO_BIT << ((uint_size - (this->index % uint_size + Constants::ALIGMENT))
			* Constants::WEIGHT_ONE_TRIT)))) | ((unsigned int)b << ((uint_size - (this->index % uint_size + Constants::ALIGMENT)) * Constants::WEIGHT_ONE_TRIT));
	return *this;
}
TritSet::Proxy& TritSet::Proxy::operator=(Trit new_value)
{
	if (this->index > this->set->compacity_trit() && new_value != Trit::Unknown)
	{ 
		this->set->my_vector.resize(this->index + Constants::ALIGMENT / uint_size);
		this->set->size = this->index;
	}
	if (this->index <= this->set->compacity_trit() && new_value != Trit::Unknown)
	{ 
		this->set->my_vector[(this->index / uint_size)] = (this->set->my_vector[(this->index / uint_size)] &
			(~(Constants::TWO_BIT << ((uint_size - (this->index % uint_size + Constants::ALIGMENT)) * Constants::WEIGHT_ONE_TRIT)))) |
			((unsigned int)new_value << ((uint_size - (this->index % uint_size + Constants::ALIGMENT)) 
				* Constants::WEIGHT_ONE_TRIT));
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
		this->size = a.compacity_trit();
	}
	else if (a.compacity_trit() < b.compacity_trit())
	{
		a.my_vector.resize(b.compacity_trit() / uint_size);
		this->size = b.compacity_trit();
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
size_t TritSet::TritHash::operator()(Trit t) const { return std::hash<int>()((int)t); }
std::unordered_map<Trit, int, TritSet::TritHash> TritSet::cardinality()
{
	std::unordered_map < Trit, int, TritHash> map_result = {
			{Trit::False, this->false_count},
			{Trit::True,  this->tru_count},
			{Trit::Unknown,this->cardinality(Trit::Unknown)}
	};
	return map_result;
}
size_t TritSet::lenght()
{
	return this->last_not_unknow_index + Constants::ALIGMENT;
}
void TritSet::trit_count(Trit value, uint index)
{
	this->last_trit_index = index;
	if (value != Trit::Unknown)
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
	case (Trit::Unknown):
		return last_not_unknow_index + Constants::ALIGMENT - (tru_count + false_count);
	}
	return Constants::FAILED_PROGRAM;
}
void TritSet::shrink() 
{
	this->my_vector.resize(this->last_trit_index + Constants::ALIGMENT / uint_size);
	this->size = this->last_trit_index;
}
void TritSet::trim(size_t lastindex) 
{
	this->my_vector[lastindex / uint_size] = (this->my_vector[lastindex / uint_size]) & 
		(((uint)pow(Constants::WEIGHT_ONE_TRIT, lastindex * Constants::WEIGHT_ONE_TRIT) - Constants::ALIGMENT) << 
		(Constants::SIZE_UINT_BIT - lastindex * Constants::WEIGHT_ONE_TRIT));
	for (auto i = lastindex / uint_size + Constants::ALIGMENT; i != this->compacity_trit() / uint_size - Constants::ALIGMENT; ++i) 
	{ 
		this->my_vector[i] = Constants::START_NULL;
	}
}
