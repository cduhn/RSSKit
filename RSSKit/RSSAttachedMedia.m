//
// RSSAttachedMedia.m
// RSSKit
//
// Created by Árpád Goretity on 21/12/2011.
// Licensed under a CreativeCommons Attribution 3.0 Unported License
//

#import "RSSAttachedMedia.h"


@implementation RSSAttachedMedia

@synthesize url;
@synthesize length;
@synthesize type;

- (void) dealloc {
	[url release];
    [type release];
	[super dealloc];
}

#pragma mark -
#pragma mark NSCoding Protocol

- (id)initWithCoder:(NSCoder *)decoder {
	if ((self = [super init])) {
        url = [[decoder decodeObjectForKey:@"url"] retain];
        type = [[decoder decodeObjectForKey:@"type"] retain];
        length = [decoder decodeIntForKey:@"length"];
	}
	return self;
}

- (void)encodeWithCoder:(NSCoder *)encoder {
    [encoder encodeObject:url forKey:@"url"];
    [encoder encodeObject:type forKey:@"type"];
    [encoder encodeInt:length forKey:@"length"];
}

@end

