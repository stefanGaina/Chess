#ifndef ASSERT_H_
#define ASSERT_H_

#define DEBUG 1

#ifdef DEBUG = 1
	#define ASSERT(condition, ...) { if (!(condition)) { CRITICAL(__VA_ARGS__); __debugbreak(); } }
	#define VERIFY(condition, ...) { if (!(condition)) { ERROR   (__VA_ARGS__);                 } }
#else
	#define ASSERT(x, ...) ((void)0)
	#define VERIFY(x, ...) ((void)0)
#endif /* DEBUG */

#endif /* ASSERT_H_ */
