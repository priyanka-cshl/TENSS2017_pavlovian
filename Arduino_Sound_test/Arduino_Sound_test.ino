
int sine2k[] = {1014,1141,1266,1387,1502,1610,1708,1795,1870,1931,1978,2010,2026,2026,2010,1978,1932,1870,1795,1708,1610,1503,1387,1266,1141,1014,887,762,641,526,418,320,233,158,97,50,18,2,2,18,50,96,158,232,320,418,525,640,761,886,1013};
int sine8k[] = {1024,1401,1725,1950,2046,1998,1813,1517,1152,769,422,159,18,18,159,421,769,1152,1517,1812,1997,2046,1951,1725,1401,1025,648,323,98,2,50,234,530,894,1277,1625,1888,2029,2030,1889,1627,1280,897,532,236,50,2,97,322,645,1022};

const byte WhiteNoisePin = 22;
const byte HighTonePin = 24;
const byte LowTonePin = 26;

volatile int i = 0;

void setup() 
{
  // put your setup code here, to run once:
  attachInterrupt(WhiteNoisePin,WhiteNoise,HIGH);
  attachInterrupt(HighTonePin,HighTone,HIGH);
  attachInterrupt(LowTonePin,LowTone,HIGH);
  
  analogWriteResolution(12);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  
}

void WhiteNoise()
{
  int wtNoise = random(0,4096);
  analogWrite(DAC1,wtNoise);
}

void HighTone()
{
  i = (i + 1) % 50;
  analogWrite(DAC1,2*sine8k[i]);
}

void LowTone()
{
  i = (i + 1) % 50;
  analogWrite(DAC1,2*sine2k[i]);
}
