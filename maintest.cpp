#include <iostream>
#include "twitter.h"
#include <vector>

using namespace std;

void getTimeLine(const char *jsonurl){
  Twitter twitter;
  vector<Tweet> tweets = twitter.TimeLine(jsonurl);
  for(vector<Tweet>::iterator it = tweets.begin(); it != tweets.end(); ++it){
    cout << (*it).getText() << "\n";
  }
  
}

int main(int argc, char **argv){
  //command
  if(argc == 2){
    if(strcmp(argv[1], "-m") == 0){
      getTimeLine("mentions_timeline.json");
    }else{
      Twitter twitter;
      twitter.Post(argv[1]);
    }
  }else if(argc == 1){
      getTimeLine("home_timeline.json");
  }
}

