

document.querySelector('.soccer-field').addEventListener('click', function(event) {
    const ball = document.getElementById('soccer-ball-id');
    const field = event.currentTarget;

    const fieldRect = field.getBoundingClientRect();

    const ballX = event.clientX - fieldRect.left;
    const ballY = event.clientY - fieldRect.top;

    ball.style.left = `${ballX}px`;
    ball.style.top = `${ballY}px`;
});