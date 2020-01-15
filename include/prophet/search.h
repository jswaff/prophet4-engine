#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <prophet/position/position.h>
#include <stdint.h>


// make this header C++ friendly.
#ifdef     __cplusplus
extern "C" {
#endif    //__cplusplus


/**
 * \brief Search the position to a fixed depth.
 *
 * \param pos           a pointer to a chess position
 * \param depth         the depth to search to
 * \param alpha         the lower bound
 * \param beta          the upper bound
 * 
 * \return the score
 */
int32_t search(const position_t* pos, int32_t depth, int32_t alpha, 
    int32_t beta);


// make this header C++ friendly.
#ifdef     __cplusplus
}
#endif    //__cplusplus

#endif /* ! defined _SEARCH_H_ */
