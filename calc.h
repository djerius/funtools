/*
 *	Copyright (c) 1999-2003 Smithsonian Astrophysical Observatory
 */

/*
 *
 * calc.h
 *
 */
#ifndef	__funcalc_h
#define	__funcalc_h

#include <prsetup.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifndef FUNCALC_CC
#define FUNCALC_CC NULL
#endif
     
#ifndef FUNCALC_CFLAGS
#define FUNCALC_CFLAGS NULL
#endif
     
/* places to look for the compiler other than user's path */
#define FUNCALC_PATH "/opt/SUNWspro/bin:/bin:/usr/bin:/usr/local/bin/:/opt/local/bin:"

#define DEFAULT_FUNCALC_TMPDIR "/tmp"
#define FUNCALC_SED            "funcalc.sed"

/* library declarations */
void _CalcCat (char *str, char **ostr, int *olen);

#ifdef __cplusplus
}
#endif

#endif /* __funtools.h */
