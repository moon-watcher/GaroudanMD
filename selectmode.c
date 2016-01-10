/* selectmode */
/* Select history or survival mode */

# include <genesis.h>
# include <res/rescomp.h>

void selectmode(u32 highscore) {

	u16 exit = 0;

	Sprite modespr[3]; /* Sprites */

	VDP_clearPlan (APLAN,0); /* Cleaning plan A & B */
        VDP_clearPlan (BPLAN,0);

	VDP_setEnable(FALSE); /* Shutdown VDP */
	VDP_setPalette(PAL0,gamemodepal.data); /* PAL0 loaded */
	SPR_initSprite(&modespr[0],&gamemode,64,80,TILE_ATTR(PAL1,FALSE,FALSE,FALSE)); /* Loading history sprite */
	SPR_initSprite(&modespr[1],&gamemode,192,80,TILE_ATTR(PAL1,FALSE,FALSE,FALSE)); /* Loading survival sprite */
	SPR_initSprite(&modespr[2],&gamemodesel,62,78,TILE_ATTR(PAL1,FALSE,FALSE,FALSE)); /* Loading selector sprite */
	VDP_drawTextBG(APLAN,"SELECT YOUR",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),14,3); /* Drawing text */
	VDP_drawTextBG(APLAN,"GAME MODE",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),15,5);
	VDP_drawTextBG(APLAN,"CAMPAING",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),8,19);
	VDP_drawTextBG(APLAN,"SURVIVAL",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),24,19);
	VDP_setEnable(TRUE); /* Enabling VDP */

	if (highscore < 19999)
		SPR_setAnim(&modespr[1],2); /* Surival mode only enabled when highscore > 20000) */

	while (exit != 1) {

		SPR_update(modespr,3);
		VDP_waitVSync( );

	}

}
