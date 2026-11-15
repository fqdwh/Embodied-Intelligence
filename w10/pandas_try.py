import pandas as pd
import numpy as np
from pandas import Series, DataFrame

# Series
# 类似字典 由一组数据和一组标签组成
# 无指定索引默认 0 ~ N-1
obj = pd.Series([4, 7, -5, 3])
print(obj)
print(obj.values)
print(obj.index)

obj = pd.Series([4, 7, -5, 3], index=['a', 'b', 'c', 'd'])
print(obj)
print(obj.index)
print(obj['b'])
print(obj[obj > 0])

# 字典直接构建
sdata = {'a': 1, 'b': 2, 'c': 3}
obj = pd.Series(sdata)
print(obj)

# 空值检测
pd.isnull(obj)
pd.notnull(obj)
obj.isnull()
obj.notnull()

# Series 对象本身和索引都有 name 属性
obj.name = 'value'
obj.index.name = 'char'
print(obj)


# DataFrame
# 类似列表的字典
# 有列索引和行索引
data = {'state': ['Ohio', 'Ohio', 'Ohio', 'Nevada', 'Nevada', 'Nevada'],
        'year': [2000, 2001, 2002, 2001, 2002, 2003],
        'pop': [1.5, 1.7, 3.6, 2.4, 2.9, 3.2]}
frame = pd.DataFrame(data, index=['one', 'two', 'three', 'four', 'five', 'six'], columns=['year', 'state', 'pop', 'name'])
print(frame)
print(frame.year)
print(frame['state'])     # 列索引获取
print(frame.loc['one'])   # 行索引获取

del frame['name']       # 删除列
print(frame)
frame = frame.drop('one')  # 删除行
print(frame)

print("返回所有请求值的和")
print(frame.sum())
print('返回选取列的和')
print(frame['year'].sum())
# mean() 返回平均值
# std()  返回标准偏差
# describe() 返回 DataFrame 统计信息的摘要
# 默认排除字符串列
# include=''    object 字符串列  number 数字列  all 全部
print(frame.describe(include='all'))


