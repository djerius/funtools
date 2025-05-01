/* ft_acht2.c
**
** Vector change type operators.
** FITS adds bzero and bascle.
**/

#if HAVE_CONFIG_H
#include <conf.h>
#endif
#include "xos.h"
#include "fitsy.h"
#include "longlong.h"
#include "generic.h"

/* *INDENT-OFF* */
typedef void *(*copy)  (void *, const void *, size_t);
typedef void (*vector)  (void *, void *, int, copy, int);
/* *INDENT-ON* */

#define cht2xx(ch1, type1, ch2, type2)					\
									\
void cht2##ch1##ch2(                                                    \
			void	*v1,					\
			void	*v2,					\
			int	npix,					\
			copy    rtn,					\
			int	direction				\
)                                                                       \
{									\
  type1 tval1;								\
  type2 tval2;								\
  if( direction == 0 ){							\
    while ( npix-- ) {							\
      (rtn)(&tval2, (char *)v2+(npix*sizeof(type2)), sizeof(type2));	\
      tval1 = tval2;							\
      memcpy((char *)v1+(npix*sizeof(type1)), &tval1, sizeof(type1));	\
    }									\
  }									\
  else{									\
    while ( npix-- ) {							\
      memcpy(&tval2, (char *)v2+(npix*sizeof(type2)), sizeof(type2));	\
      tval1 = tval2;							\
      (rtn)((char *)v1+(npix*sizeof(type1)), &tval1, sizeof(type1));	\
    }									\
  }									\
}

DOUBLE_GENERIC( cht2xx )

static int
pixtype2(
    int type
 ) {
    switch ( type ) {
	case 'A':
	    return TY_UCHAR;
	case 'B':
	    return TY_UCHAR;
	case 'X':
	    return TY_UCHAR;
	case 'I':
	    return TY_SHORT;
	case 'K':
	    return TY_LONG;
	case 'U':
	    return TY_USHORT;
	case 'J':
	    return TY_INT;
	case 'V':
	    return TY_UINT;
	case 'L':
	    return TY_UCHAR;
	case 'E':
	    return TY_REAL;
	case 'D':
	    return TY_DOUBLE;
    }

    return -1;
}

void
ft_acht2(
    int type1,
    void *v1,
    int type2,
    void *v2,
    int npix,
    int swap,
    int direction
 ) {
    copy rtn = NULL;
    int offset1, offset2, type;

    /* *INDENT-OFF* */
    static vector matrix[10][10] = {
	  {cht2cc, cht2cs, cht2ci, cht2cl, cht2cr, cht2cd, cht2ct, cht2cu, cht2cv}
	, {cht2sc, cht2ss, cht2si, cht2sl, cht2sr, cht2sd, cht2st, cht2su, cht2sv}
	, {cht2ic, cht2is, cht2ii, cht2il, cht2ir, cht2id, cht2it, cht2iu, cht2iv}
	, {cht2lc, cht2ls, cht2li, cht2ll, cht2lr, cht2ld, cht2lt, cht2lu, cht2lv}
	, {cht2rc, cht2rs, cht2ri, cht2rl, cht2rr, cht2rd, cht2rt, cht2ru, cht2rv}
	, {cht2dc, cht2ds, cht2di, cht2dl, cht2dr, cht2dd, cht2dt, cht2du, cht2dv}
	, {cht2tc, cht2ts, cht2ti, cht2tl, cht2tr, cht2td, cht2tt, cht2tu, cht2tv}
	, {cht2uc, cht2us, cht2ui, cht2ul, cht2ur, cht2ud, cht2ut, cht2uu, cht2uv}
	, {cht2vc, cht2vs, cht2vi, cht2vl, cht2vr, cht2vd, cht2vt, cht2vu, cht2vv}
    };
    /* *INDENT-ON* */

    offset1 = pixtype2( type1 );
    offset2 = pixtype2( type2 );
    if ( offset1 < 0 || offset2 < 0 ) return;

    if ( swap ) {
	if ( direction == 0 )
	    type = type2;
	else
	    type = type1;
	switch ( ft_sizeof( type ) ) {
	    case 1:
		rtn = memcpy;
		break;
	    case 2:
		rtn = swap2;
		break;
	    case 4:
		rtn = swap4;
		break;
	    case 8:
		rtn = swap8;
		break;
	    default:
		rtn = memcpy;
		break;
	}
    }
    else {
	rtn = memcpy;
    }

    ( *matrix[offset1][offset2] ) ( v1, v2, npix, rtn, direction );
}
