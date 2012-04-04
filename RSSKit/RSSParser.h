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

@protocol RSSParserDelegate;


@interface RSSParser: NSObject <NSXMLParserDelegate>{
	NSString *url;
	NSXMLParser *xmlParser;
	NSMutableArray *tagStack;
	NSMutableString *tagPath;
	RSSFeed *feed;
	RSSEntry *entry;
	id <RSSParserDelegate> delegate;
    NSURLConnection *urlConnection;
    NSData *syncData;
    NSMutableData *asyncData;
}

@property (nonatomic, assign) id <RSSParserDelegate> delegate;
@property (nonatomic, retain) NSString *url;
@property (nonatomic, assign) BOOL async;

- (id) initWithUrl:(NSString *)theUrl asynchronous:(BOOL)sync;
- (id) initWithUrl:(NSString *)theUrl;
- (void) parse;

@end


@protocol RSSParserDelegate <NSObject>
@optional
- (void) rssParser:(RSSParser *)parser parsedFeed:(RSSFeed *)feed;
- (void) rssParser:(RSSParser *)parser errorOccurred:(NSError *)error;
@end

