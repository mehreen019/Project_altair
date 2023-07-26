#define ENCA 2  //encoder inputs
#define ENCB 3
#define DRIIN1 5	//motor driver inputs
#define DRIIN2 6

long pos = 0;		//to calculate the current position of the encodeeer
int rotation = 0;	//to calculate the full number of rotations
int dir = 1;		//to calculate the direction
int encount = 0;
int preEncount = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(ENCA, INPUT_PULLUP);
  pinMode(ENCB, INPUT_PULLUP);
  pinMode(DRIIN1, OUTPUT);
  pinMode(DRIIN2, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(ENCA),setPosAndDir,RISING);
  //check for interrupts in the channel A pin of the encoder
}

void loop()
{
  setMotor(DRIIN1, DRIIN2); //sets motor motion
  
  encount= pos - preEncount;
  calculateRPM(encount);
  preEncount = pos;
  delay(150);
  
}

void setMotor(int in1, int in2){
  if(dir == 1){
    analogWrite(in1, 255);	//depending on the direction, writes a high output to the positive or negative motor channel
    analogWrite(in2, 0);
  }
  else if(dir == -1){
    analogWrite(in1, 0);
    analogWrite(in2, 255);
  }
  else{
    analogWrite(in1, 0);
    analogWrite(in2, 0);
  }  
}

void setPosAndDir(){
  if(digitalRead(ENCB) > 0){  //if the two outputs are positive, means it's clockwise
    pos++;
    dir = 1;
  }
  else{
    pos--;			//else it's anticlockwise
    dir = -1;
  }
}

void calculateRPM(int count){
	float rpm = ((float)count/36)*60;
  	Serial.println(rpm);
}