// Desarrollar un código y un esquema electrónico básico que 
//haga una secuencia de luces con 3 leds RGB.

// La secuencia es la siguiente: 
//1- Prende el 1°led en color rojo. (De forma analógica)
//2- Se apaga el 1° led y se prende el 2° led en color magenta
//   (de forma digital)
//3- Se paga el 2° led y se prende el 3° led en color cian
//   (De forma analógica y tenue)
//4- Se paga el 3° led y se prende el 1° led  devuelta y así infinitamente.

void setup()
{
  pinMode( 11 , OUTPUT);
  pinMode( 10 , OUTPUT);
  pinMode( 9 , OUTPUT);
  pinMode( 8 , OUTPUT);
  pinMode( 7 , OUTPUT);
  pinMode( 5 , OUTPUT );
  
}

void loop()
{
  
  analogWrite( 11 , 255 );
  delay(2000);
  digitalWrite( 11 , LOW );
  
  digitalWrite( 10 , HIGH );
  digitalWrite( 9 , HIGH );
  delay(2000);
  analogWrite( 9 , 0 );
  analogWrite( 10 , 0 );

  analogWrite( 8 , 225);
  analogWrite( 7 , 255 );
  analogWrite( 5 , 250 );
  delay(2000);
  analogWrite( 8 , 0 );
  analogWrite( 7 , 0 );
  analogWrite( 5 , 0 );
}