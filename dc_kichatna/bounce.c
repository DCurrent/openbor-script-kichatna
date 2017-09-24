#include "data/scripts/dc_kichatna/config.h"

int dc_kichatna_bounce(void target)
{
    int     elapsed_time;       // Engine timer.
    int     damage_direction;   // Direction to apply on impact.
    int     damage_force;       // Damage to apply.
    float   damage_velocity_X;  // Velocity to apply, X.
    float   damage_velocity_Y;  // Velocity to apply, Y.
    float   damage_velocity_Z;  // Velocity to apply, Z.
    int     result;             // Final result.
    void    status_opponent;    // Last interaction
    float   status_velocity_X;  // Velocity on impact, X.
    float   status_velocity_Y;  // Velocity on impact, X.
    float   status_velocity_Z;  // Velocity on impact, X.

    // Exit if no target entity given.
    if(!target) return result;

    status_velocity_X = getentityproperty(vSelf, "xdir");
    status_velocity_Y = getentityproperty(vSelf, "tossv");
    status_velocity_Z = getentityproperty(vSelf, "zdir");


    iXDir		= getentityproperty(vSelf, "xdir");											//Get current X velocity.
    vOpponent	= getentityproperty(vSelf, "opponent");										//Get last interaction.

	changeentityproperty(vSelf, "invinctime", iITime+20+iETime);

    if (iXDir >= 0)																			//Moving Right?
    {
        iDir	= 2;																		//Set facing right.
        iXVel	= -1.5;																		//Set movement left.
        iDamage	+= (iXDir * 3);																//Set damage (Velocity * 3).
    }
    else																					//Moving left.
    {
        iDir	= -2;																		//Set facing left.
        iXVel	= 1.5;																		//Set movement right.
        iDamage += ((-iXDir) * 3);															//Set damage (Resigned velocity * 3).
    }

    bind0008("fl_body", "fl_body", 0, 1, 0, 0, 0, 0, 0, 0, 1);								//Spawn flash.
    dama0001(vSelf, iDamage, 100, openborconstant("ATK_NORMAL"), iDir, 0, 0, 0, 0, 0, 0);	//Apply damage to self.

    changeentityproperty(vSelf, "animation", openborconstant("ANI_FALL"));					//Reset fall.
    tossentity(vSelf, 2.5, iXVel, 0);
}
