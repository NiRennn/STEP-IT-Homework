// src/components/ArticleDetail.js
import React from 'react';

const ArticleDetail = ({ article }) => {
    if (!article) return <div>Выберите статью для просмотра.</div>;

    return (
        <div>
            <h1>{article.title}</h1>
            <p><strong>Дата публикации:</strong> {article.date}</p>
            <p><strong>Теги:</strong> {article.tags.join(', ')}</p>
            <div>
                <p>{article.content}</p>
            </div>
        </div>
    );
};

export default ArticleDetail;
