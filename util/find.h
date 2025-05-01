/*
 *	Copyright (c) 1999-2003 Smithsonian Astrophysical Observatory
 */

/*
 *
 * find.h -- declarations for find finding
 *
 */

#ifndef	__find_h
#define	__find_h

#if HAVE_CONFIG_H
#include "conf.h"
#endif

#include <stdio.h>
#include <ctype.h>
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#if HAVE_STRING_H
#include <string.h>
#endif
#include <sys/types.h>
#include <sys/stat.h>
#include "xalloc.h"
#include "prsetup.h"

#ifdef __cplusplus
extern "C" {
#endif

char *ResolvePath (char *ibuf, char *obuf, int maxlen);
void ExpandEnv (char *name, char *fullname, int maxlen);
char *Access (char *name, char *mode);
char *Find (char *name, char *mode, char *extn, char *path);

#ifdef __cplusplus
}
#endif

#endif
