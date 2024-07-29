// src/components/Login/Login.js

import React, { useState } from "react";
import "../Login/Login.css";
import { useUser } from "../../contexts/UserContext";

export default function Login({ onClose, openRegister }) {
  const { login } = useUser();
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");

  const handleSubmit = (event) => {
    event.preventDefault();

    if (email && password) {
      // Здесь можно добавить проверку на существование пользователя
      login({ email });
      onClose();
    } else {
      alert("Пожалуйста, заполните все поля");
    }
  };

  return (
    <div className="modal-overlay">
      <div className="modal-window">
        <button className="close-modal" onClick={onClose}>
          &times;
        </button>

        <div className="modal-content">
          <h1>Вход</h1>
          <form onSubmit={handleSubmit}>
            <input
              type="email"
              name="Email"
              placeholder="Email"
              value={email}
              onChange={(e) => setEmail(e.target.value)}
              required
            />
            <input
              type="password"
              name="Password"
              placeholder="Password"
              value={password}
              onChange={(e) => setPassword(e.target.value)}
              required
            />
            <button className="forgot-password-button" type="button">
              Забыли пароль?
            </button>
            <button className="log-in-button" type="submit">
              Войти
            </button>
            <div className="to-registration-section">
              <p className="no-account">Нет аккаунта?</p>
              <a
                href="#toRegister"
                className="to-registration-button"
                onClick={() => {
                  onClose();
                  openRegister();
                }}
              >
                Регистрация
              </a>
            </div>
          </form>
        </div>
      </div>
    </div>
  );
}
