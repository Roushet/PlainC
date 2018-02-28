
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdio.h>
#include <stdlib.h>

#define ASSERT(cond, msg) \
{\
	if(! (cond))\
	{\
		fprintf(stderr, msg);\
		exit(-1);\
	}\
}

#endif

