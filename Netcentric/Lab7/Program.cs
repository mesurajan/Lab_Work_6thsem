using AspCoreMVCEF.Models;
using Microsoft.EntityFrameworkCore;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddControllersWithViews();

// MySQL connection
builder.Services.AddDbContext<DataDbContext>(options =>
    options.UseMySql(
        builder.Configuration.GetConnectionString("DevConnection"),
        ServerVersion.AutoDetect(builder.Configuration.GetConnectionString("DevConnection"))
    )
);

var app = builder.Build();

// Middleware
if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Home/Error");
    app.UseHsts();
}

app.UseHttpsRedirection();
app.UseStaticFiles();
app.UseRouting();
app.UseAuthorization();

// Default route
app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Users}/{action=Index}/{id?}");

// Redirect root URL to /Users
app.MapGet("/", context =>
{
    context.Response.Redirect("/Users");
    return Task.CompletedTask;
});

app.Run();
