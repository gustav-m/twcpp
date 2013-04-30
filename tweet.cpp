#include "tweet.h"


Tweet::Tweet(const char* sn, const char* n, const char* tx){
  screenName =string( sn);
  name = string(n);
  text = string(tx);
}

string Tweet::getScreenName(){ return screenName;}
string Tweet::getName(){ return name;}
string Tweet::getText(){ return text;}


