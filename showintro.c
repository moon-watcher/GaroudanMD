/* showintro.c */
/* Game intro */

# include <genesis.h>
# include <res/rescomp.h>

void show_intro_text(u16 animationumber,u16 timecounter,u16 showtextimer);
void clear_intro_text();

void show_intro() {

	u16 framesw = 0; /* Cycles to wait until switch frame */
	u16 framecounter = 0; /* Counter for frames */
	u16 timecounter = 0; /* Counter for timers */
	u16 timers[6] = {0,0,0,0,0,0}; /* Cycles to wait until change animation */
	u16 animationnumber = 0; /* Animation running */
	u16 showtexttimer = 0; /* When show text */

	Sprite animation[1]; /* Intro animations */

	if (IS_PALSYSTEM) {/* It's a PAL system, 50 Hz */
		framesw = 5; /* 1/10 second */
		timers[0] = 50; /* Time for animation 1, 1 second */
		timers[1] = 450; /* Time for animation 2, 9 seconds */
		timers[2] = 450; /* Time for animation 3, 9 seconds */
		timers[3] = 550; /* Time for animation 4, 11 seconds */
		timers[4] = 450; /* Time for animation 5, 9 seconds */
		timers[5] = 350; /* Time for second text on animation 5, 7 seconds */
		showtexttimer = 25; /* When show text, 1/2 second */
	}
	else { /* It's a NTSC system, 60 Hz */
		framesw = 6; /* 1/10 second */
		timers[0] = 60; /* Time for animation 1, 1 second */
		timers[1] = 540; /* Time for animation 2, 9 seconds */
		timers[2] = 540; /* Time for animation 3, 9 seconds */
		timers[3] = 660; /* Time for animation 4, 11 seconds */
		timers[4] = 540; /* Time for animation 5, 9 seconds */
		timers[5] = 420; /* Time for second text on animation 5, 7 seconds */
		showtexttimer = 30; /* When show text, 1/2 second */ 
	}

	VDP_resetScreen(); /* Reset VDP */

	VDP_drawImage(APLAN,&locowarn,0,0); /* Show Locomalito Logo */

	waitMs(8000); /* Waiting */

	VDP_clearPlan (APLAN,0); /* Cleaning Plan A */
	VDP_clearPlan (BPLAN,0); /* Cleaning Plan B */

	VDP_drawImageEx(BPLAN,&introback,TILE_ATTR_FULL(PAL0,FALSE,FALSE,FALSE,TILE_USERINDEX),0,0,1,1); /* Show monitor */

	VDP_setPalette(PAL1,palintrospr.data); /* Load PAL1 color */
	VDP_setPalette(PAL2,palfont.data);

	SPR_initSprite(&animation[0],&introsprites,133,60,TILE_ATTR(PAL1,FALSE,FALSE,FALSE)); /* Put animation in screen */

	while(animationnumber < 6) { /* Animation loop */	

		if (framecounter < framesw) /* Check counter */
			framecounter ++; /* Counting... */
		else {
			framecounter = 0; /* Reset counter */
			SPR_nextFrame(&animation[0]); /* Change frame */
		}

		SPR_update(animation,1); /* Update sprite */

		show_intro_text(animationnumber,timecounter,showtexttimer); /* Show text */

		VDP_waitVSync(); /* Waiting... */

		if (timecounter < timers[animationnumber]) /* Check counter */
			timecounter ++; /* Counting... */
		else { /* Timer reacher, changing animation */
			timecounter = 0; /* Reset counter */
			animationnumber ++; /* Change animation */
			framecounter = 0; /* Reset counter */
			if (animationnumber > 3)
				SPR_setAnimAndFrame(&animation[0],1,0); /* Last animation, it's the same that second loop */
			else
				SPR_setAnimAndFrame(&animation[0],animationnumber,0); /* Change sprite */
			clear_intro_text(); /* Cleaning text lines */
                }

	
	}

	SPR_clear(); /* Cleaning sprites */

}

void show_intro_text(u16 animationnumber,u16 timecounter,u16 showtexttimer) {

	if (animationnumber == 1) { /* Second animation text */
		if (timecounter == showtexttimer) {
			VDP_drawTextBG(APLAN,"BREAKING NEWS",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),14,15);
			VDP_drawTextBG(APLAN,"a giant radioactive egg",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),9,17);
			VDP_drawTextBG(APLAN,"has been found in a",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),11,19);
			VDP_drawTextBG(APLAN,"breach of MOUNT TEIDE",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),10,21);
		}
	}

	if (animationnumber == 2) { /* Third animation text */
		if (timecounter == showtexttimer) {
			VDP_drawTextBG(APLAN,"this finding coincides",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),9,15);
			VDP_drawTextBG(APLAN,"with the earthquakes",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),10,17);
			VDP_drawTextBG(APLAN,"and submarine eruptions",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),8,19);
			VDP_drawTextBG(APLAN,"of the recent days",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),11,21);
		}
	}


	if (animationnumber == 3) { /* Fourth animation text */
		if (timecounter == showtexttimer) {
			VDP_drawTextBG(APLAN,"the scientific community",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),8,15);
			VDP_drawTextBG(APLAN,"is evaluating if there",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),9,17);
			VDP_drawTextBG(APLAN,"is a relationship between",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),7,19);
			VDP_drawTextBG(APLAN,"the egg and earthquakes",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),8,21);
		}
	}

	if (animationnumber == 4) { /* Second animation text */
		if (timecounter == showtexttimer) {
			VDP_drawTextBG(APLAN,"but meanwhile, people",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),9,15);
			VDP_drawTextBG(APLAN,"are concerned because of",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),7,17);
			VDP_drawTextBG(APLAN,"the local legend about",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),8,19);
			VDP_drawTextBG(APLAN,"GAURODAN and GUAYOTA",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),9,21);
		}
	}


	if (animationnumber == 5) { /* Second animation text */
		if (timecounter == showtexttimer) {
			VDP_drawTextBG(APLAN,"we will report on this",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),9,15);
			VDP_drawTextBG(APLAN,"important finding",TILE_ATTR(PAL2, FALSE, FALSE, FALSE),11,17);
		}
	}

}

void clear_intro_text() {

	/* Cleaning */
	VDP_clearTextLine(15);
	VDP_clearTextLine(17);
	VDP_clearTextLine(19);
	VDP_clearTextLine(21);

}
