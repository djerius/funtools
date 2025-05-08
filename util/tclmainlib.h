#include <mainlib.h>

#if HAVE_TCL

/* name of tcl procedure */
#include <tcl.h>

#define TCL_MAINLIB_NAME     "mainlib"

/* library declarations */

int MainLibInit_Tcl (MainLib ml);

int MainLibLookup_Tcl (void *vinterp, char *s);

int MainLibEval_Tcl   (void *vinterp, char *s);

int MainLibProcess_Tcl (ClientData clientData, Tcl_Interp *interp,
			     int objc, Tcl_Obj *CONST objv[]);

int MainLibProcessCleanup_Tcl (ClientData clientData, Tcl_Interp *interp,
				    int objc, Tcl_Obj *CONST objv[]);

int MainLibLoad_Tcl (ClientData clientData, Tcl_Interp *interp,
			  int objc, Tcl_Obj *CONST objv[]);


#endif

