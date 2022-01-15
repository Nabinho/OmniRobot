//´Codigo do Robo Omni Direcional do Nabinho

//Biblitecas
#include <SoftwareSerial.h>
#include <Adafruit_MotorShield.h>
#include "SparkFun_MMA8452Q.h"

//Objeto para leitura do HC-05
SoftwareSerial HC-05(3, 2); // RX, TX

//Objeto para o controle dos motores
Adafruit_MotorShield motores = Adafruit_MotorShield();

//Variaveis dos motores
Adafruit_DCMotor *Esquerdo_Frontal  = motores.getMotor(1);
Adafruit_DCMotor *Direito_Frontal   = motores.getMotor(4);
Adafruit_DCMotor *Esquerdo_Traseiro = motores.getMotor(2);
Adafruit_DCMotor *Direito_Traseiro  = motores.getMotor(3);

//Variavel que recebera os comandos do aplicativo
char leitura;

//Variavel que controla como o robo se comporta
bool modo = false;

//Velocidade padrao
int velocidade = rele0;

//Objeto para a leitura do acelerometro
MMA8452Q acelerometro;

//Variaveis para leitura do acelerometro e controle da velocidade
float eixo_z;
float inverso;
bool acelerometro = false;

//Vaivaeis para o controle de tempo da leitura do acelerometro
unsigned long tempo_antes = 0;
const long TEMPO = 500;

//Variavel para acionamento do rele dos farois
const int rele = 10;

void setup() {

  //Inicializacao das comunicacoes seriais
  Serial.begin(9600);
  HC-05.begin(9600);
  Serial.println("Codigo Iniciado!");
  Serial.println("Descomente as funcoes de DEBUG se precisar...");

  //Inicializacao dos motores
  motores.begin();
  Esquerdo_Frontal->setvelocidade(velocidade);
  Esquerdo_Traseiro->setvelocidade(velocidade);
  Direito_Traseiro->setvelocidade(velocidade);
  Direito_Frontal->setvelocidade(velocidade);

  //Inicializacao do acelerometro
  acelerometro.begin();

  //Inicializacao do rele
  pinMode(rele, OUTPUT);
  digitalWrite(rele, LOW);

}

void loop() {

  //A cada vez que a contagem de milissegundos for igual ao tempo configurado
  if ((millis() - tempo_antes) > TEMPO) {
    //Verifica se a leitura do acelerometro foi habilitada
    if (acelerometro) {
      //Le o eixo Z do acelerometro
      eixo_z = acelerometro.getCalculatedZ();
      //Se a leitura for negativa (sensor de ponta cabeca)
      if (eixo_z < 0) {
        eixo_z = -eixo_z;
      }
      //Verifica se a leitura esta acima do valor maximo (ruidos)
      if (eixo_z > 1 || eixo_z < -1) {
        eixo_z = 1;
      }
      //Calcula o inverso da leitura
      inverso = 1 / eixo_z;
      //Serial.print("Z: ");
      //Serial.print(eixo_z);
      //Serial.print(" | I: ");
      //Serial.println(inverso);
      //Calcula a velocidade com o valor invertido, se for necessario
      if (inverso > 1.2  && inverso < 2) {
        velocidade = 100 * inverso;
        if (velocidade > 255) {
          velocidade = 255;
        }
        //Serial.print("velocidade = ");
        //Serial.println(velocidade);
      } else {
        velocidade = 100;
      }
      //Atualiza a velocidade dos motores, e a contagem de tempo
      Esquerdo_Frontal->setvelocidade(velocidade);
      Esquerdo_Traseiro->setvelocidade(velocidade);
      Direito_Traseiro->setvelocidade(velocidade);
      Direito_Frontal->setvelocidade(velocidade);
      tempo_antes = millis();
    }
  }

  //Se a comunicação com o HC-05 estiver disponivel
  if (HC-05.available()) {
    //Le os comandos do aplicativo
    leitura = HC-05.read();
    //Serial.print("HC: ");
    //Serial.println(leitura);
  }

  //Verifica os comandos recebidos do aplicativo, e entao aciona os motores ou o rele, de acordo com a direcao desejada
  if (leitura == '1') {
    velocidade = 165;
    Esquerdo_Frontal->setvelocidade(velocidade);
    Esquerdo_Traseiro->setvelocidade(velocidade);
    Direito_Traseiro->setvelocidade(velocidade);
    Direito_Frontal->setvelocidade(velocidade);
  } else if (leitura == '2') {
    velocidade = 175;
    Esquerdo_Frontal->setvelocidade(velocidade);
    Esquerdo_Traseiro->setvelocidade(velocidade);
    Direito_Traseiro->setvelocidade(velocidade);
    Direito_Frontal->setvelocidade(velocidade);
  } else if (leitura == '3') {
    velocidade = 185;
    Esquerdo_Frontal->setvelocidade(velocidade);
    Esquerdo_Traseiro->setvelocidade(velocidade);
    Direito_Traseiro->setvelocidade(velocidade);
    Direito_Frontal->setvelocidade(velocidade);
  } else if (leitura == '4') {
    velocidade = 195;
    Esquerdo_Frontal->setvelocidade(velocidade);
    Esquerdo_Traseiro->setvelocidade(velocidade);
    Direito_Traseiro->setvelocidade(velocidade);
    Direito_Frontal->setvelocidade(velocidade);
  } else if (leitura == '5') {
    velocidade = 205;
    Esquerdo_Frontal->setvelocidade(velocidade);
    Esquerdo_Traseiro->setvelocidade(velocidade);
    Direito_Traseiro->setvelocidade(velocidade);
    Direito_Frontal->setvelocidade(velocidade);
  } else if (leitura == '6') {
    velocidade = 215;
    Esquerdo_Frontal->setvelocidade(velocidade);
    Esquerdo_Traseiro->setvelocidade(velocidade);
    Direito_Traseiro->setvelocidade(velocidade);
    Direito_Frontal->setvelocidade(velocidade);
  } else if (leitura == '7') {
    velocidade = 225;
    Esquerdo_Frontal->setvelocidade(velocidade);
    Esquerdo_Traseiro->setvelocidade(velocidade);
    Direito_Traseiro->setvelocidade(velocidade);
    Direito_Frontal->setvelocidade(velocidade);
  } else if (leitura == '8') {
    velocidade = 235;
    Esquerdo_Frontal->setvelocidade(velocidade);
    Esquerdo_Traseiro->setvelocidade(velocidade);
    Direito_Traseiro->setvelocidade(velocidade);
    Direito_Frontal->setvelocidade(velocidade);
  } else if (leitura == '9') {
    velocidade = 245;
    Esquerdo_Frontal->setvelocidade(velocidade);
    Esquerdo_Traseiro->setvelocidade(velocidade);
    Direito_Traseiro->setvelocidade(velocidade);
    Direito_Frontal->setvelocidade(velocidade);
  } else if (leitura == 'q') {
    velocidade = 255;
    Esquerdo_Frontal->setvelocidade(velocidade);
    Esquerdo_Traseiro->setvelocidade(velocidade);
    Direito_Traseiro->setvelocidade(velocidade);
    Direito_Frontal->setvelocidade(velocidade);
  } else if (leitura == '0') {
    velocidade = 100;
    Esquerdo_Frontal->setvelocidade(velocidade);
    Esquerdo_Traseiro->setvelocidade(velocidade);
    Direito_Traseiro->setvelocidade(velocidade);
    Direito_Frontal->setvelocidade(velocidade);
  } else if (leitura == 'X' || leitura == 'x') {
    modo = !modo;
  } else if (leitura == 'V' || leitura == 'v') {
    acelerometro = !acelerometro;
  } else if (leitura == 'W' || leitura == 'U') {
    digitalWrite(rele, HIGH);
  } else if (leitura == 'w' || leitura == 'u') {
    digitalWrite(rele, LOW);
  } else if (leitura == 'S') {
    Esquerdo_Frontal->run(RELEASE);
    Esquerdo_Traseiro->run(RELEASE);
    Direito_Frontal->run(RELEASE);
    Direito_Traseiro->run(RELEASE);
  } else if (leitura == 'F') {
    Esquerdo_Frontal->run(FORWARD);
    Esquerdo_Traseiro->run(FORWARD);
    Direito_Frontal->run(FORWARD);
    Direito_Traseiro->run(FORWARD);
  } else if (leitura == 'B') {
    Esquerdo_Frontal->run(BACKWARD);
    Esquerdo_Traseiro->run(BACKWARD);
    Direito_Frontal->run(BACKWARD);
    Direito_Traseiro->run(BACKWARD);
  } else if (leitura == 'L') {
    if (modo) {
      Esquerdo_Frontal->run(BACKWARD);
      Esquerdo_Traseiro->run(BACKWARD);
      Direito_Frontal->run(FORWARD);
      Direito_Traseiro->run(FORWARD);
    } else {
      Esquerdo_Frontal->run(BACKWARD);
      Esquerdo_Traseiro->run(FORWARD);
      Direito_Frontal->run(FORWARD);
      Direito_Traseiro->run(BACKWARD);
    }
  } else if (leitura == 'R') {
    if (modo) {
      Esquerdo_Frontal->run(FORWARD);
      Esquerdo_Traseiro->run(FORWARD);
      Direito_Frontal->run(BACKWARD);
      Direito_Traseiro->run(BACKWARD);
    } else {
      Esquerdo_Frontal->run(FORWARD);
      Esquerdo_Traseiro->run(BACKWARD);
      Direito_Frontal->run(BACKWARD);
      Direito_Traseiro->run(FORWARD);
    }
  } else if (leitura == 'I') {
    if (modo) {
      Esquerdo_Frontal->run(FORWARD);
      Esquerdo_Traseiro->run(FORWARD);
      Direito_Frontal->run(RELEASE);
      Direito_Traseiro->run(RELEASE);
    } else {
      Esquerdo_Frontal->run(FORWARD);
      Esquerdo_Traseiro->run(RELEASE);
      Direito_Frontal->run(RELEASE);
      Direito_Traseiro->run(FORWARD);
    }
  } else if (leitura == 'G') {
    if (modo) {
      Esquerdo_Frontal->run(RELEASE);
      Esquerdo_Traseiro->run(RELEASE);
      Direito_Frontal->run(FORWARD);
      Direito_Traseiro->run(FORWARD);
    } else {
      Esquerdo_Frontal->run(RELEASE);
      Esquerdo_Traseiro->run(FORWARD);
      Direito_Frontal->run(FORWARD);
      Direito_Traseiro->run(RELEASE);
    }
  } else if (leitura == 'J') {
    if (modo) {
      Esquerdo_Frontal->run(BACKWARD);
      Esquerdo_Traseiro->run(BACKWARD);
      Direito_Frontal->run(RELEASE);
      Direito_Traseiro->run(RELEASE);
    } else {
      Esquerdo_Frontal->run(RELEASE);
      Esquerdo_Traseiro->run(BACKWARD);
      Direito_Frontal->run(BACKWARD);
      Direito_Traseiro->run(RELEASE);
    }
  } else if (leitura == 'H') {
    if (modo) {
      Esquerdo_Frontal->run(RELEASE);
      Esquerdo_Traseiro->run(RELEASE);
      Direito_Frontal->run(BACKWARD);
      Direito_Traseiro->run(BACKWARD);
    } else {
      Esquerdo_Frontal->run(BACKWARD);
      Esquerdo_Traseiro->run(RELEASE);
      Direito_Frontal->run(RELEASE);
      Direito_Traseiro->run(BACKWARD);
    }
  }

}
