package db

import (
	"database/sql"

	_ "github.com/mattn/go-sqlite3"
)

// global variable
var DB *sql.DB

// initializing the database and establishing a connection
func InitDB() {
	var err error
	DB, err = sql.Open("sqlite3", "api.db")

	if err != nil {
		panic("could not connect to database") // crash the app
	}

	DB.SetMaxOpenConns(10) // how many connections can be opened simultaneously at once
	DB.SetMaxIdleConns(5)  // how many connections we want to keep open if noone is using it
	createTables()         // create a table function

}

// create a bunch of tables in database in case they dont exist
func createTables() {
	createUsersTable := `
	CREATE TABLE IF NOT EXISTS users (
		id INTEGER PRIMARY KEY AUTOINCREMENT,
		email TEXT NOT NULL UNIQUE,
		password TEXT NOT NULL
	)
	`
	_, err := DB.Exec(createUsersTable)

	if err != nil {
		panic("Could not create users table.")
	}

	// when using back tics we can write across multiple lines
	createEventsTable := `
	CREATE TABLE IF NOT EXISTS events (
		id INTEGER PRIMARY KEY AUTOINCREMENT,
		name TEXT NOT NULL,
		description TEXT NOT NULL,
		location TEXT NOT NULL,
		dateTime DATETIME NOT NULL,
		user_id INTEGER,
		FOREIGN KEY(user_id) REFERENCES users(id)
	)
	`

	_, err = DB.Exec(createEventsTable) // execute this sql statement

	if err != nil {
		panic("could not create events table")
	}

	createRegistrationsTable := `
	CREATE TABLE IF NOT EXISTS registrations(
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	event_id INTEGER,
	user_id INTEGER,
	FOREIGN KEY(event_id) REFERENCES events(id),
	FOREIGN KEY(user_id) REFERENCES users(id)
	)
	`

	_, err = DB.Exec(createRegistrationsTable)
	if err != nil {
		panic("Could not create registrations table.")
	}
}
