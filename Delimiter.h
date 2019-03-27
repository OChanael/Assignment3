using namespace std;

class Delimiter
{
public:
  Delimiter(); // constructor
  ~Delimiter(); // destructor

  bool setInputFile(string name); // opening file
  void scanFile(); // reading file
  void reset(); // resetting stacks for loop

  string fileName;
  int stackSize;
};
