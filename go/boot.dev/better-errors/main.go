package main

import (
	"fmt"
)

func getSMSErrorString(cost float64, recipient string) string {
	msg := fmt.Sprintf("SMS that costs $%.2f to be sent to '%s' can not be sent", cost, recipient)
	return msg
}

func main() {
	fmt.Printf(getSMSErrorString(23.3412, "Ivan Mercedes"))
}
