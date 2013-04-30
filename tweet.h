#include <string>

using namespace std;

class Tweet{
  public:
    Tweet(const char* sn, const char* n, const char* tx);
    string getScreenName();
    string getName();
    string getText();

  private:
    string screenName;
    string name;
    string text;
};
