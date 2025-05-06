
AC_INIT([funtools],[1.4.7.1],[saord@cfa.harvard.edu],[funtools])

AC_CONFIG_HEADERS([conf.h])
AC_CONFIG_SRCDIR([./funtools.h])
AC_CANONICAL_HOST

#
# checks that we use in most projects
#
AC_PROG_CC

AC_EXEEXT
if test x"${EXEEXT}" = "xno"; then
  EXEEXT=""
fi

AC_PROG_RANLIB

# Autoupdate added the next two lines to ensure that your configure
# script's behavior did not change.  They are probably safe to remove.
AC_CHECK_INCLUDES_DEFAULT
AC_PROG_EGREP

AC_CHECK_HEADERS(malloc.h)
AC_CHECK_HEADERS(getopt.h)
AC_CHECK_HEADERS(values.h)
AC_CHECK_HEADERS(dlfcn.h)
AC_CHECK_HEADERS(setjmp.h)
AC_CHECK_HEADERS(sys/un.h)
AC_CHECK_HEADERS(sys/ipc.h)
AC_CHECK_HEADERS(sys/mman.h)
AC_CHECK_HEADERS(crt_externs.h)
case $host_os in
    *cygwin*|*Cygwin* )
        ;;
    * )
        AC_CHECK_HEADERS(sys/shm.h)
        ;;
esac

AC_TYPE_LONG_LONG_INT
AC_CHECK_SIZEOF([off_t])
AC_CHECK_SIZEOF([long long int])
AC_CHECK_SIZEOF([long int])

AC_CHECK_TYPES([socklen_t], [], [], [#include <sys/socket.h>])

AC_C_CONST

AC_CHECK_FUNCS(strchr memcpy snprintf ftello fseeko setenv)

AC_CHECK_FUNC(connect)
if test $ac_cv_func_connect = no; then
  AC_CHECK_LIB(socket, connect,  EXTRA_LIBS="$EXTRA_LIBS -lsocket")
fi                                                                          
AC_CHECK_FUNC(gethostbyname)
if test $ac_cv_func_gethostbyname = no; then
  AC_CHECK_LIB(nsl, gethostbyname, EXTRA_LIBS="$EXTRA_LIBS -lnsl")
fi                                                                          

AC_C_BIGENDIAN([BIGENDIAN=1], [BIGENDIAN=0], [BIGENDIAN=1])
AC_SUBST(BIGENDIAN)

#
# checks specific to this project
# 

AC_MSG_CHECKING(for filter cc)
AC_ARG_WITH(filter-cc, [ --with-filter-cc=CC  compiler],
	FILTER_CC=\\\"$withval\\\", FILTER_CC=NULL)
AC_MSG_RESULT($FILTER_CC)
AC_SUBST(FILTER_CC)

AC_MSG_CHECKING(for filter cflags)
AC_ARG_WITH(filter-cflags, [ --with-filter-cflags=CFLAGS  compiler flags],
	FILTER_CFLAGS=\\\"$withval\\\", FILTER_CFLAGS=NULL)
AC_MSG_RESULT($FILTER_CFLAGS)
AC_SUBST(FILTER_CFLAGS)

DEFLIB="libfuntools.a"
AC_MSG_CHECKING(for alternate target library)
AC_ARG_WITH(altlib, [ --with-altlib=LIB  library name],
	alt_lib=yes LIB=$withval, alt_lib=no LIB=$DEFLIB)
AC_MSG_RESULT($alt_lib ($LIB))
AC_SUBST(LIB)
AC_SUBST(DEFLIB)

AC_MSG_CHECKING(for external zlib)
AC_ARG_WITH(zlib, [ --with-zlib=LIB  library name],
                  [ zlib=yes
                    EXTRA_LIBS="$EXTRA_LIBS $withval"
                    ZLIB_OBJS=
                  ],
                  [
                   zlib=no
                   ZLIB_OBJS='$(ZOBJS)'
                  ]
           )
AC_SUBST(ZLIB_OBJS)
AC_MSG_RESULT($zlib)

AC_MSG_CHECKING(for external wcslib)
AC_ARG_WITH(wcslib,
                [ --with-wcslib=LIB  library name],
                [wcslib=yes
                 EXTRA_LIBS=EXTRA_LIBS="$EXTRA_LIBS $withval"
                 WCS_SUBLIB=
                 ],
                 [
                 WCS_SUBLIB=wcs
                 ]
              )
AC_SUBST([WCS_SUBLIB])
AC_MSG_RESULT($wcslib)

AC_MSG_CHECKING(for shared library build)
AC_ARG_ENABLE(shared, [  --enable-shared    build shared libraries],
    [fun_ok=$enableval], [fun_ok=no])
if test "$fun_ok" != "no"; then
  fpic="yes"
  DOSHARED=shlib
  AC_SUBST(DOSHARED)
  if test "$fun_ok" = "link"; then
    AC_CHECK_LIB(dl, dlopen, have_dl=yes, have_dl=no)
    if test "$have_dl" = yes; then
      using_shlib="yes"
      fpic="yes"
      EXTRA_LIBS="$EXTRA_LIBS -ldl"  
      if test `$CC -v -rdynamic 2>&1 | grep -c unrecognized` = "0" ; then
        LDFLAGS="$LDFLAGS -rdynamic"
      fi
    else
      AC_CHECK_LIB(c, dlopen, have_dl=yes, have_dl=no)
      if test "$have_dl" = yes; then
        using_shlib="yes"
        fpic="yes"
        if test `$CC -v -rdynamic 2>&1 | grep -c unrecognized` = "0" ; then
          LDFLAGS="$LDFLAGS -rdynamic"
        fi
      else
        using_shlib="no"
      fi
    fi
    LLIB="-L. -l$PACKAGE_NAME"
  else
    LLIB='$(LIB)'
  fi
else
  LLIB='$(LIB)'
fi
AC_SUBST(LLIB)
AC_MSG_RESULT($fun_ok)

AC_MSG_CHECKING([for dynamic loading of filters ])
AC_ARG_ENABLE(dl, [  --enable-dl    allow use of dynamic loading if available],
    [fun_ok=$enableval], [fun_ok=no])
if test "$fun_ok" = "yes"; then
if test "$CC" = "gcc" -o `$CC -v 2>&1 | grep -c gcc` != "0" ; then
  using_dl="yes"
  if test x"$using_shlib" != xyes; then
    AC_CHECK_LIB(dl, dlopen, have_dl=yes, have_dl=no)
    if test "$have_dl" = yes; then
      USE_DL="-DUSE_DL=1"
      fpic="yes"
      EXTRA_LIBS="$EXTRA_LIBS -ldl"  
      if test `$CC -v -rdynamic 2>&1 | grep -c unrecognized` = "0" ; then
        LDFLAGS="$LDFLAGS -rdynamic"
      fi
    else
      AC_CHECK_LIB(c, dlopen, have_dl=yes, have_dl=no)
      if test "$have_dl" = yes; then
        USE_DL="-DUSE_DL=1"
        fpic="yes"
        if test `$CC -v -rdynamic 2>&1 | grep -c unrecognized` = "0" ; then
          LDFLAGS="$LDFLAGS -rdynamic"
        fi
      else
        using_dl="no"
      fi
    fi
  fi
else
  using_dl="no"
fi
else
using_dl="no"
fi
AC_MSG_RESULT([$using_dl ($CC)])
AC_SUBST(USE_DL)

AC_ARG_ENABLE(fpu_double, [  --enable-fpu_double    set FPU in double round mode],
    [fun_ok=$enableval], [fun_ok=no])
if test "$fun_ok" = "yes"; then
AC_MSG_CHECKING([for setting fpu in double rounding mode (with gcc) ])
if test "$CC" = "gcc" -o `$CC -v 2>&1 | grep -c gcc` != "0" ; then
  using_fpu_double="yes"
  USE_FPU_DOUBLE="1"
else
  using_fpu_double="no"
  USE_FPU_DOUBLE="0"
fi

AC_MSG_CHECKING(for request to use posix_spawn)
AC_ARG_ENABLE(posix_spawn, [  --enable-posix_spawn    use posix_spawn() if available],
    [fun_ok=$enableval], [fun_ok=no])
AC_MSG_RESULT($fun_ok)
if test "$fun_ok" = "yes"; then
  AC_CHECK_FUNCS(posix_spawn _NSGetEnviron)
  AC_CHECK_HEADERS(crt_externs.h)
fi

AC_MSG_RESULT([$using_fpu_double])
else
  USE_FPU_DOUBLE="0"
fi
AC_SUBST(USE_FPU_DOUBLE)

AC_MSG_CHECKING(for mainlib build)
DOMAINLIB=""
AC_ARG_ENABLE(mainlib, [  --enable-mainlib    build funtools mainlib support],
    [fun_ok=$enableval], [fun_ok=no])
if test "$fun_ok" = "yes"; then
  DOMAINLIB=mainlib
elif test "$fun_ok" = "shared"; then
  DOMAINLIB=shmainlib
fi
AC_SUBST(DOMAINLIB)
AC_MSG_RESULT($fun_ok)

SC_PATH_TCLCONFIG
if test x"${no_tcl}" = x ; then
    AC_DEFINE([HAVE_TCL], [1], [Define if tcl is used.])
fi

AC_PROG_AWK

AC_CHECK_PROG(gzip, gzip, gzip, none)
if test "$gzip" = "none"; then
  GUNZIP="cat"
else
  GUNZIP="$gzip -dcf"
fi

AC_CHECK_PROG(gnuplot, gnuplot, gnuplot, none)
if test "$gnuplot" = "none"; then
  GNUPLOT="NONE"
else
  GNUPLOT="$gnuplot"
fi

AC_MSG_CHECKING([$host_os configuration])
PRE=""
POST="|\& cat"
case $host_os in
    *cygwin*|*Cygwin* )
        CFLAGS="$CFLAGS -enable-auto-import"
        AC_DEFINE([HAVE_CYGWIN],[1],[Cygwin is available])
        AC_MSG_RESULT(flagging Cygwin)
	PRE="sh -c {"
	POST="}"
        ;;
    *mingw32*|*Mingw32*)
        CFLAGS="$CFLAGS -mconsole -D_WSTRING_DEFINED=1"
	EXTRA_LIBS="$EXTRA_LIBS -lwsock32"
        AC_DEFINE([HAVE_MINGW32],[1],[Mingw32 is available])
        AC_MSG_RESULT(flagging MinGW)
        ;;
    *osf*|*Osf*)
        AC_CHECK_LIB(db, snprintf, EXTRA_LIBS="$EXTRA_LIBS -ldb")
        ;;
    *darwin*|*Darwin*)
	LDFLAGS="$LDFLAGS $CFLAGS"
	CFLAGS="$CFLAGS -fno-common"
        if test x"$fpic" = x"yes" ; then
	  CFLAGS="$CFLAGS -fPIC"
          AC_MSG_RESULT([adding -fno-common, -fPIC to CFLAGS])
	else
          AC_MSG_RESULT([adding -fno-common to CFLAGS])
	fi
	;;
    * )
        if test x"$fpic" = x"yes" ; then
          if test "$CC" = "gcc" -o `$CC -v 2>&1 | grep -c gcc` != "0" ; then
	    CFLAGS="$CFLAGS -fPIC"
	    AC_MSG_RESULT(adding -fPIC to gcc)
	  else
            AC_MSG_RESULT(none)
	  fi
	else
            AC_MSG_RESULT(none)
	fi
        ;;
esac

AC_SUBST(EXTRA_LIBS)
AC_SUBST(EXTRA_OBJS)
AC_SUBST(PRE)
AC_SUBST(POST)
AC_SUBST(AWK)
AC_SUBST(GUNZIP)
AC_SUBST(GNUPLOT)
AC_SUBST(PIPEGLUE)

AC_CONFIG_FILES([
        Makefile
        util/Makefile
        util/NaN.h
        filter/Makefile
        filter/imregions.c
        filter/evregions.c
        fitsy/Makefile
        wcs/Makefile
        gnu/Makefile
        funtest/Makefile
        faq/Makefile
        ])

# generate pkg-config meta-data file
AC_CONFIG_FILES(funtools.pc)

# generate test scripts
AC_CONFIG_FILES([funtest/tevread],[chmod +x funtest/tevread])
AC_CONFIG_FILES([funtest/funtexts],[chmod +x funtest/funtexts])
AC_CONFIG_FILES([funtest/tfunimage],[chmod +x funtest/tfunimage])
AC_CONFIG_FILES([funtest/tfunview],[chmod +x funtest/tfunview])
AC_CONFIG_FILES([funtest/timev],[chmod +x funtest/timev])
AC_CONFIG_FILES([funtest/tfunhead],[chmod +x funtest/tfunhead])
AC_CONFIG_FILES([funtest/funtests],[chmod +x funtest/funtests])
AC_CONFIG_FILES([funtest/tfuncnts],[chmod +x funtest/tfuncnts])
AC_CONFIG_FILES([funtest/tfuncalc],[chmod +x funtest/tfuncalc])
AC_CONFIG_FILES([funtest/tfundisp],[chmod +x funtest/tfundisp])

AC_CONFIG_FILES([
        funtest/funtools1.vu
        funtest/funtools2.vu
        funtest/tfile.in
        funtest/tview.in
])


AC_OUTPUT
