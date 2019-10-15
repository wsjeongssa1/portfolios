import sqlite3


class MovieRatingDAO:
    def __init__(self):
        self.movieRatingConnection = None
        self.movieRatingCursor = None

    def insertMovieRating(self, movie_rating_info):
        with sqlite3.connect('app.db') as self.movieRatingConnection:
            self.movieRatingCursor = self.movieRatingConnection.cursor()
            result = self.movieRatingCursor.execute('INSERT INTO movie_ratings(user, query, rating) SELECT * FROM ('
                                                    'SELECT ?, ?, ?) AS tmp WHERE NOT EXISTS (SELECT query FROM '
                                                    'movie_ratings WHERE query = ?) LIMIT 1', (movie_rating_info[0],
                                                                                               movie_rating_info[1],
                                                                                               movie_rating_info[2],
                                                                                               movie_rating_info[1]))
            self.movieRatingConnection.commit()

            return result

    def selectAllMovieRating(self):
        with sqlite3.connect('app.db') as self.movieRatingConnection:
            self.movieRatingCursor = self.movieRatingConnection.cursor()
            movie_rating_list = self.movieRatingCursor.execute('SELECT * FROM movie_ratings')
            return movie_rating_list

    def selectMovieRatingByQuery(self, query):
        with sqlite3.connect('app.db') as self.movieRatingConnection:
            self.movieRatingCursor = self.movieRatingConnection.cursor()
            self.movieRatingCursor.execute('SELECT * FROM movie_ratings WHERE query = ?', [query])
            result = self.movieRatingCursor.fetchone()
            self.movieRatingConnection.commit()

            return result

    def updateMovieRating(self):
        with sqlite3.connect('app.db') as self.movieRatingConnection:
            self.movieRatingCursor = self.movieRatingConnection.cursor()
            self.movieRatingConnection.commit()

    def deleteMovieRating(self):
        with sqlite3.connect('app.db') as self.movieRatingConnection:
            self.movieRatingCursor = self.movieRatingConnection.cursor()
            self.movieRatingConnection.commit()

    def close(self):
        if self.movieRatingCursor is not None:
            self.movieRatingCursor.close()
        if self.movieRatingConnection is not None:
            self.movieRatingConnection.close()
