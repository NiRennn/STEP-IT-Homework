import React from 'react';
import Header from '../Header/Header';
import Footer from '../Footer/Footer';
import './News.css';

const newsData = [
  {
    id: 1,
    title: 'Новая коллекция кроссовок',
    date: '2024-07-25',
    content: 'Мы рады представить нашу новую коллекцию кроссовок, которая включает в себя последние тенденции и уникальные дизайны. Не пропустите!'
  },
  {
    id: 2,
    title: 'Распродажа до 50%',
    date: '2024-07-20',
    content: 'Скидки до 50% на популярные модели кроссовок. Поторопитесь, предложения ограничены!'
  },
  {
    id: 3,
    title: 'Открытие нового магазина',
    date: '2024-07-15',
    content: 'Мы открыли новый магазин в центре города. Приходите, чтобы увидеть наши новинки и воспользоваться эксклюзивными предложениями!'
  },
];

export default function News() {
  return (
    <div className="news-container">
      <Header />
      <div className="news-content">
        <h1>Новости</h1>
        {newsData.map((news) => (
          <div key={news.id} className="news-item">
            <h2 className="news-title">{news.title}</h2>
            <p className="news-date">{news.date}</p>
            <p className="news-content">{news.content}</p>
          </div>
        ))}
      </div>
      <Footer />
    </div>
  );
}
