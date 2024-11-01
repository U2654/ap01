// code by help of Copilot / AI 
document.addEventListener('DOMContentLoaded', function() {
    var textElement = document.getElementById('text');
    var selectedWordElement = document.getElementById('selectedWord');

    textElement.addEventListener('click', function(event) {
        // Check if the clicked element is a word
        if (event.target.tagName === 'SPAN') {
            // Remove highlight from all words
            var words = textElement.getElementsByTagName('span');
            for (var i = 0; i < words.length; i++) {
                words[i].classList.remove('highlight');
            }

            // Highlight the clicked word
            event.target.classList.add('highlight');

            // Display the clicked word at the bottom
            selectedWordElement.innerHTML = 'Selected word: ' + event.target.innerText;
        }
    });

    // Wrap each word in a span
    var words = textElement.innerText.split(' ');
    textElement.innerHTML = '';
    words.forEach(function(word) {
        var span = document.createElement('span');
        span.innerText = word + ' ';
        textElement.appendChild(span);
    });
});
