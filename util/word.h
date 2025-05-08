/*
 *	Copyright (c) 1999-2003 Smithsonian Astrophysical Observatory
 */

/*
 *
 * word.h -- declarations for word parsing
 *
 */

#ifndef	__word_h
#define	__word_h

#if HAVE_CONFIG_H
#include <conf.h>
#endif
#ifdef HAVE_STRING_H
#include <string.h>
#endif
#if HAVE_MALLOC_H
#include <malloc.h>
#endif
#if HAVE_STDLIB_H
#include <stdlib.h>
#endif
#include <prsetup.h>
#include <xalloc.h>

/* defines the types of callback procedure we use */
typedef char *(*MacroCB)(
    char *buf,
    void *client_data
);


#ifdef __cplusplus
extern "C" {
#endif

int word (char *lbuf, char *tbuf, int *lptr);
int newdtable (char *s);
int freedtable (void);
void newdelim (char *s);
void freedelim (char *s);
int lastdelim (void);
int tmatch (char *string, char *xtemplate);
int keyword (char *ibuf, char *key, char *obuf, int maxlen);
char *macro (char *icmd, char **keyword, char **value, int nkey,
		  MacroCB client_callback, void *client_data);
void cluc (char *s);
void culc (char *s);
int nowhite (char *c, char *cr);
void nocr (char *s);
int istrue (char *s);
int isfalse (char *s);
unsigned long strtoul16 (char *s, char **t);

#ifdef __cplusplus
}
#endif

#endif
