#ifndef _LITEX_H_
#define _LITEX_H_

#include <generated/soc.h>

#ifdef __GNUC__
#define FAST_DATA __attribute__ ((section (".fast_data")))
#define FAST_CODE __attribute__ ((section (".fast_text")))
#define WEAK __attribute__((weak)) 
#else
#define FAST_DATA
#define FAST_CODE
#define WEAK 
#error You need a compiler that supports assigning code and data to specific linker sections, and weak functions
#endif


#endif
