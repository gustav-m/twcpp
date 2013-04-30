#include <string>
#include <cstdio>
#include <vector>
#include "include/rapidjson/document.h"
#include "include/rapidjson/prettywriter.h"
#include <oauth.h>
#include "tweet.h"
using namespace std;

class Twitter{

  public:
    Twitter(void);
    ~Twitter(void);
    vector<Tweet> TimeLine(const char * jsonurl);
    void Post(char * status);

  private:
    static const string rootarray;
    static const string baseurl;     
    static const string consumer_key;
    static const string consumer_secret;
    static const string access_token;
    static const string access_token_secret;

    vector<Tweet> tweets;

};
