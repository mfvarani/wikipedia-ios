
#import <Foundation/Foundation.h>
#import "MWKLanguageFilter.h"

@class MWKTitle;
@class MWKLanguageLink;

NS_ASSUME_NONNULL_BEGIN

extern NSString* const WMFPreferredLanguagesDidChangeNotification;


@interface MWKLanguageLinkController : NSObject<MWKLanguageFilterDataSource>

+ (instancetype)sharedInstance;

/**
 * Returns all languages of the receiver, sorted by name, minus unsupported languages.
 *
 * Observe this property to be notifified of changes to the list of languages.
 */
@property (readonly, copy, nonatomic) NSArray<MWKLanguageLink*>* allLanguages;

/**
 * Returns the user's 1st preferred language - used as the "App Language".
 */
@property (readonly, copy, nonatomic) MWKLanguageLink* appLanguage;

/**
 * Returns the user's preferred languages.
 */
@property (readonly, copy, nonatomic) NSArray<MWKLanguageLink*>* preferredLanguages;

/**
 * All the languages in the receiver minus @c preferredLanguages.
 */
@property (readonly, copy, nonatomic) NSArray<MWKLanguageLink*>* otherLanguages;

/**
 *  Uniquely adds a new preferred language. The new lnguage will be the first preferred language.
 *
 *  @param language the language to add
 */
- (void)addPreferredLanguage:(MWKLanguageLink*)language;

/**
 *  Uniquely appends a new preferred language. The new lnguage will be the last preferred language.
 *
 *  @param language the language to append
 */
- (void)appendPreferredLanguage:(MWKLanguageLink*)language;

/**
 *  Uniquely inserts a new preferred language. The new lnguage will be inserted at the given index.
 *
 *  @param language the language to append
 *  @param newIndex the new index of the langage
 */
- (void)insertPreferredLanguage:(MWKLanguageLink*)language atIndex:(NSUInteger)newIndex;

/**
 *  Reorders a preferred language to the index given. The language must already exist in a user's preferred languages
 *
 *  @param language the language to reorder
 *  @param newIndex the new index of the langage
 */
- (void)reorderPreferredLanguage:(MWKLanguageLink*)language toIndex:(NSUInteger)newIndex;

/**
 *  Removes a preferred language.
 *
 *  @param language the language to remove
 */
- (void)removePreferredLanguage:(MWKLanguageLink*)langage;


- (BOOL)languageIsOSLanguage:(MWKLanguageLink*)language;


- (nullable MWKLanguageLink*)languageForSite:(MWKSite*)site;

@end

NS_ASSUME_NONNULL_END
