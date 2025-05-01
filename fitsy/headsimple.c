/* headsimple.c
 */

#include <xos.h>
#include <fitsy.h>

FITSHead
ft_headsimple(
    void *mem,
    int bytes,
    int naxis,
    int *naxes,
    int bitpix
 ) {
    FITSHead fits;
    int i;

    if ( mem ) memset( mem, 0, bytes );

    fits = ft_headinit( ( FITSCard ) mem, bytes );
    ft_headappl( fits, "SIMPLE", 0, 1, NULL );
    ft_headappi( fits, "BITPIX", 0, bitpix, NULL );
    ft_headappi( fits, "NAXIS", 0, naxis, NULL );

    for ( i = 1; i <= naxis; i++ ) {
	ft_headappi( fits, "NAXIS", 1, naxes[i], NULL );
    }
    return fits;
}
