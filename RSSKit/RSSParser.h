//
// RSSParser.h
// RSSKit
//
// Created by Árpád Goretity on 01/11/2011.
// Licensed under a CreativeCommons Attribution 3.0 Unported License
//

#import <Foundation/Foundation.h>
#import "RSSDefines.h"
#import "RSSFeed.h"
#import "RSSEntry.h"


// Errors
#define RSSErrorDomain @"RSSKit"
#define RSSErrorCodeConnectionFailed 1
#define RSSErrorCodeNotInitialized   2
#define RSSErrorCodeXmlParser        3

@protocol RSSParserDelegate;


@interface RSSParser: NSObject <NSXMLParserDelegate>{
    
    // delegate
    id <RSSParserDelegate> delegate;

    // network
    NSString *url;
    NSURL *contentUrl;
    NSMutableURLRequest *request;
    NSURLConnection *urlConnection;
    NSMutableData *asyncData;
    BOOL async;
    
    // parsing
	NSXMLParser *xmlParser;
	NSMutableArray *tagStack;
	NSMutableString *tagPath;
	RSSFeed *feed;
	RSSEntry *entry;
    
    // state
    BOOL parsing;
    BOOL failed;
    BOOL successful;
}

 // required!
@property (nonatomic, assign) id <RSSParserDelegate> delegate;

// download properties
@property (nonatomic, retain) NSString *url;
@property (nonatomic, retain) NSURL *contentUrl;
@property (nonatomic, retain) NSMutableURLRequest *request;
@property (nonatomic, retain) NSURLConnection *urlConnection;
@property (nonatomic, retain) NSMutableData *asyncData;
@property (nonatomic, assign) BOOL async;

// parsing properties
@property (nonatomic, retain) NSXMLParser *xmlParser;
@property (nonatomic, retain) NSMutableArray *tagStack;
@property (nonatomic, retain) NSMutableString *tagPath;
@property (nonatomic, retain) RSSFeed *feed;
@property (nonatomic, retain) RSSEntry *entry;

// state properties
@property (nonatomic, readonly) BOOL parsing;
@property (nonatomic, readonly) BOOL failed;
@property (nonatomic, readonly) BOOL successful;

// init RSSKit
- (id) initWithUrl:(NSString *)theUrl asynchronous:(BOOL)sync;
- (id) initWithUrl:(NSString *)theUrl;

// begin parsing
- (void) parse;

// parsing method
- (void) startParsingData:(NSData*)data;
- (void) finishedParsing;

// error handling
- (void) parsingFailedWithDescription:(NSString*)message andErrorCode:(int)code;

@end

// delegate methods
@protocol RSSParserDelegate <NSObject>
@optional
- (void) rssParserDidStartParsing:(RSSParser *)parser;
- (void) rssParser:(RSSParser *)parser didParseFeed:(RSSFeed *)feed;
- (void) rssParser:(RSSParser *)parser didFailWithError:(NSError *)error;
@end

