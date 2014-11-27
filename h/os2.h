#ifdef __cplusplus
      extern "C" {
#endif

#ifndef __OS2_H__

/* NOINC */
#define __OS2_H__
/* INC */

#define OS2_INCLUDED

/* Common definitions */
#include <os2def.h>

/* OS/2 Base Include File */
#ifndef INCL_NOBASEAPI
   #include <bse.h>
#endif /* INCL_NOBASEAPI */

/* OS/2 Presentation Manager Include File */
#ifndef INCL_NOPMAPI
//   #include <pm.h>
#endif /* INCL_NOPMAPI */

#endif /* __OS2__ */

#ifdef __cplusplus
        }
#endif
