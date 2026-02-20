import 'package:flutter/material.dart';

void main() {
  runApp(const ForestLinkApp());
}

class ForestLinkApp extends StatelessWidget {
  const ForestLinkApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'ForestLink Dashboard',
      theme: ThemeData(
        primarySwatch: Colors.green,
        visualDensity: VisualDensity.adaptivePlatformDensity,
      ),
      home: const DashboardScreen(),
    );
  }
}

class DashboardScreen extends StatelessWidget {
  const DashboardScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('🌲 ForestLink Kontrol Merkezi'),
        backgroundColor: Colors.green[800],
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            const Text(
              'Sistem Durumu: AKTİF',
              style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Colors.green),
            ),
            const SizedBox(height: 20),
            Card(
              color: Colors.red[100],
              child: const ListTile(
                leading: Icon(Icons.warning, color: Colors.red, size: 40),
                title: Text('ALARM: Yüksek Sıcaklık Tespit Edildi', style: TextStyle(fontWeight: FontWeight.bold)),
                subtitle: Text('Sektör: Kuzey Ormanları - Düğüm #04\nEdge AI Doğrulaması: %85'),
              ),
            ),
            const SizedBox(height: 20),
            const Expanded(
              child: Center(
                child: Text(
                  '[ Harita Entegrasyonu (Google Maps API) Buraya Gelecek ]',
                  style: TextStyle(color: Colors.grey),
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
