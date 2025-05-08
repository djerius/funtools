/*
 *	Copyright (c) 1999-2003 Smithsonian Astrophysical Observatory
 */

/*
 *
 * mainlib.h
 *
 */

#ifndef	__mainlib_h
#define	__mainlib_h

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
#if HAVE_DLFCN_H
#include <dlfcn.h>
#endif
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <prsetup.h>
#include <xalloc.h>
#include <word.h>
#include <find.h>
#include <gio.h>

/* types of mainlibs we recognize */
#define MAINLIB_ERROR 0
#define MAINLIB_ARGV  1
#define MAINLIB_EXTN  2
#define MAINLIB_TCL   3

/* max values */
#define MAINLIB_CMDS 32
#define MAINLIB_ARGS 32

/* defines the types of callback procedure we use */
typedef int (*MainLibProc)(
    int argc,
    char **argv
);

/* define init call */
typedef void *(*MainLibInitCall)(
  void
);

/* define proc call */
typedef int (*MainLibProcessCall)(
  void *ml, char *cmd, char **buf, char *mode
);

/* define Tcl lookup call */
typedef int (*MainLibTclLookup)(
  void *interp, char *s
);

/* define Tcl eval call */
typedef int (*MainLibTclEval)(
  void *interp, char *s
);

/*
 *
 *
 * mainlib record structure for a single command
 *
 */
typedef struct mainlibentryrec{
  struct mainlibentryrec *next;
  char *xclass;
  char *name;
  MainLibProc proc;
  int type;
} *MainLibEntry, MainLibEntryRec;

/*
 *
 *
 * mainlib record structure for a group of commands
 *
 */
typedef struct mainlibrec{
  MainLibEntry head;
  void *dl;
  MainLibProcessCall mainlibprocess;
  MainLibTclLookup tcllookup;
  MainLibTclEval tcleval;
  int npid;
  pid_t pids[MAINLIB_CMDS+1];
} *MainLib, MainLibRec;

/* library declarations */
#ifdef __cplusplus
extern "C" {
#endif


/* public */
int MainLibLoad (char *name, char *shlib, void **ml, char **ermsg);
MainLib MainLibNew (void);
MainLibEntry MainLibAdd (MainLib ml, char *xclass, char *name, 
			      MainLibProc mainlibproc, int type);
int MainLibProcess (MainLib ml, char *cmd, char **buf, char *mode);
int MainLibProcessCleanup (MainLib ml);
int MainLibDel (MainLib ml, MainLibEntry mle);
int MainLibFree (MainLib ml);

#ifdef __cplusplus
}
#endif

#endif /* __mainlib.h */

