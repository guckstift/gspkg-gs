
#pragma once

#include <iostream>
#include <stdlib.h>

#define UNPACK2(A) (A)[0], (A)[1]
#define UNPACK3(A) (A)[0], (A)[1], (A)[2]
#define UNPACK4(A) (A)[0], (A)[1], (A)[2], (A)[3]

#define foreach(I,L) for (auto I = (L).begin (); I != (L).end (); ++I)

namespace gs
{
	using namespace std;
	
	typedef int8_t i8;
	typedef int16_t i16;
	typedef int32_t i32;
	typedef int64_t i64;
	typedef uint8_t u8;
	typedef uint16_t u16;
	typedef uint32_t u32;
	typedef uint64_t u64;
	
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

