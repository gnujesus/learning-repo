package main

import (
	"errors"
	"fmt"
)

func main() {
	var wentWrong error = errors.New("Something went wrong")

	fmt.Printf("%s \n", errors.Unwrap(wentWrong))
	fmt.Printf("%s", wentWrong)
}
