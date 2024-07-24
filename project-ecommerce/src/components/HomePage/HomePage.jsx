import React from "react";
import "./HomePage.css";
import BrandsCarousel from "../BrandsCarousel/BrandsCarousel";
import NewArrivalsCarousel from "../ArrivalsCarousel/NewArrivalsCarousel";
import GenderSelection from "../GenderSelection/GenderSelection";
import PopularNow from "../PopularNow/PopularNow";
import {Link} from 'react-router-dom';
import Header from "../Header/Header";
import Footer from "../Footer/Footer";


export default function HomePage() {
  return (
    <div className="homepage-container">
      <Header/>
      <NewArrivalsCarousel />
      <PopularNow />

      <GenderSelection />
      <p className="leaders">Лидеры продаж</p>
      <BrandsCarousel />
      <Footer/>
    </div>
  );
}
