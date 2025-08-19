package models

import (
	"time"

	"example.com/rest-api/db"
)

type Event struct {
	ID          int64
	Name        string    `binding:"required"`
	Description string    `binding:"required"`
	Location    string    `binding:"required"`
	DateTime    time.Time `binding:"required"`
	UserID      int64
}

var events = []Event{} // initializing to an empty slice of events

// method, first create a receiver
func (e *Event) Save() error {
	// insert data into database
	query := `
	INSERT INTO events(name, description, location, dateTime, user_id)
	VALUES(?, ?, ?, ?, ?)` // ? gives us a sql injection to insert values into this query
	stmt, err := db.DB.Prepare(query)

	if err != nil {
		return err
	}
	result, err := stmt.Exec(e.Name, e.Description, e.Location, e.DateTime, e.UserID)
	defer stmt.Close() // will close whenever save func is done

	if err != nil {
		return err
	}
	id, err := result.LastInsertId() // get id of the event that was inserted
	e.ID = id

	return err
}

func GetAllEvents() ([]Event, error) {
	query := "SELECT * FROM events"
	// since this isn't complex we don't need to prepare it like the insert
	// if we have data that changes stuff we use Exec()
	// for fetching data its Query()
	rows, err := db.DB.Query(query)
	if err != nil {
		return nil, err
	}

	defer rows.Close()

	var events []Event

	// its true as long there are rows left, this is like a while statement
	for rows.Next() {
		var event Event
		err := rows.Scan(&event.ID, &event.Name, &event.Description, &event.Location, &event.DateTime, &event.UserID) // reads the content of the row

		if err != nil {
			return nil, err
		}

		events = append(events, event)
	}

	return events, nil
}

func GetEventByID(id int64) (*Event, error) {
	query := "SELECT * FROM events WHERE id = ?" // ? to protect from sql injection
	row := db.DB.QueryRow(query, id)

	var event Event
	err := row.Scan(&event.ID, &event.Name, &event.Description, &event.Location, &event.DateTime, &event.UserID)
	if err != nil {
		return nil, err
	}

	return &event, nil

}

func (event Event) Update() error {
	query := `
	UPDATE events 
	SET name = ?, description = ?, location = ?, dateTime = ?
	WHERE id = ?
	`

	stmt, err := db.DB.Prepare(query)

	if err != nil {
		return err
	}

	defer stmt.Close()

	_, err = stmt.Exec(event.Name, event.Description, event.Location, event.DateTime, event.ID)
	return err
}

func (event Event) Delete() error {
	query := "DELETE FROM events WHERE id = ?"

	stmt, err := db.DB.Prepare(query)

	if err != nil {
		return err
	}

	defer stmt.Close()

	_, err = stmt.Exec(event.ID)
	return err
}

func (e Event) Register(userId int64) error {
	query := "INSERT INTO registrations(event_id, user_id) VALUES (?, ?)"
	stmt, err := db.DB.Prepare(query)
	if err != nil {
		return err
	}

	defer stmt.Close()

	_, err = stmt.Exec(e.ID, userId)

	return err
}

func (e Event) CancelRegistration(userId int64) error {
	query := "DELETE FROM registrations WHERE event_id = ? AND user_id = ?"
	stmt, err := db.DB.Prepare(query)
	if err != nil {
		return err
	}

	defer stmt.Close()

	_, err = stmt.Exec(e.ID, userId)

	return err
}
