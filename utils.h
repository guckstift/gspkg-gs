
#pragma once

#include <iostream>
#include <stdlib.h>

#define UNPACK2(A) (A)[0], (A)[1]
#define UNPACK3(A) (A)[0], (A)[1], (A)[2]
#define UNPACK4(A) (A)[0], (A)[1], (A)[2], (A)[3]

namespace gs
{
	using namespace std;
	
	struct Newline
	{
	};
	
	struct Fail
	{
	};
	
	struct Logger
	{
		Logger (bool _enabled = false, bool _toStdErr = false);
		
		bool enabled;
		bool toStdErr;
	};
	
	template<typename T>
	Logger &operator<< (Logger &l, const T &x)
	{
		if (l.enabled) {
			if (l.toStdErr)
				cerr << x;
			else
				cout << x;
		}
		return l;
	}
	template<>
	Logger &operator<< <Newline> (Logger &l, const Newline &x);
	template<>
	Logger &operator<< <Fail> (Logger &l, const Fail &x);

	extern Logger dbgLog;
	extern Logger errLog;
	extern Newline nl;
	extern Fail fail;
};

