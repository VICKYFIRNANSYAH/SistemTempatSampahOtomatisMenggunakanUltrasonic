#include <Servo.h>
#include <NewPing.h>

#define TRIGGER_PIN 2
#define ECHO_PIN 3
#define MAX_DISTANCE 50
#define SERVO_PIN 4

Servo myservo;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  myservo.attach(SERVO_PIN);
  myservo.write(90); // stop awal
}

void loop() {
  int jarak = sonar.ping_cm();

  if (jarak > 0 && jarak <= 30) {
    Serial.println("Tangan terdeteksi! Membuka tempat sampah...");

    myservo.write(0);     // Putar arah buka
    delay(200);           // Putar selama 0.5 detik
    myservo.write(90);    // Stop servo

    delay(2000);          // Tunggu 2 detik (tempat sampah terbuka)

    myservo.write(180);   // Putar arah tutup
    delay(200);           // Putar balik 0.5 detik
    myservo.write(90);    // Stop servo

    delay(1000);          // Delay tambahan
  }

  delay(100);
}
