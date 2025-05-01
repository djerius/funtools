/*
 *	Copyright (c) 2005 Smithsonian Astrophysical Observatory
 */

/*
 *
 * idx.h - include file for indexed filters
 *
 */
#ifndef	__idx_h
#define	__idx_h

#if HAVE_CONFIG_H
#include "conf.h"
#endif

#include "prsetup.h"
#include <stdio.h>
#include <ctype.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_STRING_H
#include <string.h>
#endif
#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif
#include "fitsy.h"
#include "gio.h"
#include "xalloc.h"
#include "strtod.h"

/* binary search edge */
#define IDX_EDGE_LEFT  1
#define IDX_EDGE_RIGHT 2
#define IDX_EDGE_BOTH  (IDX_EDGE_LEFT|IDX_EDGE_RIGHT)

/* type of row record */
#define IDX_ALLROWS	0
#define IDX_INDEF	1
#define IDX_ROW_LIST    2
#define IDX_SORT        3
#define IDX_OR_SORT     4
#define IDX_AND_SORT    5

/* methods of accessing data record */
#define IDX_IO_MMAP	1
#define IDX_IO_LSEEK	2

#ifdef HAVE_SYS_MMAN_H
#define IDX_IO_DEFAULT	IDX_IO_MMAP
#else
#define IDX_IO_DEFAULT	IDX_IO_LSEEK
#endif

/* increment for storing rowlists */
#define IDX_ROW_INC   32

/* sort program */
#define IDX_SORTPROG "_funsort"

/* idxinfo which values */
#define IDX_COLNAME	1
#define IDX_FILENAME	2
#define IDX_FILEROOT1	3
#define IDX_FILEROOT2	4
#define IDX_PATHNAME	5
#define IDX_SORTNAME	6

/* rows can be in memory range lists or file-based row numbers */
typedef struct _idxrowrec{
  struct _idxrowrec *next;
  char *s;
  int type;
  int rtype;
  int dofilt;
  int dosort;
  int rtot;
  int maxrow;
  int nrow;
  int *startrow;
  int *stoprow;
  FILE *ifile;
  int ichan;
  int ochan;
  int pid;
  struct _idxvalrec *v;
  char *fdata;
  size_t flen;
} idxrowrec;

/* values can be int, float, col, region, func */
typedef struct _idxvalrec{
  struct _idxvalrec *next;
  char *s;
  int type;
  int ntype;
  longlong ival;
  double dval;
  char *iname;
  GIO igio;
  FITSHead ifits;
  int itype;
  int ioffset;
  int in;
  int vtype;
  int voffset;
  int vn;
  int nrow;
  char *idata;
  int ilen;
  struct _idxvalrec *rv[2];
  double rlo[2], rhi[2];
} idxvalrec;

#ifdef __cplusplus
extern "C" {
#endif


idxrowrec *idxall (idxrowrec *row);
idxrowrec *idxor  (idxrowrec *row1, idxrowrec *row2);
idxrowrec *idxand (idxrowrec *row1, idxrowrec *row2);
idxrowrec *idxnot (idxrowrec *row);

idxrowrec *idxrowreg (idxvalrec *val);
idxrowrec *idxrowfun (idxvalrec *val);
idxrowrec *idxroweq  (idxvalrec *val1, idxvalrec *val2);
idxrowrec *idxrowne  (idxvalrec *val1, idxvalrec *val2);
idxrowrec *idxrowlt  (idxvalrec *val1, idxvalrec *val2);
idxrowrec *idxrowle  (idxvalrec *val1, idxvalrec *val2);
idxrowrec *idxrowgt  (idxvalrec *val1, idxvalrec *val2);
idxrowrec *idxrowge  (idxvalrec *val1, idxvalrec *val2);
idxrowrec *idxrownot (idxvalrec *val);

idxvalrec *idxvaladd (idxvalrec *val1, idxvalrec *val2);

idxvalrec *idxvalsub (idxvalrec *val1, idxvalrec *val2);
idxvalrec *idxvalmul (idxvalrec *val1, idxvalrec *val2);
idxvalrec *idxvaldiv (idxvalrec *val1, idxvalrec *val2);
idxvalrec *idxvalmod (idxvalrec *val1, idxvalrec *val2);
idxvalrec *idxvaland (idxvalrec *val1, idxvalrec *val2);
idxvalrec *idxvalor  (idxvalrec *val1, idxvalrec *val2);
idxvalrec *idxvalxor (idxvalrec *val1, idxvalrec *val2);
idxvalrec *idxvalnot (idxvalrec *val);
idxvalrec *idxvalcom (idxvalrec *val);
idxvalrec *idxvalmin (idxvalrec *val);

char *idxinfo (int which);
int idxdebug (int debug);
idxvalrec *idxvalnew (char *s);
int idxvalfree (idxvalrec *v);
idxrowrec *idxrownew (void);
int idxrowfree (idxrowrec *r);
int idxinitfilenames (char *s, int *flag);
char *idxindexfilename (char *s, int *size);
idxvalrec *idxlookupfilename (char *iname);
void idxfreefilenames (void);
void idxfreeglobals (void);
int idxinitparser (char *s);
void idxendparser (void);
void *idxread (idxrowrec *row, GIO gio, FITSHead fits,
		    void *buf, size_t size, size_t get, size_t *got,
		    int *dofilt);
void idxstring (char *s);
int idxerror (char *mmsg);
int idxlex   (void);
int idxparse (void);

#ifdef __cplusplus
}
#endif

#endif /* __idx.h */
