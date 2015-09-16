void HUD(){
          char data[200];
          sprintf(data, "Total Score:  %6d",  player.score);
          textout_right_ex(buffer, font, data, SCREEN_W - 10, 10, RED, -1);
          sprintf(data, "Health", player.health);
          textout_right_ex(buffer, font, data, SCREEN_W - 10, SCREEN_H-20, RED, -1);
          
          int tempHealth = player.health;
          int i = 1;
          int color = BLACK;
          if (tempHealth > STARTING_HEALTH*2/3)
             color = GREEN;
          else if (tempHealth > STARTING_HEALTH*1/3)
             color = YELLOW;
          else color = RED;
          while(tempHealth > 0){
                           textout_right_ex(buffer, font, "|", SCREEN_W - 3*i++ - 3, SCREEN_H-10, color, -1);
                           tempHealth -= 25;
          }
          
}
