#define PotR A1
#define PotA A2
#define PotV A3
int estado = 0;
void setup()
{
  pinMode( 2, INPUT);
  pinMode( 3, OUTPUT);//rojo
  pinMode( 5, OUTPUT);//azul
  pinMode( 6, OUTPUT);//verde
  pinMode( PotR , INPUT);
  pinMode( PotA , INPUT);
  pinMode( PotV , INPUT);
  Serial.begin(9600);
}

void loop()
{
   int valor_potenciometroR = analogRead ( PotR );
   int valorPNR = map( valor_potenciometroR , 0 , 1023 , 0 , 255 );
    
    int valor_potenciometroA = analogRead ( PotA );
  int valorPNA = map( valor_potenciometroA , 0 , 1023 , 0 , 255 );
    
    int valor_potenciometroV = analogRead ( PotV );
  int valorPNV = map( valor_potenciometroV , 0 , 1023 , 0 , 255 );
    
  if ( !digitalRead ( 2 ) == HIGH )
  {
    Serial.println("Tiene 10 s para configurar el color del led:");
    estado = estado+1 ;
    delay( 10000 ) ;
    Serial.println("El led esta usando esta configuracion de colores RGB:"); Serial.print("("); Serial.print(valorPNR); Serial.print(";"); Serial.print(valorPNA); Serial.print(";"); Serial.print(valorPNV); Serial.print(")"); 
  }
  if( estado ==1 )
  {
    analogWrite( 3, valorPNR);
    analogWrite( 5, valorPNA);
    analogWrite( 6, valorPNV);
  }else if(estado == 2)
  {
    analogWrite( 3, 0);
    analogWrite( 5, 0);
    analogWrite( 6, 0);
    estado = 0;
  }
   
}
