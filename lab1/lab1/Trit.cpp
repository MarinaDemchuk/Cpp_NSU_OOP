#include "Trit.h"
Trit operator~(Trit a) {
	switch (a) {
	case Trit::False:
		return Trit::True;
		break;
	case Trit::True:
		return Trit::False;
		break;
	case Trit::Unknow:
		return Trit::Unknow;
		break;
	}
}
Trit operator& (Trit a, Trit b) {
	if (a == Trit::True && b == Trit::True) {
		return Trit::True;
	}
	else if (a == Trit::False || b == Trit::False) {
		return Trit::False;
	}
	else {
		Trit::Unknow;
	}
}
Trit operator| (Trit a, Trit b) {
	if (a == Trit::False && b == Trit::False) {
		return Trit::False;
	}
	else if (a == Trit::True || b == Trit::True) {
		return Trit::True;
	}
	else {
		return Trit::Unknow;
	}
}