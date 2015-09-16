void initializeEnemies(){
     int h;
     for (h = 0; h < MAX_ENEMIES; h++){
         enemyStructArray[h].x = getRanNum(       0,   SCREEN_W);
         enemyStructArray[h].y = getRanNum(SCREEN_H, SCREEN_H*40) * -1;
         enemyStructArray[h].alive = true;
         enemyStructArray[h].velocity = getRanNum(0, MAX_ENEMY_SPEED);
         enemyStructArray[h].rotation = getRanNum(0, 360);
         enemyStructArray[h].active = false;    
         enemyStructArray[h].health = 100;
         enemyStructArray[h].enemy = getRandomEnemy();
     }
     
}

void updateEnemies(){
     int h;
     for (h = 0; h < MAX_ENEMIES; h++){
         
         if (enemyStructArray[h].health <= 0){
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
              //enemyStructArray[h].rotation = 0; //ftofix(128/M_PI*turretAngle+64); //insert warthog direction
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
}
