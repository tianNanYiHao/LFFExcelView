# LFFExcelView
封装了一个Excel表格, 只要设置表格的X,Y坐标,标题,单元格数据内容以及颜色 即可生成你所需要的表格,样式上比较简单,但是算是自己封装的第一个自定义控件,做一下纪念

1.用法 导入 libLFFExcel.a 库 以及 LFFExcel.h 头文件

```
#import "LFFExcel.h"
```

2.实例化数据类 
```
LFFExcelData *ds = [[LFFExcelData alloc] init];

```
3.设置标题数据 单元格数据 以及 表格起始位置的X / Y 以及单元格高度 (其余的会自动根据屏幕自己计算,但如果表格 list列 过多可能造成单元格宽度不够,一直数据内容显示不全,这个以后我在改改)

```
 LFFExcelData *ds = [[LFFExcelData alloc] init];
    ds.titles = (NSMutableArray*)@[@"时长",@"使用流量",@"地点"];
    ds.data = [NSMutableArray arrayWithObjects:
               @[@"2016-06-17",@"308M",@"详情"],
               @[@"2016-06-17",@"308M",@"详情"],
               @[@"2016-06-17",@"308M",@"详情"],
               @[@"",@"",@""],@[@"",@"",@""],@[@"",@"",@""],@[@"",@"",@""],
               nil];
    
    //设置表格标题背景色
    ds.titleColor = customBlue;
    //设置表格单元格颜色
    ds.cellColor = customGray;
    //设置单元格网格线颜色
    ds.lineColor = customLineBlue;
    

    //设置表格的x
    ds.excelX = 10;
    //设置表格的y
    ds.excelY = _infoBgVIew.y+_infoBgVIew.height;
    //设置表格的宽度
    ds.excelWidth = boundsWidth-2*ds.excelX;
    //设置表格的单元格高度
    ds.cellHeight = 40;
    
 
```

3.1 在表格的最后一列 如果需要有操作行为 则设置如下参数
```
    //设置是否可以点击
    ds.anction = YES;       (这里, 如果设置YES 则会让表格最后的一列 全部成为可以点击的按钮 可以做一些push或者操作 /一旦设置成YES, 建议实现代理 以及 代理方法)
```

4. 使用数据类 LFFExcelData 的实例对象 来生成 表格对象 (这里,如果设置 ds.anction == YES , 就要实现代理)
4.1 代理的设置
```
@interface FlowDetailViewController ()<LFFExcelDelegate>

#pragma mark LFFExcelDelegate
-(void)btnAction:(NSInteger)index{
    //这里处理事件操作
}
```

实例化表格对象
```
   LFFExcelComponent *lffexcelComponent = [[LFFExcelComponent alloc] initWithdata:ds];
    lffexcelComponent.delegate  = self;
    [self.view addSubview:lffexcelComponent];

```


