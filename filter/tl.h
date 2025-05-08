/*
 *	Copyright (c) 1999-2003 Smithsonian Astrophysical Observatory
 */

/*
 *
 * tl.h -- declarations for tl parsing
 *
 */

#ifndef	__tl_h
#define	__tl_h

#include <prsetup.h>

#ifdef __cplusplus
extern "C" {
#endif

double tlp2i (double dp, double tlmin, double binsiz, int type);
int    itlp2i  (double dp, double tlmin, double binsiz, int type);
double tli2p (double di, double tlmin, double binsiz, int type);
double tldim (double tlmin, double tlmax, double binsiz, int type);

#ifdef __cplusplus
}
#endif

#endif
