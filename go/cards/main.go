// Allowed on go: fruits[2:] or fruites [:2]; [inclusive:exclusive]
package main

// import "fmt"
//
func main() {
	// fmt.Println(cards.toString())
	// cards.saveToFile("my-cards.txt")
	var newDeck deck = loadFromFile("my-cards.txt")

	nd := newDeck.shuffle()
	nd.print()
}
