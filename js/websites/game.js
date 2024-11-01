// done with help of Copilot / AI
document.addEventListener('DOMContentLoaded', function() {
    var canvas = document.getElementById('gameCanvas');
    var context = canvas.getContext('2d');

    var paddle = {
        width: 100,
        height: 10,
        x: canvas.width / 2 - 50,
        y: canvas.height - 20
    };

    function drawPaddle() {
        context.fillStyle = 'blue';
        context.fillRect(paddle.x, paddle.y, paddle.width, paddle.height);
    }

    var ball = {
        radius: 10,
        x: Math.random() * (canvas.width - 20) + 10,
        y: 0,
        dy: 2 // for y movements
    };

    function drawBall() {
        context.beginPath();
        context.arc(ball.x, ball.y, ball.radius, 0, Math.PI * 2);
        context.fillStyle = 'red';
        context.fill();
        context.closePath();
    }

    var score = 0;
    
    function drawScore() {
        document.getElementById('score').innerText = 'Score: ' + score;
    }

    function movePaddle(event) {
        var rect = canvas.getBoundingClientRect();
        var mouseX = event.clientX - rect.left;
        paddle.x = mouseX - paddle.width / 2;

        // Prevent paddle from going out of bounds
        if (paddle.x < 0) {
            paddle.x = 0;
        } else if (paddle.x + paddle.width > canvas.width) {
            paddle.x = canvas.width - paddle.width;
        }
    }

    function moveBall() {
        ball.y += ball.dy;

        // Reset ball position if it goes off the bottom
        if (ball.y - ball.radius > canvas.height) {
            ball.x = Math.random() * (canvas.width - 20) + 10;
            ball.y = 0;
        }

        // Check for collision with paddle
        if (ball.y + ball.radius > paddle.y &&
            ball.x > paddle.x &&
            ball.x < paddle.x + paddle.width) {
            score++;
            ball.x = Math.random() * (canvas.width - 20) + 10;
            ball.y = 0;
        }
    }

    function update() {
        context.clearRect(0, 0, canvas.width, canvas.height);
        drawPaddle();
        drawBall();
        drawScore();
        moveBall();
        requestAnimationFrame(update);
    }

    canvas.addEventListener('mousemove', movePaddle);

    update();
});
