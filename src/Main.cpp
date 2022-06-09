#include "Log.h"

int main(int argc, char* argv[])
{
	Log::init();

	TRACE("ok");

	//Log::getLogger()->trace("ok");

	return 0;
}
