package main

import "fmt"

// func yourMyObsession(arr []string) string {
// 	for i, _ := range arr {
// 		if []rune(arr[i])[0] != []rune(arr[i+1])[0] {
//
// 		}
// 	}
//
// 	return "If God is a woman, then God is a weapon"
// }

/*

Result must be something like:

b: {
	bobby: 2,
	ben: 1
},
f: {
	frank: 1
}


*/

func getNameCounts(names []string) map[string]map[string]int {
	// this was what boot.dev asked for as an answer
	// nested := map[rune]map[string]int{}
	nested := map[string]map[string]int{}
	namesMap := map[string]int{}
	for _, val := range names { // O(n)

		namesMap[val] = namesMap[val] + 1
	}

	for key, val := range namesMap { // O(n)

		// this is what boot.dev asked for as an answer
		// firstLetter := []rune(key)[0]

		// this will use the numeric unicode of the rune. Must use string(0)
		firstLetter := string([]rune(key)[0])
		if names, ok := nested[firstLetter]; !ok {
			nested[firstLetter] = map[string]int{key: val}
			continue
		} else {
			// mutates the interior map
			names[key] = val
		}
	}

	return nested
}

func main() {
	names := []string{
		"Tyrion", "Tyrion", "Tyrion", "Jon", "Jon", "Jon", "Jon",
		"Arya", "Arya", "Arya", "Arya", "Arya", "Arya",
		"Sansa", "Sansa", "Sansa", "Sansa",
		"Bran", "Bran", "Bran",

		"Daenerys", "Daenerys", "Daenerys", "Daenerys", "Daenerys",
		"Cersei", "Cersei", "Cersei", "Cersei",
		"Jaimie", "Jaimie", "Jaimie",
		"Ned", "Ned", "Ned",
		"Robert", "Robert", "Robert",
		"Rhaegar", "Rhaegar", "Rhaegar",
		"Viserys", "Viserys",
		"Samwell", "Samwell", "Samwell",
		"Brienne", "Brienne",
		"Podrick", "Podrick",
		"Theon", "Theon", "Theon", "Yara",
		"Jorah", "Jorah", "Jorah", "Khal",
		"Missandei", "Missandei", "Tormund", "Tormund", "Tormund",
		"Melisandre", "Varys", "Varys", "Baelish",
		"Gendry", "Gendry", "Beric", "Greyworm", "Daario", "Shae",
		"Tywin", "Tywin", "Olenna", "Olenna", "Margaery", "Loras",
		"Renly", "Stannis", "Stannis", "Davos", "Shireen", "Rickon",
		"Oberyn", "Ellaria", "Hotpie", "Gilly", "Meera", "Jojen",
		"Ramsay", "Roose", "Balon", "Euron", "Qyburn", "Maester",
		"Tommen", "Myrcella", "Sandor", "Sandor", "Gregor", "Septa",
		"HighSepton", "Leaf", "Benjen", "Craster", "Karl", "Alliser",
		"Ed", "Grenn", "Pyp", "Lancel", "Kevan", "Ros", "Myranda",
		"Locke", "Ygritte", "Ygritte", "Olly", "Bowen", "Doreah",
		"Irri", "Rakharo", "Xaro", "Quaithe", "Thoros", "Jaqen",
		"Eddison", "Brynden", "Blackfish", "Lyanna", "Howland",
		"Arthur", "Dayne", "Rickard", "Elia", "Martell", "Doran",

		// New names added for variety
		"Jesus", "Gabriel", "Michael", "Lucifer", "Raphael", "Uriel",

		"Albert", "Isaac", "Marie", "Nikola", "Leonardo", "Ada", "Turing",
		"Einstein", "Newton", "Galileo", "Tesla", "Plato", "Socrates", "Aristotle",
		"Hermione", "Harry", "Ron", "Draco", "Snape", "Dumbledore", "Voldemort",
		"Frodo", "Sam", "Gandalf", "Legolas", "Aragorn", "Gollum", "Boromir",
		"Thorin", "Bilbo", "Sauron", "Galadriel", "Elrond", "Saruman",

		// Repeated historical and mythological figures
		"Achilles", "Hector", "Odysseus", "Perseus", "Theseus", "Heracles", "Apollo", "Zeus",
		"Ares", "Athena", "Hades", "Poseidon", "Demeter", "Artemis", "Hermes", "Hephaestus",
		"Freya", "Thor", "Loki", "Odin", "Baldur", "Frigg", "Tyr", "Heimdall",

		// Extra repetitions
		"Jon", "Jon", "Jon", "Arya", "Arya", "Daenerys", "Tyrion", "Tyrion", "Tyrion", "Tyrion",
		"Jesus", "Jesus", "Harry", "Harry", "Frodo", "Frodo", "Frodo", "Frodo",
		"Thor", "Thor", "Thor", "Zeus", "Zeus", "Zeus", "Zeus", "Zeus", "Zeus",

		"Einstein", "Einstein", "Einstein", "Einstein", "Tesla", "Tesla", "Tesla",
		"Socrates", "Plato", "Plato", "Plato", "Dumbledore", "Dumbledore", "Voldemort",

		// A few more filler to hit 300
		"Leia", "Luke", "Han", "Chewbacca", "Yoda", "Anakin", "Obi-Wan", "Rey", "Kylo", "Palpatine",
		"Neo", "Trinity", "Morpheus", "Smith", "Zion", "Tank", "Dozer", "Switch", "Cypher", "Oracle",
	}

	nameCountsMap := getNameCounts(names)
	for key, val := range nameCountsMap {
		fmt.Println(key)
		fmt.Println("-->\n\n")
		fmt.Println(val)
	}
}
