//TEMPAT SAMPAH OTOMATIS MENGGUNAKAN SERVO MG90S DAN ULTRASONIC
//BY MUHAMMAD VICKY FIRNANSYAH 
//https://github.com/VICKYFIRNANSYAH
#include <Servo.h>
#include <NewPing.h>

Servo myservo;

#define TRIGGER_PIN 2
#define ECHO_PIN 3
#define MAX_DISTANCE 50
#define LED_PIN 7

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Sesuaikan sudut jika MG90S kamu tidak bergerak sempurna
int sudut_terbuka = 90;   
int sudut_tertutup = 10;

void setup() {
  myservo.attach(5);
  delay(300); // Tambah delay agar MG90S siap
  myservo.write(sudut_tertutup);
  
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(9600);
  //https://github.com/VICKYFIRNANSYAH
}

void loop() {
  int vic_jarak = sonar.ping_cm();

  if (vic_jarak > 0 && vic_jarak <= 30) {
    Serial.println("Objek terdeteksi! Membuka tempat sampah...");
    myservo.write(sudut_terbuka);
    digitalWrite(LED_PIN, HIGH);
    delay(2000);
    myservo.write(sudut_tertutup);
    digitalWrite(LED_PIN, LOW);
    Serial.println("Menutup tempat sampah...");
    delay(1500);
  } else {
    myservo.write(sudut_tertutup);
    digitalWrite(LED_PIN, LOW);
  }

  delay(100);
}
