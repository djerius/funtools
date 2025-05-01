/*
 *	Copyright (c) 1999-2003 Smithsonian Astrophysical Observatory
 */

#include <stdio.h>
#include <stdlib.h>
#include "word.h"
#include "tl.h"

#ifndef UNUSED
#ifdef __GNUC__
#define UNUSED(x) UNUSED_ ## x __attribute__((__unused__))
#else
#define UNUSED(x) UNUSED_ ## x
#endif
#endif

/*
 * getfitsfloatcenter: funtools and cfitsio have a 0.5 pixel descrepancy
 * when converting floating point physical coords to image coords.
 * setting this environment variable makes funtools work like cfitsio
 */
static double fitscenval = 0.5;
static int ceninited = 0;
static double
getfitsfloatcenter(
    void
 ) {
    char *s = NULL;
    if ( !ceninited ) {
	if ( ( s = getenv( "FILTER_CFITSIO" ) ) && istrue( s ) ) {
	    fitscenval = 1.0;
	}
	ceninited = 1;
    }
    return fitscenval;
}

double
tlp2i(
    double dp,
    double tlmin,
    double binsiz,
    int type
 ) {
    double dval = getfitsfloatcenter(  );
    if ( ( binsiz == 1.0 ) || ( binsiz <= 0.0 ) ) {
	switch ( type ) {
	    case 'B':
	    case 'I':
	    case 'U':
	    case 'J':
	    case 'K':
	    case 'V':
	    default:
		return ( ( dp - tlmin ) + 1.0 );
	    case 'E':
	    case 'D':
		return ( ( dp - tlmin ) + dval );
	}
    }
    else {
	switch ( type ) {
	    case 'B':
	    case 'I':
	    case 'U':
	    case 'J':
	    case 'K':
	    case 'V':
	    default:
		return ( ( dp - tlmin ) / binsiz + 1.0 );
	    case 'E':
	    case 'D':
		return ( ( dp - tlmin ) / binsiz + dval );
	}
    }
}

int
itlp2i(
    double dp,
    double tlmin,
    double binsiz,
    int UNUSED( type )
 ) {
    if ( ( binsiz == 1.0 ) || ( binsiz <= 0.0 ) ) {
	return ( int ) ( ( dp - tlmin ) + 1.0 );
    }
    else {
	return ( int ) ( ( dp - tlmin ) / binsiz + 1.0 );
    }
}

double
tli2p(
    double di,
    double tlmin,
    double binsiz,
    int type
 ) {
    double dval = getfitsfloatcenter(  );
    if ( ( binsiz == 1.0 ) || ( binsiz <= 0.0 ) ) {
	switch ( type ) {
	    case 'B':
	    case 'I':
	    case 'U':
	    case 'J':
	    case 'K':
	    case 'V':
	    default:
		return ( ( di - 1.0 ) + tlmin );
	    case 'E':
	    case 'D':
		return ( ( di - dval ) + tlmin );
	}
    }
    else {
	switch ( type ) {
	    case 'B':
	    case 'I':
	    case 'U':
	    case 'J':
	    case 'K':
	    case 'V':
	    default:
		return ( ( di - 1.0 ) * binsiz + tlmin );
	    case 'E':
	    case 'D':
		return ( ( di - dval ) * binsiz + tlmin );
	}
    }
}

double
tldim(
    double tlmin,
    double tlmax,
    double binsiz,
    int type
 ) {
    if ( ( binsiz == 1.0 ) || ( binsiz <= 0.0 ) ) {
	switch ( type ) {
	    case 'B':
	    case 'I':
	    case 'U':
	    case 'J':
	    case 'K':
	    case 'V':
	    default:
		return ( ( tlmax - tlmin ) + 1.0 );
	    case 'E':
	    case 'D':
		return ( tlmax - tlmin );
	}
    }
    else {
	switch ( type ) {
	    case 'B':
	    case 'I':
	    case 'U':
	    case 'J':
	    case 'K':
	    case 'V':
	    default:
		return ( ( tlmax - tlmin ) / binsiz + 1.0 );
	    case 'E':
	    case 'D':
		return ( ( tlmax - tlmin ) / binsiz );
	}
    }
}
