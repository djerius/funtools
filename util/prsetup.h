/*
 *	Copyright (c) 1999-2003 Smithsonian Astrophysical Observatory
 */

/* prsetup.h -- define variables for ANSI prototyping */

#ifndef _prsetup
#define _prsetup

#ifndef UNUSED
#ifdef __GNUC__
#  define UNUSED(x) UNUSED_ ## x __attribute__((__unused__))
#else
#  define UNUSED(x) UNUSED_ ## x
#endif
#endif

/* the ever-present */
#ifndef SZ_LINE
#define SZ_LINE 4096
#endif

#ifndef MIN
#define MIN(a,b) (((a)<(b))?(a):(b))
#endif

#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif

#ifndef ABS
#define ABS(x)		((x)<0?(-(x)):(x))
#endif

#endif

