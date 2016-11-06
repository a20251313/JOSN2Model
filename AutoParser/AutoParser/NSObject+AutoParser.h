//
//  NSObject+AutoParser.h
//  AutoParser
//
//  Created by LiXiangCheng on 16/9/16.
//  Copyright (c) 2016年 Wanda Inc All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
//以下引用：SafeCategories
#import "NSArray+Safe.h"
#import "NSArray+WDAdd.h"
#import "NSMutableArray+Safe.h"
#import "NSData+WDAdd.h"
#import "NSDictionary+Safe.h"
#import "NSMutableDictionary+Safe.h"
#import "NSDictionary+WDAdd.h"
#import "NSManagedObject+Safe.h"
#import "NSNumber+Safe.h"
#import "NSObject+Safe.h"
#import "NSMutableSet+Safe.h"
#import "NSString+Safe.h"
#import "NSString+WDAdd.h"
#import "NSUserDefaults+Safe.h"

///------------------------------
/// @LiXiangCheng 20161022
/// GitHub:https://github.com/LarryPage/AutoParser
/// 最大缓存500个Model定义,1个model按10个左右属性，大约0.1K，500个model点内存50K
/// 实现 dictionary<->model json<->model
/// 实现 模型序列化存储、读取、copy 【NSCoding NSCopying】
/// 使用 WDSafeCategories保证每条数据安全解析
///------------------------------

/**
 support :variable type

 double
 float
 int
 bool
 BOOL
 NSInteger
 NSUInteger
 NSNumber *
 NSString * NSMutableString *
 NSDictionary * NSMutableDictionary *
 NSArray * NSMutableArray *
 NSSet * NSMutableSet *
 NSOrderedSet * NSMutableOrderedSet *
 ...
 and 自定义model类
 */
@interface NSObject (KVC)

/** dic转model */
- (id)initWithDic:(NSDictionary *)dic;
/** model转dic */
- (NSDictionary *)dic;
/** json字符串转model */
- (id)initWithJson:(NSString *)json;
/** model转json字符串 */
- (NSString *)json;

/**
 在propertyName与josnKeyName不一致时，要设置类函数
 返回replacedKeyMap：{propertyName:jsonKeyName}
 */
+ (NSDictionary *)replacedKeyMap;

/** model定义->属性字典 */
+ (NSDictionary *) propertiesOfObject:(id)object;
+ (NSDictionary *) propertiesOfClass:(Class)klass;
+ (NSDictionary *) propertiesOfSubclass:(Class)klass;//recursive

#pragma mark NSCoding
/** 支持model存储序列化文件 */
- (void)encodeWithCoder:(NSCoder *)aCoder;
/** 支持序列化文件读取model */
- (id)initWithCoder:(NSCoder *)aDecoder;

#pragma mark NSCopying
/** 支持model copy */
- (id)copyWithZone:(NSZone *)zone;
@end