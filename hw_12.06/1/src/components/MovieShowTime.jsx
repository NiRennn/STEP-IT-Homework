import React from "react";
import "../MovieShowTime.css";

const MovieShowTime = ({ showtimes }) => {
  return (
    <div className="movie-show-time">
      {showtimes.map((showtime, index) => (
        <a key={index} className="show-time-button" href="#">
            {showtime}
        </a>
      ))}
    </div>
  );
};

export default MovieShowTime;
