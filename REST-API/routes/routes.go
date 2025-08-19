package routes

import (
	"example.com/rest-api/middleware"
	"github.com/gin-gonic/gin"
)

func RegisterRoutes(server *gin.Engine) {

	server.GET("/events", getEvents)    // GET, POST, PUT, PATCH, DELETE
	server.GET("/events/:id", getEvent) // dynamic placeholder for the path using ':'

	authenticated := server.Group("/")
	authenticated.Use(middleware.Authenticate) // now this will run the middleware always before other handlers
	authenticated.POST("/events", createEvent)
	authenticated.PUT("/events/:id", updateEvent)
	authenticated.DELETE("/events/:id", deleteEvent)
	authenticated.POST("/events/:id/register", registerForEvent)
	authenticated.DELETE("/events/:id/register", cancelRegistration)

	server.POST("/signup", signup)
	server.POST("/login", login)
}
