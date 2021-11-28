#pragma once
#include <string>
#include <iostream>
namespace Exception {
	class MyException {
	public:
		virtual std::string what() = 0;
	};
}