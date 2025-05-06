/*
 *      Copyright (c) 2025 Smithsonian Astrophysical Observatory
 */

/*
 *
 * chunked_strings.c -- handle static strings stored in chunks to
 * avoid ANSI std 4096 byte limits on static string lengths
 *
 */

#include <string.h>

#include "chunked.h"
#include "xalloc.h"

void
print_chunks ( ChunkedString chunks, FILE* fd ) {

    for( int idx = 0 ; idx < chunks.nbuf ; idx++ ) {
        fputs( chunks.bufs[idx], fd );
    }
    fputc( '\n', fd );
}

char *
dechunk( ChunkedString chunks ) {

    char *dechunked;
    char *tmp;
    size_t len = 0;
    for( int idx = 0 ; idx < chunks.nbuf ; idx++ )
        len += strlen( chunks.bufs[idx] );

    tmp = dechunked = xmalloc( len + 1);

    for( int idx = 0 ; idx < chunks.nbuf ; idx++ ) {
        size_t length = strlen(chunks.bufs[idx]);
        memcpy( tmp, chunks.bufs[idx], length );
        tmp += length;
    }

    *tmp = '\0';

    return dechunked;
}
