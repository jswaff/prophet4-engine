#ifndef _EVAL_H_
#define _EVAL_H_

#include <prophet/position/position.h>


// make this header C++ friendly.
#ifdef     __cplusplus
extern "C" {
#endif    //__cplusplus


/*
BISHOP_PAIR=61
PAWN_VAL=100
ROOK_VAL=608
KNIGHT_VAL=426
QUEEN_VAL=1114
BISHOP_VAL=386
*/

static const int32_t pawn_val = 100;
static const int32_t knight_val = 426;
static const int32_t bishop_val = 386;
static const int32_t bishop_pair = 61;
static const int32_t rook_val = 608;
static const int32_t queen_val = 1114;

/**
 * \brief Evaluate a chess position for the side to move.
 *
 * Performs a static analysis of a chess position.  The score is primarily
 * influenced by material counts, but it also takes into account several
 * well known heuristics, such as king safety, passed pawns, isolated
 * pawns, rooks on open files, and several others.  
 *
 * This method will not detect end-of-game scenarios such as checkmate.
 *
 * \param pos             a pointer to a chess position
 * \param material_only   if the evaluation should consider material only
 *
 * \return the score.
 */
int32_t eval(const position_t* pos, bool material_only);


/**
 * \brief Evaluate the position's non-pawn material.
 *
 * \param pos           a pointer to a chess position
 * \param for_white     whether the returned value should be for white
 *
 * \return the score.
 */
int32_t eval_nonpawn_material(const position_t* pos, bool for_white);


/**
 * \brief Evaluate the position's pawn material.
 *
 * \param pos           a pointer to a chess position
 * \param for_white     whether the returned value should be for white
 *
 * \return the score.
 */
int32_t eval_pawn_material(const position_t* pos, bool for_white);



// make this header C++ friendly.
#ifdef     __cplusplus
}
#endif    //__cplusplus

#endif /* ! defined _EVAL_H_ */
