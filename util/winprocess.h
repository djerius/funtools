/*
 *	Copyright (c) 1999-2003 Smithsonian Astrophysical Observatory
 */

/*
 *
 * winprocess.h - include file for the process handling
 *
 *
 */

#ifndef	__winprocess_h
#define	__winprocess_h

#if HAVE_CONFIG_H
#include "conf.h"
#endif
#include <stdio.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_MALLOC_H
#include <malloc.h>
#endif
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#include "prsetup.h"

#if defined(HAVE_CYGWIN) || defined(WIN32)

#ifdef __cplusplus
extern "C" {
#endif

int WinProcessOpen (char *cmd, void **ichan, void **ochan, void **pid);
void *WinProcessRead (void *fd, void *buf, int maxbytes, int *got);
int WinProcessWrite (void *fd, void *buf, int nbytes);
int WinProcessClose (void *pid, int *exit_status);
int WinProcessGetChan (void *pid, void **ichan, void **ochan);

#ifdef __cplusplus
}
#endif

#endif

#endif /* __winprocess.h */
