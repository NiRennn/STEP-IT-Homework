import React from 'react';

const MovieInfo = ({ movie }) => {
  return (
    <div className="movie-details">
      <h2>{movie.title}</h2>
      <img src={movie.poster} alt={movie.title} className="movie-poster" />
      <p>{movie.description}</p>
      <h4>Сеансы:</h4>
      <ul>
        {movie.showtimes.map((showtime, index) => (
          <li key={index}>{showtime}</li>
        ))}
      </ul>
    </div>
  );
};

export default MovieInfo;
