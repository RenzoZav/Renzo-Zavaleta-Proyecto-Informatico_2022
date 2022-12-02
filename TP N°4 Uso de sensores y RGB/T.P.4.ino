#define sensorT A5
#define LED_R 2
#define LED_V 4
#define LED_A 3
#define sensorL A4

void setup()
{
  pinMode ( A4 , INPUT);
  pinMode ( 4 , OUTPUT);
  pinMode ( 2 , OUTPUT);
  pinMode ( 3 , OUTPUT);
  Serial.begin( 9600);
}

void loop()
{
  
  	int lecturaluz =  analogRead ( A4 );
  	
  	int porcentaje_luz = map( lecturaluz , 713, 1022, 100 , 0);
  	Serial.println("");
  
  	Serial.print("El nivel de luz actual es:");

  	Serial.println ( porcentaje_luz);
 
	int lectura =  analogRead ( A5 );
  	
  	float volt = 5.0 / 1024 * lectura;
 
  	float temp = ( volt * 100 - 50);
  	Serial.print(" La temperatura es: "); Serial.print( temp); Serial.print(" c "); 
  
  if ( porcentaje_luz == 201 )
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
  delay(5000);
}
