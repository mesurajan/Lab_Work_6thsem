using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace Chapter3WebApp.Pages
{
    public class Index1Model : PageModel
    {
        [BindProperty]
        public string? UserInput { get; set; }

        public string? Result { get; set; }

        public void OnGet()
        {
            // Runs when page is first loaded
        }

        public void OnPost()
        {
            if (!string.IsNullOrEmpty(UserInput))
            {
                Result = $"You entered: {UserInput}";
            }
        }
    }
}
