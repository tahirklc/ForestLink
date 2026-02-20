# 🌲 ForestLink: Yapay Zeka Destekli Otonom IoT Yangın Kalkanı
Turkcell Yarının Teknoloji Liderleri 2026 - Proje Deposu

ForestLink, orman yangınlarını kaynağında tespit etmek için geliştirilmiş, Edge AI (Uçta Yapay Zeka) ve Çoklu Sensör Füzyonu kullanan otonom bir IoT sensör ağıdır. Bu depo, projenin uç birim (node), yapay zeka analiz ve mobil izleme katmanlarına ait temel yazılım mimarisini içermektedir.



## 🚀 Proje Mimarisi ve Teknoloji Yığını
Projemiz 3 ana katmandan oluşmaktadır:
1. Gömülü Sistem (IoT Node): ESP32/Raspberry Pi tabanlı, termal ve gaz sensör verilerini okuyan katman. (C++ / Python)
2. Edge AI Katmanı: Cihaz üzerinde çalışan, görüntü ve veri analizi ile yangın doğrulaması yapan model. (TensorFlow Lite, OpenCV)
3. Mobil İzleme Arayüzü: Kriz merkezleri ve itfaiye ekipleri için gerçek zamanlı harita ve alarm takibi. (Flutter)

## 📡 Haberleşme Altyapısı
- Yerel Ağ: Cihazlar arası Mesh Network (LoRaWAN)
- Geniş Alan Ağı: Gateway üzerinden **Turkcell NB-IoT / 4.5G ile bulut aktarımı.

## 🛠️ Geliştirme Durumu (Roadmap)
- [x] Konsept ve Sistem Mimarisi Tasarımı
- [x] IoT Sensör Veri Okuma ve Filtreleme Algoritmaları (Taslak)
- [x] Mobil Uygulama UI/UX Temelleri
- [ ] Edge AI Model Eğitimi (Veri Seti Toplanıyor)
- [ ] Turkcell Bulut Entegrasyonu ve API Testleri (Planlanıyor)

