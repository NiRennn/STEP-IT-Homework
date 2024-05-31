let currentSlide = 0;
const images = [
  "Images/BMW/73879_Llsf7HE7T9ZVmMOurKtMGQ.jpg",
  "Images/BMW/73879_Llsf7HE7T9ZVmMOurKtMGQ (1).jpg",
  "Images/BMW/73879_Llsf7HE7T9ZVmMOurKtMGQ (2).jpg",
];

function moveSlide(step) {
  currentSlide = (currentSlide + step + images.length) % images.length;
  document.getElementById("carousel-image").src = images[currentSlide];
}

const carBrands = [
  "Abarth",
  "Acura",
  "Alfa Romeo",
  "Aprilia",
  "Ashok Leyland",
  "Asia",
  "Aston Martin",
  "ATV",
  "Audi",
  "Avatr",
  "Avia",
  "Baic",
  "Bajaj",
  "Bentley",
  "Bestune",
  "BMC",
  "BMW",
  "BMW Alpina",
  "Brilliance",
  "Buick",
  "BYD",
  "C.Moto",
  "Cadillac",
  "Can-Am",
  "CFMOTO",
  "Changan",
  "Chery",
  "Chevrolet",
  "Chrysler",
  "Citroen",
  "Dacia",
  "Daewoo",
  "DAF",
  "Daihatsu",
  "Dayun",
  "Denza",
  "DFSK",
  "Dnepr",
  "Dodge",
  "DongFeng",
  "Ducati",
  "FAW",
  "Ferrari",
  "Fiat",
  "Ford",
  "Forthing",
  "Foton",
  "Gabro",
  "GAC",
  "GAZ",
  "Geely",
  "Genesis",
  "GMC",
  "Gonow",
  "Grandmoto",
  "GWM",
  "Haima",
  "Haojue",
  "Harley-Davidson",
  "Haval",
  "Honda",
  "Hongqi",
  "HOWO",
  "Hummer",
  "Husqvarna",
  "Hycan",
  "Hyundai",
  "IJ",
  "IM",
  "Indian Motorcycle",
  "Infiniti",
  "Iran Khodro",
  "Isuzu",
  "Iveco",
  "JAC",
  "Jaguar",
  "Jeep",
  "Jetour",
  "Jiangmen",
  "Jianshe",
  "JMC",
  "Jonway",
  "KAIYI",
  "KamAz",
  "Kanuni",
  "Karry",
  "KAvZ",
  "Kawasaki",
  "Kayo",
  "KG Mobility",
  "Khazar",
  "Kia",
  "Kinroad",
  "KrAZ",
  "KTM",
  "Kuba",
  "LADA (VAZ)",
  "Lamborghini",
  "Land Rover",
  "Leapmotor",
  "Lexus",
  "Li Auto",
  "Liebherr",
  "Lifan",
  "Lincoln",
  "Lotus",
  "LuAz",
  "Lynk & Co",
  "Mack",
  "MAN",
  "Maple",
  "Maserati",
  "MAZ",
  "Mazda",
  "Mercedes",
  "Mercedes-Maybach",
  "MG",
  "Mini",
  "Minsk",
  "Mitsubishi",
  "Mondial",
  "Moskvich",
  "Muravey",
  "MV Agusta",
  "Nama",
  "Neoplan",
  "Neta",
  "Nissan",
  "Opel",
  "Otokar",
  "PAZ",
  "Peugeot",
  "Polad",
  "Polaris",
  "Polestar",
  "Porsche",
  "Radar",
  "RAF",
  "Ravon",
  "Renault",
  "Renault Samsung",
  "RKS",
  "Rolls-Royce",
  "Rover",
  "ROX (Polar Stone)",
  "Royal Enfield",
  "Saab",
  "Saipa",
  "Saturn",
  "Scania",
  "SEAT",
  "Seres",
  "Seres Aito",
  "Setra",
  "Shacman",
  "Sinski",
  "Skoda",
  "Skywell",
  "Smart",
  "Soueast",
  "Ssang Yong",
  "Star",
  "Subaru",
  "Suzuki",
  "SYM",
  "Temsa",
  "Tesla",
  "Tofas",
  "Toyota",
  "Tufan",
  "TVS",
  "UAZ",
  "Ural",
  "Vespa",
  "VGV",
  "Volkswagen",
  "Volta",
  "Volvo",
  "Voyah",
  "Wuling",
  "XCMG",
  "XPeng",
  "Yamaha",
  "ZAZ",
  "ZEEKR",
  "ZIL",
  "Zongshen",
  "Zontes",
  "ZX Auto",
  "ZXMCO",
];

const brandSelect = document.getElementById("brand");

carBrands.forEach((brand) => {
  const option = document.createElement("option");
  option.value = brand;
  option.textContent = brand;
  brandSelect.appendChild(option);
});

const bodyTypes = [
  "City car",
  "Supermini",
  "Hatchback",
  "MPV",
  "Saloon",
  "Estate",
  "Coupe",
  "Crossover",
  "SUV",
  "Cabriolet",
];

const bodySelect = document.getElementById("body-type");

bodyTypes.forEach((body) => {
  const option = document.createElement("option");
  option.value = body;
  option.textContent = body;
  bodySelect.appendChild(option);
});

const yearFromSelect = document.getElementById("year-from");
const yearToSelect = document.getElementById("year-to");

for (let year = 2024; year >= 1904; year--) {
  const option = document.createElement("option");
  option.value = year;
  option.textContent = year;

  yearFromSelect.appendChild(option.cloneNode(true));
  yearToSelect.appendChild(option);
}


const resetButton = document.querySelector('.filter-reset');

const filterItems = document.querySelectorAll('.filter-item');

resetButton.addEventListener('click', () => {
    filterItems.forEach(item => {
        if (item.tagName === 'INPUT') {
            item.value = '';
            item.value = '';
            item.selectedIndex = 0;
        }
    });
});