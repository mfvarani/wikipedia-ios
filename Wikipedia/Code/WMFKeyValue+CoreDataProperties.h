#import "WMFKeyValue+CoreDataClass.h"


NS_ASSUME_NONNULL_BEGIN

@interface WMFKeyValue (CoreDataProperties)

+ (NSFetchRequest<WMFKeyValue *> *)fetchRequest;

@property (nullable, nonatomic, copy) NSString *key;
@property (nullable, nonatomic, retain) NSObject *value;

@end

NS_ASSUME_NONNULL_END
