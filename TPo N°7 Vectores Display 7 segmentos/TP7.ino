
#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8

int num_bin[4];

int peso[] = { 8 , 4 , 2 , 1 };
int pinM[]  = { A , B , C , D , E , F , G };

int put[] = {1 , 1 , 1 , 1 , 1 , 1 , 1};

int num_0[] = { 1 , 1 , 1 , 1 , 1 , 0 , 1 };
int num_1[] = { 0 , 1 , 1 , 0 , 0 , 0 , 0 };
int num_2[] = { 1 , 1 , 0 , 1 , 1 , 1 , 0 };
int num_3[] = { 1 , 1 , 1 , 1 , 0 , 1 , 0 };
int num_4[] = { 0 , 1 , 1 , 0 , 0 , 1 , 1 };
int num_5[] = { 1 , 0 , 1 , 1 , 0 , 1 , 1 };
int num_6[] = { 1 , 0 , 1 , 1 , 1 , 1 , 1 };
int num_7[] = { 1 , 1 , 1 , 0 , 0 , 0 , 0 };
int num_8[] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 };
int num_9[] = { 1 , 1 , 1 , 0 , 0 , 1 , 1 };
int num_A[] = { 1 , 1 , 1 , 0 , 1 , 1 , 1 };
int num_C[] = { 1 , 0 , 0 , 1 , 1 , 0 , 1 };
int num_d[] = { 0 , 1 , 1 , 1 , 1 , 1 , 0 };
int num_E[] = { 1 , 0 , 0 , 1 , 1 , 1 , 1 };
int num_F[] = { 1 , 0 , 0 , 0 , 1 , 1 , 1 };
int num_H[] = { 0 , 1 , 1 , 0 , 1 , 1 , 1 };
void setup()
{
  	Serial.begin(9600);
}
void loop()
{
 	num_bin[0] = digitalRead(9);
    num_bin[1] = digitalRead(10);
  	num_bin[2] = digitalRead(11);
    num_bin[3] = digitalRead(12);
  
	
  	int dec = 0;
  	for( int i = 3 ; i >= 0 ; i-- )
    {
 
      dec = dec + ( num_bin[i] * peso[i]  );
      for( int V = 0 ;  V < 7  ; V++ )
      {
        if( dec == 0)
        {
        digitalWrite(pinM[V], num_0[V]);
        }
        else if (dec == 1)
        {
         digitalWrite(pinM[V], num_1[V]);
        }
         else if (dec == 2)
        {
         digitalWrite(pinM[V], num_2[V]);
        }
        else if (dec == 3)
        {
         digitalWrite(pinM[V], num_3[V]);
        }
        else if (dec == 4)
        {
         digitalWrite(pinM[V], num_4[V]);
        }
        else if (dec == 5)
        {
         digitalWrite(pinM[V], num_5[V]);
        }
        else if (dec == 6)
        {
         digitalWrite(pinM[V], num_6[V]);
        }
        else if (dec == 7)
        {
         digitalWrite(pinM[V], num_7[V]);
        }
        else if (dec == 8)
        {
         digitalWrite(pinM[V], num_8[V]);
        }
        else if (dec == 9)
        {
         digitalWrite(pinM[V], num_9[V]);
        }
         else if (dec == 10)
        {
         digitalWrite(pinM[V], num_A[V]);
        }
        else if (dec == 11)
        {
         digitalWrite(pinM[V], num_C[V]);
        }
        else if (dec == 12)
        {
         digitalWrite(pinM[V], num_d[V]);
        }
        else if (dec == 13)
        {
         digitalWrite(pinM[V], num_E[V]);
        }
        else if (dec == 14)
        {
         digitalWrite(pinM[V], num_F[V]);
        }
        else if (dec == 15)
        {
         digitalWrite(pinM[V], num_H[V]);
        }
        
      }
    }
	Serial.print("bin [");  
  	Serial.print(num_bin[0]);
  	Serial.print(num_bin[1]);  
  	Serial.print(num_bin[2]);  
  	Serial.print(num_bin[3]);  
  	Serial.print( "] -> " );
  	Serial.println(dec);
  	delay(500);
 
}