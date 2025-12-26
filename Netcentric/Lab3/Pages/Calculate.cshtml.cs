using System.ComponentModel.DataAnnotations;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace Chapter3WebApp.Pages;

public class CalculateModel : PageModel
{
    [BindProperty]
    public InputModel Input { get; set; } = new();

    public double? Result { get; set; }

    public void OnGet()
    {
        // initial page load
    }

    public IActionResult OnPost()
    {
        if (!ModelState.IsValid)
        {
            return Page();
        }

        Result = Input.A + Input.B;
        return Page();
    }

    public class InputModel
    {
        [Display(Name = "First number")]
        [Required]
        [Range(typeof(double), "-1E+308", "1E+308", ErrorMessage = "Enter a number")]
        public double A { get; set; }

        [Display(Name = "Second number")]
        [Required]
        [Range(typeof(double), "-1E+308", "1E+308", ErrorMessage = "Enter a number")]
        public double B { get; set; }
    }
}
