/*
 *	Copyright (c) 2025 Smithsonian Astrophysical Observatory
 */

/*
 *
 * chunked.h -- include file for chunked.c
 *
 */

#ifndef _chunked_h
#define _chunked_h

#include <stdio.h>

typedef struct {
    int  nbuf;
    char *bufs[256];  /* at 1k per string (see inc.pl), more than enough */
}  ChunkedString ;


#ifdef __cplusplus
extern "C" {
#endif

void print_chunks ( ChunkedString chunks, FILE* fd );

char* dechunk( ChunkedString chunks );

#ifdef __cplusplus
}
#endif

#endif /* _chunked_h */
