#include "twitter.h"
#include <stdio.h>
#include "const.h"

using namespace rapidjson;
using namespace std;

const string Twitter::rootarray = "{\"rootarray\":";
const string Twitter::baseurl = "https://api.twitter.com/1.1/";
const string Twitter::consumer_key = CONSUMER_KEY;
const string Twitter::consumer_secret = CONSUMER_SECRET;
const string Twitter::access_token = ACCESS_TOKEN;
const string Twitter::access_token_secret = ACCESS_TOKEN_SECRET;

Twitter::Twitter(){
  
}
Twitter::~Twitter(){

}

vector<Tweet> Twitter::TimeLine(const char *jsonurl){
  string strurl = baseurl + "statuses/" + string(jsonurl);
  char *req_url = oauth_sign_url2(strurl.c_str(),
                                  NULL,
                                  OA_HMAC,
                                  "GET",
                                  consumer_key.c_str(),
                                  consumer_secret.c_str(),
                                  access_token.c_str(),
                                  access_token_secret.c_str() );

  char *json = oauth_http_get(req_url, NULL);

  Document doc;
  char buf[strlen(json) + strlen(rootarray.c_str()) + 2];
  strcpy(buf, rootarray.c_str());
  strcat(buf, json);
  strcat(buf, "}\0");
  
  if(doc.ParseInsitu<0>(buf).HasParseError()){
    vector<Tweet> empty;
    return empty;
  }

  const Value& arr = doc["rootarray"];
  for(SizeType i=0; i< arr.Size(); i++){
    Tweet t( arr[i]["user"]["screen_name"].GetString(),
            arr[i]["user"]["name"].GetString(),
            arr[i]["text"].GetString());
    tweets.push_back(t);
  }

  return tweets;
}


void Twitter::Post(char * status){
  string encodedStatus = string( oauth_url_escape(status));
  string strurl = baseurl + "statuses/update.json?status=" + encodedStatus;
  char *postarg = NULL;

  char *req_url = oauth_sign_url2(strurl.c_str(),
                                  &postarg,
                                  OA_HMAC,
                                  "POST",
                                  consumer_key.c_str(),
                                  consumer_secret.c_str(),
                                  access_token.c_str(),
                                  access_token_secret.c_str() );
 
  char *json = oauth_http_post(req_url, postarg);
  Document doc; 
  if(doc.ParseInsitu<0>(json).HasParseError()){
  }

  const Value& arr = doc["errors"];
  for(SizeType i=0; i< arr.Size(); i++){
    printf("%s\n", arr[i]["message"].GetString());
  } 
}
