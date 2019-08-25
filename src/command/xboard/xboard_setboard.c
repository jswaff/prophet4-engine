#include <prophet/error_codes.h>
#include <prophet/position/position.h>

#include <stdio.h>
#include <string.h>

extern position_t gpos;

/**
 * \brief Execute the xboard setboard command 
 * 
 * \param input         the user entered input 
 *
 * \return 0 on successful execution, and non-zero on failure
 */
int xboard_setboard(const char* input)
{
    /* verify the command */
    if (0 != strncmp("setboard", input, 8))
    {
        return P4_ERROR_CMD_INCORRECT_COMMAND;
    }

    /* is the command long enough to contain a valid FEN? The shortest possible
     * valid FEN would be a board with two kings, e.g. k7/8/8/8/8/8/8/K8 w - - 
     * (leaving off the half move clock and full move number), so min 23 characters
     * in addition to the command itself.
     */
    if (strlen(input) < 32)
    {
        return P4_ERROR_CMD_XBOARD_USERMOVE_MISSING_FEN;   
    }

    /* set the board */
    position_t savepos;
    memcpy(&savepos, &gpos, sizeof(position_t));
    if (!set_pos(&savepos, input + 9))
    {
        printf("tellusererror Illegal position\n");
        return P4_ERROR_CMD_XBOARD_USERMOVE_INVALID_FEN;
    }

    /* success - set the game position */
    memcpy(&gpos, &savepos, sizeof(position_t));

    return 0;
}
