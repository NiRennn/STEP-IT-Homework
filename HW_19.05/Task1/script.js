

document.getElementById('name').addEventListener('input', function(e) {
    var value = e.target.value;
    e.target.value = value.replace(/[^a-z A-Z а-я А-Я\s]/g, '');
}) ;