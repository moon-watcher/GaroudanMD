/* showpstart */
/* Show "Press Start" screen */

# include <genesis.h>
# include <res/rescomp.h>

void show_pstart(u32 highscore) {

	u16 exit = 0;
	s16 mov = 0;
	char highstr[5];
	u16 offpstart = 0;
	u16 countoff = 0;

	Sprite titlespr[1]; /* Title sprite */

	if (IS_PALSYSTEM) /* It's a PAL system, 50 Hz */
		offpstart = 25; /* 0.5 seconds */
	else
		offpstart = 30; /* 0.5 seconds */

	VDP_clearPlan (APLAN,0); /* Cleaning plan A & B */
	VDP_clearPlan (BPLAN,0);

	uintToStr(highscore,highstr,1); /* Transform number to char */

	VDP_setEnable(FALSE); /* Shutdown VDP */
	VDP_drawImageEx(BPLAN,&backstart,TILE_ATTR_FULL(PAL0,FALSE,FALSE,FALSE,TILE_USERINDEX),0,0,1,1); /* Load background */
	VDP_setPalette(PAL1,titlepal.data); /* PAL1 loaded */
	SPR_initSprite(&titlespr[0],&titlestart,48,38,TILE_ATTR(PAL1,FALSE,FALSE,FALSE)); /* Load sprite file */
	VDP_drawTextBG(APLAN,"HIGH-SCORE:",TILE_ATTR(PAL2,FALSE,FALSE,FALSE),11,1); /* Show text */
	VDP_drawTextBG(APLAN,highstr,TILE_ATTR(PAL2,FALSE,FALSE,FALSE),23,1); /* Show actual HighScore */
	VDP_drawTextBG(APLAN,"PRESS START",TILE_ATTR(PAL2,FALSE,FALSE,FALSE),14,18); /* Remember Sonic Team fail in Sonic1 with this text? :) */
	VDP_drawTextBG(APLAN,"A GAME BY LOCOMALITO",TILE_ATTR(PAL2,FALSE,FALSE,FALSE),9,23); /* The creator of this game */
	VDP_drawTextBG(APLAN,"MUSIC BY GRYZOR87",TILE_ATTR(PAL2,FALSE,FALSE,FALSE),11,24); /* The music creator of this game */
	VDP_setEnable(TRUE); /* VDP on */

	while (exit != 1) { /* Loop */

		mov = mov - 1;

		VDP_setHorizontalScroll(PLAN_B,mov); /* Moving background */

		/* Blinking "press start" text. Remember in old HTML days, the Blinking tag ? >:D */
		if (countoff < 59)
			countoff ++;
		else {
			countoff = 0; /* Reset counter */
			VDP_drawTextBG(APLAN,"PRESS START",TILE_ATTR(PAL2,FALSE,FALSE,FALSE),14,18); /* Show text */
		}
		if (countoff == offpstart)
			VDP_clearTextLine(18); /* Hide text */

		SPR_update(titlespr,1); /* Update sprite */

		VDP_waitVSync(); /* Vsync */

	}

}
