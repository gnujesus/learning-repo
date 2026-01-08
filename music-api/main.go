package main

import (
	"fmt"
	"io"
	"log"
	"net/http"
)

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

func (m *MusicHandler) StoreMusic(r *http.Request) {
	body, err := io.ReadAll(r.Body)

	if err != nil {
		fmt.Println("Error")
		return
	}

	defer r.Body.Close()

	fmt.Println(string(body))
}

func (m *MusicHandler) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	switch r.Method {

	// GET
	case http.MethodGet:
		switch r.URL.Path {
		case "/songs":
			fmt.Printf("%s\n", r.Header)
		default:
			fmt.Println("No GET method supported")
		}

	// POST
	case http.MethodPost:
		switch r.URL.Path {
		case "/songs":
			m.StoreMusic(r)
		default:
			fmt.Println("No POST method supported")
		}

	default:
		fmt.Println("Method not supported")
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
