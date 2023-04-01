#include <Servo.h> //servo lib
#include <Wire.h> //This library allows you to communicate with I2C/TWI devices
#include <Keypad.h> //keypad lab
#include <LiquidCrystal_I2C.h> // lcd 2x16 I2c lib

LiquidCrystal_I2C lcd(0x27,16,2); 
Servo motor;
int digit = 0;    
const byte line = 4;               
const byte column = 4;
String entered_password="";    
String password = "1";               

char num_pad[line][column]= 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte linepin[line] = {13,12,11,10}; 
byte columnpin[column]= {9,8,7,6}; 

Keypad my_numpad= Keypad(makeKeymap(num_pad), linepin, columnpin, line, column);

void setup()
{
  
  motor.attach(5);
  pinMode(5, OUTPUT);
   lcd.init();                     
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Enter Password");
  
}


void loop()
{
  
char key = my_numpad.getKey();  // keypadden gelen değer
  if (key != NO_KEY) {
    
     lcd.setCursor(digit,1);
      lcd.print(key);
       entered_password =entered_password + key;
     digit++;
   
  }



  if(key=='#'){
      
      if((entered_password.substring(0,digit-1)) == password) {
        lcd.setCursor(0,1);
        lcd.clear();
        lcd.print("Login sccssfl");
        lcd.setCursor(0,1);
        lcd.print("Door is openng");
        delay(3000);
        motor.write(180);
        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print("WELCOME!");
        delay(3000);
        lcd.clear();
       for(int i=0; i<16; i++)
       {
        lcd.setCursor(i,1);
        lcd.print(" ");
       }
        entered_password = "";
        digit = 0;
       }
     
      else if (( entered_password.substring(0,digit-1) != password))  {
       lcd.setCursor(0,1);
       lcd.print("Try Again!");
       delay(1000);
       for(int i=0; i<16; i++)
       {
        lcd.setCursor(i,1);
        lcd.print(" ");
       }
        entered_password = "";
        digit = 0;
        
      }
    }
        }

