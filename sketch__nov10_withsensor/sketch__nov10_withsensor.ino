
#include "PCMArrays.h"

int counter = 0;

unsigned int sample_raw_len = 7941;

const int vol_pin = 0;
const int out_pin = 3;

int vol_value = 0;
int out_value = 0;
void setup() 
{
  pinMode(3, OUTPUT);
  TCCR2A = _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS20);
  play(1);
  Serial.begin(9600);
}

void play(int x) {

  if (x == 1) 
  {
    for (int i = 0; i < sample_raw_len; i++) {
      OCR2B = pgm_read_byte_near(&rawOne[i]);
      delayMicroseconds(50);    
    }
  }
  
  else if (x == 2)
  {
    for (int i = 0; i < sample_raw_len; i++) {
      OCR2B = pgm_read_byte_near(&rawOne[i]);
      delayMicroseconds(80);
    }
  }
  
  else if (x == 3)
  {
    for (int i = 0; i < sample_raw_len; i++) {
      OCR2B = pgm_read_byte_near(&rawOne[i]);
      delayMicroseconds(100);
    }  
  }
  
  else if (x == 4)
  {
    for (int i = 0; i < sample_raw_len; i++) {
      OCR2B = pgm_read_byte_near(&rawOne[i]);
      delayMicroseconds(130);
    }
  }
   else if (x == 5)
  {
    for (int i = 0; i < sample_raw_len; i++) {
      OCR2B = pgm_read_byte_near(&rawOne[i]);
      delayMicroseconds(150);
    }
  }
  else if (x == 6)
  {
    for (int i = 0; i < sample_raw_len; i++) {
      OCR2B = pgm_read_byte_near(&rawOne[i]);
      delayMicroseconds(180);
    }
  }
  else if (x == 7)
  {
    for (int i = 0; i < sample_raw_len; i++) {
      OCR2B = pgm_read_byte_near(&rawOne[i]);
      delayMicroseconds(200);
    }
  }
  else if (x == 8)
  {
    for (int i = 0; i < sample_raw_len; i++) {
      OCR2B = pgm_read_byte_near(&rawOne[i]);
      delayMicroseconds(230);
    }
  }
  else if (x == 9)
  {
    for (int i = 0; i < sample_raw_len; i++) {
      OCR2B = pgm_read_byte_near(&rawOne[i]);
      delayMicroseconds(250);
    }
  }
  else if (x == 10)
  {
    for (int i = 0; i < sample_raw_len; i++) {
      OCR2B = pgm_read_byte_near(&rawOne[i]);
      delayMicroseconds(3000);
    }
  }

  
//    OCR2B = pgm_read_byte_near(&sample_raw[i]);
//    delayMicroseconds(125);
} 


void(* resetFunc)(void) = 0;

void loop() {
 // 感圧センサーの値を受け取ります
  vol_value = analogRead( vol_pin );
  Serial.println(vol_value); 
  delay(200);
  Serial.println(counter);

if(vol_value > 700){
  
  if (counter < 5) 
  {
    Serial.println("one");  
    play(1);
  }
  
  else if (counter >= 5, counter < 9)
  {
    Serial.println("two");  
    play(2);
   }
  else if (counter  >= 9, counter < 15)
  {
    Serial.println("three");  
    play(3);
  }
    else if (counter  >= 15, counter < 20)
  {
    Serial.println("four");  
    play(4);
  }
    else if (counter  >= 20, counter < 21)
  {
    Serial.println("five");  
    play(5);
  }
    else if (counter  >= 21, counter < 23)
  {
    Serial.println("six");  
    play(6);
  }
  else if (counter  >= 23, counter < 25)
  {
    Serial.println("seven");  
    play(7);
  }
  else if (counter  >= 25, counter < 28)
  {
    Serial.println("eight");  
    play(8);
  }
  else if (counter  >= 28, counter < 30)
  {
    Serial.println("nine");  
    play(9);
  }
  else if (counter  >= 30, counter < 31)
  {
    Serial.println("ten");  
    play(10);
  }
  }
  

  if(vol_value < 700){
    delay(7000);
    resetFunc();
    
  }
  
  
    counter++;
//  delay(200);
  
  // 感圧センサーの値を受け取ります
  vol_value = analogRead( vol_pin );
  Serial.println(vol_value);  
  Serial.write(byte(vol_value/5)); //シリアル通信ここ足す大きかったら割る
  // センサーを押さえていないときの値が1023、押さえた力に応じて値が小さくなるので、
//  if (vol_value > 100) {
//    Serial.println("inside if");
//   play(1);
//  }
//  else {
//  }
//  counter++;
//  delay(200);
  }
