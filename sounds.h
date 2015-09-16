MIDI *backgroundMusic;

SAMPLE *warthogEngine;
SAMPLE *shootBullet, *shootRocket, *shootGauss;
SAMPLE *bulletHit, *rocketHit, *gaussHit;
SAMPLE *eDeath01, *eDeath02, *eDeath03, *eDeath04, *eDeath05, *eDeath06, 
       *eDeath07, *eDeath08;
SAMPLE *eCall01, *eCall02, *eCall03, *eCall04, *eCall05;
SAMPLE *mCall01, *mCall02, *mCall03, *mCall04, *mCall05, *mCall06, 
       *mCall07, *mCall08, *mCall09, *mCall10, *mCall11; 
SAMPLE *guiltySpark01, *guiltySpark02, *guiltySpark03, *guiltySpark04;
SAMPLE *spartanLaser;
SAMPLE *gameOverVoice;



void loadSounds(){
     
     //backgroundMusic = load_midi("On_A_Pale_Horse.mid");
     warthogEngine = load_sample("Sounds//warthogEngine.wav");
     
     shootBullet = load_sample("Sounds//shootBullet.wav");
     shootGauss  = load_sample("Sounds//shootGauss.wav");
     shootRocket = load_sample("Sounds//shootRocket.wav");
     
     bulletHit = load_sample("Sounds//bulletHit.wav");
     rocketHit = load_sample("Sounds//rocketHit.wav");
     gaussHit  = load_sample("Sounds//gaussHit.wav");
     
     eDeath01 = load_sample("Sounds//eDeath01.wav");
     eDeath02 = load_sample("Sounds//eDeath02.wav");
     eDeath03 = load_sample("Sounds//eDeath03.wav");
     eDeath04 = load_sample("Sounds//eDeath04.wav");
     eDeath05 = load_sample("Sounds//eDeath05.wav");
     eDeath06 = load_sample("Sounds//eDeath06.wav");
     eDeath07 = load_sample("Sounds//eDeath07.wav");
     eDeath08 = load_sample("Sounds//eDeath08.wav");
     
     eCall01 = load_sample("Sounds//eCall01.wav");
     eCall02 = load_sample("Sounds//eCall02.wav");
     eCall03 = load_sample("Sounds//eCall03.wav");
     eCall04 = load_sample("Sounds//eCall04.wav");
     eCall05 = load_sample("Sounds//eCall05.wav");
     
     mCall01 = load_sample("Sounds//mCall01.wav");
     mCall02 = load_sample("Sounds//mCall02.wav");
     mCall03 = load_sample("Sounds//mCall03.wav");
     mCall04 = load_sample("Sounds//mCall04.wav");
     mCall05 = load_sample("Sounds//mCall05.wav");
     mCall06 = load_sample("Sounds//mCall06.wav");
     mCall07 = load_sample("Sounds//mCall07.wav");
     mCall08 = load_sample("Sounds//mCall08.wav");
     mCall09 = load_sample("Sounds//mCall09.wav");
     mCall10 = load_sample("Sounds//mCall10.wav");
     mCall11 = load_sample("Sounds//mCall11.wav");
     
     guiltySpark01 = load_sample("Sounds//guiltySpark01.wav");
     guiltySpark02 = load_sample("Sounds//guiltySpark02.wav");
     guiltySpark03 = load_sample("Sounds//guiltySpark03.wav");
     guiltySpark04 = load_sample("Sounds//guiltySpark04.wav");
     
     spartanLaser = load_sample("Sounds//spartanLaser.wav");
     gameOverVoice = load_sample("Sounds//gameOver.wav");
     
     soundErrorCheck();

}

void soundErrorCheck(){
   	if (!warthogEngine) {
		allegro_message("Error loading warthogEngine.wav file");
    }
    ////////////////////////////////////////////////////////////
    //if (!shootBullet) {
	//	allegro_message("Error loading shootBullet.wav file");
    //}
    if (!shootGauss) {
		allegro_message("Error loading shootGauss.wav file");
    }
    if (!shootRocket) {
		allegro_message("Error loading shootRocket.wav file");
    }
    /*///////////////////////////////////////////////////////////*
    if (!bulletHit){
        allegro_message("Error loading bulletHit.wav file");
    }
    if (!gaussHit){
        allegro_message("Error loading gaussHit.wav file");
    }
    if (!rocketHit){
        allegro_message("Error loading rocketHit.wav file");
    }
    *////////////////////////////////////////////////////////////
    if (!eDeath01){
        allegro_message("Error loading eDeath01.wav file");
    }
    if (!eDeath02){
        allegro_message("Error loading eDeath02.wav file");
    }
    if (!eDeath03){
        allegro_message("Error loading eDeath03.wav file");
    }
    if (!eDeath04){
        allegro_message("Error loading eDeath04.wav file");
    }
    if (!eDeath05){
        allegro_message("Error loading eDeath05.wav file");
    }
    if (!eDeath06){
        allegro_message("Error loading eDeath06.wav file");
    }
    if (!eDeath07){
        allegro_message("Error loading eDeath07.wav file");
    }
    if (!eDeath08){
        allegro_message("Error loading eDeath08.wav file");
    }
    ////////////////////////////////////////////////////////////
    if (!eCall01){
        allegro_message("Error loading eCall01.wav file");
    }
    if (!eCall02){
        allegro_message("Error loading eCall02.wav file");
    }
    if (!eCall03){
        allegro_message("Error loading eCall03.wav file");
    }
    if (!eCall04){
        allegro_message("Error loading eCall04.wav file");
    }
    if (!eCall05){
        allegro_message("Error loading eCall05.wav file");
    }
    ////////////////////////////////////////////////////////////
    if (!mCall01){
        allegro_message("Error loading mCall01.wav file");
    }
    if (!mCall02){
        allegro_message("Error loading mCall02.wav file");
    }
    if (!mCall03){
        allegro_message("Error loading mCall03.wav file");
    }
    if (!mCall04){
        allegro_message("Error loading mCall04.wav file");
    }
    if (!mCall05){
        allegro_message("Error loading mCall05.wav file");
    }
    if (!mCall06){
        allegro_message("Error loading mCall06.wav file");
    }
    if (!mCall07){
        allegro_message("Error loading mCall07.wav file");
    }
    if (!mCall08){
        allegro_message("Error loading mCall08.wav file");
    }
    if (!mCall09){
        allegro_message("Error loading mCall09.wav file");
    }
    if (!mCall10){
        allegro_message("Error loading mCall10.wav file");
    }
    if (!mCall11){
        allegro_message("Error loading mCall11.wav file");
    }
    ////////////////////////////////////////////////////////////
    if (!guiltySpark01){
        allegro_message("Error loading guiltySpark01.wav file");
    }
    if (!guiltySpark02){
        allegro_message("Error loading guiltySpark02.wav file");
    }
    if (!guiltySpark03){
        allegro_message("Error loading guiltySpark03.wav file");
    }
    if (!guiltySpark04){
        allegro_message("Error loading guiltySpark04.wav file");
    }
    ////////////////////////////////////////////////////////////
    if (!spartanLaser){
        allegro_message("Error loading spartanLaser.wav file");
    }    
    if (!gameOverVoice){
        allegro_message("Error loading gameOver.wav file");
    }    
    
    
}

void playRandomDeath(){
     switch(getRanNum(1, 8)){
          case 1:
               play_sample(eDeath01, 255, 127, 1000, false);
               break;
          case 2:
               play_sample(eDeath02, 255, 127, 1000, false);
               break;
          case 3:
               play_sample(eDeath03, 255, 127, 1000, false);
               break;
          case 4:
               play_sample(eDeath04, 255, 127, 1000, false);
               break;
          case 5:
               play_sample(eDeath05, 255, 127, 1000, false);
               break;
          case 6:
               play_sample(eDeath06, 255, 127, 1000, false);
               break;
          case 7:
               play_sample(eDeath07, 255, 127, 1000, false);
               break;
          case 8:
               play_sample(eDeath08, 255, 127, 1000, false);
               break;
          default:
               play_sample(eDeath01, 255, 127, 1000, false);
     }
}

void playRandomMarineCall(){
     switch(getRanNum(1, 11)){
          case 1:
               play_sample(mCall01, 255, 127, 1000, false);
               break;
          case 2:
               play_sample(mCall02, 255, 127, 1000, false);
               break;
          case 3:
               play_sample(mCall03, 255, 127, 1000, false);
               break;
          case 4:
               play_sample(mCall04, 255, 127, 1000, false);
               break;
          case 5:
               play_sample(mCall05, 255, 127, 1000, false);
               break;
          case 6:
               play_sample(mCall06, 255, 127, 1000, false);
               break;
          case 7:
               play_sample(mCall07, 255, 127, 1000, false);
               break;
          case 8:
               play_sample(mCall08, 255, 127, 1000, false);
               break;
          case 9:
               play_sample(mCall09, 255, 127, 1000, false);
               break;
          case 10:
               play_sample(mCall10, 255, 127, 1000, false);
               break;
          case 11:
               play_sample(mCall11, 255, 127, 1000, false);
               break;
          default:
               play_sample(mCall01, 255, 127, 1000, false);
     }
}

void playRandomEnemyCall(){
     switch(getRanNum(1, 6)){
          case 1:
               play_sample(eCall01, 255, 127, 1000, false);
               break;
          case 2:
               play_sample(eCall02, 255, 127, 1000, false);
               break;
          case 3:
               play_sample(eCall03, 255, 127, 1000, false);
               break;
          case 4:
               play_sample(eCall04, 255, 127, 1000, false);
               break;
          case 5:
               play_sample(eCall05, 255, 127, 1000, false);
               break;

          default:
               play_sample(mCall01, 255, 127, 1000, false);
     }
}

void playIntroduction(){
     play_sample(guiltySpark01, 255, 127, 1000, false);
                                rest(2000);
     play_sample(guiltySpark02, 255, 127, 1000, false);
                                rest(2000);
     play_sample(guiltySpark03, 255, 127, 1000, false);
                                rest(2000);
     play_sample(guiltySpark04, 255, 127, 1000, false);
                                rest(2000);
}

int soundInit(){
     
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, "") != 0) 
    {
        allegro_message("Error initializing sound system");
        return 1;
    }
    	
	backgroundMusic = load_midi("Sounds//On_A_Pale_Horse.mid");
	
	if (!backgroundMusic) {
		allegro_message("Error loading Midi file");
		return 1;
	}
	
	if (play_midi(backgroundMusic, 1) != 0) {
		allegro_message("Error playing Midi\n%s", allegro_error);
		return 1;
	}
	
	return 0;     
}
