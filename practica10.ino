//Límites frecuencia
#define MINFREQ 0.1
#define MAXFREQ 0.5


//Parametros senoidal
#define FREQ 0.05
#define PI 3.14159

float w;
//float fakeTime;
//float taimuEstopu;

void setup()
{
  	pinMode(13, OUTPUT);
  	Serial.begin(9600);
	w = 2*PI*FREQ;
  	//fakeTime=0.0;
  	//taimuEstopu=millis(); 
}

void loop()
{

	float res = sin(w*millis()/1000);
  	float freq = ((res - (-1.0)) * (MAXFREQ - MINFREQ) / (1.0 - (-1.0)) + MINFREQ);
    digitalWrite(13, LOW);
  	delay((1.0/freq)*50.0);
    digitalWrite(13, HIGH);
  	delay((1.0/freq)*50.0);
  	fakeTime+= 0.5;
  	/*if(res > -0.05 && res < 0.05){
  		Serial.println(millis() - taimuEstopu);
      	taimuEstopu=millis(); 
  	}*/
}
