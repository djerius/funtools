/* headwcs.c
 */

#include "xos.h"
#include "fitsy.h"

int
ft_trxlcs(
    FITSLinWCS lcs,
    double x0,
    double y0,
    double *x1,
    double *y1,
    int direction
 ) {
    if ( !lcs->has_wcs ) {
	*x1 = x0;
	*y1 = y0;
	return 0;
    }

    if ( direction ) {
	*x1 = x0 * lcs->fwd[0][0] + y0 * lcs->fwd[1][0] + lcs->fwd[2][0];
	*y1 = x0 * lcs->fwd[0][1] + y0 * lcs->fwd[1][1] + lcs->fwd[2][1];
    }
    else {
	*x1 = x0 * lcs->rev[0][0] + y0 * lcs->rev[1][0] + lcs->rev[2][0];
	*y1 = x0 * lcs->rev[0][1] + y0 * lcs->rev[1][1] + lcs->rev[2][1];
    }

    return 1;
}

int
ft_trxsiz(
    FITSLinWCS lcs,
    double x0,
    double y0,
    double *x1,
    double *y1,
    int direction
 ) {
    if ( !lcs->has_wcs ) {
	*x1 = x0;
	*y1 = y0;
	return 0;
    }

    if ( direction ) {
	*x1 = x0 * lcs->fwd[0][0];
	*y1 = y0 * lcs->fwd[1][1];
    }
    else {
	*x1 = x0 * lcs->rev[0][0];
	*y1 = y0 * lcs->rev[1][1];
    }

    return 1;
}

void
ft_loglcs(
    FITSHead fits,
    double m11,
    double m12,
    double m21,
    double m22,
    double v1,
    double v2
 ) {
    if ( m11 != 1.0 ) ft_headsetr( fits, "LTM1_1", 0, m11, 7, NULL, 1 );
    if ( m12 != 0.0 ) ft_headsetr( fits, "LTM1_2", 0, m12, 7, NULL, 1 );
    if ( m21 != 0.0 ) ft_headsetr( fits, "LTM2_1", 0, m21, 7, NULL, 1 );
    if ( m22 != 1.0 ) ft_headsetr( fits, "LTM2_2", 0, m22, 7, NULL, 1 );
    if ( v1 != 0.0 ) ft_headsetr( fits, "LTV1", 0, v1, 7, NULL, 1 );
    if ( v2 != 0.0 ) ft_headsetr( fits, "LTV2", 0, v2, 7, NULL, 1 );
}

void
ft_wcslcs(
    FITSHead fits,
    double m11,
    double m12,
    double m21,
    double m22,
    double crv1,
    double crv2,
    double crp1,
    double crp2,
    char *cun1,
    char *cun2
 ) {
    ft_headsets( fits, "CTYPE1", 0, "LINEAR", NULL, 1 );
    ft_headsets( fits, "CTYPE2", 0, "LINEAR", NULL, 1 );

    if ( crv1 != 0.0 ) ft_headsetr( fits, "CRVAL1", 0, crv1, 7, NULL, 1 );
    if ( crp1 != 0.0 ) ft_headsetr( fits, "CRPIX1", 0, crp1, 7, NULL, 1 );
    if ( cun1 != NULL ) ft_headsets( fits, "CUNIT1", 0, cun1, NULL, 1 );

    if ( crv2 != 0.0 ) ft_headsetr( fits, "CRVAL2", 0, crv2, 7, NULL, 1 );
    if ( crp2 != 0.0 ) ft_headsetr( fits, "CRPIX2", 0, crp2, 7, NULL, 1 );
    if ( cun2 != NULL ) ft_headsets( fits, "CUNIT2", 0, cun2, NULL, 1 );

    if ( m11 != 1.0 ) ft_headsetr( fits, "CD1_1", 0, m11, 7, NULL, 1 );
    if ( m12 != 0.0 ) ft_headsetr( fits, "CD1_2", 0, m12, 7, NULL, 1 );
    if ( m21 != 0.0 ) ft_headsetr( fits, "CD2_1", 0, m21, 7, NULL, 1 );
    if ( m22 != 1.0 ) ft_headsetr( fits, "CD2_2", 0, m22, 7, NULL, 1 );
}
