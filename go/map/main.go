package main

import "fmt"

func main() {

	// var colors map[string]string

	// colors := make(map[string]string)

	// map with key:value string:string
	colors := map[string]string{
		"red":      "#ff0000",
		"blackish": "#0f0f0f",
	}

	delete(colors, "red")
}

func printMap(c map[string]string) {
	for color, hex := range c {
		fmt.Println(color, hex)
	}
}
