/*
 * Maze.h
 *
 *  Created on: Mar 11, 2013
 *      Author: Erich Styger
 */

#ifndef SOURCES_INTRO_COMMON_MAZE_H_
#define SOURCES_INTRO_COMMON_MAZE_H_

#include "Platform.h"
#if PL_CONFIG_HAS_LINE_MAZE
#include "Turn.h"

/*!
 * \brief Adds a new path while going forward through the maze
 * \param kind New path to be added
 */
void MAZE_AddPath(TURN_Kind kind);

/*!
 * \brief Tries to simplify the path, basically cutting dead end paths.
 */
void MAZE_SimplifyPath(void);

/*!
 * \brief Returns TRUE if the maze has been solved (finish has been found)
 * \return TRUE if finish has been found, so maze is solved
 */
bool MAZE_IsSolved(void);

/*!
 * \brief Marks the maze as solved.
 */
void MAZE_SetSolved(void);

/*!
 * This clears the solution, and MAZE_IsSolved() will return FALSE
 */
void MAZE_ClearSolution(void);

/*!
 * \brief Used to get the solution turns, one after each other
 * \param solvedIdx Solution index, starting with zero. The callee will increment the index.
 * \return Solution turn
 */
TURN_Kind MAZE_GetSolvedTurn(uint8_t *solvedIdx);

/*!
 * \brief Selects the new turn based.
 * \param prev Line previous the intersection
 * \param curr Line kind of the intersection.
 * \return The new turn.
 */
TURN_Kind MAZE_SelectTurn(REF_LineKind prev, REF_LineKind curr, bool rule);

/*!
 * \brief Performs a turn.
 * \return Returns TRUE while turn is still in progress.
 * \param finished Set to TRUE if we have reached the finish area
 */
uint8_t MAZE_EvaluteTurn(bool *finished, bool rule);

void MAZE_RevertPath(void);

#if PL_CONFIG_HAS_SHELL
#include "CLS1.h"
/*!
 * \brief Module command line parser
 * \param cmd Pointer to command string to be parsed
 * \param handled Set to TRUE if command has handled by parser
 * \param io Shell standard I/O handler
 * \return Error code, ERR_OK if everything was ok
 */
uint8_t MAZE_ParseCommand(const unsigned char *cmd, bool *handled, const CLS1_StdIOType *io);
#endif

/*!
 * \brief Module de-initialization.
 */
void MAZE_Deinit(void);

/*!
 * \brief Module initialization.
 */
void MAZE_Init(void);

#endif /* PL_HAS_LINE_SENSOR */

#endif /* SOURCES_INTRO_COMMON_MAZE_H_ */
