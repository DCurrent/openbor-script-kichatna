#ifndef DC_KICHATNA
#define DC_KICHATNA 1

// Status flags so we can decide how to react to
// different conditions. If a new item is added,
// it should be double the previous item
// value (1, 2, 4, 8, 16, ...). This is so
// we can use bitwise operators to verify
// more than one condition at once.
#define DC_KICHATNA_CONDITION_FALLING      1
#define DC_KICHATNA_CONDITION_INVINCIBLE   2
#define DC_KICHATNA_CONDITION_PROJECTILE   4

#define DC_KICHATNA_DEFAULT_DAMAGE_INVINCIBLE_TIME_ADD  20
#define DC_KICHATNA_DEFAULT_DAMAGE_FORCE_MUTIPLIER      3
#define DC_KICHATNA_DEFAULT_DAMAGE_VELOCITY_X_MUTIPLIER 0.25
#define DC_KICHATNA_DEFAULT_DAMAGE_VELOCITY_Y_MUTIPLIER 1

#define DC_KICHATNA_TARGET "dc_kichatna_0"

#endif
