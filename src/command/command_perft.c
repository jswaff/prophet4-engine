#include "command.h"

#include "prophet/error_codes.h"
#include "prophet/position.h"

#include "movegen/movegen_internal.h"
#include "util/output.h"
#include "util/time.h"

#include <inttypes.h>
#include <stdint.h>
#include <string.h>

extern position_t gpos;

/**
 * \brief Execute the perft command.
 * 
 * Command should be in the format "perft D", where D is depth.  The perft is
 * executed iteratively, starting with depth=1 and ending with depth=D.
 * The number of nodes and nodes-per-second are printed to stdout for each
 * iteration.
 *
 * \param input         the user entered input 
 *
 * \return 0 on successful execution, and non-zero on failure
 */
int command_perft(const char* input)
{
    /* verify the command */
    if (0 != strncmp("perft", input, 5)) {
        return P4_ERROR_CMD_INCORRECT_COMMAND;
    }

    int depth;

    /* advance the base command pointer past the "perft " substring */
    if (1 != sscanf(input + 6, "%d", &depth)) {
        return P4_ERROR_CMD_PERFT_DEPTH;
    }


    plog("running perft depth %d.\n", depth);
    for (int i=1; i <= depth; i++) {
        uint64_t start_time = milli_timer();
        uint64_t nodes = perft(&gpos, i);
        uint64_t elapsed = milli_timer() - start_time;
        plog("depth %d - nodes: %" PRIu64 " - rate: %" PRIu64 " kn/s\n", 
            i, nodes, nodes / (elapsed+1)); /* avoid div by 0 */
    }

    return 0;
}
