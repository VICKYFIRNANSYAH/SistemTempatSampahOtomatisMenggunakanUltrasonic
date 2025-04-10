// PROJECT TEMPAT SAMPAH OTOMATIS
// BY MUHAMMAD VICKY FIRNANSYAH
//https://github.com/VICKYFIRNANSYAH

#include <Servo.h>     // Library untuk mengontrol servo
#include <NewPing.h>   // Library untuk sensor ultrasonik

Servo myservo;  

// Pin dan batas deteksi
#define TRIGGER_PIN 2  
#define ECHO_PIN 3
#define MAX_DISTANCE 50  // Batasi deteksi maksimal hingga 50 cm

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

// Variabel sudut servo untuk memudahkan pengubahan
int sudut_terbuka = 90; // Sudut saat tempat sampah terbuka
int sudut_tertutup = 0; // Sudut saat tempat sampah tertutup

void setup() {
  myservo.attach(4);     
  myservo.write(sudut_tertutup); // Pastikan servo dalam kondisi tertutup saat mulai
  Serial.begin(9600);
}

void loop() {
  int vic_jarak = sonar.ping_cm(); // Baca jarak dari sensor ultrasonik

  // Pastikan data jarak valid (>0)
  if (vic_jarak > 0 && vic_jarak <= 30) {  // Batasi jangkauan agar lebih efektif
    Serial.println("Objek terdeteksi! Membuka tempat sampah...");
    myservo.write(sudut_terbuka);   // Gunakan variabel sudut_terbuka
    delay(2000);                    // Tunggu 2 detik dalam kondisi terbuka
    myservo.write(sudut_tertutup);  // Gunakan variabel sudut_tertutup
    Serial.println("Menutup tempat sampah...");
    delay(1500);                    // Tunggu 1,5 detik sebelum memeriksa lagi
  } else {
    myservo.write(sudut_tertutup); // Tetap tutup jika tidak ada objek
  }

  delay(100); // Tambahkan delay untuk mengurangi polling sensor terlalu cepat
}
