import React, { useState, useEffect } from 'react';

const quotes = [
    "Не стоит ждать идеального момента, нужно просто взять и сделать.",
    "Жизнь – это то, что происходит с нами, пока мы строим планы.",
    "Чем больше мы делаем, тем больше мы можем сделать.",
    "Каждый день – это новая возможность.",
    "Успех – это сумма мелких усилий, повторяемых изо дня в день.",
    "Путешествие в тысячу миль начинается с одного шага.",
    "Смелость – это начало, контроль над собой – это завершение.",
    "Каждый момент – это выбор, выбери правильно."
];

const getRandomQuote = () => {
    const randomIndex = Math.floor(Math.random() * quotes.length);
    return quotes[randomIndex];
};

const QuoteDisplay = () => {
    const [quote, setQuote] = useState(getRandomQuote());

    useEffect(() => {
        const intervalId = setInterval(() => {
            setQuote(getRandomQuote());
        }, 10000); 

        return () => clearInterval(intervalId); 
    }, []);

    const updateQuote = () => {
        setQuote(getRandomQuote());
    };

    return (
        <div>
            <h1>Случайная цитата</h1>
            <p>"{quote}"</p>
            <button onClick={updateQuote}>Обновить цитату</button>
        </div>
    );
};

export default QuoteDisplay;
