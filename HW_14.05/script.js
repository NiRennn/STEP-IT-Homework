//#region Task1



let shoppingList = [
    {
        name: `Apple`,
        count: 5,
        purchased: true
    },
    {
        name: `Bread`,
        count: 2,
        purchased: false
    },
    {
        name: `Milk`,
        count: 1,
        purchased: true
    }
]

function displayShopList() {
    let unPurchased = shoppingList.filter(i => i.purchased === false)
    let purchased = shoppingList.filter(i => i.purchased === true)
    let sortedList = unPurchased.concat(purchased);

    sortedList.forEach(i => {
        alert(`${i.name} - ${i.count} шт - ${i.purchased ? `purchased` : `not purchased`}`);
    })
}

function addPurchase() {
    let name = prompt("Enter name of product:");
    let count = parseInt(prompt("Enter count: "));

    let item = shoppingList.find(i => i.name === name);

    if (item)
        item.count += count;
    else
        shoppingList.push(
            {
                name: name,
                count: count,
                purchased: false
            })
}

function buyProduct() {
    let name = prompt("Enter name of product which you also purchased: ")
    let itemToBuy = shoppingList.find(i => i.name === name);
    if (itemToBuy) {  
        displayShopList();
        itemToBuy.purchased = true;
        
    }
    else {
        alert('Product not found');
    }
}
displayShopList();
addPurchase();
buyProduct();


//#endregion Task1

//#region Task2

let receipt = [
    {
        productName: 'milk',
        count: 2,
        price: 5
    },

    {
        productName: 'bread',
        count: 1,
        price: 3
    },

    {
        productName: 'lemon',
        count: 3,
        price: 7
    },
    {
        productName: 'crisps',
        count: 2,
        price: 8
    }
];


function displayReceinpt(receipt){
    console.log('Your receipt info')
    console.log(`Product | Count | Price `)

    receipt.forEach(element => {
        console.log(`${element.productName} -- ${element.count} -- ${element.price}`)
    });
}

function totalPrice(receipt){

    let totalSum = 0;
    receipt.forEach(element => {
        totalSum += element.count*element.price
    });
    console.log(`Total: ${totalSum}`);
}


function mostExpensiveProduct(receipt){
    let tmpPrice = 0;
    let tmpName = '';
    receipt.forEach(element => {
        if (element.price > tmpPrice) {
            tmpPrice = element.price;
            tmpName = element.productName;
        }
    });

    console.log(`Most expensive product: ` + tmpName);
}

function averagePrice(receipt) {
    let totalItems = 0;
    let totalPrice = 0;
    receipt.forEach(element => {
        totalItems += element.count;
        totalPrice += element.count * element.price;
    });
    let averagePrice = totalPrice / totalItems;
    console.log(`Average price per item: ${averagePrice.toFixed(2)}`);
}


displayReceinpt(receipt);
totalPrice(receipt);
mostExpensiveProduct(receipt)
averagePrice(receipt);


//#endregion Task2


//#region Task3

let styles = [
    {
        name: `color`,
        value: `red`
    },
    {
        name: `font-size`,
        value: `25px`
    },
    {
        name: `text-decoration`,
        value: `underline`
    },
    {
        name: `text-align`,
        value: `center`
    },
    {
        name: `cursor`,
        value: `pointer`
    }
]

function applyStyles(styles, text) {
    let styleString = '';

    styles.forEach(s => {
        styleString += `${s.name}: ${s.value}; `
    });
    document.write(`<p style="${styleString}">${text}</p>`)
}
applyStyles(styles, 'Hello, world!')



//#endregion Task3


//#region Task4

let audiences = [
    {
        name: '1A',
        seats: 13,
        faculty: 'Griffindor'
    },
    {
        name: '4B',
        seats: 19,
        faculty: 'Slytherin'
    },
    {
        name: '2C',
        seats: 10,
        faculty: 'Hufflepuff'
    },
    {
        name: '3A',
        seats: 16,
        faculty: 'Ravenclaw'
    }
]

function displayAllAudiences(audiences) {
    audiences.forEach(element => {
        console.log(`${element.name} - seats count: ${element.seats} - ${element.faculty}`)
    });
}

function displayForFaculty(audiences, fac) {
    audiences.forEach(element => {
        if (element.faculty === fac) {
            console.log(`${element.name}`)
        }
    });
}

function sortByName(audiences) {
    let sortedAudiences = audiences.slice().sort((a, b) => {
        if (a.faculty < b.faculty) return -1;
        if (a.faculty > b.faculty) return 1; 
        return 0;
    });

    displayAllAudiences(sortedAudiences);
}

function sortBySeatsCount(audiences) {
    let sortedAudiences = audiences.slice().sort((a, b) => a.seats - b.seats);

    displayAllAudiences(sortedAudiences);

}




displayAllAudiences(audiences);
displayForFaculty(audiences,'Ravenclaw');

sortBySeatsCount(audiences);
sortByName(audiences);

//#endregion Task4


