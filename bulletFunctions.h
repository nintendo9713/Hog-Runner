void startLaser(){
     int z = 0;
     
     while (laserStructArray[z].active){
           z++;
     }
     
     if (z < MAX_LASERS){
           laserStructArray[z].active = true;
           laserStructArray[z].x = x+WARTHOG_WIDTH*3/4 - marine->w/2;
           laserStructArray[z].y = y + WARTHOG_HEIGHT*2/4 - marine->h/2;
           laserStructArray[z].rotation = enemy_angle(enemyLockOn);
           laserStructArray[z].bulletSpeed = 8;
           laserStructArray[z].xVelocity = laserStructArray[z].bulletSpeed*cos(enemyAngle); //atan2(mouse_y - laserStructArray[z].y, mouse_x - laserStructArray[z].x));
           laserStructArray[z].yVelocity = laserStructArray[z].bulletSpeed*sin(enemyAngle); //atan2(mouse_y - laserStructArray[z].y, mouse_x - laserStructArray[z].x));
     }
}

void startEnemyVehicleBullet(int h){
     int z = 0;
     
     while (enemyBulletArray[z].active){
           z++;
     }
     
     if (z < MAX_ENEMY_BULLETS){
           
           
           enemyBulletArray[z].active = true;
           enemyBulletArray[z].x = enemyVehicleArray[h].x + enemyVehicleArray[h].enemy->w/2 - enemyBullet->w/2;
           enemyBulletArray[z].y = enemyVehicleArray[h].y + enemyVehicleArray[h].enemy->h/2 - enemyBullet->h/2;
           enemyBulletArray[z].rotation = enemyVehicleArray[h].rotation;
           enemyBulletArray[z].bulletSpeed = ENEMY_BULLET_SPEED;

           float direction = atan2((y+WARTHOG_HEIGHT/2-enemyBulletArray[z].y), x+WARTHOG_WIDTH/2 - enemyBulletArray[z].x);

           enemyBulletArray[z].xVelocity = enemyBulletArray[z].bulletSpeed*cos(direction);
           enemyBulletArray[z].yVelocity = enemyBulletArray[z].bulletSpeed*sin(direction);

     }
     
}

void startGauss(){
     int z = 0;
     while (gaussStructArray[z].active){
           z++; 
     }
     if (z < MAX_GAUSS){
            play_sample(shootGauss, 255, 127, 1000, false);
            gaussStructArray[z].active = true;
            gaussStructArray[z].x = (x + WARTHOG_WIDTH/2) - (gauss->w/2) + TURRET_LENGTH*cos(turretAngle);
            gaussStructArray[z].y = (y + 93)              + TURRET_LENGTH*sin(turretAngle);
            gaussStructArray[z].xVelocity = GAUSS_SPEED*cos(turretAngle);  
            gaussStructArray[z].yVelocity = GAUSS_SPEED*sin(turretAngle); 
            gaussStructArray[z].rotation = ftofix(128/M_PI*turretAngle+64);
     }   
     rotate_sprite(buffer,  gaussEffect, x+WARTHOG_WIDTH/2-bulletEffect->w/2, y+93-bulletEffect->h/2, mouse_angle()); 
     
     if (powerupThreeShot || powerupSevenShot){

         z = 0;
         while (gaussStructArray[z].active){
               z++; 
         }
         if (z < MAX_GAUSS){
                gaussStructArray[z].active = true;
                gaussStructArray[z].x = (x + WARTHOG_WIDTH/2) - (gauss->w/2) + TURRET_LENGTH*cos(turretAngle);
                gaussStructArray[z].y = (y + 93)              + TURRET_LENGTH*sin(turretAngle);
                gaussStructArray[z].xVelocity = GAUSS_SPEED*cos(turretAngle + deg2Rad(THREE_OFFSET));  
                gaussStructArray[z].yVelocity = GAUSS_SPEED*sin(turretAngle + deg2Rad(THREE_OFFSET)); 
                gaussStructArray[z].rotation = ftofix(128/M_PI*turretAngle+64);
         }   
         z = 0;
         while (gaussStructArray[z].active){
               z++; 
         }
         if (z < MAX_GAUSS){
                gaussStructArray[z].active = true;
                gaussStructArray[z].x = (x + WARTHOG_WIDTH/2) - (gauss->w/2) + TURRET_LENGTH*cos(turretAngle);
                gaussStructArray[z].y = (y + 93)              + TURRET_LENGTH*sin(turretAngle);
                gaussStructArray[z].xVelocity = GAUSS_SPEED*cos(turretAngle - deg2Rad(THREE_OFFSET));  
                gaussStructArray[z].yVelocity = GAUSS_SPEED*sin(turretAngle - deg2Rad(THREE_OFFSET)); 
                gaussStructArray[z].rotation = ftofix(128/M_PI*turretAngle+64);
         }                             
     
     }
     
     if (powerupSevenShot){

         z = 0;
         while (gaussStructArray[z].active){
               z++; 
         }
         if (z < MAX_GAUSS){
                gaussStructArray[z].active = true;
                gaussStructArray[z].x = (x + WARTHOG_WIDTH/2) - (gauss->w/2) + TURRET_LENGTH*cos(turretAngle);
                gaussStructArray[z].y = (y + 93)              + TURRET_LENGTH*sin(turretAngle);
                gaussStructArray[z].xVelocity = GAUSS_SPEED*cos(turretAngle + deg2Rad(THREE_OFFSET/2));  
                gaussStructArray[z].yVelocity = GAUSS_SPEED*sin(turretAngle + deg2Rad(THREE_OFFSET/2)); 
                gaussStructArray[z].rotation = ftofix(128/M_PI*turretAngle+64);
         }   
         
         z = 0;
         while (gaussStructArray[z].active){
               z++; 
         }
         if (z < MAX_GAUSS){
                gaussStructArray[z].active = true;
                gaussStructArray[z].x = (x + WARTHOG_WIDTH/2) - (gauss->w/2) + TURRET_LENGTH*cos(turretAngle);
                gaussStructArray[z].y = (y + 93)              + TURRET_LENGTH*sin(turretAngle);
                gaussStructArray[z].xVelocity = GAUSS_SPEED*cos(turretAngle - deg2Rad(THREE_OFFSET/2));  
                gaussStructArray[z].yVelocity = GAUSS_SPEED*sin(turretAngle - deg2Rad(THREE_OFFSET/2)); 
                gaussStructArray[z].rotation = ftofix(128/M_PI*turretAngle+64);
         }   
         
         z = 0;
         while (gaussStructArray[z].active){
               z++; 
         }
         if (z < MAX_GAUSS){
                gaussStructArray[z].active = true;
                gaussStructArray[z].x = (x + WARTHOG_WIDTH/2) - (gauss->w/2) + TURRET_LENGTH*cos(turretAngle);
                gaussStructArray[z].y = (y + 93)              + TURRET_LENGTH*sin(turretAngle);
                gaussStructArray[z].xVelocity = GAUSS_SPEED*cos(turretAngle + deg2Rad(THREE_OFFSET*3/2));  
                gaussStructArray[z].yVelocity = GAUSS_SPEED*sin(turretAngle + deg2Rad(THREE_OFFSET*3/2)); 
                gaussStructArray[z].rotation = ftofix(128/M_PI*turretAngle+64);
         }   
         
         z = 0;
         while (gaussStructArray[z].active){
               z++; 
         }
         if (z < MAX_GAUSS){
                gaussStructArray[z].active = true;
                gaussStructArray[z].x = (x + WARTHOG_WIDTH/2) - (gauss->w/2) + TURRET_LENGTH*cos(turretAngle);
                gaussStructArray[z].y = (y + 93)              + TURRET_LENGTH*sin(turretAngle);
                gaussStructArray[z].xVelocity = GAUSS_SPEED*cos(turretAngle - deg2Rad(THREE_OFFSET*3/2));  
                gaussStructArray[z].yVelocity = GAUSS_SPEED*sin(turretAngle - deg2Rad(THREE_OFFSET*3/2)); 
                gaussStructArray[z].rotation = ftofix(128/M_PI*turretAngle+64);
         }                             
     
     }
     
}

void startRocket(){
     int z = 0;
     while (rocketStructArray[z].active){
           z++; 
     }
     if (z < MAX_ROCKETS){
            play_sample(shootRocket, 255, 127, 1000, false);
            rocketStructArray[z].active = true;
            rocketStructArray[z].x = (x + WARTHOG_WIDTH/2) - (rocket->w/2) + TURRET_LENGTH*cos(turretAngle);
            rocketStructArray[z].y = (y + 93)              + TURRET_LENGTH*sin(turretAngle) - rocket->h/2;
            rocketStructArray[z].xVelocity = ROCKET_SPEED*cos(turretAngle);  
            rocketStructArray[z].yVelocity = ROCKET_SPEED*sin(turretAngle); 
            rocketStructArray[z].rotation = ftofix(128/M_PI*turretAngle+64);
     }    
     
     rotate_sprite(buffer,  rocketEffect, x+WARTHOG_WIDTH/2-bulletEffect->w/2, y+93-bulletEffect->h/2, mouse_angle()); 
     
     if (powerupThreeShot || powerupSevenShot){
             z = 0;
             while (rocketStructArray[z].active){
                   z++; 
             }
             if (z < MAX_ROCKETS){
                    rocketStructArray[z].active = true;
                    rocketStructArray[z].x = (x + WARTHOG_WIDTH/2) - (rocket->w/2) + TURRET_LENGTH*cos(turretAngle);
                    rocketStructArray[z].y = (y + 93)              + TURRET_LENGTH*sin(turretAngle) - rocket->h/2;
                    rocketStructArray[z].xVelocity = ROCKET_SPEED*cos(turretAngle + deg2Rad(THREE_OFFSET));  
                    rocketStructArray[z].yVelocity = ROCKET_SPEED*sin(turretAngle + deg2Rad(THREE_OFFSET)); 
                    rocketStructArray[z].rotation = ftofix(128/M_PI*turretAngle+64);
             }  
             
             z = 0;
             while (rocketStructArray[z].active){
                   z++; 
             }
             if (z < MAX_ROCKETS){
                    rocketStructArray[z].active = true;
                    rocketStructArray[z].x = (x + WARTHOG_WIDTH/2) - (rocket->w/2) + TURRET_LENGTH*cos(turretAngle);
                    rocketStructArray[z].y = (y + 93)              + TURRET_LENGTH*sin(turretAngle) - rocket->h/2;
                    rocketStructArray[z].xVelocity = ROCKET_SPEED*cos(turretAngle - deg2Rad(THREE_OFFSET));  
                    rocketStructArray[z].yVelocity = ROCKET_SPEED*sin(turretAngle - deg2Rad(THREE_OFFSET)); 
                    rocketStructArray[z].rotation = ftofix(128/M_PI*turretAngle+64);
             }  
             
     }
     
     if (powerupSevenShot){
     
             z = 0;
             while (rocketStructArray[z].active){
                   z++; 
             }
             if (z < MAX_ROCKETS){
                    rocketStructArray[z].active = true;
                    rocketStructArray[z].x = (x + WARTHOG_WIDTH/2) - (rocket->w/2) + TURRET_LENGTH*cos(turretAngle);
                    rocketStructArray[z].y = (y + 93)              + TURRET_LENGTH*sin(turretAngle) - rocket->h/2;
                    rocketStructArray[z].xVelocity = ROCKET_SPEED*cos(turretAngle + deg2Rad(THREE_OFFSET/2));  
                    rocketStructArray[z].yVelocity = ROCKET_SPEED*sin(turretAngle + deg2Rad(THREE_OFFSET/2)); 
                    rocketStructArray[z].rotation = ftofix(128/M_PI*turretAngle+64);
             }  
             
             z = 0;
             while (rocketStructArray[z].active){
                   z++; 
             }
             if (z < MAX_ROCKETS){
                    rocketStructArray[z].active = true;
                    rocketStructArray[z].x = (x + WARTHOG_WIDTH/2) - (rocket->w/2) + TURRET_LENGTH*cos(turretAngle);
                    rocketStructArray[z].y = (y + 93)              + TURRET_LENGTH*sin(turretAngle) - rocket->h/2;
                    rocketStructArray[z].xVelocity = ROCKET_SPEED*cos(turretAngle - deg2Rad(THREE_OFFSET/2));  
                    rocketStructArray[z].yVelocity = ROCKET_SPEED*sin(turretAngle - deg2Rad(THREE_OFFSET/2)); 
                    rocketStructArray[z].rotation = ftofix(128/M_PI*turretAngle+64);
             }  
             z = 0;
             while (rocketStructArray[z].active){
                   z++; 
             }
             if (z < MAX_ROCKETS){
                    rocketStructArray[z].active = true;
                    rocketStructArray[z].x = (x + WARTHOG_WIDTH/2) - (rocket->w/2) + TURRET_LENGTH*cos(turretAngle);
                    rocketStructArray[z].y = (y + 93)              + TURRET_LENGTH*sin(turretAngle) - rocket->h/2;
                    rocketStructArray[z].xVelocity = ROCKET_SPEED*cos(turretAngle + deg2Rad(THREE_OFFSET*3/2));  
                    rocketStructArray[z].yVelocity = ROCKET_SPEED*sin(turretAngle + deg2Rad(THREE_OFFSET*3/2)); 
                    rocketStructArray[z].rotation = ftofix(128/M_PI*turretAngle+64);
             }  
             
             z = 0;
             while (rocketStructArray[z].active){
                   z++; 
             }
             if (z < MAX_ROCKETS){
                    rocketStructArray[z].active = true;
                    rocketStructArray[z].x = (x + WARTHOG_WIDTH/2) - (rocket->w/2) + TURRET_LENGTH*cos(turretAngle);
                    rocketStructArray[z].y = (y + 93)              + TURRET_LENGTH*sin(turretAngle) - rocket->h/2;
                    rocketStructArray[z].xVelocity = ROCKET_SPEED*cos(turretAngle - deg2Rad(THREE_OFFSET*3/2));  
                    rocketStructArray[z].yVelocity = ROCKET_SPEED*sin(turretAngle - deg2Rad(THREE_OFFSET*3/2)); 
                    rocketStructArray[z].rotation = ftofix(128/M_PI*turretAngle+64);
             }  
              
                          
     }
}

void startBullet(){
     int z = 0;
     while (bulletShellArray[z].active){
           z++; 
     }
     if (z < MAX_BULLET_SHELLS){
            bulletShellArray[z].active = true;
            bulletShellArray[z].x = x + WARTHOG_WIDTH/2 ;
            bulletShellArray[z].y = y + 93;
            bulletShellArray[z].xVelocity = 4*cos(turretAngle+90);  
            bulletShellArray[z].yVelocity = 4*sin(turretAngle+90); 
            bulletShellArray[z].rotation = ftofix(128/M_PI*turretAngle+64);
     }
     
     z = 0;
     
     rotate_sprite(buffer,  bulletEffect, x+WARTHOG_WIDTH/2-bulletEffect->w/2, y+93-bulletEffect->h/2, mouse_angle()); 
     
     while (bulletStructArray[z].active){
           z++;
     }
     if (z < MAX_BULLETS){
            bulletStructArray[z].active = true;
            bulletStructArray[z].x = (x + WARTHOG_WIDTH/2) - (bullet->w/2) + TURRET_LENGTH*cos(turretAngle) ;
            bulletStructArray[z].y = (y + 93)              + TURRET_LENGTH*sin(turretAngle) ;
            bulletStructArray[z].xVelocity = BULLET_SPEED*cos(turretAngle);  
            bulletStructArray[z].yVelocity = BULLET_SPEED*sin(turretAngle); 
            bulletStructArray[z].rotation = ftofix(128/M_PI*turretAngle+64);           
     }
     
     if (powerupThreeShot || powerupSevenShot){
             z = 0;
             while (bulletStructArray[z].active){
                   z++;
             }
             if (z < MAX_BULLETS){
                    bulletStructArray[z].active = true;
                    bulletStructArray[z].x = (x + WARTHOG_WIDTH/2) - (bullet->w/2) + TURRET_LENGTH*cos(turretAngle) ;
                    bulletStructArray[z].y = (y + 93)              + TURRET_LENGTH*sin(turretAngle) ;
                    bulletStructArray[z].xVelocity = BULLET_SPEED*cos(turretAngle + deg2Rad(THREE_OFFSET));  
                    bulletStructArray[z].yVelocity = BULLET_SPEED*sin(turretAngle + deg2Rad(THREE_OFFSET)); 
                    bulletStructArray[z].rotation = ftofix(128/M_PI*turretAngle+64);           
             }
             
             z = 0;
             while (bulletStructArray[z].active){
                   z++;
             }
             if (z < MAX_BULLETS){
                    bulletStructArray[z].active = true;
                    bulletStructArray[z].x = (x + WARTHOG_WIDTH/2) - (bullet->w/2) + TURRET_LENGTH*cos(turretAngle) ;
                    bulletStructArray[z].y = (y + 93)              + TURRET_LENGTH*sin(turretAngle) ;
                    bulletStructArray[z].xVelocity = BULLET_SPEED*cos(turretAngle - deg2Rad(THREE_OFFSET));  
                    bulletStructArray[z].yVelocity = BULLET_SPEED*sin(turretAngle - deg2Rad(THREE_OFFSET)); 
                    bulletStructArray[z].rotation = ftofix(128/M_PI*turretAngle+64 );           
             }
             
     }
     
     if (powerupSevenShot){
             z = 0;
             while (bulletStructArray[z].active){
                   z++;
             }
             if (z < MAX_BULLETS){
                    bulletStructArray[z].active = true;
                    bulletStructArray[z].x = (x + WARTHOG_WIDTH/2) - (bullet->w/2) + TURRET_LENGTH*cos(turretAngle) ;
                    bulletStructArray[z].y = (y + 93)              + TURRET_LENGTH*sin(turretAngle) ;
                    bulletStructArray[z].xVelocity = BULLET_SPEED*cos(turretAngle + deg2Rad(THREE_OFFSET/2));  
                    bulletStructArray[z].yVelocity = BULLET_SPEED*sin(turretAngle + deg2Rad(THREE_OFFSET/2)); 
                    bulletStructArray[z].rotation = ftofix(128/M_PI*turretAngle+64);           
             }
             
             z = 0;
             while (bulletStructArray[z].active){
                   z++;
             }
             if (z < MAX_BULLETS){
                    bulletStructArray[z].active = true;
                    bulletStructArray[z].x = (x + WARTHOG_WIDTH/2) - (bullet->w/2) + TURRET_LENGTH*cos(turretAngle) ;
                    bulletStructArray[z].y = (y + 93)              + TURRET_LENGTH*sin(turretAngle) ;
                    bulletStructArray[z].xVelocity = BULLET_SPEED*cos(turretAngle - deg2Rad(THREE_OFFSET/2));  
                    bulletStructArray[z].yVelocity = BULLET_SPEED*sin(turretAngle - deg2Rad(THREE_OFFSET/2)); 
                    bulletStructArray[z].rotation = ftofix(128/M_PI*turretAngle+64 );           
             }
             
             z = 0;
             while (bulletStructArray[z].active){
                   z++;
             }
             if (z < MAX_BULLETS){
                    bulletStructArray[z].active = true;
                    bulletStructArray[z].x = (x + WARTHOG_WIDTH/2) - (bullet->w/2) + TURRET_LENGTH*cos(turretAngle) ;
                    bulletStructArray[z].y = (y + 93)              + TURRET_LENGTH*sin(turretAngle) ;
                    bulletStructArray[z].xVelocity = BULLET_SPEED*cos(turretAngle + deg2Rad(THREE_OFFSET*3/2));  
                    bulletStructArray[z].yVelocity = BULLET_SPEED*sin(turretAngle + deg2Rad(THREE_OFFSET*3/2)); 
                    bulletStructArray[z].rotation = ftofix(128/M_PI*turretAngle+64);           
             }
             
             z = 0;
             while (bulletStructArray[z].active){
                   z++;
             }
             if (z < MAX_BULLETS){
                    bulletStructArray[z].active = true;
                    bulletStructArray[z].x = (x + WARTHOG_WIDTH/2) - (bullet->w/2) + TURRET_LENGTH*cos(turretAngle) ;
                    bulletStructArray[z].y = (y + 93)              + TURRET_LENGTH*sin(turretAngle) ;
                    bulletStructArray[z].xVelocity = BULLET_SPEED*cos(turretAngle - deg2Rad(THREE_OFFSET*3/2));  
                    bulletStructArray[z].yVelocity = BULLET_SPEED*sin(turretAngle - deg2Rad(THREE_OFFSET*3/2)); 
                    bulletStructArray[z].rotation = ftofix(128/M_PI*turretAngle+64 );           
             }    
     }
}

void updateBullets(){
     int w;
     
     for (w = 0; w< MAX_BULLETS; w++){
         if (bulletStructArray[w].active == true){
             bulletStructArray[w].x += bulletStructArray[w].xVelocity;
             bulletStructArray[w].y += bulletStructArray[w].yVelocity;
             rotate_sprite(buffer, bullet, bulletStructArray[w].x, bulletStructArray[w].y, bulletStructArray[w].rotation); 
         }
         if (bulletStructArray[w].x > SCREEN_W || bulletStructArray[w].x < 0 || bulletStructArray[w].y > SCREEN_H || bulletStructArray[w].y < 0)
                bulletStructArray[w].active = false;   
     }
     for (w = 0; w < MAX_BULLET_SHELLS; w++){
         if (bulletShellArray[w].active == true){
            bulletShellArray[w].x += bulletShellArray[w].xVelocity;
            bulletShellArray[w].y += bulletShellArray[w].yVelocity;
            rotate_sprite(buffer, bulletShell, bulletShellArray[w].x, bulletShellArray[w].y, itofix(bulletShellArray[w].rotation)); 
            bulletShellArray[w].rotation += 6;
            bulletShellArray[w].yVelocity += 0.2;
            bulletShellArray[w].rotation %= 360;

         }
         if (bulletShellArray[w].x > SCREEN_W || bulletShellArray[w].x < 0 || bulletShellArray[w].y > SCREEN_H)
            bulletShellArray[w].active = false;
     }  
     
     for (w = 0; w < MAX_ROCKETS; w++){
         if (rocketStructArray[w].active == true){
             rocketStructArray[w].x += rocketStructArray[w].xVelocity;
             rocketStructArray[w].y += rocketStructArray[w].yVelocity;
             rotate_sprite(buffer, rocket, rocketStructArray[w].x, rocketStructArray[w].y, rocketStructArray[w].rotation);
         }
     
         if (rocketStructArray[w].x > SCREEN_W || rocketStructArray[w].x < 0 || rocketStructArray[w].y > SCREEN_H || rocketStructArray[w].y < 0)
                rocketStructArray[w].active = false;
     }   
     
     for (w = 0; w < MAX_GAUSS; w++){
         if (gaussStructArray[w].active == true){
             gaussStructArray[w].x += gaussStructArray[w].xVelocity;
             gaussStructArray[w].y += gaussStructArray[w].yVelocity;
             rotate_sprite(buffer, gauss, gaussStructArray[w].x, gaussStructArray[w].y, gaussStructArray[w].rotation);
         }
     
         if (gaussStructArray[w].x > SCREEN_W || gaussStructArray[w].x < 0 || gaussStructArray[w].y > SCREEN_H || gaussStructArray[w].y < 0)
                gaussStructArray[w].active = false;
     }
     
     for (w = 0; w < MAX_ENEMY_BULLETS; w++){
         if (enemyBulletArray[w].active == true){
             enemyBulletArray[w].x += enemyBulletArray[w].xVelocity;
             enemyBulletArray[w].y += enemyBulletArray[w].yVelocity;
             rotate_sprite(buffer, enemyBullet, enemyBulletArray[w].x, enemyBulletArray[w].y, enemyBulletArray[w].rotation);
         }
     
         if (enemyBulletArray[w].x > SCREEN_W || enemyBulletArray[w].x < 0 || enemyBulletArray[w].y > SCREEN_H || enemyBulletArray[w].y < 0)
                enemyBulletArray[w].active = false;
     }
     
     for (w = 0; w < MAX_LASERS; w++){
         if (laserStructArray[w].active == true){
             laserStructArray[w].x += laserStructArray[w].xVelocity;
             laserStructArray[w].y += laserStructArray[w].yVelocity;
             rotate_sprite(buffer, laser, laserStructArray[w].x, laserStructArray[w].y, laserStructArray[w].rotation);
         }
     
         if (laserStructArray[w].x > SCREEN_W || laserStructArray[w].x < 0 || laserStructArray[w].y > SCREEN_H || laserStructArray[w].y < 0)
                laserStructArray[w].active = false;
     }     
     
}

float deg2Rad(int deg){
      return (float(deg*M_PI/180));
}

int rad2Deg(float rad){
      return (int(rad/M_PI*180));
}
