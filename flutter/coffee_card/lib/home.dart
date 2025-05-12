import 'package:flutter/material.dart';
import 'package:coffee_card/coffee_prefs.dart';

class Home extends StatelessWidget {
  const Home({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(
          "Hello W0rld",
          style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold),
        ),
        backgroundColor: Colors.blue[300],
        centerTitle: true,
      ),
      body: Column(
        crossAxisAlignment: CrossAxisAlignment.stretch,
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          Container(
            color: Colors.brown[300],
            padding: EdgeInsets.all(20),
            child: const Text(
              "How I like my coffee",
              style: TextStyle(color: Colors.white),
            ),
          ),
          Container(
            color: Colors.brown[500],
            padding: EdgeInsets.fromLTRB(20, 50, 20, 50),
            child: CoffeePrefs(),
          ),
        ],
      ),
    );
  }
}
