/*
 *	Copyright (c) 1999-2003 Smithsonian Astrophysical Observatory
 */

/*
 *
 * filtprog.c -- hi level support for filters using different techniques
 *
 */

#include <filter.h>

/*
 *
 * FilterProgStart -- start the filtering process
 *
 */
int
FilterProgStart(
    Filter filter
 ) {
    /* make sure we have something to play with */
    if ( filter == NULL )
	return ( 0 );

    /* call the technique-specific routine */
    if ( filter->filt_start )
	return ( ( filter->filt_start ) ( filter ) );
    else {
	return ( 0 );
    }
}

/*
 *
 * FilterProgOpen -- return filter program as a file for writing
 *
 */
int
FilterProgOpen(
    Filter filter
 ) {
    /* make sure we have something to play with */
    if ( filter == NULL )
	return ( 0 );

    /* check the mode for known techniques and load drivers */
    switch ( filter->method ) {
	case METHOD_C:
	    FilterProgLoad_C( filter );
	    break;
	default:
	    gerror( stderr, "unknown filter technique: %d\n", filter->method );
	    return ( 0 );
    }

    /* call the technique-specific routine */
    if ( filter->filt_open ) {
	return ( ( filter->filt_open ) ( filter ) );
    }
    else {
	return ( 1 );
    }
}

/*
 *
 * FilterProgPrepend -- prepend to the filter
 *
 */
int
FilterProgPrepend(
    Filter filter
 ) {
    /* make sure we have something to play with */
    if ( filter == NULL )
	return ( 0 );

    /* call the technique-specific routine */
    if ( filter->filt_prepend )
	return ( ( filter->filt_prepend ) ( filter ) );
    else
	return ( 1 );
}

/*
 *
 * FilterProgWrite -- write the symbols
 *
 */
int
FilterProgWrite(
    Filter filter
 ) {
    /* make sure we have something to play with */
    if ( filter == NULL )
	return ( 0 );

    /* call the technique-specific routine */
    if ( filter->filt_write )
	return ( ( filter->filt_write ) ( filter ) );
    else
	return ( 1 );
}

/*
 *
 * FilterProgAppend -- append the filter program body
 *
 */
int
FilterProgAppend(
    Filter filter
 ) {
    /* make sure we have something to play with */
    if ( filter == NULL )
	return ( 0 );

    /* call the technique-specific routine */
    if ( filter->filt_append )
	return ( ( filter->filt_append ) ( filter ) );
    else
	return ( 1 );
}

/*
 *
 * FilterProgClose -- close the filter program file
 *
 */
int
FilterProgClose(
    Filter filter
 ) {
    /* make sure we have something to play with */
    if ( filter == NULL )
	return ( 0 );

    /* debugging only */
    if ( filter->debug >= 2 )
	return ( 1 );

    /* call the technique-specific routine */
    if ( filter->filt_close )
	return ( ( filter->filt_close ) ( filter ) );
    else
	return ( 1 );
}

/*
 *
 * FilterProgCompile -- compile the filter program
 *
 */
int
FilterProgCompile(
    Filter filter
 ) {
    /* make sure we have something to play with */
    if ( filter == NULL )
	return ( 0 );

    /* debugging only */
    if ( filter->debug >= 2 )
	return ( 1 );

    /* call the technique-specific routine */
    if ( filter->filt_compile )
	return ( ( filter->filt_compile ) ( filter ) );
    else
	return ( 1 );
}

/*
 *
 * FilterProgEnd -- end the filtering process
 *
 */
int
FilterProgEnd(
    Filter filter
 ) {
    /* make sure we have something to play with */
    if ( filter == NULL )
	return ( 0 );

    /* call the technique-specific routine */
    if ( filter->filt_end )
	return ( ( filter->filt_end ) ( filter ) );
    else {
	return ( 0 );
    }
}

/*
 *
 * FilterLexName -- return the "in-expression" name
 *
 */
char *
FilterLexName(
    Filter filter,
    char *name
 ) {
    /* make sure we have something to play with */
    if ( filter == NULL )
	return ( name );

    /* call the technique-specific routine */
    if ( filter->filt_name )
	return ( ( filter->filt_name ) ( filter, name ) );
    else
	return ( name );
}

/*
 *
 * FilterLexRoutine1 -- return the beginning of the routine string
 *
 */
char *
FilterLexRoutine1(
    Filter filter,
    char *name
 ) {
    /* make sure we have something to play with */
    if ( filter == NULL )
	return ( NULL );

    /* call the technique-specific routine */
    if ( filter->filt_routine1 )
	return ( ( filter->filt_routine1 ) ( filter, name ) );
    else
	return ( name );
}

/*
 *
 * FilterLexRoutine2 -- return the beginning of the routine string
 *
 */
char *
FilterLexRoutine2(
    Filter filter,
    char *name
 ) {
    /* make sure we have something to play with */
    if ( filter == NULL )
	return ( NULL );

    /* call the technique-specific routine */
    if ( filter->filt_routine2 )
	return ( ( filter->filt_routine2 ) ( filter, name ) );
    else
	return ( name );
}

/*
 *
 * FilterLexRegion1 -- return the beginning of the region string
 *
 */
char *
FilterLexRegion1(
    Filter filter,
    char *name
 ) {
    /* make sure we have something to play with */
    if ( filter == NULL )
	return ( NULL );

    /* call the technique-specific region */
    if ( filter->filt_region1 )
	return ( ( filter->filt_region1 ) ( filter, name ) );
    else
	return ( name );
}

/*
 *
 * FilterLexRegion2 -- return the end of the region string
 *
 */
char *
FilterLexRegion2(
    Filter filter,
    char *name
 ) {
    /* make sure we have something to play with */
    if ( filter == NULL )
	return ( NULL );

    /* call the technique-specific region */
    if ( filter->filt_region2 )
	return ( ( filter->filt_region2 ) ( filter, name ) );
    else
	return ( name );
}
