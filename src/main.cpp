#include "pch.h"
#include <assert.h>

int main(int argc, char* argv[])
{
	bool x = false;

	Log::init();

	TRACE("ok");
	VERIFY(x, "nop");
	ASSERT(x, "nope");
	TRACE("cont");

	return 0;
}
