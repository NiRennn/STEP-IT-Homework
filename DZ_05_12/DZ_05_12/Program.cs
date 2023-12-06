

using DZ_05_12.Classes;
using DZ_05_12.Factories;

var officeFurniture = new Furniture(new OfficeFurnitureFactory());

var homeFurniture = new Furniture(new HomeFurnitureFactory());

officeFurniture.UseFurniture();
homeFurniture.UseFurniture();