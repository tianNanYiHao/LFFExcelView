//
//  LFFExcel.h
//  LFFExcellView
//
//  Created by Lff on 16/8/18.
//  Copyright © 2016年 Lff. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface LFFExcel : NSObject
@end



@interface LFFExcelData : NSObject
{
    NSMutableArray *titles;  //标题列表
    NSMutableArray *data ;  //excel数据 (数组[数组,数组,数组])
    CGFloat excelWidth; // 表格宽
    CGFloat excelX;   //表格x
    CGFloat excelY;   //表格y
    CGFloat cellHeight; //单元格高
    CGFloat cellwidth; //单元格宽
    
    //标题背景颜色
    UIColor *titleColor;
    
    //单元格颜色
    UIColor *cellColor;
    
    //单元格线颜色
    UIColor *lineColor;
    
    //最后一个单元格是否有点击效果
    BOOL anction;

}
@property(retain) NSMutableArray *titles;
@property(retain) NSMutableArray *data;
@property (assign)CGFloat excelWidth;
@property (assign)CGFloat excelX;
@property (assign)CGFloat excelY;
@property (assign)CGFloat cellHeight;
@property (assign)CGFloat cellwidth;
@property (nonatomic,strong) UIColor *titleColor;
@property (nonatomic,strong) UIColor *cellColor;
@property (nonatomic,strong) UIColor *lineColor;
@property (nonatomic,assign) BOOL anction;
@end



@protocol LFFExcelDelegate <NSObject>
- (void)btnAction:(NSInteger)index;
@end

@interface LFFExcelComponent : UIView<UIScrollViewDelegate>{
    //上标题
    UIView *vTopLeft;
    //ecxel 行view
    UIView *vRowView;
    //单元格view
    UIView *vCellView;
    
    //列表数据源
    LFFExcelData *dataSource;
    
    //单元格默认宽度
    CGFloat cellWidth;
    
    //单元格默认高度
    CGFloat cellHeight;

}
@property(readonly) CGFloat cellHeight;
@property(readonly) CGFloat cellWidth;
@property (nonatomic,assign) id <LFFExcelDelegate> delegate;


@property(retain) LFFExcelData *dataSource;
//用数据源->初始化
-(instancetype)initWithdata:(LFFExcelData*)DataSource;


@end

