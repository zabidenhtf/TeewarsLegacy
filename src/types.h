/* copyright (c) 2026 mykyta polishyk, see LICENSE file for more info */

#ifndef TYPES_H
#define TYPES_H

// Menu state
enum menu_state{
	serverlist = 0, // Servers list
	online, // Nothing, because player ingame
	pausemenu // Pause menu
};

// Player state
enum player_state{
	walk_left = 0,
	walk_right,
	idle_left,
	idle_right,
	fall_left,
	fall_right
};

#endif
