package main

import (
	"fmt"
)

func main() {
	slur := "dick"
	removeProfanity(&slur)

	fmt.Println(slur)
}

func removeProfanity(message *string) {

	chars := []rune(*message)

	for i := range chars {
		chars[i] = '*'
	}

	*message = string(chars)
}
