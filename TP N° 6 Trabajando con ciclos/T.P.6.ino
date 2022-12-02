void setup()
{
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  for (int verde = 0 ; verde <= 6 ; verde++ )
  {
   
  for(int azul = 0 ;  azul <= 255  ; azul++)
  {
     
      for (int rojo = 0 ; rojo <= 255 ; rojo++ )
      {
    analogWrite(3 , azul);
        analogWrite(5 , rojo);
        analogWrite(6 , verde);

      }
  }
  }
}