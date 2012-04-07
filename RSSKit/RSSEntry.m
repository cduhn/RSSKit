//
// RSSEntry.m
// RSSKit
//
// Created by Árpád Goretity on 01/11/2011.
// Licensed under a CreativeCommons Attribution 3.0 Unported License
//

#import "RSSEntry.h"


@implementation RSSEntry

@synthesize title;
@synthesize url;
@synthesize uid;
@synthesize date;
@synthesize summary;
@synthesize categories;
@synthesize comments;
@synthesize content;
@synthesize copyright;
@synthesize attachedMedia;
@synthesize author;
@synthesize image;


- (id) init {
	self = [super init];
	NSArray *theCategories = [[NSArray alloc] init];
	self.categories = theCategories;
	[theCategories release];
	return self;
}


- (void) dealloc {
	[title release];
    [url release];
    [uid release];
    [date release];
    [summary release];
    [categories release];
    [comments release];
    [content release];
    [copyright release];
    [attachedMedia release];
    [author release];
    [image release];
	[super dealloc];
}

#pragma mark -
#pragma mark NSCoding Protocol

- (id)initWithCoder:(NSCoder *)decoder {
	if ((self = [super init])) {
        title = [[decoder decodeObjectForKey:@"title"] retain];
        url = [[decoder decodeObjectForKey:@"url"] retain];
        uid = [[decoder decodeObjectForKey:@"uid"] retain];
        date = [[decoder decodeObjectForKey:@"date"] retain];
        summary = [[decoder decodeObjectForKey:@"summary"] retain];
        categories = [[decoder decodeObjectForKey:@"categories"] retain];
        comments = [[decoder decodeObjectForKey:@"comments"] retain];
        content = [[decoder decodeObjectForKey:@"content"] retain];
        copyright = [[decoder decodeObjectForKey:@"copyright"] retain];
        attachedMedia = [[decoder decodeObjectForKey:@"attachedMedia"] retain];
        author = [[decoder decodeObjectForKey:@"author"] retain];
        image = [[decoder decodeObjectForKey:@"image"] retain];
	}
	return self;
}

- (void)encodeWithCoder:(NSCoder *)encoder {
    [encoder encodeObject:title forKey:@"title"];
    [encoder encodeObject:url forKey:@"uid"];
    [encoder encodeObject:uid forKey:@"url"];
    [encoder encodeObject:date forKey:@"date"];
    [encoder encodeObject:summary forKey:@"summary"];
    [encoder encodeObject:categories forKey:@"categories"];
    [encoder encodeObject:comments forKey:@"comments"];
    [encoder encodeObject:content forKey:@"content"];
    [encoder encodeObject:copyright forKey:@"copyright"];
    [encoder encodeObject:attachedMedia forKey:@"attachedMedia"];
    [encoder encodeObject:author forKey:@"author"];
    [encoder encodeObject:image forKey:@"image"];
}

@end

