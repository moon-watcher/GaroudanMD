/* showinfo.c */
/* Show this info only at console statup */

# include <genesis.h>
# include <res/rescomp.h>

void show_info() {

        SPR_init(0); /* Init sprite engine */

        VDP_resetScreen();

        /* This game is not licensed by Sega */
        VDP_drawText("NOT PRODUCED BY OR UNDER LICENSE",4,13);
        VDP_drawText("FROM SEGA ENTERPRISES LTD.",7,15);

        waitMs(8000); /* Waiting */

        /* Deleting lines */
        VDP_clearTextLine(13);
        VDP_clearTextLine(15);

        /* Credit to the guys who made this game */
        VDP_drawText("ORIGINAL GAME",12,9);
        VDP_drawText("(c)2013 LOCOMALITO & GRYZOR87",5,11);
        VDP_drawText("MEGADRIVE VERSION",10,15); /* The poor guy who write this game to Megadrive */
        VDP_drawText("2015 NEVAT",14,17); /* I hope to end this game in 2016 :) */

        waitMs(9000); /* More waiting */

        /* Deleting lines */
        VDP_clearTextLine(9);
        VDP_clearTextLine(11);
        VDP_clearTextLine(15);
        VDP_clearTextLine(17);

        VDP_drawImage(APLAN, &logogpl3, 0, 0); /* Show GPL3 logo */
	/* TODO: A fade in & out effect will be cool */

        waitMs(8000); /* wait */

	VDP_loadFont (&font, 0); /* Loading font */

}

