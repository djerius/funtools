#ifndef	__dl_h
#define	__dl_h

#if HAVE_CONFIG_H
#include <conf.h>
#endif

#ifdef HAVE_DLFCN_H
#include <dlfcn.h>
#endif

#include <prsetup.h>

#ifdef __cplusplus
extern "C" {
#endif

void *DLOpen (char *name);
void *DLSym (void *dl, char *name);
int DLClose (void *dl);

#ifdef __cplusplus
}
#endif

#endif
