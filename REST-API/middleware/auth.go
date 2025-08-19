package middleware

import (
	"net/http"

	"example.com/rest-api/utils"
	"github.com/gin-gonic/gin"
)

func Authenticate(context *gin.Context) {
	token := context.Request.Header.Get("Authorization") // looking at request header to get token

	if token == "" {
		// aborts the current request and sends this response and no other requests will run
		context.AbortWithStatusJSON(http.StatusUnauthorized, gin.H{"message": "Not authorized."})
		return
	}

	userId, err := utils.VerifyToken(token)
	if err != nil {
		context.AbortWithStatusJSON(http.StatusUnauthorized, gin.H{"message": "Not authorized."})
		return
	}

	context.Set("userId", userId) // allows us to add some data to this context and be used anywhere context is available
	context.Next()

}
