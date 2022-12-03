#include <LiquidCrystal.h>

#define sensorT A5
#define LED_R 2
#define LED_V 4
#define LED_A 3
#define sensorL A4

#define Boton 11
#define RS 9
#define E  10
#define DB4 5
#define DB5 6
#define DB6 7
#define DB7 8
LiquidCrystal pantallita( RS , E , DB4 , DB5 , DB6 , DB7 );
int estado = 0;


void setup()
{
  pinMode( A5 , INPUT);
  pinMode ( 11 , INPUT);
  pinMode ( A4 , INPUT);
  pinMode ( 4 , OUTPUT);
  pinMode ( 2 , OUTPUT);
  pinMode ( 3 , OUTPUT);
  pantallita.begin( 16 , 2 );
  Serial.begin( 9600);
}

void loop()
{
  
  if (!digitalRead(Boton) == HIGH)
  {
    estado = estado+1;
  }
  
  int lecturaluz =  analogRead ( A4 );
  	
  int porcentaje_luz = map( lecturaluz , 713, 1022, 100 , 0);
  
  float temp = ((5.0 / 1024 * analogRead( sensorT )) * 100 - 50);
  
  if (estado == 1)
  {
    pantallita.clear();
  	pantallita.setCursor( 3 , 0);
  	pantallita.print("Luz");
  	pantallita.setCursor( 7 , 1 ); 
  	pantallita.print(porcentaje_luz);
  	pantallita.print("%");
  }
  
  else if(estado == 2)
  {
    pantallita.clear();
  	pantallita.setCursor( 3 , 0);
  	pantallita.print("Temperatura");
  	pantallita.setCursor( 7 , 1 ); //indica donde comienza a escribir, parecido al serial. 
  	pantallita.print(temp);
  	pantallita.print("c");
  }
  else if(estado == 3)
  {
   estado = 1; 
  }
  if ( porcentaje_luz >= 1 )
  {
   digitalWrite( LED_R , LOW); 
   digitalWrite( LED_V , LOW); 
   digitalWrite( LED_A , LOW);
  }
  else if ( (temp >= 18) && (temp <=90))
  {
 	digitalWrite( LED_R , LOW); 
   digitalWrite( LED_V , HIGH); 
   digitalWrite( LED_A , LOW); 
  }else if ( temp < 18){
    digitalWrite( LED_R , LOW); 
   digitalWrite( LED_V , LOW); 
   digitalWrite( LED_A , HIGH); 
  }else if (temp > 90){
    digitalWrite( LED_R , HIGH); 
   digitalWrite( LED_V , LOW); 
   digitalWrite( LED_A , LOW); 
  }
  delay(200);
}

  
