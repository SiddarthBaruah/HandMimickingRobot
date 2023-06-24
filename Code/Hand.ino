#include <Servo.h>

Servo servo;

//#define pmeter A0;

int pos,initialpos,finalpos;


int bring_to(int finalpos){       //this function brings the servo to angle mentioned
  initialpos= servo.read();
  pos= initialpos;
  
  if(initialpos<finalpos){
    while(pos<=finalpos){
      servo.write(pos);
      pos++;
      delay(5);
    }
  }
  else if(initialpos>finalpos){
    while(pos>=finalpos){
      servo.write(pos);
      pos--;
      delay(5);
      
    }
  }
  else if(initialpos==finalpos){
    servo.write(pos);
  }
  return 0;
}

void setup() {
  servo.attach(8);
  Serial.begin(9600);
  initialpos= servo.read();
  pos= initialpos;
  while(finalpos<= pos){
    servo.write(pos);
    pos--;
    delay(10);
  }
  pinMode(A0,INPUT);

}

void loop() {
  int read_;
  read_=analogRead(A0);

  if(read_<256){
    bring_to(0);
    Serial.println(read_);
  }
  else if(read_<512 && read_>=256){
    bring_to(60);
    Serial.println(read_);
  }
  else if(read_<768 && read_>=512){
    bring_to(120);
    Serial.println(read_);
  }
  else if(read_>=768){
    bring_to(180);
    Serial.println(read_);
  }
  
  

}
