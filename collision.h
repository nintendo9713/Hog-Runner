void collision(){
     int r, s;
     
     for (r = 0; r < MAX_ENEMIES; r++){
         for (s = 0; s < MAX_BULLETS; s++){
             if (bulletStructArray[s].active){
                if (enemyStructArray[r].health > 0){
                     if (isInside(bulletStructArray[s].x + bullet->w/2, bulletStructArray[s].y + bullet->h/2, enemyStructArray[r].x, 
                     enemyStructArray[r].y, enemyStructArray[r].x + enemy00->w, enemyStructArray[r].y + enemy00->h)){
                         bulletStructArray[s].active = false;
                         enemyStructArray[r].health -= BULLET_DAMAGE;   
                         startBulletExplosion(s);
                         player.score += 1;
                     }
                }
             }
             
         }
         
         for (s = 0; s < MAX_GAUSS; s++){
             if (gaussStructArray[s].active){
                if (enemyStructArray[r].health > 0){
                     if (isInside(gaussStructArray[s].x + gauss->w/2, gaussStructArray[s].y + gauss->h/2, enemyStructArray[r].x, 
                     enemyStructArray[r].y, enemyStructArray[r].x + enemy00->w, enemyStructArray[r].y + enemy00->h)){
                         gaussStructArray[s].active = false;
                         enemyStructArray[r].health -= GAUSS_DAMAGE;   
                         startGaussExplosion(s);
                         player.score += 5;
                     }
                }
             }             
         }
         
         for (s = 0; s < MAX_ROCKETS; s++){
             if (rocketStructArray[s].active){
                if (enemyStructArray[r].health > 0){
                     if (isInside(rocketStructArray[s].x + rocket->w/2, rocketStructArray[s].y + rocket->h/2, enemyStructArray[r].x, 
                     enemyStructArray[r].y, enemyStructArray[r].x + enemy00->w, enemyStructArray[r].y + enemy00->h)){
                         rocketStructArray[s].active = false;
                         enemyStructArray[r].health -= ROCKET_DAMAGE;   
                         startRocketExplosion(s);
                         player.score += 10;
                     }
                }
             }                
         } 
         
         
         for (s = 0; s < MAX_LASERS; s++){
             if (laserStructArray[s].active){
                if (enemyStructArray[r].health > 0){
                     if (isInside(laserStructArray[s].x + laser->w/2, laserStructArray[s].y + laser->h/2, enemyStructArray[r].x, 
                     enemyStructArray[r].y, enemyStructArray[r].x + enemy00->w, enemyStructArray[r].y + enemy00->h)){
                         enemyStructArray[r].health -= LASER_DAMAGE;   
                         startLaserExplosion(s);
                         player.score += 1;
                     }
                }
             }             
         }
                  
         //Warthog itself
                if (enemyStructArray[r].health > 0){
                     if (isInside(enemyStructArray[r].x + enemyStructArray[r].enemy->w/2, enemyStructArray[r].y + enemyStructArray[r].enemy->h/2,
                     x, y, x + WARTHOG_WIDTH, y + WARTHOG_HEIGHT)){
                         enemyStructArray[r].health -= 1000;
                         if (y < SCREEN_H - WARTHOG_HEIGHT)
                            y += KNOCKBACK;
                         if (!invincible)
                            player.health -= 3;
                         player.score += 15;
                     }
                }         
         
         //Powerups!
         for (s = 0; s < MAX_POWERUPS; s++){
             if (powerupArray[s].active){
                if (isInside(powerupArray[s].x + powerupArray[s].powerup->w/2, powerupArray[s].y + powerupArray[s].powerup->h/2,
                     x, y, x + WARTHOG_WIDTH, y + WARTHOG_HEIGHT)){
                     if (powerupArray[s].powerup == powerInvincible){
                        timerInvincible += POWERUP_TIME_INCREMENT;
                     }
                     if (powerupArray[s].powerup == powerRocket){
                        timerRocket += POWERUP_TIME_INCREMENT;
                     }
                     if (powerupArray[s].powerup == powerGauss){
                        timerGauss += POWERUP_TIME_INCREMENT;
                     }
                     if (powerupArray[s].powerup == powerThreeShot){
                        timerThreeShot += POWERUP_TIME_INCREMENT;
                     }
                     if (powerupArray[s].powerup == powerSevenShot){
                        timerSevenShot += POWERUP_TIME_INCREMENT;
                     }
                     player.score += 50;
                     powerupArray[s].active = false;
                }
             }    
         }
     }
     
     for (r = 0; r < MAX_ENEMY_VEHICLES; r++){
         for (s = 0; s < MAX_BULLETS; s++){
             if (bulletStructArray[s].active){
                if (enemyVehicleArray[r].health > 0){
                     if (isInside(bulletStructArray[s].x + bullet->w/2, bulletStructArray[s].y + bullet->h/2, enemyVehicleArray[r].x, 
                     enemyVehicleArray[r].y, enemyVehicleArray[r].x + enemyVehicleArray[r].enemy->w, enemyVehicleArray[r].y + enemyVehicleArray[r].enemy->h)){
                         bulletStructArray[s].active = false;
                         enemyVehicleArray[r].health -= BULLET_DAMAGE;   
                         //startGaussExplosion(s);
                         //playnoise?
                         player.score += 3;
                     }
                }
             }
             
         }
         
         for (s = 0; s < MAX_GAUSS; s++){
             if (gaussStructArray[s].active){
                if (enemyVehicleArray[r].health > 0){
                     if (isInside(gaussStructArray[s].x + gauss->w/2, gaussStructArray[s].y + gauss->h/2, enemyVehicleArray[r].x, 
                     enemyVehicleArray[r].y, enemyVehicleArray[r].x + enemyVehicleArray[r].enemy->w, enemyVehicleArray[r].y + enemyVehicleArray[r].enemy->h)){
                         gaussStructArray[s].active = false;
                         enemyVehicleArray[r].health -= GAUSS_DAMAGE;   
                         startGaussExplosion(s);
                         player.score += 10;
                     }
                }
             }             
         }
         
         for (s = 0; s < MAX_ROCKETS; s++){
             if (rocketStructArray[s].active){
                if (enemyVehicleArray[r].health > 0){
                     if (isInside(rocketStructArray[s].x + rocket->w/2, rocketStructArray[s].y + rocket->h/2, enemyVehicleArray[r].x, 
                     enemyVehicleArray[r].y, enemyVehicleArray[r].x + enemyVehicleArray[r].enemy->w, enemyVehicleArray[r].y + enemyVehicleArray[r].enemy->h)){
                         rocketStructArray[s].active = false;
                         enemyVehicleArray[r].health -= ROCKET_DAMAGE;   
                         startRocketExplosion(s);
                         player.score += 10;
                     }
                }
             }                
         } 
         
         for (s = 0; s < MAX_LASERS; s++){
             if (laserStructArray[s].active){
                if (enemyVehicleArray[r].health > 0){
                     if (isInside(laserStructArray[s].x + laser->w/2, laserStructArray[s].y + laser->h/2, enemyVehicleArray[r].x, 
                     enemyVehicleArray[r].y, enemyVehicleArray[r].x + enemyVehicleArray[r].enemy->w, enemyVehicleArray[r].y + enemyVehicleArray[r].enemy->h)){
                         enemyVehicleArray[r].health -= LASER_DAMAGE;   
                         startLaserExplosion(s);
                         player.score += 1;
                     }
                }
             }                
         } 
         
         //Warthog itself
                if (enemyVehicleArray[r].health > 0){
                     if (isInside(enemyVehicleArray[r].x + enemyVehicleArray[r].enemy->w/2, enemyVehicleArray[r].y + enemyVehicleArray[r].enemy->h/2,
                     x, y, x + WARTHOG_WIDTH, y + WARTHOG_HEIGHT)){
                         if (!invincible)
                            player.health -= 10;   
                         //player.score += 100;
                     }
                }         
         

     }
     
     for (r = 0; r < MAX_ENEMY_BULLETS; r++){
         if(enemyBulletArray[r].active){
              if (isInside(enemyBulletArray[r].x, enemyBulletArray[r].y, x, y, x + WARTHOG_WIDTH, y + WARTHOG_HEIGHT)){
                 enemyBulletArray[r].active = false;
                 if (!invincible)
                    player.health -= 10;                           
              }
         }
     }
}
