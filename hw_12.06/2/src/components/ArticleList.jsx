// src/components/ArticleList.js
import React from 'react';

const ArticleList = ({ articles, onSelect }) => {
    return (
        <div>
            <h1>Список статей</h1>
            {articles.map(article => (
                <div key={article.id} onClick={() => onSelect(article)}>
                    <h2>{article.title}</h2>
                    <p>{article.date}</p>
                    <p>{article.tags.join(', ')}</p>
                </div>
            ))}
        </div>
    );
};

export default ArticleList;
