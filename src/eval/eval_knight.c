#include <prophet/parameters.h>

#include "eval_internal.h"

#include  <assert.h>

/**
 * \brief Evaluate a single knight.
 *
 * \param pos           a pointer to a chess position
 * \param sq            the square the knight is on
 * \param mgscore       a pointer to the middle game score accumulator
 * \param egscore       a pointer to the endgame score accumulator
 *
 */
void eval_knight(const position_t* pos, square_t sq, int32_t* mgscore, int32_t* egscore)
{
    assert(pos->piece[sq] == KNIGHT || pos->piece[sq] == -KNIGHT);

    if (is_white_piece(pos->piece[sq]))
    {
        uint32_t d = distance(sq, pos->black_king);
        *mgscore += knight_pst[sq] + knight_tropism * d;
        *egscore += knight_endgame_pst[sq] + knight_tropism_endgame * d;
    }
    else
    {
        int32_t flipsq = flip_rank[sq];
        uint32_t d = distance(sq, pos->white_king);
        *mgscore -= knight_pst[flipsq] + knight_tropism * d;
        *egscore -= knight_endgame_pst[flipsq] + knight_tropism_endgame * d;
    }


}
