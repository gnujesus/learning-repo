package main

import "fmt"

type contactInfo struct {
	email   string
	zipCode int
}

type person struct {
	firstName string
	lastName  string
	contactInfo
}

func main() {

	// different from other languages, trailing commas are mandatory here

	jesus := person{
		firstName: "Jesus",
		lastName:  "Martinez",
		contactInfo: contactInfo{
			email:   "gnujesus@gmail.com",
			zipCode: 11205,
		},
	}

	jesus.updateName("Albert")
	jesus.print()
}

func (p person) print() {
	fmt.Printf("%+v", p)
}

func (personPtr *person) updateName(newFirstName string) {
	(*personPtr).firstName = newFirstName
}
