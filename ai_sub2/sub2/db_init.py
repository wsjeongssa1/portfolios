import sqlite3


def initMovieRatingDB():
    conn = sqlite3.connect('app.db')

    c = conn.cursor()

    c.execute(
        '''
        CREATE TABLE movie_ratings (
            created_datetime TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
            user text NOT NULL,
            query text NOT NULL,
            rating number NOT NULL
        )
        '''
    )

    conn.commit()
    conn.close()
