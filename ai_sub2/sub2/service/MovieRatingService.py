from sub2.repository.MovieRatingDAO import MovieRatingDAO

class MovieRatingService:
    def __init__(self):
        self.dao = MovieRatingDAO()

    def insertMovieRating(self, user, query, rating):
        rating = [user, query, rating]

        self.dao.insertMovieRating(rating)
        self.dao.close()

    def searchMovieRating(self, query):
        result = self.dao.selectMovieRatingByQuery(query)
        self.dao.close()

        return result