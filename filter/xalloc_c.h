
#include "chunked.h"

ChunkedString XALLOC_C = {
  2,
  { "/*\n *\tCopyright (c) 2004-2009 Smithsonian Astrophysical Observatory\n */\n\n/*\n *\n * xalloc -- safe memory allocation with error checking\n *\n */\n\n/* this module is compiled within a funtools filter and must not require\n   the header files */\n#ifdef FILTER_PTYPE\n#define ANSI_FUNC 1\n#else\n#include \"xalloc.h\"\n#endif\n\n#define XALLOC_ERROR \"ERROR: can't allocate memory (xalloc)\\n\"\n\n#if XALLOC_SETJMP\n\nstatic jmp_buf *xalloc_envptr = NULL;\n\nvoid\nxalloc_savejmp(\n    jmp_buf * env\n ) {\n    xalloc_envptr = env;\n}\n#endif\n\n\nstatic void\n_xalloc_error(\n    void\n ) {\n    write( 1, XALLOC_ERROR, strlen( XALLOC_ERROR ) );\n#if XALLOC_SETJMP\n    if ( xalloc_envptr )\n\tlongjmp( *xalloc_envptr, XALLOC_SETJMP );\n    else\n#endif\n\texit( 1 );\n}\n\nvoid *\nxmalloc(\n    size_t n\n ) {\n    void *p;\n\n    if ( !( p = ( void * ) malloc( n ) ) )\n\t_xalloc_error(  );\n    return p;\n}\n\nvoid *\nxcalloc(\n    size_t n,\n    size_t s\n ) {\n    void *p;\n\n    if ( !( p = ( void * ) calloc( n, s ) ) )\n\t_xalloc_error(  );\n    return p;\n}\n\nvoid *\nxrealloc(\n    voi",
"d *p,\n    size_t n\n ) {\n    if ( !p )\n\treturn xmalloc( n );\n    if ( !( p = ( void * ) realloc( p, n ) ) )\n\t_xalloc_error(  );\n    return p;\n}\n\nvoid\nxfree(\n    void *p\n ) {\n    if ( p )\n\tfree( p );\n}\n\nchar *\nxstrdup(\n    char *s\n ) {\n    if ( s )\n        return ( ( char * )\n\t         strcpy( ( char * ) xmalloc( ( size_t ) strlen( s ) + 1 ), s ) );\n    else\n\treturn NULL;\n}\n" }
};

