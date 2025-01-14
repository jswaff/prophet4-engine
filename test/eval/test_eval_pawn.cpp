#include "eval/eval_internal.h"

#include "prophet/position.h"

#include <gtest/gtest.h>

#include <stdint.h>

TEST(eval_test, eval_pawn)
{
    position_t pos;
    reset_pos(&pos);

    /* test the piece square term */
    int32_t mg = 0; int32_t eg = 0;
    eval_pawn(&pos, E2, &mg, &eg);
    EXPECT_EQ(pawn_pst_mg[E2], mg);
    EXPECT_EQ(pawn_pst_eg[E2], eg);

    /* test the symmetry */
    int32_t mg2 = 0; int32_t eg2 = 0;
    eval_pawn(&pos, E7, &mg2, &eg2);
    EXPECT_EQ(mg, -mg2);
    EXPECT_EQ(eg, -eg2);
}


TEST(eval_test, eval_pawn_wiki3)
{
    position_t pos;

    ASSERT_TRUE(
        set_pos(&pos,"8/8/1PP2PbP/3r4/8/1Q5p/p5N1/k3K3 b - - 0 1"));

    /*
    - - - - - - - -
    - - - - - - - -
    - P P - - P b P    black to move
    - - - r - - - -    no ep
    - - - - - - - -    no castling rights
    - Q - - - - - p
    p - - - - - N -
    k - - - K - - -
    */

    /* the white pawn on B6 is passed */
    int32_t mg = 0; int32_t eg = 0;
    eval_pawn(&pos, B6, &mg, &eg);
    EXPECT_EQ(pawn_pst_mg[B6] + passed_pawn_mg[2], mg);
    EXPECT_EQ(pawn_pst_eg[B6] + passed_pawn_eg[2], eg);


    /* the black pawn on A2 is passed and isolated */
    int32_t mg2 = 0; int32_t eg2 = 0;
    eval_pawn(&pos, A2, &mg2, &eg2);
    EXPECT_EQ(-pawn_pst_mg[A7] - passed_pawn_mg[1] - isolated_pawn_mg, mg2);
    EXPECT_EQ(-pawn_pst_eg[A7] - passed_pawn_eg[1] - isolated_pawn_eg, eg2);
}
