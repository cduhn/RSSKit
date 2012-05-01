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
    id <RSSParserDelegate> __unsafe_unretained delegate;

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
@property (nonatomic, unsafe_unretained) id <RSSParserDelegate> delegate;

// download properties
@property (nonatomic) NSString *url;
@property (nonatomic) NSURL *contentUrl;
@property (nonatomic) NSMutableURLRequest *request;
@property (nonatomic) NSURLConnection *urlConnection;
@property (nonatomic) NSMutableData *asyncData;
@property (nonatomic, assign) BOOL async;

// parsing properties
@property (nonatomic) NSXMLParser *xmlParser;
@property (nonatomic) NSMutableArray *tagStack;
@property (nonatomic) NSMutableString *tagPath;
@property (nonatomic) RSSFeed *feed;
@property (nonatomic) RSSEntry *entry;

// state properties
@property (nonatomic, readonly) BOOL parsing;
@property (nonatomic, readonly) BOOL failed;
@property (nonatomic, readonly) BOOL successful;

// init parser
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

