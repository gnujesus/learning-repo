import 'package:flutter/material.dart';

// ?: for note imports, you don't write the lib directoy, since flutter automatically imports from lib
// ?: if the view is on a folder, you'll have to add it
// import 'package:<project-name>/<folder>/<component>.dart'
import 'package:coffee_card/home.dart';

void main() {
  // ?: method that runs the app. Receives the main widget (or the root widget of the app)
  runApp(MaterialApp(home: const Home()));
}

class Sandbox extends StatelessWidget {
  const Sandbox({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Sandbox'),
        backgroundColor: Colors.grey,
      ),
      body: Row(
        mainAxisAlignment: MainAxisAlignment.center,
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Container(height: 100, width: 100, color: Colors.blue),
          Container(height: 200, width: 100, color: Colors.red),
          Container(height: 300, width: 100, color: Colors.yellow),
        ],
      ),
    );
  }
}
