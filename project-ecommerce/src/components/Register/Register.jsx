import React, { useState } from "react";
import xMark from "../../Logos/xmark.svg";
import "../Register/Register.css";
import { useUser } from "../../contexts/UserContext";

export default function Register({ onClose, openLogin }) {
  const { registerUser } = useUser();
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [confirmPassword, setConfirmPassword] = useState("");

  const handleRegister = (event) => {
    event.preventDefault();

    if (password !== confirmPassword) {
      alert("Пароли не совпадают!");
      return;
    }

    registerUser({ email, password });
    const userData = { email, password };

    console.log("Регистрация пользователя:", userData);

    onClose();
    openLogin();
  };

  return (
    <div className="modal-overlay">
      <div className="modal-window">
        <button className="close-modal" onClick={onClose}>
          <img src={xMark} alt="close-btn" />
        </button>
        <div className="modal-content">
          <h1>Регистрация</h1>
          <form onSubmit={handleRegister}>
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
            <input
              type="password"
              name="Confirm Password"
              placeholder="Confirm Password"
              value={confirmPassword}
              onChange={(e) => setConfirmPassword(e.target.value)}
              required
            />
            <button className="register-button" type="submit">
              Регистрация
            </button>
            <div className="to-login-section">
              <p className="have-account">Уже есть аккаунт?</p>
              <a
                href="#toLogin"
                className="to-login-button"
                onClick={() => {
                  onClose();
                  openLogin();
                }}
              >
                Войти
              </a>
            </div>
          </form>
        </div>
      </div>
    </div>
  );
}
