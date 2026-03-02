/* copyright (c) 2007 magnus auvinen, see licence.txt for more info */
/* copyright (c) 2026 mykyta polishyk, see LICENSE file for more info */

#ifndef GAME_MAPRES_COL_H
#define GAME_MAPRES_COL_H

enum{
	SOLID=0,
	NOT_SOLID
};

void ColInit(Map object);
int ColIsSolid(int x, int y);
bool ColIntersectLine(int x0, int y0, int x1, int y1, int *outx, int *outy);

#endif
