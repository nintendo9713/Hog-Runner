void startBulletExplosion(int index){
     int z = 0;
     while (bulletExplosionArray[z].active){
           z++;
     }
     if (z < MAX_BULLET_EXPLOSIONS){
           bulletExplosionArray[z].active = true;
           bulletExplosionArray[z].x = bulletStructArray[index].x;
           bulletExplosionArray[z].y = bulletStructArray[index].y;
           bulletExplosionArray[z].frame = 0;
     }

}
void startRocketExplosion(int index){
     int z = 0;
     while (rocketExplosionArray[z].active){
           z++;
     }
     if (z < MAX_BULLET_EXPLOSIONS){
           rocketExplosionArray[z].active = true;
           rocketExplosionArray[z].x = rocketStructArray[index].x;
           rocketExplosionArray[z].y = rocketStructArray[index].y;
           rocketExplosionArray[z].frame = 0;
     }
}
void startGaussExplosion(int index){
     int z = 0;
     while (gaussExplosionArray[z].active){
           z++;
     }
     if (z < MAX_BULLET_EXPLOSIONS){
           gaussExplosionArray[z].active = true;
           gaussExplosionArray[z].x = gaussStructArray[index].x;
           gaussExplosionArray[z].y = gaussStructArray[index].y;
           gaussExplosionArray[z].frame = 0;
     }
}

void startBansheeExplosion(int index){
     int z = 0;
     while (bansheeExplosionArray[z].active){
           z++;
     }
     if (z < MAX_BANSHEE_EXPLOSIONS){
           bansheeExplosionArray[z].active = true;
           bansheeExplosionArray[z].x = enemyVehicleArray[index].x + enemyVehicleArray[index].enemy->w/2;
           bansheeExplosionArray[z].y = enemyVehicleArray[index].y + enemyVehicleArray[index].enemy->h/2;
           bansheeExplosionArray[z].frame = 0;
     }
}

void startLaserExplosion(int index){
     int z = 0;
     while (laserExplosionArray[z].active){
           z++;
     }
     if (z < MAX_BULLET_EXPLOSIONS){
           laserExplosionArray[z].active = true;
           laserExplosionArray[z].x = laserStructArray[index].x;
           laserExplosionArray[z].y = laserStructArray[index].y;
           laserExplosionArray[z].frame = 0;
     }
}

void updateExplosions(){
     int w;
     
     for (w = 0; w< MAX_BULLET_EXPLOSIONS; w++){
         if (bulletExplosionArray[w].active == true){
             bulletExplosionArray[w].y += SCROLL_SPEED;
             masked_blit(bulletExplosion, buffer, 16*bulletExplosionArray[w].frame++,0, bulletExplosionArray[w].x-8, 
                                          bulletExplosionArray[w].y - 8, 16, 16);
         }
         
         if (bulletExplosionArray[w].y > SCREEN_H || bulletExplosionArray[w].frame > 5){
            bulletExplosionArray[w].active = false;
         }

     }
     for (w = 0; w < MAX_ROCKET_EXPLOSIONS; w++){
         if (rocketExplosionArray[w].active == true){
             rocketExplosionArray[w].y += SCROLL_SPEED;
             masked_blit(rocketExplosion, buffer, 64*rocketExplosionArray[w].frame++,0, rocketExplosionArray[w].x-32, 
                                          rocketExplosionArray[w].y - rocketExplosion->h/2, 64, 64);
         }
         
         if (rocketExplosionArray[w].y > SCREEN_H || rocketExplosionArray[w].frame > 25){
            rocketExplosionArray[w].active = false;
         }

     }  
     
     for (w = 0; w < MAX_GAUSS_EXPLOSIONS; w++){
         if (gaussExplosionArray[w].active == true){
             gaussExplosionArray[w].y += SCROLL_SPEED;
             masked_blit(gaussExplosion, buffer, 25*gaussExplosionArray[w].frame++, 0, gaussExplosionArray[w].x - 13,
                                         gaussExplosionArray[w].y - 13, 25, 25);
         }
         
         if (gaussExplosionArray[w].y > SCREEN_H || gaussExplosionArray[w].frame > 9){
            gaussExplosionArray[w].active = false;
         }
     }   
     
     for (w = 0; w < MAX_BANSHEE_EXPLOSIONS; w++){
         if (bansheeExplosionArray[w].active == true){
             bansheeExplosionArray[w].y += SCROLL_SPEED;
             masked_blit(bansheeExplosion, buffer, 64*bansheeExplosionArray[w].frame++,0, bansheeExplosionArray[w].x-32, 
                                          bansheeExplosionArray[w].y - bansheeExplosion->h/2, 64, 64);
         }
         
         if (bansheeExplosionArray[w].y > SCREEN_H || bansheeExplosionArray[w].frame > 25){
            bansheeExplosionArray[w].active = false;
         }

     }  
     
     for (w = 0; w < MAX_LASER_EXPLOSIONS; w++){
         if (laserExplosionArray[w].active == true){
             laserExplosionArray[w].y += SCROLL_SPEED;
             masked_blit(laserExplosion, buffer, 64*laserExplosionArray[w].frame++, 0, laserExplosionArray[w].x - 32,
                                         laserExplosionArray[w].y - 32, 64, 64);
         }
         
         if (laserExplosionArray[w].y > SCREEN_H || laserExplosionArray[w].frame > 7){
            laserExplosionArray[w].active = false;
         }
     }  
}
