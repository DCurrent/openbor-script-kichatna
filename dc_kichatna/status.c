#include "data/scripts/dc_kichatna/config.h"

// Return true (1) if target entity is
// falling and not invincible. Otherwise
// returns false (0).
int dc_kichatna_status()
{
    int     elapsed_time;       // Engine timer.
    int     result;             // Final result.
    void    target;             // Target entity.
    int     status_falling;     // Falling flag.
    int     status_invinctime;  // Currently invincible?

    // Default false result.
    result = 0;

    // Get our target entity.
    target = getlocalvar(DC_KICHATNA_TARGET);

    // Exit if no target entity given.
    if(!target) return result;

    // Get the status we'll need from the engine
    // and our target entity.
        elapsed_time        = openborvariant("elapsed_time");
        status_falling      = getentityproperty(target, "aiflag", "falling");

        // The invinctime property returns a blank
        // if not set, so add a 0 to force int value.
        status_invinctime   = 0 + getentityproperty(vSelf, "invinctime");

    // Is target falling?
    if (status_falling)
	{
	    // Is target NOT invincible?
	    if(status_invinctime < elapsed_time)
        {
            // We can return true..
            result = 1;
        }
	}

	return result;
}
