/*
===========================================================================
Copyright (C) 1999-2005 Id Software, Inc.

This file is part of Quake III Arena source code.

Quake III Arena source code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

Quake III Arena source code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Quake III Arena source code; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/
//
/*
=======================================================================

CREDITS

=======================================================================
*/


#include "ui_local.h"


typedef struct {
	menuframework_s	menu;
	int frame;
} creditsmenu_t;

static creditsmenu_t	s_credits;


/*
===============
UI_CreditMenu_Draw_ioq3
===============
*/
static void UI_CreditMenu_Draw_ekron( void ) {
	int		y;
	int		i;

	// These are all people that have made commits to Subversion, and thus
	//  probably incomplete.
	// (These are in alphabetical order, for the defense of everyone's egos.)
	static const char *names[] = {
		"Pedro Dias Vicente",
		"Luis Manuel Vicente",
		NULL
	};

	// Center text vertically on the screen
	y = (SCREEN_HEIGHT - ARRAY_LEN(names) * (1.42 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE)) / 2;

	UI_DrawProportionalString( 320, y, "ekron contributors:", UI_CENTER|UI_SMALLFONT, color_white );
	y += 1.42 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;

	for (i = 0; names[i]; i++) {
		UI_DrawProportionalString( 320, y, names[i], UI_CENTER|UI_SMALLFONT, color_white );
		y += 1.42 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	}

	UI_DrawString( 320, 459, "https://www.gleentech.com/", UI_CENTER|UI_SMALLFONT, color_red );
}


/*
=================
UI_CreditMenu_Key
=================
*/
static sfxHandle_t UI_CreditMenu_Key( int key ) {
	if( key & K_CHAR_FLAG ) {
		return 0;
	}

	s_credits.frame++;
	if (s_credits.frame == 1) {
		s_credits.menu.draw = UI_CreditMenu_Draw_ekron;
	} else {
		trap_Cmd_ExecuteText( EXEC_APPEND, "quit\n" );
	}
	return 0;
}


/*
===============
UI_CreditMenu_Draw
===============
*/
static void UI_CreditMenu_Draw( void ) {
	int		y;

	y = 12;
	UI_DrawProportionalString( 320, y, "Gleentech is:", UI_CENTER|UI_SMALLFONT, color_white );

	y += 1.42 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	UI_DrawProportionalString( 320, y, "Programming", UI_CENTER|UI_SMALLFONT, color_white );
	y += PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	UI_DrawProportionalString( 320, y, "Pedro Dias Vicente, Luis Manuel Vicente", UI_CENTER|UI_SMALLFONT, color_white );

	y += 1.42 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	UI_DrawProportionalString( 320, y, "Art", UI_CENTER|UI_SMALLFONT, color_white );
	y += PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	UI_DrawProportionalString( 320, y, "Pedro Dias Vicente,", UI_CENTER|UI_SMALLFONT, color_white );
	/*y += PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	UI_DrawProportionalString( 320, y, "Pedro Dias Vicente", UI_CENTER|UI_SMALLFONT, color_white );*/

	y += 1.42 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	UI_DrawProportionalString( 320, y, "Game Designer", UI_CENTER|UI_SMALLFONT, color_white );
	y += PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	UI_DrawProportionalString( 320, y, "Pedro Dias Vicente", UI_CENTER|UI_SMALLFONT, color_white );

	y += 1.42 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	UI_DrawProportionalString( 320, y, "Level Design", UI_CENTER|UI_SMALLFONT, color_white );
	y += PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	UI_DrawProportionalString( 320, y, "Pedro Dias Vicente, Luis Manuel Vicente", UI_CENTER|UI_SMALLFONT, color_white );

	y += 1.42 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	UI_DrawProportionalString( 320, y, "CEO", UI_CENTER|UI_SMALLFONT, color_white );
	y += PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	UI_DrawProportionalString( 320, y, "Luis Manuel Vicente", UI_CENTER|UI_SMALLFONT, color_white );

	y += 1.42 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	UI_DrawProportionalString( 320, y, "Director of Business Development", UI_CENTER|UI_SMALLFONT, color_white );
	y += PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	UI_DrawProportionalString( 320, y, "Pedro Dias Vicente", UI_CENTER|UI_SMALLFONT, color_white );


	y += 1.35 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	UI_DrawString( 320, y, "To order: +351-931308134     www.gleentech.com     www.pedrolvicente.kreatyve.com", UI_CENTER|UI_SMALLFONT, color_red );
	y += SMALLCHAR_HEIGHT;
	UI_DrawString( 320, y, "Ekron Roads Deep(c) 2014-2019, Gleentech, Inc.  All Rights Reserved", UI_CENTER|UI_SMALLFONT, color_red );
}


/*
===============
UI_CreditMenu
===============
*/
void UI_CreditMenu( void ) {
	memset( &s_credits, 0 ,sizeof(s_credits) );

	s_credits.menu.draw = UI_CreditMenu_Draw;
	s_credits.menu.key = UI_CreditMenu_Key;
	s_credits.menu.fullscreen = qtrue;
	UI_PushMenu ( &s_credits.menu );
}
