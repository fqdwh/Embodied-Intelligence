import matplotlib.pyplot as plt
import numpy as np
import random

# 图像中文设置
plt.rcParams['font.sans-serif'] = [u'SimHei']

# Figure 图(画板)
fig = plt.figure()

# Axes 轴
ax = fig.add_subplot(111)
ax.set(xlim=[0, 5.0], ylim=[0, 10], title='轴实例', ylabel='Y-轴', xlabel='X-轴')
# plt.show()

# 子图
fig = plt.figure()
ax1 = fig.add_subplot(221)
ax2 = fig.add_subplot(222)
ax3 = fig.add_subplot(223)
# plt.show()

# Multiple Axis 轴
# 一次性设置子图
fig, axes = plt.subplots(nrows=2, ncols=2)
axes[0, 0].set(title='左上限')
axes[0, 1].set(title='右上限')
axes[1, 1].set(title='右下限')
axes[1, 0].set(title='左下限')
# plt.show()


# 折线图
fig = plt.figure()
x_data = np.arange(2012, 2019, 1)
print(x_data)
y_data = np.random.randint(0, 10000, size=7)
plt.plot(x_data, y_data)
plt.show()
