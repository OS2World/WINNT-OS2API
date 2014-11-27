#ifdef __cplusplus
      extern "C" {
#endif

#ifndef __OS2DEF__
/* NOINC */
#define __OS2DEF__
/* INC */

#define OS2DEF_INCLUDED



/* NOINC */
#define FAR         /* this will be deleted shortly */
#define NEAR        /* this will be deleted shortly */

#if defined(__IBMC__) || defined(__IBMCPP__) || defined(__WATCOMC__)
#define APIENTRY    _System
#else
   #define APIENTRY
#endif
#if defined(__IBMC__) || defined(__IBMCPP__) || defined(__WATCOMC__)
#define EXPENTRY    _System
#else
   #define EXPENTRY
   #define _Seg16
   #define _Far16
   #define _Pascal
   #define _Optlink
   #define _optlink
   #define _Cdecl
   #define _cdecl
   typedef unsigned long DWORD;
#endif

#define APIENTRY16  _Far16 _Pascal
#define PASCAL16    _Far16 _Pascal
#define CDECL16     _Far16 _Cdecl

#define VOID        void
/* INC */

typedef unsigned long  APIRET;
typedef unsigned short APIRET16;
typedef unsigned long  APIRET32;

#ifndef FALSE
   #define FALSE   0
#endif

#ifndef TRUE
   #define TRUE    1
#endif

#ifndef NULL
   #ifdef __cplusplus
      #define NULL 0
   #else
     #define NULL ((void *)0)
   #endif
#endif

typedef unsigned short   SHANDLE;
typedef unsigned long    LHANDLE;

#define NULLHANDLE    ( (LHANDLE) 0)
#define NULLSHANDLE   ( (SHANDLE) 0)

/* NOINC */
#define CHAR    char            /* ch  */
#define SHORT   short           /* s   */
#define LONG    long            /* l   */

#ifndef INCL_SAADEFS
   #define INT  int             /* i   */
#endif /* !INCL_SAADEFS */
/* INC */

typedef unsigned char  UCHAR;   /* uch */
typedef unsigned short USHORT;  /* us  */
typedef unsigned long  ULONG;   /* ul  */

#ifndef INCL_SAADEFS
   typedef unsigned int UINT;   /* ui  */
#endif /* !INCL_SAADEFS */

typedef UCHAR     * _Seg16 PUCHAR16;
typedef CHAR      * _Seg16 PCHAR16;

typedef char BYTE;     /* b   */

typedef char *PSZ;
typedef char *NPSZ;

typedef char *PCH;
typedef char *NPCH;
typedef const char *PCSZ;

typedef int ( APIENTRY _PFN)  ();
typedef _PFN    *PFN;
typedef int ( APIENTRY _NPFN)  ();
typedef _NPFN   *NPFN;


typedef BYTE *PBYTE;
typedef BYTE *NPBYTE;

typedef CHAR *PCHAR;
typedef SHORT *PSHORT;
typedef LONG *PLONG;

#ifndef INCL_SAADEFS
   typedef INT *PINT;
#endif /* !INCL_SAADEFS */

typedef UCHAR *PUCHAR;
typedef USHORT *PUSHORT;
typedef ULONG *PULONG;

#ifndef INCL_SAADEFS
   typedef UINT *PUINT;
#endif /* !INCL_SAADEFS */

typedef VOID   *PVOID;
typedef PVOID  *PPVOID;
typedef VOID   * _Seg16  PVOID16;

typedef unsigned long BOOL;     /* f   */
typedef BOOL *PBOOL;

typedef unsigned short  BOOL16;
typedef BOOL16     * _Seg16 PBOOL16;

/* NOINC */
#define BOOL32    BOOL
#define PBOOL32   PBOOL
/* INC */

/* Quad-word */
/* NOINC */
typedef struct _QWORD          /* qword */
{
   ULONG   ulLo;
   ULONG   ulHi;
} QWORD;
typedef QWORD *PQWORD;
/* INC */

#ifndef INCL_SAADEFS
   typedef unsigned short SEL;     /* sel */
   typedef SEL *PSEL;

   /*** Useful Helper Macros */

   /* Create untyped far pointer from selector and offset */
   #define MAKEP( sel,off ) (( void * )( void * _Seg16 )( (sel) << 16 | (off) ))
   #define MAKE16P( sel,off ) (( void * _Seg16 )( (sel) << 16 | (off) ))

   /* Extract selector or offset from far pointer */
   /* Warning:the selectorof macro should not be used*/
   /* for 32 bit objects                             */
   #define SELECTOROF(ptr)     ((((ULONG)(ptr))>>13)|7)
   #define OFFSETOF(p)         (((PUSHORT)&(p))[0])
#endif  /* !INCL_SAADEFS */

/* Cast any variable to an instance of the specified type. */
#define MAKETYPE(v, type)   (*((type *)&v))

/* Calculate the byte offset of a field in a structure of type type. */
#define FIELDOFFSET(type, field)    ((SHORT)&(((type *)0)->field))

/* Combine l & h to form a 32 bit quantity. */
#define MAKEULONG(l, h)  ((ULONG)(((USHORT)(l)) | ((ULONG)((USHORT)(h))) << 16))
#define MAKELONG(l, h)   ((LONG)MAKEULONG(l, h))

/* Combine l & h to form a 16 bit quantity. */
#define MAKEUSHORT(l, h) (((USHORT)(l)) | ((USHORT)(h)) << 8)
#define MAKESHORT(l, h)  ((SHORT)MAKEUSHORT(l, h))

/* Extract high and low order parts of 16 and 32 bit quantity */
#define LOBYTE(w)       LOUCHAR(w)
#define HIBYTE(w)       HIUCHAR(w)
#define LOUCHAR(w)      ((UCHAR)(w))
#define HIUCHAR(w)      ((UCHAR)(((USHORT)(w) >> 8) & 0xff))
#define LOUSHORT(l)     ((USHORT)((ULONG)l))
#define HIUSHORT(l)     ((USHORT)(((ULONG)(l) >> 16) & 0xffff))

/*** Common Error definitions ****/

typedef ULONG ERRORID;  /* errid */
typedef ERRORID *PERRORID;

/* Combine severity and error code to produce ERRORID */
#define MAKEERRORID(sev, error) (ERRORID)(MAKEULONG((error), (sev)))

/* Extract error number from an errorid */
#define ERRORIDERROR(errid)            (LOUSHORT(errid))

/* Extract severity from an errorid */
#define ERRORIDSEV(errid)              (HIUSHORT(errid))

/* Severity codes */
#define SEVERITY_NOERROR                    0x0000
#define SEVERITY_WARNING                    0x0004
#define SEVERITY_ERROR                      0x0008
#define SEVERITY_SEVERE                     0x000C
#define SEVERITY_UNRECOVERABLE              0x0010

/* Base component error values */

#define WINERR_BASE     0x1000  /* Window Manager                  */
#define GPIERR_BASE     0x2000  /* Graphics Presentation Interface */
#define DEVERR_BASE     0x3000  /* Device Manager                  */
#define SPLERR_BASE     0x4000  /* Spooler                         */

/*** Common types used across components */

/*** Common DOS types */

typedef LHANDLE HMODULE;        /* hmod */
typedef LHANDLE PID;            /* pid  */
typedef LHANDLE TID;            /* tid  */

#ifndef INCL_SAADEFS
   typedef USHORT  SGID;        /* sgid */
#endif  /* !INCL_SAADEFS */

typedef HMODULE *PHMODULE;
typedef PID *PPID;
typedef TID *PTID;

#ifndef INCL_SAADEFS
   #ifndef __HSEM__
/* NOINC */
       #define __HSEM__
/* INC */
       typedef VOID *HSEM;      /* hsem */
       typedef HSEM *PHSEM;
   #endif
#endif  /* !INCL_SAADEFS */

/* structure for Device Driver data */

typedef struct _DRIVDATA       /* driv */
{
   LONG    cb;
   LONG    lVersion;
   CHAR    szDeviceName[32];
   CHAR    abGeneralData[1];
} DRIVDATA;
typedef DRIVDATA *PDRIVDATA;

#endif /* __OS2DEF__ */

#ifdef __cplusplus
        }
#endif
