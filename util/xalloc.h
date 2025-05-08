/*
 *	Copyright (c) 2004 Smithsonian Astrophysical Observatory
 */

/*
 *
 * xalloc.h -- declarations for safe (error-checked) memory allocation
 *
 */

#ifndef	__xalloc_h
#define	__xalloc_h

#if HAVE_CONFIG_H
#include <conf.h>
#endif

#include <sys/types.h>
#if HAVE_STRING_H
#include <string.h>
#endif
#if HAVE_MALLOC_H
#include <malloc.h>
#endif
#if HAVE_STDLIB_H
#include <stdlib.h>
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_SETJMP_H
#define XALLOC_SETJMP 142857
#include <setjmp.h>
#endif

#include <prsetup.h>

#ifdef __cplusplus
extern "C" {
#endif

void *xmalloc (size_t n);
void *xcalloc (size_t n, size_t s);
void *xrealloc (void *p, size_t n);
void xfree (void *p);
char *xstrdup (char *s);
#if HAVE_SETJMP
void xalloc_savejmp (jmp_buf *env);
#endif

#ifdef __cplusplus
}
#endif

#endif
