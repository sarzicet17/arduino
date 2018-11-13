//Dual Moco

//カットオフ系 : CC 52
//レゾナンス系 : CC 53
//それ以外 - 1 : CC 54
//それ以外　 -2 : CC 55

#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

const int CC_52 = 0; //Analog0
const int CC_53 = 1; //Analog1
const int CC_54 = 2; //Analog2
const int CC_55 = 3; //Analog3

const int CutOff = 52;
const int Resonance = 53;
const int ContChange54 = 54;
const int ContChange55 = 55; 

#define cc_MIN 0
#define cc_MAX 127

#define vol_MIN 0
#define vol_MAX 1023
void setup() {
  // put your setup code here, to run once:
  MIDI.begin(1);
  MIDI.turnThruOff();


}
  int cc_val[4] = {0,0,0,0};
void loop() {
  // put your main code here, to run repeatedly:
  int nowcc_val[4];
  
  // CCの52番をコントロール
  nowcc_val[0] = analogRead(CC_52);
  nowcc_val[0] = map(nowcc_val[0],vol_MAX,vol_MIN,cc_MIN,cc_MAX);
  MIDI.sendControlChange(CutOff,nowcc_val[0],1);
  cc_val[0] = nowcc_val[0]; 

  // CCの53番をコントロール
  nowcc_val[1] = analogRead(CC_53);
  nowcc_val[1] = map(nowcc_val[1],vol_MAX,vol_MIN,cc_MIN,cc_MAX);
  MIDI.sendControlChange(Resonance,nowcc_val[1],1);
  cc_val[1] = nowcc_val[1]; 

  // CCの54番をコントロール
  nowcc_val[2] = analogRead(CC_54);
  nowcc_val[2] = map(nowcc_val[2],vol_MAX,vol_MIN,cc_MIN,cc_MAX);
  MIDI.sendControlChange(ContChange54,nowcc_val[2],1);
  cc_val[2] = nowcc_val[2]; 

  // CCの55番をコントロール
  nowcc_val[3] = analogRead(CC_55);
  nowcc_val[3] = map(nowcc_val[3],vol_MAX,vol_MIN,cc_MIN,cc_MAX);
  MIDI.sendControlChange(ContChange55,nowcc_val[3],1);
  cc_val[3] = nowcc_val[3]; 
  
}
