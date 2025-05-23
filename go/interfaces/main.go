package main

import "fmt"

// all structs or types that implement this method are now of type bot (honorary member)
type bot interface {
	getGreeting() string
}

type englishBot struct{}
type spanishBot struct{}

func main() {
	eb := englishBot{}
	sb := spanishBot{}

	printGreeting(eb)
	printGreeting(sb)
}

// if you're not using the value, you can just have the reciever
func (englishBot) getGreeting() string {

	// imagine there's some custom logic here
	return "Sup"
}

func (spanishBot) getGreeting() string {

	// imaginate que aqui hay una vaina super complicada y diferente de la lógica del bot ingles
	return "Dime a ve"
}

// receives a type bot
func printGreeting(b bot) {
	fmt.Println(b.getGreeting())
}
