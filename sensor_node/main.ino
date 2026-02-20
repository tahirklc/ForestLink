/*
 * ForestLink - IoT Sensor Node Base Firmware
 * Açıklama: Bu kod, MQ serisi gaz sensörlerinden ve sıcaklık sensöründen
 * veri okur. Eşik değeri aşıldığında veriyi LoRa modülü üzerinden Gateway'e iletir.
 */

#include <DHT.h>
// LoRa kütüphaneleri eklenecek (Örn: LoRa.h)

#define DHTPIN 4
#define DHTTYPE DHT22
#define GAS_SENSOR_PIN A0

DHT dht(DHTPIN, DHTTYPE);

// Eşik Değerleri (Yangın Alarmı İçin)
const float TEMP_THRESHOLD = 50.0; // Santigrat
const int GAS_THRESHOLD = 400;     // ppm

void setup() {
  Serial.begin(115200);
  dht.begin();
  // LoRa.begin(868E6); // Türkiye LoRa frekansı
  Serial.println("ForestLink Node Başlatıldı...");
}

void loop() {
  // 1. Sensörlerden Veri Oku
  float temperature = dht.readTemperature();
  int gasLevel = analogRead(GAS_SENSOR_PIN);

  // 2. Çoklu Sensör Füzyonu - Basit Kontrol
  if (temperature > TEMP_THRESHOLD && gasLevel > GAS_THRESHOLD) {
    Serial.println("🔥 DİKKAT: Yüksek Sıcaklık ve Gaz Tespit Edildi!");
    
    // Edge AI modülünü tetikle (Kamera doğrulama için)
    triggerEdgeAI();
    
    // LoRa ile Gateway'e alarm gönder
    sendLoRaPayload(temperature, gasLevel);
  }

  // Güç tasarrufu için derin uykuya geç (Deep Sleep)
  delay(5000); 
}

void sendLoRaPayload(float temp, int gas) {
  // Turkcell NB-IoT Gateway'e iletilmek üzere LoRa paketinin oluşturulması
  Serial.print("LoRa Paketi Gönderiliyor -> Temp: ");
  Serial.print(temp);
  Serial.print(" Gas: ");
  Serial.println(gas);
  // LoRa.beginPacket(); ... LoRa.endPacket();
}

void triggerEdgeAI() {
  // Görüntü analizi için sinyal gönderilir
  Serial.println("Edge AI Kamera Modülü Uyandırılıyor...");
}
