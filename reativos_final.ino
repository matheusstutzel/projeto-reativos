#define trataBT(btn,value) \
loop do \
			var int on = await KEY1 until on == btn;\
			{\
        mySerial(@value,1);\
			};\
		end

input int KEY1;

#define FULL 2
#define EMPTY 3
#define A 0
#define B 1
#define MAXSTA 100


#define btnNONE 23;  
#define btnUP 24;  
#define btnRIGHT 25; 
#define btnLEFT 26; 
#define btnDOWN 27; 
#define btnSELECT 28; 

native/pre do

##include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);



int photocellPin=8;
int btPin = 0;
int sta=100;
int lum;
int visi;

byte off   = 0b00000;
byte mask[5] = {
  0b10000,
  0b01000,
  0b00100,
  0b00010,
  0b00001
  };

  byte teste[8] = {
    0b11111,
    0b11111,
    0b00001,
    0b00010,
    0b10010,
    0b01111,
    0b10010,
    0b00100
  };
byte f[8] = {
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111
  };

byte e[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000
  };


void mySerial(int info, int base){
  Serial.println((int)base*1000+info);
}
void draw_per(int per,int c){
  byte my_per[8];
  byte aux = off;
    int i,j;
    for(i=1;i<=10;i++){
      if(per>=i*10)lcd.write((uint8_t)FULL);
      else if(per<=(i-1)*10)lcd.write((uint8_t)EMPTY);
      else{
        int tmp = per-((i-1)*10);
        tmp/=2;
        for(j=0;j<5;j++){
          if(tmp>=j)aux= aux | mask[j];
        }
        for(j=0;j<8;j++)my_per[j]=aux;


        lcd.createChar(c, my_per);
        lcd.setCursor(5+i,c);
        lcd.write((uint8_t)c);
      }
    }
}
int calcVisi(){
  int a = lum/10;
  if(a>sta)return sta;
  return a;
}
void draw(){

    lcd.setCursor(0,0);
  	lcd.write("Visib.");
    draw_per(visi,A);
    lcd.setCursor(0,1);
    lcd.write("Energ.");
    draw_per(sta,B);
}
int readPhotocell(){
  int photocellReading = analogRead(photocellPin);
  if(photocellReading>1000)photocellReading=1000;

  return photocellReading;
}

int read_button()
{
 int key_in = analogRead(btPin);
 if (key_in > 1000)
	return btnNONE;
 if (key_in < 50)   return btnUP;
 if (key_in < 250)  return btnRIGHT;
 if (key_in < 450)  return btnLEFT;
 if (key_in < 650)  return btnDOWN;
 if (key_in < 850)  return btnSELECT;

 return btnNONE;
}
int calcSta(){
	sta=sta +10-lum/35;
	if(sta>=MAXSTA)sta=MAXSTA;
	if(sta<=0)sta=0;
	return sta;
}
end

{
    Serial.begin(9600);
    //Define o número de colunas e linhas do LCD
    lcd.begin(16, 2);
    //Define alguns chars personalizados
    lcd.createChar(FULL, f);
    lcd.createChar(EMPTY, e);
}
par do
   loop do
	{draw();};
	await 320ms; 
   end
  with
    loop do
      {
        lum = readPhotocell();
        sta = calcSta();
        visi = calcVisi();
        mySerial(visi,0);
      }
	await 50ms; 
    end
  with
  	trataBT(btnUP,1);
  with
  	trataBT(btnDOWN,2);
  with
	trataBT(btnRIGHT,3);
  with
  	trataBT(btnLEFT,4);
  with
	var int key = 0;
	loop do
		var int read1 = {read_button();};
		await 20ms;
		var int read2 = {read_button();};
		if read1==read2 and key!=read1 then
			key = read1;
			if key != 0 then
			        await async (read1) do
				           emit KEY1(read1);
			        end
		  end
		end
  	end
end

