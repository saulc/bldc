#include <TimerOne.h>

#include <PinChangeInt.h>

int a = 9;
int b = 10;
int c = 11;


int d = 10;

int dmn = 30;
int dmx = 60;


int n = 127; // neutural
int h = 255;
int l = 0;

//int n = 127; // neutural
//int h = 190;
//int l = 70;
volatile int st = 0;

int s = 1;
int mx = 7;
int v = 0;
volatile int vv = 0;
volatile bool changed = false;
int ramptime = 70;


int t = 0;
int tt = 0;

void ca(){
  noInterrupts();
  st = st+1;
  interrupts();

}
void setup() {

//  attachPinChangeInterrupt(9, ca, CHANGE);
//  attachPinChangeInterrupt(10, ca, CHANGE);
//  attachPinChangeInterrupt(11, ca, CHANGE);
  
  Timer1.initialize(500);
  Timer1.attachInterrupt(updateMotor);

  
  // put your setup code here, to run once:
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  
  neutural();
  delay(1000);
  
}

void updateMotor(){
  if(t++ >= tt){  
    t = 0;
    st++;
    if( st > 5) st = 0;
    
    changed = true;
  }

    
}

void go(){
  
    switch(5 -st){
      case 0: one();
      
        break;
        case 1: two();
        break;
        case 2: three();
        break;
        case 3: four();
        break;
        case 4: five();
        break;
        case 5: six();
        break;
    }
   
}


void no(){
  
    switch(5 - st){
      case 0: c1();
      
        break;
        case 1: c2();
        break;
        case 2: c3();
        break;
        case 3: c4();
        break;
        case 4: c5();
        break;
        case 5: c6();
        break;
    }
   
}

void neutural(){
  analogWrite(a, n);
  analogWrite(b, n);
  analogWrite(c, n);
}

void one(){
   analogWrite(a, h);
  analogWrite(b, l);
  analogWrite(c, n);
}

void two(){
   analogWrite(a, h);
  analogWrite(b, n);
  analogWrite(c, l);
}


void three(){
   analogWrite(a, n);
  analogWrite(b, h);
  analogWrite(c, l);
}


void four(){
   analogWrite(a, l);
  analogWrite(b, h);
  analogWrite(c, n);
}


void five(){
   analogWrite(a, l);
  analogWrite(b, n);
  analogWrite(c, h); 
}

void six(){
   analogWrite(a, n);
  analogWrite(b, l);
  analogWrite(c, h);
}


void c1(){
   analogWrite(a, l);
  analogWrite(b, l);
  analogWrite(c, n);
}

void c2(){
   analogWrite(a, l);
  analogWrite(b, n);
  analogWrite(c, l);
}


void c3(){
   analogWrite(a, n);
  analogWrite(b, l);
  analogWrite(c, l);
}


void c4(){
   analogWrite(a, l);
  analogWrite(b, l);
  analogWrite(c, n);
}


void c5(){
   analogWrite(a, l);
  analogWrite(b, n);
  analogWrite(c, l); 
}

void c6(){
   analogWrite(a, n);
  analogWrite(b, l);
  analogWrite(c, l);
}

void loop() {

 
    if(s++ > mx){
       tt = analogRead(5);
      tt = map(tt, 0, 1023, 0 , 100);
      s = 0;
    }

    //stop 
    if(tt > 90) {
      neutural();
      delay(10);
      return;
    }

  if( changed ) {
    go();
    delayMicroseconds(30);
    changed = false;
  }
  
    go(); 
    delayMicroseconds(30);
    no();
    delayMicroseconds(30);
 
}
