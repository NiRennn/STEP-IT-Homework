import React from 'react'
import './Footer.css'

export default function Footer() {
  return (
<footer className="footer">
      <div className="footer-section">
        <h4>О компании</h4>
        <ul>
          <li>
            <a href="#about">О нас</a>
          </li>
          <li>
            <a href="#contact">Контакты</a>
          </li>
          <li>
            <a href="#careers">Карьера</a>
          </li>
        </ul>
      </div>
      <div className="footer-section">
        <h4>Полезные ссылки</h4>
        <ul>
          <li>
            <a href="#faq">FAQ</a>
          </li>
          <li>
            <a href="#support">Поддержка</a>
          </li>
          <li>
            <a href="#privacy">Политика конфиденциальности</a>
          </li>
        </ul>
      </div>
      <div className="footer-section">
        <h4>Следите за нами</h4>
        <ul className="social-links">
          <li>
            <a href="#facebook">
              <img src={require('../../Logos/facebook.svg').default} alt="" />
            </a>
          </li>
          <li>
            <a href="#tiktok">
            <img src={require('../../Logos/tiktok.svg').default} alt="" />
            </a>
          </li>
          <li>
            <a href="#linkedin">
            <img src={require('../../Logos/linkedin.svg').default} alt="" />
            </a>
          </li>
          <li>
            <a href="#instagram">
            <img src={require('../../Logos/instagram.svg').default} alt="" />
            </a>
          </li>
        </ul>
      </div>
    </footer>
  )
}
