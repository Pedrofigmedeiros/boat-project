#include <Wire.h>
#include <Servo.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

// Instâncias de componentes
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);
Servo leme;

// Pinos
#define PIN_POTENCIOMETRO A1
#define PIN_SERVO 9
#define PIN_MOTOR_PWM 3

// Variáveis
float norteReferencia = 0; // Norte ajustável
float direcaoAtual = 0; // Direção atual do magnetômetro
float erro; // Desvio em relação ao norte
float offset = 0; // Offset fixo para corrigir leitura do magnetômetro

void setup() {
  Serial.begin(9600);

  // Inicializar magnetômetro
  if (!mag.begin()) {
    Serial.println("Erro no Magnetômetro!");
    while (1); // Parar o programa se houver erro
  }

  // Inicializar servo
  leme.attach(PIN_SERVO);

  // Configurar motor (inicialmente parado)
  pinMode(PIN_MOTOR_PWM, OUTPUT);
  analogWrite(PIN_MOTOR_PWM, 0);

  Serial.println("Sistema Pronto!");
}

void loop() {
  // Ler o norte de referência ajustável
  norteReferencia = analogRead(PIN_POTENCIOMETRO) * 360.0 / 1023.0;

  // Ler a direção atual do magnetômetro
  sensors_event_t event;
  mag.getEvent(&event);

  // Calcular direção (azimute)
  direcaoAtual = atan2(event.magnetic.y, event.magnetic.x) * 180 / PI;
  if (direcaoAtual < 0) direcaoAtual += 360;

  // Aplicar offset para corrigir leitura
  direcaoAtual += offset;
  if (direcaoAtual >= 360) direcaoAtual -= 360;

  // Calcular erro (diferença para o norte ajustável)
  erro = direcaoAtual - norteReferencia;
  if (erro > 180) erro -= 360;
  if (erro < -180) erro += 360;

  // Limitar o erro dentro de -90° a 90°
  if (erro > 90) erro = 90;
  if (erro < -90) erro = -90;

  // Mapear o erro (-90 a 90) para o ângulo do servo (0 a 180)
  int anguloLeme = map(erro, -90, 90, 0, 180); 
  leme.write(anguloLeme);

  // Exibir dados no monitor serial
  Serial.print("Direcao Atual: ");
  Serial.print(direcaoAtual, 1); // Direção com 1 casa decimal
  Serial.print(" graus | ");

  Serial.print("Ref Norte: ");
  Serial.print(norteReferencia, 1); // Norte ajustável
  Serial.print(" graus | ");

  Serial.print("Erro: ");
  Serial.print(erro, 1); // Erro em graus
  Serial.print(" graus | ");

  Serial.print("Leme: ");
  Serial.print(anguloLeme); // Posição do leme
  Serial.println(" graus");

  // Ligar o motor (velocidade constante)
  analogWrite(PIN_MOTOR_PWM, 200);

  delay(200); // Atraso para leitura
}
