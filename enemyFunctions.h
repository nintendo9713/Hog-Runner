void initializeEnemies(){
     int h;
     for (h = 0; h < MAX_ENEMIES; h++){
         enemyStructArray[h].x = getRanNum(       0,   SCREEN_W);
         enemyStructArray[h].y = getRanNum(SCREEN_H*4, BOTTOM-SCREEN_H) * -1;
         enemyStructArray[h].alive = true;
         enemyStructArray[h].velocity = getRanNum(0, MAX_ENEMY_SPEED);
         enemyStructArray[h].rotation = getRanNum(0, 360);
         enemyStructArray[h].active = false;    
         enemyStructArray[h].health = 100;
         enemyStructArray[h].enemy = getRandomEnemy();
     }
     
     for (h = 0; h < MAX_ENEMY_VEHICLES; h++){
         enemyVehicleArray[h].enemy = banshee;
         enemyVehicleArray[h].x = getRanNum(0,   SCREEN_W - enemyVehicleArray[h].enemy->h);
         enemyVehicleArray[h].y = getRanNum(SCREEN_H*4, BOTTOM-SCREEN_H) * -1;
         enemyVehicleArray[h].alive = true;
         enemyVehicleArray[h].velocity = getRanNum(0, MAX_VEHICLE_SPEED);
         enemyVehicleArray[h].rotation = 0;
         enemyVehicleArray[h].active = false;    
         enemyVehicleArray[h].health = 1000;
         enemyVehicleArray[h].ROF = getRanNum(50, 100);
         enemyVehicleArray[h].ROFcount = 0;
         

         enemyVehicleArray[h].lowPoint = getRanNum(0, SCREEN_H - enemyVehicleArray[h].enemy->h);
     }
     
}

BITMAP* getRandomEnemy(){
        switch(getRanNum(0,6)){
             case 0:
                  return enemy00;
             case 1:
                  return enemy01;
             case 2:
                  return enemy02;
             case 3:
                  return enemy03;
             case 4:
                  return enemy04;
             case 5:
                  return enemy05;
             default:
                  return enemy00;
        }
}
/*
BITMAP* getRandomEnemyVehicle(){
        switch(getRanNum(0,6)){
             case 0:
                  return enemy00;
             case 1:
                  return enemy01;
             case 2:
                  return enemy02;
             case 3:
                  return enemy03;
             case 4:
                  return enemy04;
             case 5:
                  return enemy05;
             default:
                  return banshee;
        }
}
*/
void updateEnemies(){
     int h;
     //Ground Enemies!
     for (h = 0; h < MAX_ENEMIES; h++){
         
         if (enemyStructArray[h].health <= 0 && enemyStructArray[h].alive){
            if (enemyStructArray[h].enemy == enemy05){
               if (getRanNum(0,5) == 3)
                        generatePowerup(h);
            }
            playRandomDeath();
            enemyStructArray[h].alive = false;
         }
         if(!enemyStructArray[h].active && enemyStructArray[h].y > (SCREEN_H*-1) && enemyStructArray[h].alive){
              enemyStructArray[h].active = true;
         }
         if(enemyStructArray[h].y > SCREEN_H){
              enemyStructArray[h].active = false;
         }
         if(enemyStructArray[h].alive && !enemyStructArray[h].active){
              enemyStructArray[h].y += SCROLL_SPEED;
         }
         if(enemyStructArray[h].alive && enemyStructArray[h].active){
              enemyStructArray[h].y += SCROLL_SPEED;
              enemyStructArray[h].y += enemyStructArray[h].velocity*sin(enemyStructArray[h].rotation);
              enemyStructArray[h].x += enemyStructArray[h].velocity*cos(enemyStructArray[h].rotation);
              //enemyStructArray[h].rotation = ftofix(turretAngle); //ftofix(128/M_PI*turretAngle+64); //insert warthog direction
              rotate_sprite(buffer, enemyStructArray[h].enemy, enemyStructArray[h].x, enemyStructArray[h].y, itofix(enemyStructArray[h].rotation));
         }
         if (!enemyStructArray[h].alive && enemyStructArray[h].active){
            enemyStructArray[h].y += SCROLL_SPEED;
            if (enemyStructArray[h].enemy == enemy00)
               rotate_sprite(buffer, eDead00, enemyStructArray[h].x - eDead00->w/2, enemyStructArray[h].y - eDead00->h/2, itofix(enemyStructArray[h].rotation));
               
            if (enemyStructArray[h].enemy == enemy01)
               rotate_sprite(buffer, eDead01, enemyStructArray[h].x - eDead00->w/2, enemyStructArray[h].y - eDead00->h/2, itofix(enemyStructArray[h].rotation));
               
            if (enemyStructArray[h].enemy == enemy02)
               rotate_sprite(buffer, eDead02, enemyStructArray[h].x - eDead00->w/2, enemyStructArray[h].y - eDead00->h/2, itofix(enemyStructArray[h].rotation));
               
            if (enemyStructArray[h].enemy == enemy03)
               rotate_sprite(buffer, eDead03, enemyStructArray[h].x - eDead00->w/2, enemyStructArray[h].y - eDead00->h/2, itofix(enemyStructArray[h].rotation));
               
            if (enemyStructArray[h].enemy == enemy04)
               rotate_sprite(buffer, eDead04, enemyStructArray[h].x - eDead00->w/2, enemyStructArray[h].y - eDead00->h/2, itofix(enemyStructArray[h].rotation));
               
            if (enemyStructArray[h].enemy == enemy05)
               rotate_sprite(buffer, eDead05, enemyStructArray[h].x - eDead00->w/2, enemyStructArray[h].y - eDead00->h/2, itofix(enemyStructArray[h].rotation));
               
               
               
            if (enemyStructArray[h].y > SCREEN_H)
               enemyStructArray[h].active = false;

         }
           
     }
     
     //Enemy Vehicles!
     for (h = 0; h < MAX_ENEMY_VEHICLES; h++){
         
         if (enemyVehicleArray[h].health <= 0 && enemyVehicleArray[h].alive){
            playRandomEnemyCall();
            startBansheeExplosion(h);
            enemyVehicleArray[h].alive = false;
         }
         if(!enemyVehicleArray[h].active && enemyVehicleArray[h].y > (SCREEN_H*-1) && enemyVehicleArray[h].alive){
              enemyVehicleArray[h].active = true;
         }
         if(enemyVehicleArray[h].y > SCREEN_H){
              enemyVehicleArray[h].active = false;
         }
         if(enemyVehicleArray[h].alive && !enemyVehicleArray[h].active){
              enemyVehicleArray[h].y += SCROLL_SPEED;
         }
         if(enemyVehicleArray[h].alive && enemyVehicleArray[h].active){
              if (enemyVehicleArray[h].y < enemyVehicleArray[h].lowPoint){
                 enemyVehicleArray[h].y += SCROLL_SPEED;
              }
              //printf("%3d %3d\n", enemyVehicleArray[h].ROF, enemyVehicleArray[h].ROFcount);
              enemyVehicleArray[h].ROFcount++;
              enemyVehicleArray[h].ROFcount %= enemyVehicleArray[h].ROF;
              
              enemyVehicleArray[h].rotation = ftofix(128/M_PI*(atan2((enemyVehicleArray[h].y+enemyVehicleArray[h].enemy->h/2)-(y+WARTHOG_HEIGHT/2),
                                                                     (enemyVehicleArray[h].x+enemyVehicleArray[h].enemy->w/2)-(x+WARTHOG_WIDTH/2)))+64);
                                              //itofix(rad2Deg(atan2((enemyVehicleArray[h].y+enemyVehicleArray[h].enemy->h/2)-(y+93),
                                              //                     (enemyVehicleArray[h].x+enemyVehicleArray[h].enemy->w/2)-(x+WARTHOG_WIDTH)))); 
                                              //ftofix(128/M_PI*turretAngle+64); 
              //enemyVehicleArray[h].y += 5*cos(fixtof(enemyVehicleArray[h].rotation));//enemyVehicleArray[h].velocity*sin(enemyVehicleArray[h].rotation);
              //enemyVehicleArray[h].x += 5*sin(fixtof(enemyVehicleArray[h].rotation));//enemyVehicleArray[h].velocity*cos(enemyVehicleArray[h].rotation);
              if (enemyVehicleArray[h].ROF-1 == enemyVehicleArray[h].ROFcount){
                 startEnemyVehicleBullet(h);
              }
              rotate_sprite(buffer, enemyVehicleArray[h].enemy, enemyVehicleArray[h].x, enemyVehicleArray[h].y, enemyVehicleArray[h].rotation);
         }
         if (!enemyVehicleArray[h].alive && enemyVehicleArray[h].active){
            enemyVehicleArray[h].y += SCROLL_SPEED;
            if (enemyVehicleArray[h].enemy == banshee){
               rotate_sprite(buffer, bansheeDead, enemyVehicleArray[h].x, enemyVehicleArray[h].y, itofix(enemyVehicleArray[h].rotate));
               enemyVehicleArray[h].rotate += 10;
               enemyVehicleArray[h].rotate %= 360;
            }
               
            if (enemyVehicleArray[h].y > SCREEN_H)
               enemyVehicleArray[h].active = false;

         }
           
     }
}
