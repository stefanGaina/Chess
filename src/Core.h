#ifndef CORE_H_
#define CORE_H_

#define DEBUG 1

/* Type definitions */
typedef signed   char      Sint8;
typedef unsigned char      Uint8;
typedef signed   short     Sint16;
typedef unsigned short     Uint16;
typedef signed   long      Sint32;
typedef unsigned long      Uint32;
typedef signed   long long Sint64;
typedef unsigned long long Uint64;

#ifdef DEBUG = 1
	#define ASSERT(x, ...) { if (!(x)) { CRITICAL("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define VERIFY(x, ...) { if (!(x)) { ERROR   ("Verify Failed: {0}"   , __VA_ARGS__);                 } }
#else
	#define ASSERT(x, ...) ((void)0)
	#define VERIFY(x, ...) ((void)0)
#endif /* DEBUG */

#endif /* CORE_H_ */
