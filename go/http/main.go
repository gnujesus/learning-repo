package main

import (
	"fmt"
	"net/http"
	"os"
)

func main() {
	res, err := http.Get("https://adamix.net/defensa_civil/def/servicios.php")

	if err != nil {
		fmt.Println("Error", err)
		os.Exit(1)
	}

	fmt.Println(res.Body)
}
