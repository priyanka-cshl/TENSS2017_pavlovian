 //  ff//1kHz
//int sine1k[] = {2048,2305,2557,2802,3035,3252,3450,3626,3777,3901,3996,4060,4092,4092,4060,3996,3901,3777,3626,3450,3252,3035,2802
//,2558,2305,2049,1792,1539,1295,1062,845,647,470,319,195,100,36,4,4,36,100,195,318,469,645,843,1061,1293,1538,1790,2047,};

int sine1k[] = {1014,1141,1266,1387,1502,1610,1708,1795,1870,1931,1978,2010,2026,2026,2010,1978,1932,1870,1795,1708,1610,1503,1387,1266
,1141,1014,887,762,641,526,418,320,233,158,97,50,18,2,2,18,50,96,158,232,320,418,525,640,761,886,1013,};

//3kHz
//int sine3k[] = {2048,2802,3450,3901,4092,3996,3626,3035,2305,1539,845,319,36,36,318,843,1538,2304,3034,3625,3995,4092,3902,3451,2803
//,2050,1296,647,196,4,100,469,1060,1789,2555,3250,3776,4059,4060,3778,3254,2560,1794,1064,472,101,4,194,644,1291,2045,};

int sine3k[] ={ 4096,5604,6900,7802,8184,7992,7252,6070,4610,3078,1690,638,72,72,636,1686,3076,4608,6068,7250,7990,8184,7804,6902,5606
,4100,2592,1294,392,8,200,500,7552,8118,8120,7556,6508,5120,3588,2128,944,202,8,388,1288,2582,4090,};

//int sine3k2[] = {2048,2802,3450,3901,4092,3996,3626,3035,2305,1539,845,319,36,36,318,843,1538,2304,3034,3625,3995,4092,3902,3451,2803
//,2050,1296,647,196,4,100,469,1060,1789,2555,3250,3776,4059,4060,3778,3254,2560,1794,1064,472,101,4,194,644,1291,2045,};

int sine3k2[]={ 1024,1401,1725,1950,2046,1998,1813,1517,1152,769,422,159,18,18,159,421,769,1152,1517,1812,1997,2046,1951,1725,1401
,1025,648,323,98,2,50,234,530,894,1277,1625,1888,2029,2030,1889,1627,1280,897,532,236,50,2,97,322,645,1022,};

//5kHz
//int sine5k[] = {2048,3252,3996,3996,3252,2049,845,100,100,843,2047,3251,3995,3996,3253,2050,846,101,100,843,2046,3250,3995,3996,3254,
//2051,846,101,99,842,2045,3249,3995,3997,3255,2052,847,101,99,841,2044,3248,3994,3997,3255,2053,848,102,99,840,2043,};

const byte  lowTone = 38;    // the pin that reads the low
const byte  highTone = 40;    // the pin that reads the high
const byte  midTone = 36;
const byte  noiseTone = 34;    // the pin that reads the error signal
volatile bool playTone = false;

// All sounds are written to DAC1:
void setup() {                
  //pinMode(DAC1, OUTPUT);
  //pinMode(highTone, INPUT);
  pinMode(lowTone, INPUT);
  //pinMode(midTone, INPUT);
  //attachInterrupt(noiseTone,whiteNoise,HIGH);

//  attachInterrupt(digitalPinToInterrupt(lowTone), PlayLowTone, RISING);
//  attachInterrupt(digitalPinToInterrupt(highTone), PlayHighTone, RISING);
//  attachInterrupt(digitalPinToInterrupt(midTone), PlayMidTone, RISING);
//  attachInterrupt(digitalPinToInterrupt(noiseTone), PlayWhiteNoise, RISING);
  Serial.begin(115200);
  analogWriteResolution(12);
    pinMode(13, OUTPUT);

}

//This defines the action to be performed on interrupt, it plays white noise while the interrupt pin is HIGH
//and writes LOW to the ouput pins

//void whiteNoise() {
//     int wtNoise = random(0,4096);
//     analogWrite(DAC1,wtNoise);
//    
//    //for(int i = 0; i<50 ;i = i++){
//    //analogWriteResolution(12);
//    //analogWrite(DAC1, wtNoise[i]);
//    //delayMicroseconds(50000);
//    //}
//         
////   digitalWrite(highTone, LOW);
////   digitalWrite(lowTone, LOW);
////   digitalWrite(midTone, LOW);
//
//}

//Play respective frequencies while read pin == HIGH
void loop() {
  Serial.println(digitalRead(lowTone));
//    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);              // wait for a second
//  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
//  delay(1000);              // wait for a second
//  while(digitalRead(highTone) == HIGH){
//  for(int i = 0; i<50 ;i = i++){
//    analogWriteResolution(12);
//    analogWrite(DAC1, sine3k[i]);
//    //delayMicroseconds(3);
//  }
//  }
  while(digitalRead(lowTone) == HIGH){
  for(int i = 0; i<50 ;i = i++){
    analogWriteResolution(12);
    analogWrite(DAC1, sine1k[i]);
    //delayMicroseconds(14);
  }
  }
//  while(digitalRead(midTone) == HIGH){
//  for(int i = 0; i<50 ;i = i++){
//    analogWriteResolution(12);
//    analogWrite(DAC1, sine3k2[i]);
//    delayMicroseconds(1);
//  }
//  }
}


//// one function for each tone type
//void PlayLowTone()
//{
//  while(digitalRead(lowTone))
//  {
//  Serial.println("running");
//    for(int i = 0; i<50 ;i = i++)
//    {
//      analogWriteResolution(12);
//      analogWrite(DAC1, sine1k[i]);
//    }
//  }
//}

void PlayMidTone()
{
  while(digitalRead(midTone) == HIGH)
  {
    for(int i = 0; i<50 ;i = i++)
    {
      analogWrite(DAC1, sine3k2[i]);
    }
  }
}

void PlayHighTone()
{
  while(digitalRead(highTone) == HIGH)
  {
    for(int i = 0; i<50 ;i = i++)
    {
      analogWrite(DAC1, sine3k[i]);
    }
  }
}

void PlayWhiteNoise()
{
  while(digitalRead(noiseTone) == HIGH)
  {
    for(int i = 0; i<50 ;i = i++)
    {
      //analogWrite(DAC1, sine3k[i]);
      int wtNoise = random(0,4096);
      analogWrite(DAC1,wtNoise);
    }
  }
}

