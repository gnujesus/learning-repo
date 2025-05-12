import 'package:flutter/material.dart';

class CoffeePrefs extends StatelessWidget {
  const CoffeePrefs({super.key});

  @override
  Widget build(BuildContext context) {
    const defaultStyle = TextStyle(color: Colors.white);

    return const Column(
      children: [
        Row(
          children: [
            Text("Strength: ", style: defaultStyle),
            SizedBox(width: 50),
            Image.asset("assets/img/coffee_bean.png", width: 25),
            Text("2", style: defaultStyle),
          ],
        ),
        Row(
          children: [
            Text("Sugars: ", style: defaultStyle),
            SizedBox(width: 50),
            Image.asset("assets/img/sugar_cube.png", width: 25),
            Text("3", style: defaultStyle),
          ],
        ),
      ],
    );
  }
}
