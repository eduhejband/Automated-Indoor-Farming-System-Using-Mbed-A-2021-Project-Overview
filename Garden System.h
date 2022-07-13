#include "mbed.h"
#include "C12832.h"
#include "Sht31.h"

C12832 lcd(SPI_MOSI, SPI_SCK, SPI_MISO, p8, p11);
Sht31 sht31(I2C_SDA, I2C_SCL);
PwmOut Ventilação(p13);
DigitalOut botao (p9);


int main() {
    
        printf ("\n\nIniciaremos o controle de temperatura e ventilação do ambiente\n");
        
        if(botao == 0) {
            
            lcd.cls();

            float temperatura = sht31.readTemperature();
            float aquecedor = sht31.readTemperature();
            float resfriador = sht31.readTemperature();
            float ventilação = sht31.readHumidity();
            
            
            for (ventilação = 0; ventilação <101; ventilação++){
                if (ventilação ==100){
                printf ("\nVentilação ajustada\n\n");}
                lcd.locate(3, 3);
                lcd.printf("Ventilacao: %.f%% ", ventilação);
                wait(0.1);
            }
        printf ("Em processo de Resfriamento\n\n\n");
            for (temperatura = 30; temperatura > 14; temperatura--){
        
            lcd.locate(3, 13);
            lcd.printf("Temperatura: %.2f C", temperatura);
            wait(0.05);
            for (resfriador = 0; resfriador < 30; resfriador++){
            lcd.locate(3, 23);
            lcd.printf("Resfriador %.f s", resfriador);
            wait(0.05);}
    
            
        
            if (temperatura == 15){
                printf("Processo encerrado\n\n\n\n");
                wait(10.0);
                printf ("Em processo de aquecimento\n\n");
                for (ventilação = 100; ventilação > -1; ventilação--){
                  if ( ventilação ==0){
                  printf ("\nVentilação ajustada\n\n");}
                lcd.locate(3, 3);
                lcd.printf("Ventilacao: %.f%% ", ventilação);
                wait(0.05);
            }
            
                aquecedor = 0;
        
                for (temperatura = 15; temperatura < 26; temperatura++){
               
                    
                lcd.locate(3, 13);
                lcd.printf("Temperatura: %.2f C", temperatura);
                wait(0.05);
                for (aquecedor = 0; aquecedor < 61; aquecedor++){
                lcd.locate(3, 23);
                lcd.printf("Aquecedor %.f s", aquecedor);
                wait(0.05);}
            
        
                if (temperatura == 25){
        
                  for (ventilação = 0; ventilação < 51; ventilação++){
                      if (ventilação == 50){
                      
                      printf ("\n\n\nTemperatura regulada\n");
                      printf("\nVentilação regulada\n\n\n\n");
                          
                      aquecedor = 0;
                      lcd.locate(3, 3);
                      lcd.printf("Ventilacao: %.f%% ", ventilação);
                      wait(0.05);
                      aquecedor = 0;
                      lcd.locate(3, 13);
                      lcd.printf("Temperatura: %.2f C", temperatura);
                      wait(0.05);
                      lcd.locate(3, 23);
                      lcd.printf("Desligado", aquecedor);
                      wait (100.0);
                      }     
                    }
                }
            }       
          }       
       }
    }
    return 0;
}
