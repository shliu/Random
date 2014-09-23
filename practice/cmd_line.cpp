#include <iostream>
#include <sstream>
#include <cstdlib>
#include <getopt.h>

class InputException{
public:
  InputException(const std::string& msg) : m_msg(msg){};
  const std::string& what() const {return m_msg;}
private:
  const std::string m_msg;
};

int main(int argc, char* argv[]) {

  // set up default values

  const int defaultNumberOfHotDogs = 1;

  std::cout << "Argument count: " << argc << '\n';
  for(int i=0; i<argc; ++i)
    std::cout << "argv[" << i << "]: " << argv[i] << '\n';
  std::cout << std::flush;

  try {

    // initialize option values to defaults
    int numberOfHotDogs = defaultNumberOfHotDogs;
    int numberOfHamburgers = 0;
    bool wholeGrain = false;
    bool vegetarian = false;
    bool printOrder = false;
    bool kosher     = false;

    // process options
    const char* optstring = "d:h:Hpvw";
    const struct option longOpts[] = {
    { "hot-dogs",    required_argument, 0, 'd' },
    { "hamburgers",  required_argument, 0, 'h' },
    { "help",        no_argument,       0, 'H' },
    { "kosher",      no_argument,       0,  0  },
    { "print-order", no_argument,       0, 'p' },
    { "vegetarian",  no_argument,       0, 'v' },
    { 0,             no_argument,       0, 0 }};

    int c;
    int longIndex;
    while((c = getopt_long(argc, argv, optstring, longOpts, &longIndex)) != -1){
      switch(c){
      case 'd':
        {
          std::istringstream is(optarg);
          char leftoverChar;
          if(!(is >> numberOfHotDogs) || is.get(leftoverChar))
            throw(InputException("Invalid argument for hot dogs"));
        }
        break;
      case 'h':
        {
          std::istringstream is(optarg);
          char leftoverChar;
          if(!(is >> numberOfHamburgers) || is.get(leftoverChar))
            throw(InputException("Invalid argument for hamburgers"));
        }
        break;
      case 'p':
        {
          printOrder = true;
        }
        break;
      case 'v':
        {
          vegetarian = true;
        }
        break;
      case 'w':
        {
          wholeGrain = true;
        }
        break;
      case 0:
        { // long option without corresponding short option
          std::string option(longOpts[longIndex].name);
          if(option == "kosher") {
            kosher = true;
          } else
          {
            std::cerr << "Unknown long option " << option << '\n';
            exit(1);
          }
          break; 
        }
      case '?':
      case 'H':
      default:
        {
          std::cerr << "Usage: " << argv[0] << "[-d # -h # -pvw] [remark]\n";
          std::cerr << "Options:\n"
            << "-d, --hot-dogs     Number of hot dogs\n"
            << "                   Default: " << defaultNumberOfHotDogs << '\n'
            << "-h, --hamburgers   Number of hamburgers\n"
            << "    --kosher       Request kosher preparation\n"
            << "-p, --print        Print order\n"
            << "-v, --vegetarian   Request vegetarian franks and burgers\n"
            << "-w, --whole-grain  Request whole grain buns\n"
            << "-H, --help         Display this message\n"
            << "Arguments:\n"
            << "remark             Remark to pass on to the kitchen\n";
          exit(-1);
        }
      }
    }

    // check options for semantic correctness

    if(numberOfHotDogs<0)
      throw InputException
        ("Sorry, you must order a positive number of hot dogs");

    if(numberOfHamburgers<0)
      throw InputException
        ("Sorry, you must order a positive number of hamburgers");

    if(kosher && numberOfHotDogs>0 && !vegetarian)
      throw InputException
        ("Sorry, you cannot have kosher, non--vegetarian hot dogs");

    // process non-option arguments
    if(argc-optind>0) {
      std::cout << "Found additional arguments:\n";
      for(int i=optind; i<argc; ++i)
        std::cout << "argv[" << i << "]: " << argv[i] << '\n';
      std::cout << std::endl;
    }

    // start working, using the options and arguments

    if(printOrder) {
      std::cout << "Your order:\n"
                << "   Hot Dogs: " << numberOfHotDogs << '\n'
                << " Hamburgers: " << numberOfHamburgers << '\n'
                << " Vegetarian: " << (vegetarian?"Yes":"No") << '\n'
                << "Whole Grain: " << (wholeGrain?"Yes":"No") << '\n'
                << "     Kosher: " << (kosher?"Yes":"No") << '\n';
    }
  }
  catch(InputException& e){
    std::cerr << "Invalid input: " << e.what() << '\n';
    std::cerr << "Use the --help option for usage information\n";
    exit(2);
  }
  catch(...){
    std::cerr << "Unknown exception caught\n";
    exit(3);
  }

  return 0;
}