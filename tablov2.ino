#include <Adafruit_NeoPixel.h>
#define NUMPIXELS 56
#define PIN 4
#define BUT 2
#define BUT_RESET 6
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


int8_t yacheyki[30] = {16, 17, 27, 37, 47, 46, 45, 44, 43, 42, 41, 31, 32, 33, 34, 35, 36, 26, 25, 24, 23, 22, 21, 11, 12, 13, 14, 15, 16};
int8_t yach[30] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};


void reset() {
  for (int8_t j = 0; j < 28; j++) {yach[j] = 0;}
  cl();
  }


void zagruzka() {
  int8_t zagruzochnik[28] = {41, 42, 43, 44, 45, 46, 47, 34, 24, 14, 15, 16, 17};
  for (int8_t i = 0; i < (sizeof(zagruzochnik)/sizeof(zagruzochnik[0])); i++) {
    dinya(255, 0, 255, zagruzochnik[i]);
    delay(100);
  }
  delay(1000);
  cl();
}

int readButton() {
  if (digitalRead(BUT) == HIGH) {begushyayaStroka(); return 0;};
  if (digitalRead(BUT_RESET) == HIGH) {reset(); return 0;};
  delay(10);
}

void vibitiey() {
  for (int8_t i = 0; i < 28; i++) {
    if (yach[i] == 0) {
      dinya(255, 0, 0, yacheyki[i]);
      }
    }
  } 

void dinya(int16_t red, int16_t  green, int16_t  blue, int16_t xyz) {     
  if (xyz == 0) {return ;}
    int8_t nomber, a, b;
    a = xyz % 10;
    b = (xyz-a) / 10;
    if ((xyz % 2) == 1) {nomber = ((a*4)-(b-1));};
    if ((xyz % 2) == 0) {nomber = (((a-1)*4)+b);};     
    if (nomber > 16) {blue ^= green ^= blue ^= green;}
    pixels.setPixelColor((nomber*2)-1, pixels.Color(red, green, blue));                    
    pixels.setPixelColor((nomber*2)-2, pixels.Color(red, green, blue));
    pixels.show();
    }

void cl() {pixels.clear(); pixels.show();}

void begushyayaStroka() {
  cl();
  int8_t rand = random(57, 85);
  int8_t jn, jp = 0;
    if (yach[rand-56] == 0) {
      while(yach[rand-56] == 0) {
        rand = random(57, 85);
        }
      }
  for (int8_t i = 1; i < (rand+1); i++) {
    jn = i % 28;
    dinya(128, 0, 128, yacheyki[jn]);
    dinya(0, 0, 0, yacheyki[jp]);
    jp = jn;
    if (i == rand) {
        dinya(0, 255, 0, yacheyki[jn]);
        delay(3000);
        vibitiey();
        yach[jn] = 0;
      }
    delay(100);
    }
  }


void musick(int8_t time) {
  
  }


void setup() {
pinMode(BUT, INPUT_PULLUP);
pixels.clear();
pixels.show();
pixels.begin();
zagruzka();
pixels.clear();
}

void cikl() {
  for (uint32_t fff = 0; fff < 1000; fff++) {
    readButton();
    };
  animation();
  }


void animation() {                                    //Сюда надо написать анимацию загрузки и функцию для отмены режима ожидания (в результате любово действия(какого пожелаещь) нужно чтобы была команда "break" или "return")
  


  }

void loop() {
  cikl();
  //readButton();
}

