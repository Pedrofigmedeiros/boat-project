#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include <Servo.h> // Biblioteca para controlar o servo motor

// Configuração do Magnetômetro
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

// Configuração do Servo Motor
Servo servoMotor; // Cria o objeto do servo
#define SERVO_PIN 9 // Pino onde o servo está conectado

float targetHeading = 180; // Definindo Norte para 180 graus

// Inicializa sensor e pino do servo motor
void setup() {
  Serial.begin(9600);
  servoMotor.attach(SERVO_PIN); // Associa o servo ao pino definido
  Serial.println("--------------");

  if (!mag.begin()) {
    Serial.println("Magnetômetro não detectado!");
    while (1);
  }
}

// Função para calcular e retornar o heading em graus
float getHeading() {
  sensors_event_t event;
  mag.getEvent(&event);

  // Calcula o ângulo de direção em graus
  float heading = atan2(event.magnetic.y, event.magnetic.x) * (180.0 / M_PI);

  // Declinação magnética em graus (ajuste de acordo com a sua localização)
  float declinationAngle = 45;
  heading += declinationAngle;

  // Ajusta o heading para estar entre 0 e 360 graus
  if (heading < 0) heading += 360;
  if (heading >= 360) heading -= 360;

  // Ajusta o Norte para ser 180 graus
  heading = fmod(heading + 180.0, 360.0);

  return heading;
}

// Função para ajustar o servo motor em direção ao heading alvo
void adjustServo(float target, float current) {
  float difference = target - current;

  // Converte a diferença para um ângulo válido para o servo (0 a 180 graus)
  float servoPosition = map(difference, -180, 180, 0, 180);
  servoPosition = constrain(servoPosition, 0, 180);

  // Ajusta o ângulo do servo motor
  servoMotor.write(servoPosition);
}

void loop() {
  float currentHeading = getHeading();
  Serial.print("Current Heading: "); 
  Serial.println(currentHeading);
  adjustServo(targetHeading, currentHeading);
  delay(200); // Delay para estabilidade
}
