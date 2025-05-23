package main

// must separated by a new line, commas or ; not supported on golang
import (
	"fmt"
	"io/ioutil"
	"math/rand"
	"os"
	"strings"
	"time"
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
	// type deck is, essentially, == []string, but the Join method from strings only takes a string, so, even if string and deck are the same,
	// we have to convert it.Then, join all the values on the string slice (list) using a comma, and return it
	return strings.Join([]string(d), ",")
}

func (d deck) saveToFile(fileName string) error {
	return ioutil.WriteFile(fileName, []byte(d.toString()), 0666)
}

func loadFromFile(fileName string) deck {

	// If everything goes correctly, err is nil
	// bullshit... I mean, byteSlice
	bs, err := ioutil.ReadFile(fileName)

	if err != nil {
		// log & return empty deck
		fmt.Println("An error has ocurred: ", err)
		os.Exit(1)
	}

	stringSlice := strings.Split(string(bs), ",")

	return deck(stringSlice)
}

func (d deck) shuffle() deck {

	rand.Shuffle(len(d), func(i, j int) {
		d[i], d[j] = d[j], d[i]
	})

	return d
}

func (d deck) unnecessarilyLongShuffleMethodThatImNotGoingToUse() {
	// source is based on the current time
	source := rand.NewSource(time.Now().UnixNano())
	r := rand.New(source)

	for i := range d {
		newPosition := r.Intn(len(d) - 1)
		d[i], d[newPosition] = d[newPosition], d[i]
	}
}
