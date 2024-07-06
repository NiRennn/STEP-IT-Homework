// src/App.js
import React, { useState } from 'react';
import ArticleList from './components/ArticleList';
import ArticleDetail from './components/ArticleDetail';

const initialArticles = [
    {
        id: 1,
        title: 'Первая статья',
        content: 'Это текст первой статьи.',
        date: '2024-07-01',
        tags: ['React', 'JavaScript', 'Web Development']
    },
    {
        id: 2,
        title: 'Вторая статья',
        content: 'Это текст второй статьи.',
        date: '2024-07-02',
        tags: ['CSS', 'Design', 'Frontend']
    },
    // Добавьте больше статей, если необходимо
];

function App() {
    const [articles, setArticles] = useState(initialArticles);
    const [selectedArticle, setSelectedArticle] = useState(null);

    return (
        <div className="App">
            <ArticleList articles={articles} onSelect={setSelectedArticle} />
            <ArticleDetail article={selectedArticle} />
        </div>
    );
}

export default App;
