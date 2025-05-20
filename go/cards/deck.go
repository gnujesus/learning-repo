package main

// must separated by a new line, commas or ; not supported on golang
import (
	"fmt"
	"strings"
)

// []string is now equal to deck
type deck []string

func newDeck() deck {
	d := deck{}

	cardSuites := []string{"Spades", "Diamonds", "Hearts", "Clubs"}
	cardValues := []string{"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jester", "Queen", "King"}

	for _, suite := range cardSuites {
		for _, value := range cardValues {
			d = append(d, value+" of "+suite)
		}
	}

	return d
}

// By convention, the reciever is one or two letters that match the type
func (d deck) print() {
	for i, card := range d {
		fmt.Println(i, card)
	}
}

func deal(d deck, handSize int) (deck, deck) {
	return d[handSize:], d[:handSize]
}

func (d deck) toString() string {
	return strings.Join([]string(d), ",")
}
