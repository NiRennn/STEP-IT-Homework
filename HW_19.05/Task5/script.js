document.addEventListener('DOMContentLoaded', function() {
    const books = document.querySelectorAll('.list-of-books li');

    books.forEach(book => {
        book.addEventListener('click', function() {
            books.forEach(b => {
                b.style.backgroundColor = '';
            });

            if (book.style.backgroundColor !== 'orange') {
                book.style.backgroundColor = 'orange';
            } else {
                book.style.backgroundColor = '';
            }
        });
    });
});
