/* showpstart */
/* Show "Press Start" screen */

# include <genesis.h>
# include <res/rescomp.h>

void show_pstart() {

	u16 exit = 0;
	s16 mov = 0;

	Sprite titlespr[1]; /* Title sprite */

	VDP_clearPlan (APLAN,0); /* Cleaning plan A & B */
	VDP_clearPlan (BPLAN,0);

	VDP_setEnable(FALSE); /* Shutdown VDP */
	VDP_drawImageEx(BPLAN,&backstart,TILE_ATTR_FULL(PAL0,FALSE,FALSE,FALSE,TILE_USERINDEX),0,0,1,1); /* Load background */
	VDP_setPalette(PAL1,titlepal.data); /* PAL1 loaded */
	SPR_initSprite(&titlespr[0],&titlestart,48,67,TILE_ATTR(PAL1,FALSE,FALSE,FALSE)); /* Load sprite file */
	VDP_setEnable(TRUE); /* VDP on */

	while (exit != 1) { /* Loop */

		mov = mov - 1;

		VDP_setHorizontalScroll(PLAN_B,mov); /* Moving background */

		SPR_update(titlespr,1); /* Update sprite */

		VDP_waitVSync(); /* Vsync */

	}

}
