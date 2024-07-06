import React from 'react';
import MovieShowTime from './MovieShowTime';


const MovieItem = ({ movie }) => {
  return (
    <div className="movie-item">
      <img src={movie.poster} alt={movie.title} className="movie-poster" />
      <h3>{movie.title}</h3>
      <p>{movie.description}</p>
        <MovieShowTime showtimes={movie.showtimes}/>
        
    </div>
  );
};

export default MovieItem;
