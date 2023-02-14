OLED I2C   SDA = A4 e SCL = A5
   drawRoundRect(x,y,w,h,r,color)
   x   coordenada x (topo esquerda)
   y   coordenada y (topo esquerda)
   w   largura em pixels
   h   altura em pixels
   r   raio da borda
   color  cor
*/
//#include <Wire.h>                                   // biblioteca I2C
#include <Adafruit_GFX.h>                            // biblioteca gráfica da Adafruit
#include <Adafruit_SSD1306.h>                        // biblioteca Oled da Adafruit
#include <Fonts/FreeMono9pt7b.h>                     // tipo de fonte do caracter
#define SCREEN_WIDTH 128                             // largura do display 128 pixels
#define SCREEN_HEIGHT 64                             // altura do display 64 pixels 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
int pinSensor = A0; //Pino Sensor
int Rele = 3; //Pino Relé
int valor = 0;

void setup()
{  
  pinMode(Rele, OUTPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();                                              // limpa o display
  display.setFont(&FreeMono9pt7b);                                     // tipo de fonte
  display.setTextSize(1);                                              // tamamho do caracter
  displayMessage ();                                                   // mostra mensagem no display
}
void loop()
{
 valor = analogRead(pinSensor); //Faz a leitura da entrada do sensor
 valor = map(valor, 0, 1023, 0, 100); //Faz a conversão da variável para porcentagem
 display.setCursor(0, 0);
  display.println("Gerando Hidrôgenio...");

  // Exiba a segunda string na segunda linha do OLED
  display.setCursor(0, 16);
  display.println("valor");

  // Atualize o display OLED
  display.display();
 if (valor >= 900){
   digitalWrite(rele, HIGH); 

   display.setCursor(0, 0);
  display.println("Hidrôgenio Produzido");

  // Exiba a segunda string na segunda linha do OLED
  display.setCursor(0, 16);
  display.println("valor");

  // Atualize o display OLED
  display.display();
} else {
  // código a ser executado se a condição for falsa
  digitalWrite(rele, LOW);
}
 }
