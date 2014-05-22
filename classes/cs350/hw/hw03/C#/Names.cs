/* Nik Ramsey
 * Felicia N'tui
 * CMPS 350: Programming Languages
 *
 * Contents: various word banks stored as string arrays
 */

using System;
using CS350HW3;

abstract public class Names {

    public static string [] degree = {
    	"Ph.D.", "M.S.", "B.S.", "A.A." };

    public static string [] department = {
	"Mathematics", "Business", "English", "Dentistry", "Optometry",
	"Computer Science", "Pharmacy", "Engineering", "Fine Arts", "MIS",
	"Biology", "Nursing", "Botany" };
    
    public static string [] major = {
	"Mathematics", "Business", "Modern Language", "Dentistry", "Optometry",
	"Computer Science", "Pharmacy", "Engineering", "Fine Arts", "MIS",
	"Biology", "Nursing", "Communications", "Botany", "Physics" };

    public static string [] title = {
	"Accountant", "Admin Asst.", "Techician", "Manager", "Secretary",
	"Director", "Supervisor" };
 
    public static string [] position = {
	"Lecturer", "Assoc. Prof", "Asst. Prof.", "Professor" };
	
    public static string [] lastName = {
    	"Abdalla", "Andres", "Anzai", "Armstrong", "Arvig", "Ash", "Baca", "Badine",
	"Baehr", "Bair", "Baligad", "Barlow", "Barrett", "Becker", "Bell",
	"Benbow", "Biggs", "Blevins", "Blood", "Bohan", "Bond", "Bonner",
	"Bosch", "Bryson", "Buechele", "Bullis", "Burk", "Burns", "Byron",
	"Calderon", "Careuthers", "Carr", "Carson", "Carter", "Castle", "Chan",
	"Charney", "Christenson", "Cisneros", "Cliton", "Coldewey", "Coodey",
	"Cook", "Cooper", "Coy", "Currie", "Curtis", "Dirkse", "Dirscoll",
	"Dodrill", "Ehlert", "Elias", "Elliott", "Enterline", "Ericsson",
	"Fernandez", "Fisher", "Flory", "Freese", "Fruzza", "Fu", "Fuhrman", "Gage",
	"Garcia", "Garmon", "Giffith", "Gill", "Gillen", "Glascock", "Gomez",
	"Goraya", "Greer", "Hansen", "Hartley", "Hawkins", "Hemme", "Hensley",
	"Hentges", "Herron", "Hightower", "Hines", "Hoefner", "Holloway", "Holmes",
	"Issac", "Jackson", "Jagodin", "Jiang", "Johnson", "Jordan", "Jouda", "Joven",
	"Kalpesh", "Katz", "Kaur", "Kegley", "Kimsey", "King", "Kohn", "Kone",
	"LaCasse", "Lackey", "Lathrop", "Le", "Levy", "Lynos", "Maas", "Mackall",
	"Madsen", "Magee", "Maldonado", "McDaneld", "McMillian", "McNeill",
	"Meadors", "Medina", "Metz", "Millikin", "Minner", "Mondragon", "Monge", "Moore",
	"Moreno", "Murkland", "Musick", "Myers", "Neal", "Ngo", "Nolan", "Nunez",
	"O'Neil", "Oropeza", "Owen", "Patel", "Pfister", "Philips", "Picato",
	"Porras", "Porter", "Pratt", "Pryor", "Ragle", "Rai", "Raja", "Rill",
	"Roberts", "Roddy", "Rose", "Roux", "Rubio", "Ruiz", "Saito", "Samidin",
	"Sampson", "Sanchez", "Scanlan", "Schmidt", "Schoberg", "Sheppard",
	"Simmons", "Singh","Sison", "Smith", "Snow", "Soto", "Sozinho", "Stevens",
	"Stidham", "Strange", "Sy", "Tamayo", "Taylor", "Thomas", "Tran", "Vincent",
	"Walker", "Wandke", "Ward", "Warner", "Waugh", "Webb", "Wells", "White",
	"Wilson", "Winther", "Wuertz", "Yong" }; 

   public static string [] firstName  = {
	"Aaron","Alan", "Ali", "Alicia","Andrew", "Anne", "Anthony", "Archie", "Ariel",
	"Arlene", "Barbara", "Bebedict", "Benjamin", "Bey-Fen", "Bikram", "Brain",
	"Brandon", "Brent", "Brian", "Bridget", "Brock", "Candice", "Cathleen", "Chad",
	"Charles", "Charlie", "Christopher", "Cindy", "Clinton", "Craig", "Daniel",
	"Danna", "David", "Dean", "Denise", "Dexter", "Diane", "Dinna", "Donna",
	"Douglas", "Eduardo", "Edward", "Elsa", "Eric", "Ernesto", "Fernando",
	"Francisco", "Frank", "Gabby", "Garmund", "Garvin", "Genevieve", "George",
	"Gil", "Gregory", "Gurinder", "Hemant", "Herman", "Hernando", "Isabel",
	"James", "Janet", "Janice", "Jarret", "Jason", "Javier", "Jeffrey",
	"Jennifer", "Jeremy", "Jerold", "Jerrie", "Jim", "Joanna", "Joe", "Joel", "John",
	"Jon", "Jonathan", "Jose", "Joseph", "Josephine", "Josh", "Joshua",
	"Julie", "Kenneth", "Kenny", "Kent", "Kristi", "Kurt", "Kyle", "Lance",
	"Laura", "Leslie", "Malcolm", "Maneje", "Manja", "Marco", "Marcos",
	"Marcus", "Marianna", "Maritza", "Mark", "Marques", "Masaaki", "Mathew", "Matt",
	"Mayur", "Melissa", "Michael", "Miera", "Mike", "Mina", "Mohamed", "Moises",
	"Morgan", "Muntaga", "Myron", "Nathan", "Nilli", "Norma", "Olga",
	"Paradorn", "Patel", "Patrick", "Paul", "Pedro", "Peter", "Philip",
	"Preet", "Ralf", "Ralph", "Raymond", "Reuben", "Ricardo", "Richard",
	"Robert", "Roberto", "Rohit", "Ronald", "Ronne", "Rosa", "Roy", "Rushabh",
	"Ryan", "Samat", "Sara", "Sarah", "Scott", "Sean", "Sergio", "Shahzad", "Shawn",
	"Shi-Wei", "Silvia", "Simon", "Stacy", "Stephanie", "Stephen", "Steven",
	"Sukhum", "Susan", "Suzanne", "Tahnee", "Tahra", "Tam", "Tammy", "Tate",
	"Terry", "Thomas", "Thonas", "To", "Todd", "Tommy", "Travis", "Trevor",
	"Troy", "Valerie", "Ven", "Victor", "Vidya", "Vikramjwed", "Wernher",
	"Wesley", "William", "Yu" } ;
}


