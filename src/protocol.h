/* copyright (c) 2026 mykyta polishyk, see LICENSE file for more info */
#ifndef PROTOCOL_H
#define PROTOCOL_H

/* Network input struct */
struct input{
	int left;
	int right;
	int angle;
	int jump;
	int fire;
	int hook;
	int activeweapon;
};

/* Vertex of vertex map system, also this is like float, but 1 is 32/32 */
struct map_vertex{
	int x,y;
};

/* Map object like pickup and etc */
struct map_object{
	int x,y;
	int type;
};

enum{
	ITEM_NULL = 0,
	WEAPON_GUN,
	WEAPON_SHOTGUN,
	WEAPON_RIFLE,
	WEAPON_GRENADE,
	WEAPON_MELEE,
	ARMOR_1,
	ARMOR_5,
	ARMOR_10,
	HEALTH_1,
	HEALTH_5,
	HEALTH_10
};

#endif