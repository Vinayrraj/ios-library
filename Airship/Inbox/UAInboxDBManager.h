/*
 Copyright 2009-2013 Urban Airship Inc. All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 2. Redistributions in binaryform must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided withthe distribution.

 THIS SOFTWARE IS PROVIDED BY THE URBAN AIRSHIP INC ``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL URBAN AIRSHIP INC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>

#import "UAGlobal.h"

@class UA_FMDatabase;
@class UAInboxMessage;

#define UA_FMDBLogError if ([self.db hadError]) { UALOG(@"Err %d: %@", [self.db lastErrorCode], [self.db lastErrorMessage]);}
#define DB_NAME @"UAInbox.db"

@interface UAInboxDBManager : NSObject {
}

@property (nonatomic, strong) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, strong) NSManagedObjectModel *managedObjectModel;
@property (nonatomic, strong) NSPersistentStoreCoordinator *persistentStoreCoordinator;

SINGLETON_INTERFACE(UAInboxDBManager);

- (NSMutableArray *)getMessagesForUser:(NSString *)userID app:(NSString *)appKey;


/**
 * Adds a new message.
 *
 * @param message A dictionary with keys and values conforming to the
 * Urban Airship JSON API for retrieving inbox messages.
 * @param userID the userID of the message.
 * @param appID the appID of the message.
 *
 * @return A message, populated with data from the message dictionary.
 */
- (UAInboxMessage *)addMessageFromDict:(NSDictionary *)dict forUser:(NSString *)userID app:(NSString *)appKey;


- (void)deleteMessages:(NSArray *)messages;
- (void)saveContext;

@end
