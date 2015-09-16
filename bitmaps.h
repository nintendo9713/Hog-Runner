BITMAP *buffer;
BITMAP *warthog, *warthogG, *marine;
BITMAP *turretM, *turretR, *turretG;
BITMAP *bullet, *rocket, *gauss, *laser;
BITMAP *crosshair, *bulletShell;
BITMAP *bulletEffect, *rocketEffect, *gaussEffect;
BITMAP *bulletExplosion, *rocketExplosion, *gaussExplosion, *laserExplosion;
BITMAP *powerInvincible, *powerRocket, *powerGauss, *powerThreeShot, *powerSevenShot;
BITMAP *enemy00, *enemy01, *enemy02, *enemy03, *enemy04, *enemy05;
BITMAP *eDead00, *eDead01, *eDead02, *eDead03, *eDead04, *eDead05;
BITMAP *banshee, *bansheeDead, *bansheeExplosion, *enemyBullet;


void bitmapInit(){

    banshee = load_bitmap("Images//Enemies//banshee.bmp", NULL);
    bansheeDead = load_bitmap("Images//Enemies//bansheeDead.bmp", NULL);
    bansheeExplosion = load_bitmap("Images//Explosions//bansheeExplosion.bmp", NULL);
    buffer    = create_bitmap(SCREEN_W, SCREEN_H);
    bullet    = load_bitmap("Images//Projectiles//Bullet.bmp", NULL);
    bulletEffect = load_bitmap("Images//Effects//bulletEffect.bmp", NULL);
    bulletExplosion = load_bitmap("Images//Explosions//bulletExplosion.bmp", NULL);
    bulletShell = load_bitmap("Images//Effects//bulletShell.bmp", NULL);
    crosshair = load_bitmap("Images//Crosshair.bmp", NULL);
    eDead00 = load_bitmap("Images//Enemies//eDead00.bmp", NULL);
    eDead01 = load_bitmap("Images//Enemies//eDead01.bmp", NULL);
    eDead02 = load_bitmap("Images//Enemies//eDead02.bmp", NULL);
    eDead03 = load_bitmap("Images//Enemies//eDead03.bmp", NULL);
    eDead04 = load_bitmap("Images//Enemies//eDead04.bmp", NULL);
    eDead05 = load_bitmap("Images//Enemies//eDead05.bmp", NULL);
    enemy00 = load_bitmap("Images//Enemies//enemy00.bmp", NULL);
    enemy01 = load_bitmap("Images//Enemies//enemy01.bmp", NULL);
    enemy02 = load_bitmap("Images//Enemies//enemy02.bmp", NULL);
    enemy03 = load_bitmap("Images//Enemies//enemy03.bmp", NULL);
    enemy04 = load_bitmap("Images//Enemies//enemy04.bmp", NULL);
    enemy05 = load_bitmap("Images//Enemies//enemy05.bmp", NULL);
    enemyBullet = load_bitmap("Images//Projectiles//enemyBullet.bmp", NULL);
    gauss     = load_bitmap("Images//Projectiles//Gauss.bmp", NULL);
    gaussEffect = load_bitmap("Images//Effects//gausseffect.bmp", NULL);
    gaussExplosion = load_bitmap("Images//Explosions//gaussExplosion.bmp", NULL);
    laser     = load_bitmap("Images//Projectiles//Laser.bmp", NULL);
    laserExplosion = load_bitmap("Images//Explosions//laserExplosion.bmp", NULL);
    marine    = load_bitmap("Images//Vehicle//Marine.bmp", NULL);
    powerGauss      = load_bitmap("Images//Powerups//powerGauss.bmp", NULL);
    powerInvincible = load_bitmap("Images//Powerups//powerInvincible.bmp", NULL);
    powerRocket     = load_bitmap("Images//Powerups//powerRocket.bmp", NULL);
    powerSevenShot  = load_bitmap("Images//Powerups//powerSevenShot.bmp", NULL);
    powerThreeShot  = load_bitmap("Images//Powerups//powerThreeShot.bmp", NULL);
    rocket    = load_bitmap("Images//Projectiles//Rocket.bmp", NULL);
    rocketEffect = load_bitmap("Images//Effects//rocketEffect.bmp", NULL);
    rocketExplosion= load_bitmap("Images//Explosions//rocketExplosion.bmp", NULL);
    turretG   = load_bitmap("Images//Vehicle//TurretG.bmp", NULL);
    turretM   = load_bitmap("Images//Vehicle//TurretM.bmp", NULL);
    turretR   = load_bitmap("Images//Vehicle//TurretR.bmp", NULL);
    warthog   = load_bitmap("Images//Vehicle//Warthog.bmp", NULL);
    warthogG  = load_bitmap ("Images//Vehicle//WarthogG.bmp", NULL);

    /* 
    buffer    = create_bitmap(SCREEN_W, SCREEN_H);
    warthog   = load_bitmap("Images//Vehicle//Warthog.bmp", NULL);
    warthogG  = load_bitmap ("Images//Vehicle//WarthogG.bmp", NULL);
    turretM   = load_bitmap("Images//Vehicle//TurretM.bmp", NULL);
    turretR   = load_bitmap("Images//Vehicle//TurretR.bmp", NULL);
    turretG   = load_bitmap("Images//Vehicle//TurretG.bmp", NULL);
    marine    = load_bitmap("Images//Vehicle//Marine.bmp", NULL);
    bullet    = load_bitmap("Images//Projectiles//Bullet.bmp", NULL);
    rocket    = load_bitmap("Images//Projectiles//Rocket.bmp", NULL);
    gauss     = load_bitmap("Images//Projectiles//Gauss.bmp", NULL);
    laser     = load_bitmap("Images//Projectiles//Laser.bmp", NULL);
    bulletShell = load_bitmap("Images//Effects//bulletShell.bmp", NULL);
    crosshair = load_bitmap("Images//Crosshair.bmp", NULL);
    bulletEffect = load_bitmap("Images//Effects//bulletEffect.bmp", NULL);
    rocketEffect = load_bitmap("Images//Effects//rocketEffect.bmp", NULL);
    gaussEffect = load_bitmap("Images//Effects//gausseffect.bmp", NULL);
    bulletExplosion = load_bitmap("Images//Explosions//bulletExplosion.bmp", NULL);
    rocketExplosion= load_bitmap("Images//Explosions//rocketExplosion.bmp", NULL);
    gaussExplosion = load_bitmap("Images//Explosions//gaussExplosion.bmp", NULL);
    bansheeExplosion = load_bitmap("Images//Explosions//bansheeExplosion.bmp", NULL);
    laserExplosion = load_bitmap("Images//Explosions//laserExplosion.bmp", NULL);
    
    powerInvincible = load_bitmap("Images//Powerups//powerInvincible.bmp", NULL);
    powerRocket     = load_bitmap("Images//Powerups//powerRocket.bmp", NULL);
    powerGauss      = load_bitmap("Images//Powerups//powerGauss.bmp", NULL);
    powerThreeShot  = load_bitmap("Images//Powerups//powerThreeShot.bmp", NULL);
    powerSevenShot  = load_bitmap("Images//Powerups//powerSevenShot.bmp", NULL);
    
    
    enemy00 = load_bitmap("Images//Enemies//enemy00.bmp", NULL);
    enemy01 = load_bitmap("Images//Enemies//enemy01.bmp", NULL);
    enemy02 = load_bitmap("Images//Enemies//enemy02.bmp", NULL);
    enemy03 = load_bitmap("Images//Enemies//enemy03.bmp", NULL);
    enemy04 = load_bitmap("Images//Enemies//enemy04.bmp", NULL);
    enemy05 = load_bitmap("Images//Enemies//enemy05.bmp", NULL);
    
    eDead00 = load_bitmap("Images//Enemies//eDead00.bmp", NULL);
    eDead01 = load_bitmap("Images//Enemies//eDead01.bmp", NULL);
    eDead02 = load_bitmap("Images//Enemies//eDead02.bmp", NULL);
    eDead03 = load_bitmap("Images//Enemies//eDead03.bmp", NULL);
    eDead04 = load_bitmap("Images//Enemies//eDead04.bmp", NULL);
    eDead05 = load_bitmap("Images//Enemies//eDead05.bmp", NULL);
    
    banshee = load_bitmap("Images//Enemies//banshee.bmp", NULL);
    bansheeDead = load_bitmap("Images//Enemies//bansheeDead.bmp", NULL);
    enemyBullet = load_bitmap("Images//Projectiles//enemyBullet.bmp", NULL);
    */
    bitmapErrorCheck();
    
    
}

void bitmapErrorCheck(){
     
   	if (!warthog) {
		allegro_message("Error loading Warthog.bmp file");
    }
    if (!warthogG) {
		allegro_message("Error loading Warthog.bmp file");
    }
    if (!turretM) {
		allegro_message("Error loading Warthog.bmp file");
    }
    if (!turretR) {
		allegro_message("Error loading Warthog.bmp file");
    }
    if (!turretG) {
		allegro_message("Error loading Warthog.bmp file");
    }
    if (!marine) {
		allegro_message("Error loading Warthog.bmp file");
    }
    if (!bullet) {
		allegro_message("Error loading Warthog.bmp file");
    }
    if (!rocket) {
		allegro_message("Error loading Warthog.bmp file");
    }
    if (!gauss) {
		allegro_message("Error loading Warthog.bmp file");
    }
    if (!laser) {
		allegro_message("Error loading Warthog.bmp file");
    }
    if (!bulletShell) {
		allegro_message("Error loading Warthog.bmp file");
    }
    if (!crosshair) {
		allegro_message("Error loading Warthog.bmp file");
    }
    if (!bulletEffect) {
		allegro_message("Error loading Warthog.bmp file");
    }
    if (!rocketEffect) {
		allegro_message("Error loading Warthog.bmp file");
    }
    if (!gaussEffect) {
		allegro_message("Error loading Warthog.bmp file");    
    }
    if (!bulletExplosion) {
		allegro_message("Error loading Warthog.bmp file");
    }
    if (!rocketExplosion) {
		allegro_message("Error loading Warthog.bmp file");
    }
    if (!gaussExplosion) {
		allegro_message("Error loading Warthog.bmp file");    
    }
    if (!bansheeExplosion) {
		allegro_message("Error loading Warthog.bmp file");
    }
    if (!laserExplosion) {
		allegro_message("Error loading Warthog.bmp file");    
    }
    if (!powerInvincible) {
		allegro_message("Error loading Warthog.bmp file");
    }
    if (!powerGauss) {
		allegro_message("Error loading Warthog.bmp file");    
    }
    if (!powerRocket) {
		allegro_message("Error loading Warthog.bmp file");
    }
    if (!powerThreeShot) {
		allegro_message("Error loading Warthog.bmp file");
    }
    if (!powerSevenShot) {
		allegro_message("Error loading Warthog.bmp file");    
    }
    if (!enemy01){
        allegro_message("Error loading eCall01.wav file");
    }
    if (!enemy02){
        allegro_message("Error loading eCall02.wav file");
    }
    if (!enemy03){
        allegro_message("Error loading eCall03.wav file");
    }
    if (!enemy04){
        allegro_message("Error loading eCall04.wav file");
    }
    if (!enemy05){
        allegro_message("Error loading eCall05.wav file");
    }
    if (!eDead01){
        allegro_message("Error loading eCall01.wav file");
    }
    if (!eDead02){
        allegro_message("Error loading eCall02.wav file");
    }
    if (!eDead03){
        allegro_message("Error loading eCall03.wav file");
    }
    if (!eDead04){
        allegro_message("Error loading eCall04.wav file");
    }
    if (!eDead05){
        allegro_message("Error loading eCall05.wav file");
    }
    if (!banshee){
        allegro_message("Error loading eCall05.wav file");
    }
    if (!enemyBullet){
        allegro_message("Error loading eCall05.wav file");
    }
    if (!bansheeDead){
        allegro_message("Error loading eCall05.wav file");
    }
     
}
