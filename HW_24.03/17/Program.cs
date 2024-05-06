using Models;
using DZ;
using Microsoft.EntityFrameworkCore;
using System.Globalization;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

CultureInfo.DefaultThreadCurrentCulture = CultureInfo.InvariantCulture;

builder.Services.AddDbContext<BikeStoreContext>(ops =>
{
    ops.UseSqlServer(builder.Configuration.GetConnectionString("Default"));
});

var app = builder.Build();

if (app.Environment.IsDevelopment())
{
    app.UseSwagger(); 
    app.UseSwaggerUI();
}

app.MapGet("getproducts", (BikeStoreContext context) =>
{
    var brands = context.Brands;
    return brands;
})
    .WithName("GetProducts") 
    .WithOpenApi(); 


app.MapPost("addbrand", async (BikeStoreContext context, HttpRequest request) =>
{
    var headers = request.Headers;

    try
    {
        var brandName = headers.First(x => x.Key.ToLower() == "brand");

        var brand = new Brand()
        {
            BrandName = brandName.Value
        };

        await context.Brands.AddAsync(brand);

        await context.SaveChangesAsync();
        return new
        {
            Result = "Brand added",
            Code = 200
        };
    }
    catch (Exception ex)
    {
        return new
        {
            Result = ex.Message,
            Code = ex.HResult
        };
    }
})
    .WithName("AddBrand")
    .WithOpenApi();


app.UseHttpsRedirection();

app.Run();