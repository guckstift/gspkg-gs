
#include "utils.h"

namespace gs
{
	Logger dbgLog;
	Logger errLog (true, true);
	Newline nl;
	Fail fail;
	
	Logger::Logger (bool _enabled, bool _toStdErr) :
		enabled(_enabled), toStdErr(_toStdErr)
	{
	}
	
	template<>
	Logger &operator<< <Newline> (Logger &l, const Newline &x)
	{
		if (l.enabled) {
			if (l.toStdErr)
				cerr << endl;
			else
				cout << endl;
		}
		return l;
	}
	
	template<>
	Logger &operator<< <Fail> (Logger &l, const Fail &x)
	{
		exit (1);
		return l;
	}
}

