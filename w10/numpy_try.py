# 命名惯例
import numpy as np
import random
import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import statsmodels as sm

data = np.random.randn(3, 3, 3)   # 2*3 随机数组
print(data)
data = data * 10
print(data)
data = data + data
print(data)

print(data.shape)  # 包含各维度大小的元祖
print(data.dtype)  # 数组数据类型

# 创建 ndarray 数组
data1 = [1, 2, 3, 4, 5, 6]
data2 = [[1, 2, 3], [4, 5, 6]]    # 嵌套序列构建为多维数组
arr1 = np.array(data1)
arr2 = np.array(data2)
print(arr1)
print(arr2)

# 全 0 / 全 1 数组
# 无特指默认类型为 float64
arr3 = np.zeros(10, dtype=np.int64)
arr4 = np.ones((3, 5))      # 多维度数据用元组传入
arr5 = np.empty((2, 3, 3))  # 纯空数组 数据未初始化
arr6 = np.arange(15)        # 0-14

# 手动类型转化
# 浮点转为整数 截断小数部分
# 若字符串全为数值 也可以转换为相应类型
float_arr1 = arr3.astype(np.float64)
print(float_arr1)

# 数组运算
# 乘除是相应位置数据乘除 不是矩阵运算
print(data/data)
print(data > data)
print(1/data)

# 索引和切片
# 针对 ndarray
# 切片是视图不是复制 切片上的更改会影响源数组
arr1_slice = arr1[0:4]
print(arr1_slice)
arr1_slice[0] = 100
print(arr1)
arr1_slice_copy = arr1[0:4].copy()
data[0] = 1     # 索引赋值常数等于赋值所有
print(data)
# 多维切片索引传入多层参数即可

# 布尔型数组用于索引 长度要相同
# 布尔型索引创建数据副本 修改不影响源数组
names = np.array(['Bob', 'a', 'Bob'])
data = np.random.randn(3)
print(data)
data_slice = data[names == 'Bob']
data_slice[0] = 100
print(data)

data[data < 0] = 0
print(data)

# 花式索引
data = np.random.randn(3, 3)
print(data)
print(data[[2, 0, 1]])
print(data[[2, 0, 1], [0, 1, 2]])

# 数组转置/轴对换
data = np.random.randn(6, 3)
print(data)
# print(data.T)
# print(np.dot(data.T, data))   # 矩阵乘积

# 灰度图
# points = np.arange(-5, 5, 0.01)
# xs, ys = np.meshgrid(points, points)
# z = np.sqrt(xs ** 2 + ys ** 2)
# plt.imshow(z, cmap=plt.cm.gray)
# plt.colorbar()
# plt.title("Image plot of $\sqrt{x^2 + y^2}$ for a grid of values")
# plt.savefig("result.png", dpi=150, bbox_inches="tight")   # 先保存
# plt.show()                                                 # 再显示


# 三元表达式 x if c else y
xarr = np.array([1.1, 1.2, 1.3, 1.4, 1.5])
yarr = np.array([2.1, 2.2, 2.3, 2.4, 2.5])
cond = np.array([True, False, True, True, False])
result = np.where(cond, xarr, yarr)
print(result)

# 文件保存 / 读取
np.save('data_array.npy', data)
data_read = np.load('data_array.npy')
print(data_read)

nsteps = 1000
draws = np.random.randint(0, 2, size=nsteps)
steps = np.where(draws > 0, 1, -1)
walk = steps.cumsum()
print(walk)
plt.plot(walk[:1000])
plt.show()
