import pandas as pd
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


