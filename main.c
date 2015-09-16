#include "allegro.h"
#include "stdlib.h"
#include "math.h"
#include "mappyal.h"
#include "prototypes.h"
#include "stdio.h"
#include "defines.h"
#include "bitmaps.h"
#include "sounds.h"
#include "structs.h"
#include "explosionFunctions.h"
#include "enemyFunctions.h"
#include "bulletFunctions.h"
#include "timer.h"
#include "collision.h"
#include "HUD.h"

int main(void){
    
    if (init() == 1 || soundInit() == 1)
       return 1;

    loadSounds();
    
    midi_pause();
    playIntroduction();
    midi_resume();
    
    bitmapInit();
    mappyLoad();
    initTimer();
    
    srand(time(NULL));
    
    x = STARTING_POINT_X;
    y = STARTING_POINT_Y;
    
    player.health = STARTING_HEALTH;
    player.score = 0;
    
    initializeEnemies();
    intro();
    
    while (!key[KEY_ESC]){
          while(ticks == 0){
                    rest(1);
          }
		  while(ticks > 0){
                    int old_ticks = ticks;
                    timerCheck();
                    ticks--;
                    if(old_ticks <= ticks)//logic is taking too long: abort and draw a frame
                                 break; 
 		  }
          updateBackground();
                   
          updateEnemies();
          
          updatePowerups();
                   
          drawVehicle();
                    
          input();
          
          updateBullets();
          
          updateExplosions();
          
          collision();
          
          updateReticule();
          
          HUD();

          acquire_screen();
		  blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
		  release_screen();
          
          rest(25);
          clear_bitmap(buffer);
          
          if (gameOver())
             break;
          
          //checkMouse();
    
    }
    
   	MapFreeMem();
   	allegro_exit();
   	
    return 0;
    
}
END_OF_MAIN();

void intro(){
     while(!key[KEY_ENTER]){
          clear_to_color(buffer, WHITE);
          char data[200];
          sprintf(data, "Hog Runner Beta]");
          textout_centre_ex(buffer, font, data, SCREEN_W/2, SCREEN_H/2, BLACK, -1);
          sprintf(data, "[Press Enter]");
          textout_centre_ex(buffer, font, data, SCREEN_W/2, SCREEN_H/2+30, BLACK, -1);
          acquire_screen();
		  blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
		  release_screen();          
		  rest(50);
     }
     play_sample(warthogEngine, 255, 127, 1000, true);
}

int gameOver(){
     if (player.health < 0 || yoffset <=5){
        stop_midi();
        stop_sample(warthogEngine);
        play_sample(gameOverVoice, 255, 127, 1000, false);
        while (!key[KEY_ESC]){
          clear_to_color(buffer, WHITE);
          char data[200];
          sprintf(data, "Game Over!");
          textout_centre_ex(buffer, font, data, SCREEN_W/2, SCREEN_H/2, BLACK, -1);
          sprintf(data, "Final Score: %d", player.score);
          textout_centre_ex(buffer, font, data, SCREEN_W/2, SCREEN_H/2+30, BLACK, -1);
          sprintf(data, "[Press ESC]");
          textout_centre_ex(buffer, font, data, SCREEN_W/2, SCREEN_H/2+60, BLACK, -1);
          acquire_screen();
		  blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
		  release_screen();    
          rest (100); 
       }
        return 1;
     }
     else
         return 0;
}

void generatePowerup(int index){
     int z = 0;
     while (powerupArray[z].active){
           z++;
     }
     
     if (z < MAX_POWERUPS){
        powerupArray[z].active = true;
        powerupArray[z].x = enemyStructArray[index].x;
        powerupArray[z].y = enemyStructArray[index].y;
        powerupArray[z].rotation = itofix(getRanNum(0,360));
        switch (getRanNum(0, 6)){
               case 0:
                    powerupArray[z].powerup = powerInvincible;
                    break;
               case 2:
                    powerupArray[z].powerup = powerRocket;
                    break;
               case 3:
                    powerupArray[z].powerup = powerGauss;
                    break;
               case 4:
                    powerupArray[z].powerup = powerThreeShot;
                    break;
               case 5:
                    powerupArray[z].powerup = powerSevenShot;
                    break;
               default:
                    powerupArray[z].powerup = powerInvincible;
        }
                       
                             
     }
}

void updatePowerups(){
     int w;
     
     for (w = 0; w< MAX_POWERUPS; w++){
         if (powerupArray[w].active == true){
             powerupArray[w].y += SCROLL_SPEED;
             rotate_sprite(buffer, powerupArray[w].powerup, powerupArray[w].x, powerupArray[w].y, powerupArray[w].rotation); 
         }
         if (powerupArray[w].y > SCREEN_H)
                powerupArray[w].active = false;   
     }
}


fixed mouse_angle(){
      
      int xTurret = mouse_x -(x+WARTHOG_WIDTH/2);
      int yTurret = mouse_y -(y+WARTHOG_HEIGHT*93/120);
      turretAngle = atan2(yTurret, xTurret);
      return ftofix(128/M_PI*atan2(yTurret, xTurret)+64);
      
}

fixed enemy_angle(int z){
      //I didn't change variables, just copied and pasted from above but with the vehicle, not the mouse!
      int xTurret = (enemyVehicleArray[z].x + enemyVehicleArray[z].enemy->w/2) -(x+WARTHOG_WIDTH/2);
      int yTurret = (enemyVehicleArray[z].y + enemyVehicleArray[z].enemy->h/2) -(y+WARTHOG_HEIGHT*93/120);
      enemyAngle = atan2(yTurret, xTurret);
      return ftofix(128/M_PI*atan2(yTurret, xTurret)+64);
      
}

void input(){
     //Movement
     if (key[KEY_W])
        if (y > BARRIER)
           y-= SPEED;
     if (key[KEY_S])
        if (y+WARTHOG_HEIGHT < SCREEN_H)
           y+= SPEED;
     if (key[KEY_D])
        if (x+WARTHOG_WIDTH < SCREEN_W)
           x+= SPEED;
     if (key[KEY_A])
        if (x > 0)
           x-= SPEED;     
           
     //Select Weapon
     if (key[KEY_1])
        timerRocket += 40;
     if (key[KEY_2])
        timerGauss += 40;
     if (key[KEY_3])
        timerThreeShot += 40;
     if (key[KEY_4])
        timerSevenShot += 40;
     if (key[KEY_5])
        timerInvincible += 40;
     
        
        
     if (mouse_b & 1){
        if (currentWeapon == 1)
           startBullet();
        if (currentWeapon == 2)
           startRocket();
        if (currentWeapon == 3)
           startGauss();
     }
     
     if (mouse_b & 2){
        startLaser();
        playRandomMarineCall();
     }
     
     /*
     if (key[KEY_SPACE])
        invincible = true;
     else
        invincible = false;
     */
}

void drawVehicle(){
          //Wheels
          masked_blit(warthog, buffer, 14*wheelRotation, 121,  x-7, y+25, 14, 24);
          masked_blit(warthog, buffer, 14*wheelRotation, 121, x+50, y+25, 14, 24);
          masked_blit(warthog, buffer, 14*wheelRotation, 121,  x-7, y+84, 14, 24);
          masked_blit(warthog, buffer, 14*wheelRotation, 121, x+50, y+84, 14, 24);
          ++wheelRotation %=4;
          
          //Draw Hull
          if (!invincible)
             masked_blit(warthog, buffer, 0, 0, x, y, WARTHOG_WIDTH, WARTHOG_HEIGHT);
          else
             masked_blit(warthogG, buffer, 0, 0, x, y, WARTHOG_WIDTH, WARTHOG_HEIGHT); 
             
          //rotate_sprite(buffer, marine, x+WARTHOG_WIDTH*3/4 - marine->w/2, y + WARTHOG_HEIGHT*2/4 - marine->h/2, mouse_angle());
          drawMarine();
          
          //Draw Turret
          switch (currentWeapon){
                 case 1:
                      rotate_sprite(buffer, turretM, x+WARTHOG_WIDTH/2-TURRET_LENGTH, y+93-TURRET_LENGTH, mouse_angle()); 
                      break;
                 case 2:
                      rotate_sprite(buffer, turretR, x+WARTHOG_WIDTH/2-TURRET_LENGTH, y+93-TURRET_LENGTH, mouse_angle()); 
                      break;
                 case 3:
                      rotate_sprite(buffer, turretG, x+WARTHOG_WIDTH/2-TURRET_LENGTH, y+93-TURRET_LENGTH, mouse_angle()); 
                      break;
                 default:
                      rotate_sprite(buffer, turretM, x+WARTHOG_WIDTH/2-TURRET_LENGTH, y+93-TURRET_LENGTH, mouse_angle()); 
                      break;
          }
}

int glowRadar = 47;
void drawMarine(){
     int z = 0;
     if (enemyLockOn == -1){
         while (!enemyVehicleArray[z].active){
               z++;
         }
         
         if (z < MAX_ENEMY_VEHICLES){
               enemyLockOn = z;
         }
     }
     
     if (!enemyVehicleArray[enemyLockOn].active || !enemyVehicleArray[enemyLockOn].alive){
         enemyLockOn = -1;
         rotate_sprite(buffer, marine, x+WARTHOG_WIDTH*3/4 - marine->w/2, y + WARTHOG_HEIGHT*2/4 - marine->h/2, mouse_angle());
     }
     else{
         circle(buffer, enemyVehicleArray[enemyLockOn].x+enemyVehicleArray[enemyLockOn].enemy->w/2 , enemyVehicleArray[enemyLockOn].y+enemyVehicleArray[enemyLockOn].enemy->h/2, glowRadar+50, RED);
         circle(buffer, enemyVehicleArray[enemyLockOn].x+enemyVehicleArray[enemyLockOn].enemy->w/2 , enemyVehicleArray[enemyLockOn].y+enemyVehicleArray[enemyLockOn].enemy->h/2, glowRadar+55, RED);
         circle(buffer, enemyVehicleArray[enemyLockOn].x+enemyVehicleArray[enemyLockOn].enemy->w/2 , enemyVehicleArray[enemyLockOn].y+enemyVehicleArray[enemyLockOn].enemy->h/2, glowRadar+60, RED);
         glowRadar++; glowRadar%=5;
         rotate_sprite(buffer, marine, x+WARTHOG_WIDTH*3/4 - marine->w/2, y + WARTHOG_HEIGHT*2/4 - marine->h/2, enemy_angle(enemyLockOn));
     }
}

int init(){
     
    if (allegro_init() != 0)
      return 1;
      
    install_keyboard();
    install_mouse();
    set_color_depth(16); 
	set_window_title("Hog Runner");  
	
	

    
    //if (set_gfx_mode(GFX_AUTODETECT, 640, 480, 0, 0) != 0) {
        if (set_gfx_mode(GFX_SAFE, 640, 480, 0, 0) != 0) {
            set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
            allegro_message("Unable to set any graphic mode\n%s\n", allegro_error);
            return 1;
        }
    //}
    return 0;
}

void mappyLoad(){
    //load the Mappy file
	if (MapLoad("Halo.fmp"))
    {
        set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
		allegro_message ("Can't find Halo.fmp");
		return;
	}

    //set palette
    MapSetPal8();         
     
}

void updateBackground()
{

        
    //make sure it doesn't scroll beyond map edge
    if (yoffset < 5) 
    {
        //level is over
        yoffset = 5;
        textout_centre(buffer, font, "END OF LEVEL", SCREEN_W/2, SCREEN_H/2, WHITE);
    }
    if (yoffset > BOTTOM) 
       yoffset = BOTTOM;

    yoffset-=SCROLL_SPEED;


    //draw map with single layer
    MapDrawBG(buffer, 0, yoffset, 0, 0, SCREEN_W-1, SCREEN_H-1);


}

void updateReticule(){
     masked_blit(crosshair, buffer, 0, 0, mouse_x-crosshair->w/2, mouse_y - crosshair->h/2, crosshair->w, crosshair->h);
}

int isInside(int x,int y,int left,int top,int right,int bottom){
    
    if (x > left && x < right && y > top && y < bottom)
        return 1;
    else
        return 0;
}

void checkMouse(){
     /*
     if (xPos < 5)
        position_mouse(5, yPos);
     if (xPos > SCREEN_W-5)
        position_mouse(SCREEN_W-5, yPos);
     if (yPos < 5)
        position_mouse(xPos, 5);
     if (yPos > SCREEN_H-5)
        position_mouse(xPos, SCREEN_H-5);
     if(mouse_on_screen() == 0)
       position_mouse(xPos, yPos);
      */  
}

int getRanNum(int min,int max)
{
    int range = max - min;
    return rand() % range + min;
}
