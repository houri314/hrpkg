#define VERSION "0.0.2"
#define ARGNO 7


/*
 * Getting CPU architecture.
 * Copied from https://stackoverflow.com/a/66249936
 */
#if defined(__x86_64__) || defined(_M_X64)
	#define ARCH "x86_64"
#elif defined(i386) || defined(__i386__) || defined(__i386) || defined(_M_IX86)
	#define ARCH "x86"
#elif defined(__ARM_ARCH_2__)
	#define ARCH "ARM2"
#elif defined(__ARM_ARCH_3__) || defined(__ARM_ARCH_3M__)
	#define ARCH "ARM3"
#elif defined(__ARM_ARCH_4T__) || defined(__TARGET_ARM_4T)
	#define ARCH "ARM4T"
#elif defined(__ARM_ARCH_5_) || defined(__ARM_ARCH_5E_)
	#define ARCH "ARM5"
#elif defined(__ARM_ARCH_6T2_) || defined(__ARM_ARCH_6T2_)
	#define ARCH "ARM6T2"
#elif defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) || defined(__ARM_ARCH_6K__) || defined(__ARM_ARCH_6Z__) || defined(__ARM_ARCH_6ZK__)
	#define ARCH "ARM6"
#elif defined(__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
	#define ARCH "ARM7"
#elif defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
	#define ARCH "ARM7A"
#elif defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
	#define ARCH "ARM7R"
#elif defined(__ARM_ARCH_7M__)
	#define ARCH "ARM7M"
#elif defined(__ARM_ARCH_7S__)
	#define ARCH "ARM7S"
#elif defined(__aarch64__) || defined(_M_ARM64)
	#define ARCH "ARM64"
#elif defined(mips) || defined(__mips__) || defined(__mips)
	#define ARCH "MIPS"
#elif defined(__sh__)
	#define ARCH "SUPERH"
#elif defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) || defined(__POWERPC__) || defined(__ppc__) || defined(__PPC__) || defined(_ARCH_PPC)
	#define ARCH "POWERPC"
#elif defined(__PPC64__) || defined(__ppc64__) || defined(_ARCH_PPC64)
	#define ARCH "POWERPC64"
#elif defined(__sparc__) || defined(__sparc)
	#define ARCH "SPARC"
#elif defined(__m68k__)
	#define ARCH "M68K"
#else
	#define ARCH "UNKNOWN"
#endif

