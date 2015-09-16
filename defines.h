#define BARRIER 100
#define BOTTOM 32000 - 480
#define BULLET_DAMAGE 34
#define BULLET_SPEED 15
#define ENEMY_BULLET_SPEED 8
#define GAUSS_DAMAGE 50
#define GAUSS_SPEED 25
#define KNOCKBACK 10
#define LASER_DAMAGE 2000
#define MAX_BANSHEE_EXPLOSIONS 100
#define MAX_BULLET_EXPLOSIONS 100
#define MAX_BULLET_SHELLS 100
#define MAX_BULLETS 1000
#define MAX_ENEMIES 2000
#define MAX_ENEMY_BULLETS 100
#define MAX_ENEMY_SPEED 5
#define MAX_ENEMY_VEHICLES 100
#define MAX_GAUSS 500
#define MAX_GAUSS_EXPLOSIONS 50
#define MAX_LASER_EXPLOSIONS 100
#define MAX_LASERS 1
#define MAX_POWERUPS 20
#define MAX_ROCKET_EXPLOSIONS 50
#define MAX_ROCKETS 500
#define MAX_VEHICLE_SPEED 10
#define POWERUP_TIME_INCREMENT 250
#define ROCKET_DAMAGE 100
#define ROCKET_SPEED 15
#define SCROLL_SPEED 10
#define STARTING_HEALTH 1000
#define STARTING_POINT_X 292
#define STARTING_POINT_Y 300
#define THREE_OFFSET 25
#define TURRET_LENGTH 33
#define WARTHOG_HEIGHT 120
#define WARTHOG_WIDTH 56

#define BLACK makecol(0,0,0)
#define BLUE makecol(0,0,255)
#define CORNFLOWERBLUE makecol(100, 149, 237)
#define GOLD makecol(255,215,0)
#define GREEN makecol(0,255,0)
#define MAGENTA makecol(255,0,255)
#define ORANGE makecol(255,165,0)
#define RED makecol(255,0,0)
#define SMOKE makecol(140,130,120)
#define WHITE makecol(255,255,255)
#define YELLOW makecol(255,255,0)

bool invincible = false;
bool powerupGauss = false;
bool powerupRocket = false;
bool powerupSevenShot = false;
bool powerupThreeShot = false;
float turretAngle;
float enemyAngle;
int currentWeapon = 1;
int SPEED = 8;
int wheelRotation, bulletRotation;
int x, y;
int xPos, yPos;
int yoffset = BOTTOM;
int enemyLockOn = -1;


/*
#define STARTING_POINT_X 292
#define STARTING_POINT_Y 300
#define BARRIER 100
#define WARTHOG_WIDTH 56
#define WARTHOG_HEIGHT 120
#define TURRET_LENGTH 33
#define BOTTOM 32000 - 480
#define SCROLL_SPEED 10
#define BULLET_SPEED 15
#define MAX_BULLETS 1000
#define MAX_BULLET_SHELLS 100
#define MAX_BULLET_EXPLOSIONS 100
#define ROCKET_SPEED 15
#define MAX_ROCKET_EXPLOSIONS 50
#define MAX_ROCKETS 500
#define GAUSS_SPEED 25
#define MAX_GAUSS_EXPLOSIONS 50
#define MAX_GAUSS 500
#define MAX_LASERS 5
#define MAX_ENEMIES 2000
#define MAX_ENEMY_SPEED 5
#define MAX_VEHICLE_SPEED 10
#define BULLET_DAMAGE 34
#define ROCKET_DAMAGE 100
#define GAUSS_DAMAGE 50
#define THREE_OFFSET 25
#define MAX_POWERUPS 20
#define POWERUP_TIME_INCREMENT 250
#define MAX_ENEMY_VEHICLES 100
#define STARTING_HEALTH 1000
#define MAX_ENEMY_BULLETS 100
#define ENEMY_BULLET_SPEED 8
#define MAX_BANSHEE_EXPLOSIONS 100
#define KNOCKBACK 10
#define LASER_DAMAGE 20
#define MAX_LASER_EXPLOSIONS 100

//Colors

#define WHITE makecol(255,255,255)
#define BLACK makecol(0,0,0)
#define RED makecol(255,0,0)
#define GREEN makecol(0,255,0)
#define BLUE makecol(0,0,255)
#define SMOKE makecol(140,130,120)
#define CORNFLOWERBLUE makecol(100, 149, 237)
#define ORANGE makecol(255,165,0)
#define YELLOW makecol(255,255,0)
#define MAGENTA makecol(255,0,255)
#define GOLD makecol(255,215,0)



float turretAngle;
int yoffset = BOTTOM;
int SPEED = 8;
int x, y;
int xPos, yPos;
int wheelRotation, bulletRotation;
int currentWeapon = 1;


bool invincible = false;
bool powerupRocket = false;
bool powerupGauss = false;
bool powerupThreeShot = false;
bool powerupSevenShot = false;


*/
