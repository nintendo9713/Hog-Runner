#include <allegro.h>
#include "stdio.h"
 
volatile int ticks = 0;
const int updates_per_second = 60;
int timerInvincible = 0;
int timerRocket = 0;
int timerGauss = 0;
int timerThreeShot = 0;
int timerSevenShot = 0;

void ticker()
{
	ticks++;
}
END_OF_FUNCTION(ticker)
 
 

 
void initTimer(){
	LOCK_VARIABLE(ticks);
	LOCK_FUNCTION(ticker);
	install_int_ex(ticker, BPS_TO_TIMER(updates_per_second));
}

void timerCheck(){
     if (timerInvincible > 0){
        invincible = true;
        timerInvincible--;
     }
     else{
          invincible = false;
     }
     
     if (timerGauss > 0){
        powerupGauss = true;
        currentWeapon = 3;
        timerGauss--;
     }
     else{
          powerupGauss = false;
     }
     
     if (timerRocket > 0){
        powerupRocket = true;
        currentWeapon = 2;
        
        timerRocket--;
     }
     else{
          powerupRocket = false;
     }
     
     if (timerThreeShot > 0){
        powerupThreeShot = true;
        timerThreeShot--;
     }
     else{
          powerupThreeShot = false;
     }
     
     if (timerSevenShot > 0){
        powerupSevenShot = true;
        timerThreeShot++;
        timerSevenShot--;
     }
     else{
          powerupSevenShot = false;
     }
     
     if (!powerupRocket && !powerupGauss){
        currentWeapon = 1;
     }
     
     //printf("Invincible -> %3d (%d) |\nRocket -> %3d (%d) |\nGauss -> %3d (%d) |\nThree -> %3d (%d) |\nNine -> %3d (%d)|\n\n",
     //                  timerInvincible, invincible, timerRocket, powerupRocket, timerGauss, powerupGauss, timerThreeShot,
     //                   powerupThreeShot, timerSevenShot, powerupSevenShot);
}
/* 
	bool quit = false;
 
	while(!quit)
	{
		while(ticks == 0)
		{
			rest(1);//rest until a full tick has passed
		}
 
		while(ticks > 0)
		{
			int old_ticks = ticks;
 
			//DoLogic();
		  printf("%5d\n", ticks); 
			ticks--;

			if(old_ticks <= ticks)//logic is taking too long: abort and draw a frame
				break; 
		}

 
		//DrawEverything();
	}
	return 0;
}
END_OF_MAIN()
*/
