import React, { useState } from "react";
import "./Header.css";
import { Link } from "react-router-dom";

import logo from "../../Logos/logo.svg";
import user from "../../Logos/user.svg";
import settings from "../../Logos/settings.svg";

export default function Header() {
  const [menuOpen, setMenuOpen] = useState(false);

  const toggleMenu = () => {
    setMenuOpen(!menuOpen);
  };

  return (
    <div className="header-container">
      <div className="logo-container">
        <img src={logo} alt="Logo" />
      </div>
      <div className="navbar-container">
        <Link to="/home">
          <button className="nav-button">Главная</button>
        </Link>

        <Link to="/catalog">
          <button className="nav-button">Каталог</button>
        </Link>
        <Link to="/news">
          <button className="nav-button">Новости</button>
        </Link>

        <Link to="/about">
          <button className="nav-button">О Нас</button>
        </Link>
      </div>
      <div className="user-favorites-container">
        <img src={settings} alt="Settings" />
        <div className="user-menu-container">
          <img src={user} alt="User" onClick={toggleMenu} />
          {menuOpen && (
            <div className="user-menu">
              <a href="#profile">Профиль</a>
              <a href="#orders">Мои заказы</a>
              <a href="#logout">Выйти</a>
            </div>
          )}
        </div>
      </div>
    </div>
  );
}
