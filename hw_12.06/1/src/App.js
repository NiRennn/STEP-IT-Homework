import logo from "./logo.svg";
import "./App.css";
import React, { useState } from "react";
import MovieList from "./components/MovieList";
import MovieInfo from "./components/MovieInfo";

const App = () => {
  const [movies] = useState([
    {
      id: 1,
      title: "Головоломки 2",
      description:
        "Головной отдел мозга Райли внезапно подвергается капитальному ремонту в тот момент, когда необходимо освободить место для чего-то совершенно неожиданного: новых эмоций.",
      poster:
        "https://static.kinoafisha.info/k/movie_posters/1080x1920/upload/movie_posters/6/2/7/8367726/707278473808.jpg",
      showtimes: ["12:00", "16:00", "21:00"],
    },
    {
      id: 2,
      title: "Гарфилд",
      description: "Всемирно известный, ненавидящий понедельники и любящий лазанью домашний кот Гарфилд, отправляется в дикое приключение за пределы домашнего комфорта!",
      poster: "https://static.kinoafisha.info/k/movie_posters/1080x1920/upload/movie_posters/8/9/0/8367098/171647145171.jpg",
      showtimes: ["13:00", "15:00", "20:00"],
    },
    {
      id: 3,
      title: "Игра королевы",
      description: "Англия эпохи Тюдоров. Страной правит Генрих VIII, известный своей жестокостью даже к женам, две из которых были обезглавлены.",
      poster: "https://static.kinoafisha.info/k/movie_posters/1080x1920/upload/movie_posters/3/3/6/8365633/913055425819.jpg",
      showtimes: ["10:00", "12:00", "14:00"],
    },
    {
      id: 4,
      title: "Плохие парни до конца",
      description: "Современное, высокопрофессиональное полицейское подразделение сталкивается с Плохими Парнями, когда в Майами появляется новая угроза.",
      poster: "https://static.kinoafisha.info/k/movie_posters/1080x1920/upload/movie_posters/6/7/3/8369376/912147995423.jpg",
      showtimes: ["9:00", "17:00", "22:00"],
    },
  ]);

  return (
    <div className="app">
      <h1>Расписание кинотеатра</h1>
      <MovieList movies={movies} />
    </div>
  );
};

export default App;
