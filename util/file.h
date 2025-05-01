/*
 *	Copyright (c) 1999-2003 Smithsonian Astrophysical Observatory
 */

/*
 *
 * file.h -- declarations for file parsing
 *
 */

#ifndef	__file_h
#define	__file_h

#if HAVE_CONFIG_H
#include "conf.h"
#endif

#include <stdio.h>
#include <ctype.h>
#ifdef HAVE_STRING_H
#include <string.h>
#endif
#ifdef HAVE_MALLOC_H
#include <malloc.h>
#endif
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#include <sys/types.h>
#include <sys/stat.h>
#include "prsetup.h"
#include "macro.h"
#include "xalloc.h"

#ifdef __cplusplus
extern "C" {
#endif

int FileExists (char *filename);
int IsFile (char *s, char *filename, int len);
int IsFits (char *filename);
char *FileNameFromPath (char *s);
char *FileContents (char *path, int isize, int *osize);
int FileSize (char *path);
int FileCopy (char *iname, char *oname);
char *FileRoot (char *fname);
char *FileExtension (char *fname);
int GenerateArraySpecification (char *ispec, char *ospec, int olen);
int GenerateArraySpec2 (char *iname, char *ispec, char *ospec, int olen);
int GetNextFileName (char *filenames, int *ip, char *filename, int len);
int ParseArraySpec (char *tbuf, int *xdim, int *ydim, int *bitpix,
			 int *skip, int *bigendian);

#ifdef __cplusplus
}
#endif

#endif
