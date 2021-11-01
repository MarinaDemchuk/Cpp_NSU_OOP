#pragma once
enum class Trit {
	Unknow = 0, //00
	True ,//01
	False //10
};
Trit operator~(Trit a);
Trit operator& (Trit a, Trit b);
Trit operator| (Trit a, Trit b);

