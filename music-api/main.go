package main

import (
	"log"
	"net/http"
)

import "fmt"

type Song struct {
	Id              int
	Name            string
	Artist          string
	Genre           string
	Rating          int
	MonthlyAudience int
	Platforms       []string
}

func (s *Song) ToString() string {
	return fmt.Sprintf("Song Name: %s \nArtist Name: %s \nGenre: %s \nRating: %d \nMonthly Audience: %d", s.Name, s.Artist, s.Genre, s.Rating, s.MonthlyAudience)
}

// NOTE: this is wrong if you're going to use the plain http.Handle function, in order to implement handling for http you need a type that implements the
// method ServerHTTP

type MusicHandler struct {
	MusicStorage []string
}

func (f *MusicHandler) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	switch r.URL.Path {
	case "/songs":
		fmt.Printf("%s\n", r.Header)
	default:
		fmt.Printf("%s\n", r.URL.Path)
	}
}

func main() {
	// router := http.NewServeMux()

	musicHandler := &MusicHandler{}

	// song := &Song{
	// 	Name:            "Saucy",
	// 	Artist:          "Tim Henson",
	// 	Genre:           "Undefined",
	// 	Rating:          5,
	// 	MonthlyAudience: 1000,
	// }

	fmt.Printf("Listening to localhost on port :8080\n\n")
	log.Fatal(http.ListenAndServe(":8080", musicHandler))

}
