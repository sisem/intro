/*
 * LineFollow.h
 *
 *  Created on: Feb 15, 2013
 *      Author: Erich Styger
 */

#ifndef SOURCES_INTRO_COMMON_LINEFOLLOW_H_
#define SOURCES_INTRO_COMMON_LINEFOLLOW_H_

#include "Platform.h"
#if PL_CONFIG_HAS_LINE_FOLLOW

#if PL_CONFIG_HAS_SHELL
#include "CLS1.h"

uint8_t LF_ParseCommand(const unsigned char *cmd, bool *handled, const CLS1_StdIOType *io);
#endif

void LF_SetRule(bool newRule);
void LF_StartFollowing(void);
void LF_StopFollowing(void);
void LF_StartStopFollowing(void);
bool LF_IsFollowing(void);

void LF_Init(void);
void LF_Deinit(void);

#endif /* PL_CONFIG_HAS_LINE_FOLLOW */

#endif /* SOURCES_INTRO_COMMON_LINEFOLLOW_H_ */
