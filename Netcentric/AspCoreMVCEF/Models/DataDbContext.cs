using Microsoft.EntityFrameworkCore;

namespace AspCoreMVCEF.Models
{
    public class DataDbContext : DbContext
    {
        public DataDbContext(DbContextOptions<DataDbContext> options) : base(options) { }

        public DbSet<User> Users { get; set; }
    }
}
