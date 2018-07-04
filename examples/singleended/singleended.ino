#include <Wire.h>
#include <Adafruit_ADS1015.h>

 Adafruit_ADS1115 ads;  /* Use this for the 16-bit version */
//Adafruit_ADS1015 ads;     /* Use thi for the 12-bit version */

void setup(void) 
{
  Serial.begin(9600);
  Serial.println("Hello!");
  
  // The ADC input range (or gain) can be changed via the following
  // functions, but be careful never to exceed VDD +0.3V max, or to
  // exceed the upper and lower limits if you adjust the input range!
  // Setting these values incorrectly may destroy your ADC!
  //                                                             ADS1015  ADS1115
  //                                                             -------  -------
  ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
//  ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
//  ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
//  ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
//  ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
//  ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV
  
  Serial.println("Getting single-ended readings from AIN0..3");
  Serial.print("ADC Range: ");
  if (ads.getGain() == GAIN_TWOTHIRDS)
  {
	  Serial.println("+/- 6.144V (1 bit = 3mV/ADS1015, 0.1875mV/ADS1115)");
  }
  else if (ads.getGain() == GAIN_ONE)
  {
  	  Serial.println("+/- 4.096V (1 bit = 2mV/ADS1015, 0.125mV/ADS1115)");
  }
  else if (ads.getGain() == GAIN_TWO)
  {
  	  Serial.println("+/- 2.048V (1 bit = 1mV/ADS1015, 0.0625mV/ADS1115)");
  }
  else if (ads.getGain() == GAIN_FOUR)
  {
   	  Serial.println("+/- 1.024V (1 bit = 0.5mV/ADS1015, 0.03125mV/ADS1115)");
  }
  else if (ads.getGain() == GAIN_EIGHT)
  {
   	  Serial.println("+/- 0.512V (1 bit = 0.25mV/ADS1015, 0.015625mV/ADS1115)");
  }
  else if (ads.getGain() == GAIN_SIXTEEN)
  {
      Serial.println("+/- 0.256V (1 bit = 0.125mV/ADS1015, 0.0078125mV/ADS1115)");
  }
  Serial.println();

  //ads.begin(1,0);                // for ESP8266  SDA, SCL can be specified
  ads.begin();
}

void loop(void) 
{
  int16_t adc0, adc1, adc2, adc3;
  float ADS_bitValue = ads.voltsPerBit();		// store bit value (V/bit) to defined gain

  // read each channel
  adc0 = ads.readADC_SingleEnded(0);
  adc1 = ads.readADC_SingleEnded(1);
  adc2 = ads.readADC_SingleEnded(2);
  adc3 = ads.readADC_SingleEnded(3);

  // print RAW value and mV value
  Serial.print("AIN0: "); Serial.print(adc0);
  Serial.print("    -->   "); Serial.print(adc0 * ADS_bitValue * 1000); Serial.println(" mV");
  Serial.print("AIN1: "); Serial.print(adc1);
  Serial.print("    -->   "); Serial.print(adc1 * ADS_bitValue * 1000); Serial.println(" mV");
  Serial.print("AIN2: "); Serial.print(adc2);
  Serial.print("    -->   "); Serial.print(adc2 * ADS_bitValue * 1000); Serial.println(" mV");
  Serial.print("AIN3: "); Serial.print(adc3);
  Serial.print("    -->   "); Serial.print(adc3 * ADS_bitValue * 1000); Serial.println(" mV");
  Serial.println(" ");
  
  delay(1000);
}
