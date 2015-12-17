#include <notas.h>

/***************************************************\
| DUDU PARA NATAL                                   |
|                                                   |
|                                                   |
|                                                   |
| Created on 5 May 2011 by Lana Mesquita            |
\***************************************************/

// Define o pin para ligar o autofalante
int piezopin = 12;
int sensor = 2;  //Pino ligado ao sensor PIR


int acionamento;
 
// duração das notas
#define se 6
#define tr 4
#define co 3
#define SMbpm 250
 
// As notas...
int tonesA[] = {MI5, MI5, MI5, 0, MI5, MI5, MI5, 0, MI5, SOL5, DO5, RE5, MI5, 0, 0, 0, FA5, FA5, FA5, 0, FA5, MI5, MI5, 0 };  // MI5 MI5 MI5 0 MI5 MI5 MI5 0 MI5 SOL5 DO5 RE5 MI5 0 0 0 FA5 FA5 FA5 0 FA5 MI5 MI5 0 
int tonesB[] = {MI5, RE5, RE5, MI5, RE5, 0, SOL5, 0}; // MI5 RE5 RE5 MI5 RE5 0 SOL5 0
int tonesC[] = {SOL5, SOL5, FA5, RE5, DO5, 0}; // SOL5 SOL5 FA5 RE5 DO5 0
int tonesD[] = {DO5, LA5, SOL5, FA5, DO5, 0, 0, 0, DO5, LA5, SOL5, FA5, RE5, 0, 0, 0}; // DO5 LA5 SOL5 FA5 DO 0 0 0 DO5 LA5 SOL5 FA5 RE5 0 0 0  
int tonesE[] = {RE5, LAS5, LA5, SOL5, MI5, 0, MI5, 0, DO5, DO6, DO6, LAS5, SOL5, LA5}; // RE5 LAS5 LA5 SOL5 MI5 0 MI5 0 DO5 DO6 DO6 LAS5 SOL5 LA5
int tonesF[] = {RE5, LAS5, LA5, SOL5, DO6, 0, DO6, 0, RE6, DO6, LAS5, SOL5, FA5}; // RE5 LAS5 LA5 SOL5 DO6 0 DO6 0 RE6 DO6 LAS5 SOL5 FA5
int tonesG[] = {LA5, LA5, LA5, 0, LA5, LA5, LA5, 0, LA5, DO6, FA5, SOL5, LA5, 0, 0, 0}; // LA5 LA5 LA5 0 LA5 LA5 LA5 0 LA5 DO6 FA5 SOL5 LA5 0 0 0 
int tonesH[] = {LAS5, LAS5, LAS5, 0, LAS5, LA5, LA5, 0, LA5, SOL5, SOL5, FA5, SOL5, 0, DO6, 0}; // LAS5 LAS5 LAS5 LAS5 LA5 LA5 LA5 SOL5 SOL5 FA5 SOL5 DO6
int tonesI[] = {DO6, 0, 0, 0, DO6, 0, 0, 0, LAS5, 0, 0, 0, SOL5, 0, 0, 0, FA5, 0, 0, 0, FA5, 0}; // DO6 0 0 0 DO6 0 0 0 LAS5 0 0 0 SOL5 0 0 0 FA5 0 0 0 FA5 0

// as durações de cada nota
int durationA[] = {co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co};
int durationB[] = {co,co,co,co,co,co,co,co};
int durationC[] = {co,co,co,co,co,co};
int durationD[] = {co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co};
int durationE[] = {co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co};
int durationF[] = {co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co};
int durationG[] = {co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co};
int durationH[] = {co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co};
int durationI[] = {co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co,co};

 
char melody[] = "abacdedfghghi";
 
// quantidade de notas de cada parte
int numberA = 24;
int numberB = 8;
int numberC = 6;
int numberD = 16;
int numberE = 14;
int numberF = 13;
int numberG = 15;
int numberH = 16;
int numberI = 22;

int melodynum = 33;
 
// Função que recebe uma faixa (notas e durações) e o número de notas
void play(int tones[], int duration[], int number, int bpm){
  int i;
 
  for (i = 0; i < number; i++) {
 
    int lenght = bpm*duration[i];
    digitalWrite(13,HIGH);
    tone(piezopin, tones[i],lenght);
    digitalWrite(13,LOW);
    // Pausas para que as notas não fiquem coladas umas nas outras
    if(duration[i]==se)
      delay(bpm/0.5);
    if(duration[i]==tr)
      delay(bpm/.75);
    if(duration[i]==co)
      delay(bpm);
    
    // Pára de tocar a nota
    noTone(piezopin);
    
   }
}
 
// Função que recebe uma string que contam as faixas para criar uma música (e o seu tamanho)
void playall(char melody[], int num){
 
  int i;
 
  for(i=0;i < num; i++){
    if(melody[i]=='a')
      play(tonesA, durationA, numberA, SMbpm);
    if(melody[i]=='b')
      play(tonesB, durationB, numberB, SMbpm);
    if(melody[i]=='c')
      play(tonesC, durationC, numberC, SMbpm);
    if(melody[i]=='d')
      play(tonesD, durationD, numberD, SMbpm);
    if(melody[i]=='e')
      play(tonesE, durationE, numberE, SMbpm);
    if(melody[i]=='f')
      play(tonesF, durationF, numberF, SMbpm);
    if(melody[i]=='g')
      play(tonesG, durationG, numberG, SMbpm);
    if(melody[i]=='h')
      play(tonesH, durationH, numberH, SMbpm);
    if(melody[i]=='i')
      play(tonesI, durationI, numberI, SMbpm);
    }
}
 
void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(13,OUTPUT);
}
 
void loop() {
  acionamento = digitalRead(sensor); //Le o valor do sensor PIR
 if (acionamento == LOW)  //Sem movimento
 {
    Serial.println("no one");
 }
 else  //Caso seja detectado um movimento
 {
    Serial.println("moviment");
    playall(melody,melodynum);
 }
 delay(1000);
}
