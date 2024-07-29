import React from "react";
import "./Favorites.css";
import Header from "../Header/Header";
import Footer from "../Footer/Footer";

export default function Favorites() {
  return (
    <div>
      <Header />
      <div className="container-for-something"></div>

      <div className="favorites-page-container">
        <h2>Избранное</h2>
        <div className="favorites-container">




          <div className="no-favorites">
            <p>
              Понравилась какая-то вещь? Добавьте её в избранное и вернитесь к
              ней позже в любой момент
            </p>
            <button>В Каталог</button>
          </div>
        </div>
      </div>
      <footer>
        <Footer />
      </footer>
    </div>
  );
}
