package main

import "fmt"

type Formatter interface {
	Format() string
}

/*
type Text struct {
	message string
}

// This works, but tests aren't declaring the variables the way they're intended with this approach, so fuck it

type PlainText struct {
	Text
}

type Bold struct {
	Text
}

type Code struct {
	Text
}
*/

type PlainText struct {
	message string
}

type Bold struct {
	message string
}

type Code struct {
	message string
}

func (p PlainText) Format() string {
	return p.message
}

func (b Bold) Format() string {
	// NOTE: Use fmt.Sprintf() to recieve the formatted string, not fmt.Printf()
	return fmt.Sprintf("**%s**", b.message)
}

func (c Code) Format() string {
	return fmt.Sprintf("`%s`", c.message)
}

// Don't Touch below this line

func SendMessage(formatter Formatter) string {
	return formatter.Format() // Adjusted to call Format without an argument
}
