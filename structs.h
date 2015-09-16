struct playerStruct{
       int score;
       int health;
};

struct playerStruct player = {0};

struct laserStruct{
       int x;
       int y;
       fixed rotation;
       int bulletSpeed;
       bool active;
       float xVelocity;
       float yVelocity;
};

struct laserStruct laserStructArray[MAX_LASERS] = {0};

struct laserExplosionStruct{
       int x;
       int y;
       int frame;
       bool active;
};

struct laserExplosionStruct laserExplosionArray[MAX_LASER_EXPLOSIONS] = {0};

struct bulletStruct{
       int x;
       int y;
       fixed rotation;      
       bool active;   
       float xVelocity;
       float yVelocity;
};

struct bulletStruct bulletStructArray[MAX_BULLETS] = {0};

struct bulletShellStruct{
       int x;
       int y;
       fixed rotation;      
       bool active;   
       float xVelocity;
       float yVelocity;
       int damage;
};

struct bulletShellStruct bulletShellArray[MAX_BULLET_SHELLS] = {0};

struct bulletExplosionStruct{
       int x;
       int y;
       int frame;
       bool active;
};

struct bulletExplosionStruct bulletExplosionArray[MAX_BULLET_EXPLOSIONS];

struct rocketStruct{
       int x;
       int y;
       fixed rotation;
       bool active;
       bool hit;
       float xVelocity;
       float yVelocity;
       int xExplo;
       int yExplo;
};

struct rocketStruct rocketStructArray[MAX_ROCKETS] = {0};

struct rocketExplosionStruct{
       int x;
       int y;
       int frame;
       bool active;
};

struct rocketExplosionStruct rocketExplosionArray[MAX_ROCKET_EXPLOSIONS];

struct guassStruct{
       int x;
       int y;
       fixed rotation;
       bool active;
       bool hit;
       float xVelocity;
       float yVelocity;
       int xExplo;
       int yExplo;
       int damage;
};

struct guassStruct gaussStructArray[MAX_GAUSS] = {0};

struct gaussExplosionStruct{
       int x;
       int y;
       int frame;
       bool active;
};

struct gaussExplosionStruct gaussExplosionArray[MAX_GAUSS_EXPLOSIONS] = {0};

struct bansheeExplosionStruct{
       int x;
       int y;
       int frame;
       bool active;
};

struct bansheeExplosionStruct bansheeExplosionArray[MAX_BANSHEE_EXPLOSIONS] = {0};

struct enemyStruct{
       bool active;
       bool alive;
       int x;
       int y;
       float velocity;
       fixed rotation;
       int health;
       BITMAP *enemy;
};

struct enemyStruct enemyStructArray[MAX_ENEMIES] = {0};

struct enemyVehicleStruct{
       bool active;
       bool alive;
       int x;
       int y;
       int lowPoint;
       float velocity;
       int rotate;
       fixed rotation;
       int health;
       int ROF;
       int ROFcount;
       BITMAP *enemy;
};

struct enemyVehicleStruct enemyVehicleArray[MAX_ENEMY_VEHICLES] = {0};

struct enemyBulletStruct{
       int x;
       int y;
       fixed rotation;      
       bool active;   
       float xVelocity;
       float yVelocity;
       int bulletSpeed;
};

struct enemyBulletStruct enemyBulletArray[MAX_ENEMY_BULLETS] = {0};

struct powerupStruct{
       bool active;
       int x;
       int y;
       fixed rotation;
       BITMAP *powerup;
};

struct powerupStruct powerupArray[MAX_POWERUPS] = {0};
