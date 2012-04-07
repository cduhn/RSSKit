//
// RSSFeed.m
// RSSKit
//
// Created by Árpád Goretity on 01/11/2011.
// Licensed under a CreativeCommons Attribution 3.0 Unported License
//

#import "RSSFeed.h"


@implementation RSSFeed

@synthesize type;
@synthesize title;
@synthesize description;
@synthesize url;
@synthesize date;
@synthesize author;
@synthesize articles;
@synthesize uid;
@synthesize language;
@synthesize copyright;
@synthesize categories;
@synthesize generator;
@synthesize validTime;
@synthesize iconUrl;
@synthesize cloudService;


- (id) init {
	if (self = [super init]) {
        NSArray *theArticles = [[NSArray alloc] init];
        self.articles = theArticles;
        [theArticles release];
        NSArray *theCategories = [[NSArray alloc] init];
        self.categories = theCategories;
        [theCategories release];

    }
	return self;
}


- (void) dealloc {
    [title release];
    [description release];
    [url release];
    [date release];
    [author release];
    [articles release];
    [uid release];
    [language release];
    [copyright release];
    [categories release];
    [generator release];
    [iconUrl release];
    [cloudService release];
	[super dealloc];
}

#pragma mark -
#pragma mark NSCoding Protocol

- (id)initWithCoder:(NSCoder *)decoder {
	if ((self = [super init])) {
        type = [decoder decodeIntForKey:@"type"];
        title = [[decoder decodeObjectForKey:@"title"] retain];
        description = [[decoder decodeObjectForKey:@"description"] retain];
        url = [[decoder decodeObjectForKey:@"url"] retain];
        date = [[decoder decodeObjectForKey:@"date"] retain];
        author = [[decoder decodeObjectForKey:@"author"] retain];
        articles = [[decoder decodeObjectForKey:@"articles"] retain];
        uid = [[decoder decodeObjectForKey:@"uid"] retain];
        language = [[decoder decodeObjectForKey:@"language"] retain];
        copyright = [[decoder decodeObjectForKey:@"copyright"] retain];
        categories = [[decoder decodeObjectForKey:@"categories"] retain];
        generator = [[decoder decodeObjectForKey:@"generator"] retain];
        validTime = [decoder decodeFloatForKey:@"validTime"];
        iconUrl = [[decoder decodeObjectForKey:@"iconUrl"] retain];
        cloudService = [[decoder decodeObjectForKey:@"cloudService"] retain];
	}
	return self;
}

- (void)encodeWithCoder:(NSCoder *)encoder {
    [encoder encodeInt:type forKey:@"type"];
    [encoder encodeObject:title forKey:@"title"];
    [encoder encodeObject:description forKey:@"description"];
    [encoder encodeObject:url forKey:@"url"];
    [encoder encodeObject:date forKey:@"date"];
    [encoder encodeObject:author forKey:@"author"];
    [encoder encodeObject:articles forKey:@"articles"];
    [encoder encodeObject:uid forKey:@"uid"];
    [encoder encodeObject:language forKey:@"language"];
    [encoder encodeObject:copyright forKey:@"copyright"];
    [encoder encodeObject:categories forKey:@"categories"];
    [encoder encodeObject:generator forKey:@"generator"];
    [encoder encodeFloat:validTime forKey:@"validTime"];
    [encoder encodeObject:iconUrl forKey:@"inconUrl"];
    [encoder encodeObject:cloudService forKey:@"cloudService"];
}

@end

