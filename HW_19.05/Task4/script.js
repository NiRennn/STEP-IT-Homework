

let leftLight = document.getElementById('left')
let midLight = document.getElementById('mid')
let rightLight = document.getElementById('right')

let button = document.getElementById('nextLightBtn')

button.addEventListener('click', function (e) {
    
    if (leftLight.style.backgroundColor === '#8A8A8A' && midLight.style.background === '#8A8A8A' && rightLight.style.background === '#8A8A8A') {
        leftLight.style.backgroundColor = 'orange'
    }
    else if (leftLight.style.backgroundColor === 'orange') {
        leftLight.style.backgroundColor = '#8A8A8A'
        midLight.style.backgroundColor = 'orange'
    }
    else if (midLight.style.backgroundColor === 'orange') {
        midLight.style.backgroundColor = '#8A8A8A'
        rightLight.style.backgroundColor = 'orange'
    }
    else if (rightLight.style.backgroundColor === 'orange') {
        rightLight.style.backgroundColor = '#8A8A8A'
        leftLight.style.backgroundColor = 'orange'
    }



})
