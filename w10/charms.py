import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import random
plt.rcParams['font.sans-serif'] = [u'SimHei']

# 折线图
x_data = np.arange(2012, 2019, 1)
print(x_data)
y_data1 = np.random.randint(0, 10000, size=7)
y_data2 = np.random.randint(0, 10000, size=7)
# 支持多组数据  还可以传入多种属性 color linewidth linestyle '--' 虚线  ':' 点线  '-.' 短线
plt.plot(x_data, y_data1, color='red', linewidth=2, linestyle='--')
plt.show()

# 散点图
x_data = np.arange(0, 10, 1)
y_data = np.random.randint(0, 10, size=10)
# 可跟一堆属性
plt.scatter(x_data, y_data)
plt.show()

y_data1 = np.random.randint(0, 100, size=10)
y_data2 = np.random.randint(0, 100, size=10)
plt.scatter(x_data, y_data1, label='圆形')
plt.scatter(x_data, y_data2, marker='^', label='三角形')
plt.legend(loc='best')    # 显示图例
plt.show()

# 条形图
fig = plt.figure()
ax = fig.add_axes([0, 0, 1, 1])
langs = ['C', 'C++', 'Java', 'Python', 'PHP']
students = np.random.randint(0, 50, size=5)
ax.bar(langs, students)
plt.show()
# 可以同时绘制 多个 / 堆积 条形图

# 饼图
plt.pie(students, labels=langs, autopct="%1.2f%%")
plt.legend(fontsize=16)
plt.title("各语言学生使用人数")
plt.show()
# 可以做成 凸显 / 旋转 / 环形 效果

# 箱线图 没听过

# 等高线图
plt.rcParams['axes.unicode_minus'] = False

# 高度生成函数
def f(x, y):
    return (1-x/2+x**5+y**3) * np.exp(-x**2-y**2)
n = 256
x = np.linspace(-3, 3, n)
y = np.linspace(-3, 3, n)
X, Y = np.meshgrid(x, y)
plt.contourf(X, Y, f(X, Y))
plt.show()
# 各种属性参数

# 三维绘图
