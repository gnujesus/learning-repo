import 'package:flutter/material.dart';

class CoffeePrefs extends StatelessWidget {
  const CoffeePrefs({super.key});

  @override
  Widget build(BuildContext context) {
    const defaultStyle = TextStyle(color: Colors.white);

    return Column(
      children: [
        Row(
          children: [
            Text("Strength: ", style: defaultStyle),
            SizedBox(width: 50),
            Image.asset("assets/img/coffee_bean.jpg", width: 25),
            Text("2", style: defaultStyle),
          ],
        ),
        Row(
          children: [
            Text("Sugars: ", style: defaultStyle),
            SizedBox(width: 50),
            Image.asset("assets/img/sugar_cube.jpg", width: 25),
            Text("3", style: defaultStyle),
          ],
        ),
      ],
    );
  }
}
