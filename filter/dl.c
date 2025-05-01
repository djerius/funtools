#ifdef USE_DL

#include <stdio.h>
#include <dl.h>
#include <gio.h>
#include <prsetup.h>

int have_dl = 1;

void *
DLOpen(
    char *name
 ) {
    void *d;
    if ( !( d = dlopen( name, RTLD_LAZY ) ) )
	gerror( stderr, "%s\n", dlerror(  ) );
    return d;
}

void *
DLSym(
    void *dl,
    char *name
 ) {
    void *d;
    if ( !( d = dlsym( dl, name ) ) )
	gerror( stderr, "%s\n", dlerror(  ) );
    return d;
}

int
DLClose(
    void *dl
 ) {
    if ( dl )
	return dlclose( dl );
    else
	return -1;
}

#else

int have_dl = 0;

#endif
