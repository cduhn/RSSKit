RSSKit
=========

RSSKit is an easy-to use iOS framework to make RSS feed processing simple. It consists of only 3 small classes, so it's extremely lightweight yet powerful. It supports both the RSS 2.0 and the Atom 1.0 feed formats.

How To Use It
-------------

1. #import <RSSKit/RSSKit.h>

2. Define a class which conforms to the RSSParserDelegate, i. e.: @interface MyParserDelegate: NSObject <RSSParserDelegate> 

3. Instantiate an RSSParser object using an NSString with an URL containing a valid RSS/Atom feed, i. e.: RSSParser *parser = [[RSSParser alloc] initWithUrl:@"http://example.com/feed"];  

4. Set an instance of your freshly declared delegate class as the parser's delegate, that is: 
MyParserDelegate *theDelegateObject = [[MyParserDelegate alloc] init];
parser.delegate = theDelegateObject;

5. Call [parser parse];

6. Implement the rssParser:parsedFeed: method in your delegate class. As the 2nd parameter it'll be passed an RSSFeed instance. The properties of this class are named meaningfully; the articles property will contain an NSArray of RSSEntry objects, representing the items/summaries of the feed, respectively (this class also has obviously-named properties).

Author
------

1. Arpad Goretity (H2CO3)
   email : arpad.goretity@gmail.com

2. Louis Larpin (lilfaf)
   email : louis.larpin@gmail.com
