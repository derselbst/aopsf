/////////////////////////////////////////////////////////////////////////////
//
// r3000dis - R3000 disassembler
//
/////////////////////////////////////////////////////////////////////////////

#ifndef __PSX_R3000DIS_H__
#define __PSX_R3000DIS_H__

#include "spu/emuconfig.h"

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////////////////////
//
// Returns:
// 0 on success
// 1 on success + there's a delay slot too
// negative on failure
// dest must have 256 bytes available
//
sint32 EMU_CALL r3000dis(char *dest, uint32 rich, uint32 pc, uint32 ins);

/////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif
