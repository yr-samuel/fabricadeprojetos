// SENSOR ULTRASSONICO
const int echo = 5;
const int trigger = 13;

// BUZZER
const int buzzer = 7;
 
// BOTOES
const int btn_um = 4;
const int btn_dois = 2; 

// DISPLAY 7 SEGMENTOS
const int pino_a = 12;
const int pino_b = 9;
const int pino_c = 10;
const int pino_d = 11;


int cont_btn1 = 0;
int cont_btn2 = 0;

int valor_botao;

int inches = 0;

int cm = 0;

//FUNCAO DO SENSOR ULTRASSONICO
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // LIMPA O TRIGGER
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  // CONFIGURA O PINO TRIGGER COMO HIGH, POR 10 MICROSSEGUNDOS
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  
  // LE O PINO ECHO, E RETORNA O TEMPO DO CAMINHO DA ONDE EM MICROSSEGUNDOS
  return pulseIn(echoPin, HIGH);
}

void Idoso(){
  float cm = 0.01723 * readUltrasonicDistance(trigger,echo);
  if (cm > 200){
    digitalWrite(buzzer, HIGH);
  }  else {
    digitalWrite(buzzer, LOW);
    
  }
}

void Crianca(){
  float cm = 0.01723 * readUltrasonicDistance(trigger,echo);
  if (cm > 20){
    digitalWrite(buzzer, HIGH);
  }  else {
    digitalWrite(buzzer, LOW);
    
  }
}

void setup(){  
    pinMode(buzzer, OUTPUT);
    pinMode(btn_um, INPUT);
    pinMode(btn_dois, INPUT);
  
}

void loop(){

  
  
 if(digitalRead(btn_um)==  0){  // Se a leitura do botão quando for pressionado for igual a 0
  cont_btn1++;  // Atribui +1 a variavel cont_btn1
  delay(300); // Da um tempo para a leitura do arduino, senão crasha.
  }
  
  if(digitalRead(btn_dois)==  0){  // Se a leitura do botão quando for pressionado for igual a 0
  cont_btn2++;  // Atribui +1 a variavel cont_btn2
  delay(300); // Da um tempo para a leitura do arduino, senão crasha.
  }
  
// LOGICA PARA LIMITAÇÃO DO BOTAO
 if(cont_btn1 == 3){
    cont_btn1 = 1;
   digitalWrite(pino_a, HIGH);
   digitalWrite(pino_b, LOW);
   digitalWrite(pino_c, LOW);
   digitalWrite(pino_d, LOW);
 }  //	deixa o valor somente de 1 a 3
 
// LOGICA PARA LIMITAÇÃO DO BOTAO
 if(cont_btn2==3){
    cont_btn2=1;
   digitalWrite(pino_a, HIGH);
   digitalWrite(pino_b, LOW);
   digitalWrite(pino_c, LOW);
   digitalWrite(pino_d, LOW);
 }   //  deixa o valor somente de 1 a 3
  
  

 if(cont_btn1==1){
  cont_btn2 = 0;
   
  Idoso();				// NESSA CONDIÇÃO, QUANDO O BTN1 É PRESSIONADO, A FUNÇÃO IDOSO COMEÇA A FUNCIONAR
   
   digitalWrite(pino_a, 1);
   digitalWrite(pino_b, 0);
   digitalWrite(pino_c, 0);
   digitalWrite(pino_d, 0);
  
 } else if(cont_btn1 == 2){
    digitalWrite(buzzer, LOW);
   
     digitalWrite(pino_a, 1);		// NESSA CONDIÇÃO, QUANDO O BTN1 É PRESSIONADO, CONTINUA NESSA FUNÇÃO, MAS DESATIVA O BUZZER
     digitalWrite(pino_b, 0);
     digitalWrite(pino_c, 0);
     digitalWrite(pino_d, 0);
  }
  
  if(cont_btn2==1){
    cont_btn1 = 0;
    
  Crianca();				// NESSA CONDIÇÃO, QUANDO O BTN2 É PRESSIONADO, A FUNÇÃO IDOSO COMEÇA A FUNCIONAR
   
   digitalWrite(pino_a, 0);
   digitalWrite(pino_b, 1);
   digitalWrite(pino_c, 0);
   digitalWrite(pino_d, 0);
   
 }else if(cont_btn2==2){
  digitalWrite(buzzer, LOW);
   
   digitalWrite(pino_a, 0);		// NESSA CONDIÇÃO, QUANDO O BTN2 É PRESSIONADO, CONTINUA NESSA FUNÇÃO, MAS DESATIVA O BUZZER
   digitalWrite(pino_b, 1);
   digitalWrite(pino_c, 0);
   digitalWrite(pino_d, 0);
 }
}	