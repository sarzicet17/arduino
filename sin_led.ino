

const int ledPin=3;

const unsigned char sine64 [] = {
      127,130,133,136,139,143,146,149,152,155,158,161,164,167,170,173,176,178,181,184,187,190,192,195,198,200,203,205,208,210,212,215,217,219,221,223,225,227,229,231,233,234,236,238,239,240,
  242,243,244,245,247,248,249,249,250,251,252,252,253,253,253,254,254,254
};

void setup() {
  Serial.begin(9600);
//  pinMode(ledPin,OUTPUT);
}

void loop() {

  int i=0;
  // put your main code here, to run repeatedly:
  for(i=0;i<64;i++){
    analogWrite(ledPin,sine64[i]);
    Serial.println(sine64[i]);
    delay(10);
  }
  for(i=63;i>0;i--){
    analogWrite(ledPin,sine64[i]);
    Serial.println(sine64[i]);
    delay(10);
  }
  for(i=0;i<64;i++){
    analogWrite(ledPin,254-sine64[i]);
    Serial.println(254-sine64[i]);
    delay(10);  
  }
  for(i=63;i>0;i--){
    analogWrite(ledPin,254-sine64[i]);
    Serial.println(254-sine64[i]);
    delay(10);     
  }
}
