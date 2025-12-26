using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using System.ComponentModel.DataAnnotations;

namespace Lab6FormDemo.Pages
{
    // Class to store each user's entry
    public class UserEntry
    {
        public string Name { get; set; } = "";
        public int Age { get; set; }
        public string Address { get; set; } = "";
    }

    public class IndexModel : PageModel
    {
        [BindProperty]
        [Required(ErrorMessage = "Please enter your name")]
        public string? Name { get; set; }

        [BindProperty]
        [Required(ErrorMessage = "Please enter your age")]
        [Range(1, 120, ErrorMessage = "Enter a valid age between 1 and 120")]
        public int? Age { get; set; }

        [BindProperty]
        [Required(ErrorMessage = "Please enter your address")]
        public string? Address { get; set; }

        // Static list to keep all submissions
        public static List<UserEntry> Entries { get; set; } = new List<UserEntry>();

        public void OnGet() { }

        public IActionResult OnPost()
        {
            if (!ModelState.IsValid)
                return Page();

            // Add new submission to the list
            Entries.Add(new UserEntry { Name = Name!, Age = Age!.Value, Address = Address! });

            // Clear input fields after submission
            ModelState.Clear();

            return Page();
        }
    }
}
