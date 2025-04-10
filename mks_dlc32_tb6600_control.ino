#define ACTUATOR_PUL_PIN 16 // Pin de pulso para el actuador
#define ACTUATOR_DIR_PIN 17 // Pin de dirección para el actuador

#define MOTOR_PUL_PIN 18    // Pin de pulso para el motor
#define MOTOR_DIR_PIN 19    // Pin de dirección para el motor

// Configuración del actuador
const int actuatorStepsPerMM = 200;  // Pasos por mm del actuador (ajustar según hardware)
const int actuatorTravelMM = 200;   // Recorrido del actuador en mm
const int actuatorTravelTime = 300000; // Tiempo para recorrer 200 mm en milisegundos (5 min)
const int actuatorStepDelay = actuatorTravelTime / (actuatorStepsPerMM * actuatorTravelMM); // Tiempo entre pasos

// Configuración del motor
const int motorStepsPerRevolution = 200; // Pasos por revolución del motor
const float motorRPM = 0.45;             // Velocidad deseada en RPM
const int motorStepDelay = (60000 / motorRPM) / motorStepsPerRevolution; // Tiempo entre pasos en ms

void setup() {
  pinMode(ACTUATOR_PUL_PIN, OUTPUT);
  pinMode(ACTUATOR_DIR_PIN, OUTPUT);
  pinMode(MOTOR_PUL_PIN, OUTPUT);
  pinMode(MOTOR_DIR_PIN, OUTPUT);

  // Inicializar pines
  digitalWrite(ACTUATOR_PUL_PIN, LOW);
  digitalWrite(ACTUATOR_DIR_PIN, LOW);
  digitalWrite(MOTOR_PUL_PIN, LOW);
  digitalWrite(MOTOR_DIR_PIN, LOW);
}

void loop() {
  // Mover el actuador hacia adelante
  digitalWrite(ACTUATOR_DIR_PIN, HIGH); // Dirección hacia adelante
  for (int i = 0; i < actuatorStepsPerMM * actuatorTravelMM; i++) {
    digitalWrite(ACTUATOR_PUL_PIN, HIGH);
    delayMicroseconds(actuatorStepDelay / 2);
    digitalWrite(ACTUATOR_PUL_PIN, LOW);
    delayMicroseconds(actuatorStepDelay / 2);
  }
  delay(1000); // Pausa de 1 segundo

  // Regresar el actuador
  digitalWrite(ACTUATOR_DIR_PIN, LOW); // Dirección hacia atrás
  for (int i = 0; i < actuatorStepsPerMM * actuatorTravelMM; i++) {
    digitalWrite(ACTUATOR_PUL_PIN, HIGH);
    delayMicroseconds(actuatorStepDelay / 2);
    digitalWrite(ACTUATOR_PUL_PIN, LOW);
    delayMicroseconds(actuatorStepDelay / 2);
  }
  delay(1000); // Pausa de 1 segundo

  // Girar el motor paso a paso
  digitalWrite(MOTOR_DIR_PIN, HIGH); // Dirección del motor
  for (int i = 0; i < motorStepsPerRevolution; i++) {
    digitalWrite(MOTOR_PUL_PIN, HIGH);
    delayMicroseconds(motorStepDelay / 2);
    digitalWrite(MOTOR_PUL_PIN, LOW);
    delayMicroseconds(motorStepDelay / 2);
  }
}