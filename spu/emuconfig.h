/////////////////////////////////////////////////////////////////////////////
//
// Configuration for emulation libraries
//
/////////////////////////////////////////////////////////////////////////////

#ifndef __EMUCONFIG_H__
#define __EMUCONFIG_H__

/////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>

/////////////////////////////////////////////////////////////////////////////
//
// One of these has to be defined when compiling the library.
// Shouldn't be necessary for using it.
//
#if defined(EMU_COMPILE) && !defined(EMU_BIG_ENDIAN) && !defined(EMU_LITTLE_ENDIAN)
#error "Hi I forgot to set EMU_x_ENDIAN"
#endif
#if defined(EMU_COMPILE) && defined(EMU_BIG_ENDIAN) && defined(EMU_LITTLE_ENDIAN)
#error "Both byte orders should not be defined"
#endif

/////////////////////////////////////////////////////////////////////////////
//
// WIN32 native project definitions
//
/////////////////////////////////////////////////////////////////////////////
#if defined(WIN32) && !defined(__GNUC__)

#define EMU_CALL   __fastcall
#define EMU_CALL_  __cdecl
#define EMU_INLINE __inline

/////////////////////////////////////////////////////////////////////////////
//
// LINUX / other platform definitions
//
/////////////////////////////////////////////////////////////////////////////
#else

//#if defined(__GNUC__) && defined(__i386__)
//#define EMU_CALL __attribute__((__regparm__(2)))
//#else
#define EMU_CALL
//#endif

#define EMU_CALL_
#define EMU_INLINE __inline

#endif

#ifdef EMU_BIG_ENDIAN
#define EMU_ENDIAN_XOR_L2H(x) (x)
#define EMU_ENDIAN_XOR_B2H(x) (0)
#else
#define EMU_ENDIAN_XOR_L2H(x) (0)
#define EMU_ENDIAN_XOR_B2H(x) (x)
#endif

// deprecated
#define EMU_ENDIAN_XOR(x) EMU_ENDIAN_XOR_L2H(x)

/////////////////////////////////////////////////////////////////////////////

#endif
