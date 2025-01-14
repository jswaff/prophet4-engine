#include "prophet/position.h"

#include <stdlib.h>
#include <time.h>

bool initialized = false;

extern void init_logging();
extern void init_bitmap_lsb_msb();
extern void init_bitmap_file_rank();
extern void init_bitmap_ray();
extern void init_squares();
extern void init_zkeys();

extern void init_king_movegen();
extern void init_knight_movegen();
extern void init_bishop_movegen();
extern void init_rook_movegen();

extern void init_outpost();
extern void init_pawn_attacked();
extern void init_pawn_isolated();
extern void init_pawn_passed();

extern int init_hash_tables();

extern position_t gpos;


/**
 * \brief Initialize the program.
 *
 * \return 0 on successful execution, and non-zero on failure.
 */
int init()
{
    int retval = 0;

    if (!initialized) {
        /* initialize the random number generator */
        srand(time(0));

        init_logging();
        init_bitmap_lsb_msb();
        init_bitmap_file_rank();
        init_squares();
        init_zkeys();
        init_bishop_movegen();
        init_king_movegen();
        init_knight_movegen();
        init_rook_movegen();
        init_pawn_isolated();
        init_bitmap_ray();
        init_outpost();
        init_pawn_attacked();
        init_pawn_passed();
        retval = init_hash_tables();
        if (0 != retval) {
            goto bailout;
        }
        
        reset_pos(&gpos);
    }

    initialized = true;

bailout:

    return retval;
}
