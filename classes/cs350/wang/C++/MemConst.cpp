int maxLastName = 180;
int maxFirstName = 180;
int maxItemName = 20;
int maxSportName = 10;
int maxPopularity = 10;
int maxDepartment = 10; 
int maxDeptName = 10; 
int maxJobTitle = 10;
int maxDegree = 5;
int maxStatus = 4;

const char *status [] = {"Freshman", "Sophomore", "Junior", "Senior"};
const char *degreeName[] = {"Ph.D.", "M.D.", "B.S.", "B.A.", "Ed.D."};
const char *sportName[] = {"Basketball", "Table Tennis", "Swiming",
                          "Tennis", "Golf", "Hockey", "Target Shooting",
                               "VolleyBall", "Soccer", "FootBall"};
const char *popularity[] = {"Most Popular", "Very Popular", "Popular",
                          "Not Popular"};
const char *deptName[] = {"Math", "Business", "Computer Graphics",
                                "Dentistry", "Optomistry", "Computer Science",
                                     "Pharmacy", "Engineering", "Fine Arts",
					 "MIS"};
const char *jobTitle[] = {"Accountant", "Secretary", "Web Designer", "Dentist",
                         "Doctor", "Programmer", "Physician Assistant",
                              "Network Admin", "Artist", "Computer Tech"};

const char * lastName[] = {
    "Andres", "Anzai", "Armstrong", "Arvig", "Ash", "Baca", 
    "Badine", "Baehr", "Bair", "Baligad", "Barlow", "Barrett", 
    "Becker", "Bell", "Benbow", "Biggs", "Blevins", "Blood", 
    "Bohan", "Bond", "Bonner", "Bosch", "Bryson", "Buechele", 
    "Bullis", "Burk", "Burns", "Byron", "Calderon", "Careuthers", 
    "Carr", "Carson", "Carter", "Castle", "Chan", "Charney", 
    "Christenson", "Cisneros", "Cliton", "Coldewey", "Coodey", 
    "Cook", "Cooper", "Coy", "Currie", "Curtis", 
    "Dirkse", "Dirscoll", "Dodrill", "Ehlert", "Elias", "Elliott", 
    "Enterline", "Ericsson", "Fernandez", "Fisher", "Flory", "Freese", 
    "Fruzza", "Fuhrman", "Gage", "Garcia", "Garmon", "Giffith", 
    "Gill", "Gillen", "Glascock", "Gomez", "Goraya", "Greer", "Hansen", 
    "Hartley", "Hawkins", "Hemme", "Hensley", "Hentges", "Herron", 
    "Hightower", "Hines", "Holloway", "Holmes", "Issac", "Jackson", 
    "Jiang", "Johnson", "Jordan", "Jouda", "Joven", "Kalpesh", "Katz", 
    "Kaur", "Kegley", "Kimsey", "King", "Kohn", "Kone", "LaCasse", 
    "Lackey", "Lathrop", "Le", "Levy", "Lynos", "Maas", "Mackall", 
    "Madsen", "Magee", "Maldonado", "McDaneld", "McMillian", "McNeill", 
    "Meadors", "Medina", "Metz", "Minner", "Mondragon", "Monge", "Moore", 
    "Moreno", "Murkland", "Musick", "Myers", "Neal", "Ngo", "Nolan", "Nunez", 
    "O'Neil", "Oropeza", "Owen", "Patel", "Pfister", "Philips", "Picato", 
    "Porras", "Porter", "Pratt", "Pryor", "Ragle", "Rai", "Raja", 
    "Rill", "Roberts", "Roddy", "Rose", "Roux", "Rubio", "Ruiz", 
    "Saito", "Samidin", "Sampson", "Sanchez", "Scanlan", "Schmidt", "Schoberg", 
    "Sheppard", "Simmons", "Sison", "Smith", "Snow", "Soto", "Sozinho", 
    "Stevens", "Stidham", "Strange", "Tamayo", "Taylor", "Thomas", "Tran", 
    "Vincent", "Walker", "Wandke", "Ward", "Warner", "Waugh", "Webb", "Wells", 
    "White", "Wilson", "Winther", "Wuertz", "Yong"
  }; 

const char * firstName[] = {
     "Aaron","Alan", "Alicia","Andrew", "Anne", "Anthony", "Archie",
     "Ariel", "Arlene", "Barbara", "Bebedict", "Benjamin", "Bey-Fen", 
     "Bikram", "Brain", "Brandon", "Brent", "Brian", "Brock", "Candice", 
     "Cathleen", "Chad", "Charles", "Charlie", "Christopher", "Cindy",
     "Clinton", "Craig", "Daniel", "Danna", "David", "Dean", "Denise",
     "Dexter", "Diane", "Dinna", "Donna", "Douglas", "Eduardo", 
     "Edward", "Elsa", "Eric", "Ernesto", "Fernando", "Francisco", "Frank",
     "Gabby", "Garmund", "Garvin", "Genevieve", "George", "Gil", "Gregory", 
     "Gurinder", "Hemant", "Herman", "Hernando", "Isabel", "James",
     "Janet", "Janice", "Jarret", "Jason", "Javier", "Jeffrey", "Jennifer",
     "Jeremy", "Jerold", "Jerrie", "Jim", "Joanna", "Joel", "John", 
     "Jon", "Jonathan", "Jose", "Joseph", "Josephine", "Josh", "Joshua",
     "Julie", "Kenneth", "Kenny", "Kent", "Kristi", "Kurt", "Kyle", "Lance",
     "Laura", "Leslie", "Malcolm", "Maneje", "Manja", "Marco", "Marcos",
     "Marcus", "Maritza", "Mark", "Marques", "Masaaki", "Mathew", "Matt", 
     "Mayur", "Melissa", "Michael", "Miera", "Mike", "Mina", "Mohamed", 
     "Moises", "Morgan", "Muntaga", "Myron", "Nathan", "Nilli", "Norma",
     "Olga", "Paradorn", "Patel", "Patrick", "Paul", "Pedro", "Peter",
     "Philip", "Preet", "Ralf", "Ralph", "Raymond", "Reuben", "Ricardo", 
     "Richard", "Robert", "Roberto", "Rohit", "Ronald", "Ronne", "Rosa", 
     "Roy", "Rushabh", "Ryan", "Sara", "Sarah", "Scott", "Sean", "Sergio",
     "Shahzad", "Shawn", "Shi-Wei", "Silvia", "Simon", "Stacy", "Stephanie",
     "Stephen", "Steven", "Sukhum", "Susan", "Suzanne", "Tahnee",
     "Tahra", "Tam", "Tammy", "Tate", "Terry", "Thomas", "Thonas",
     "To", "Todd", "Tommy", "Travis", "Trevor", "Troy", "Valerie", 
     "Ven", "Victor", "Vidya", "Vikramjwed", "Wernher", "Wesley", "William", 
     "Yu"
   } ;
