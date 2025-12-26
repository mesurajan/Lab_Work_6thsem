using Microsoft.AspNetCore.Mvc;

namespace OpenRedirectDemo.Controllers
{
    public class TestController : Controller
    {
        // ✅ This now loads the Index.cshtml view
        public IActionResult Index()
        {
            return View();
        }

        // ✅ This now loads the Create.cshtml view
        public IActionResult Create()
        {
            return View();
        }

        // Optional custom error page
        public IActionResult Error()
        {
            return View();
        }

        // Unsafe redirect - might cause open redirect vulnerability
        public IActionResult GoLocalRedirect(string url)
        {
            return LocalRedirect(url);
        }

        // Safe redirect using IsLocalUrl()
        public IActionResult GoIsLocalUrl(string url)
        {
            if (Url.IsLocalUrl(url))
                return Redirect(url);
            else
                return RedirectToAction("Error", "Test");
        }
    }
}
