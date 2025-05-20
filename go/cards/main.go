// Allowed on go: fruits[2:] or fruites [:2]; [inclusive:exclusive]
package main

import "fmt"

func main() {
	cards := newDeck()
	fmt.Println(cards.toString())
}
