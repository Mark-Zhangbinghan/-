import Function
import math
import numpy as np
import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif'] = ['SimHei']  # 显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 设置正常显示符号

"""
r     判断两智能体是否为邻居
L     绘图要求矩形边长
rou   极坐标随机长度
theta 极坐标随机坐标
box   用来设定划分好的区域
"""

r = 1
L = 10 * r

# fig-4(a)实现
ax1 = plt.figure(figsize=(5, 5))
axa = plt.subplot(111)
# 先随机生成100个在范围内的盒子，再将x和y填入每个盒子
box_x = []
box_y = []
for i in range(20):
    box_x = np.concatenate((box_x, np.arange(0, 10, 1)))
    box_y = np.concatenate((box_y, np.arange(0, 10, 1)))
box_x = sorted(box_x)
x = np.random.rand(200) + box_x
y = np.random.rand(200) + box_y
Function.set_subplot_1(x, y, '(a) Top-2: 200 agents')


# fig-4(b)实现
ax2 = plt.figure(figsize=(5, 5))
axb = plt.subplot(111)
# 运用极坐标的方式生成数据
rou = 5 * np.sqrt(np.random.rand(200))   # 极坐标长度
theta = 2 * np.pi * np.random.rand(200)  # 极坐标角度
x = rou * np.cos(theta)
y = rou * np.sin(theta)
Function.set_subplot_2(x, y, '(b) Top-1: 200 agents')


# fig-4(c)实现
ax3 = plt.figure(figsize=(5, 5))
axc = plt.subplot(111)
# 运用极坐标的方式生成数据
rou = (L / (2 + math.sqrt(2))) * np.sqrt(np.random.rand(100))   # 极坐标长度
theta = 2 * np.pi * np.random.rand(100)                         # 极坐标角度
x = rou * np.cos(theta) + (L / (2 + 2 * math.sqrt(2)))
y = rou * np.sin(theta) + (L / (2 + 2 * math.sqrt(2)))
# 重新生成一组智能体
rou = (L / (2 + math.sqrt(2))) * np.sqrt(np.random.rand(100))   # 极坐标长度
theta = 2 * np.pi * np.random.rand(100)                         # 极坐标角度
new_x = rou * np.cos(theta) - (L / (2 + 2 * math.sqrt(2)))
new_y = rou * np.sin(theta) - (L / (2 + 2 * math.sqrt(2)))
x = np.concatenate((x, new_x))
y = np.concatenate((y, new_y))
Function.set_subplot_2(x, y, '(c) Top-3: 200 agents')


# fig-4(d)实现
ax4 = plt.figure(figsize=(5, 5))
axd = plt.subplot(111)
# 运用极坐标的方式生成数据
rou = 2 * np.sqrt(np.random.rand(200)) + 3  # 极坐标长度
theta = 2 * np.pi * np.random.rand(200)     # 极坐标角度
x = rou * np.cos(theta)
y = rou * np.sin(theta)
Function.set_subplot_2(x, y, '(d) Top-4: 200 agents')


# fig-4(e)实现
ax5 = plt.figure(figsize=(5, 5))
axe = plt.subplot(111)
x = []
y = []
while len(x) < 200:
    test_y = np.random.uniform(0, 10, 1)
    test_x = np.random.uniform(0, 10, 1)
    if (test_y/2) < test_x < (10 - test_y/2):
        x = np.concatenate((x, test_x))
        y = np.concatenate((y, test_y))
Function.set_subplot_1(x, y, '(e) Top-5: 200 agents')


# fig-4(f)实现
ax6 = plt.figure(figsize=(5, 5))
axf = plt.subplot(111)
x = []
y = []
while len(x) < 200:
    test_y = np.random.uniform(0, 10, 1)
    test_x = np.random.uniform(0, 10, 1)
    if not (((2 * L / 3) < test_x or test_x < (L / 3)) and ((2 * L / 3) < test_y or test_y < (L / 3))):
        x = np.concatenate((x, test_x))
        y = np.concatenate((y, test_y))
Function.set_subplot_1(x, y, '(f) Top-6: 200 agents')


# fig-4(g)实现
ax7 = plt.figure(figsize=(5, 5))
axg = plt.subplot(111)
m = np.arange(1, int((5 / (0.5 * r)) + 1))
x = [0]
y = [0]
for i in m:
    rou = i * 0.5
    num = int(np.ceil(2 * np.pi * rou / 0.8))
    theta = np.linspace(0, 2 * np.pi, num, endpoint=False)
    x = np.concatenate((x, rou * np.cos(theta)))
    y = np.concatenate((y, rou * np.sin(theta)))
Function.set_subplot_2(x, y, '(g) Top-7: 221 agents')


# fig-4(h)实现
ax8 = plt.figure(figsize=(5, 5))
axh = plt.subplot(111)
m = np.arange(1, int((5 / (0.5 * r)) + 1))
x = [0]
y = [0]
for i in m:
    rou = i * 0.5
    theta = np.linspace(0, 2 * np.pi, 20, endpoint=False)
    x = np.concatenate((x, rou * np.cos(theta)))
    y = np.concatenate((y, rou * np.sin(theta)))
Function.set_subplot_2(x, y, '(h) Top-8: 217 agents')


# fig-4(i)实现
ax9 = plt.figure(figsize=(5, 5))
axi = plt.subplot(111)
x = []
y = []
for i in range(15):
    x = np.concatenate((x, np.linspace(-5, 5, 15)))
    y = np.concatenate((y, np.linspace(-5, 5, 15)))
x = np.array(sorted(x))
Function.set_subplot_2(x, y, '(i) Top-9: 225 agents')


# fig-4(j)实现
ax10 = plt.figure(figsize=(5, 5))
axj = plt.subplot(111)
x = []
y = []
num = 0
box_x1 = np.linspace(0, 9.8, 14)
box_x2 = np.linspace(0.35, 9.45, 13)
box_y = np.linspace(0, 9.8, 16)
for i in box_y:
    if num % 2 == 0:
        x = np.concatenate((x, box_x1))
        y = np.concatenate((y, [i] * len(box_x1)))
    else:
        x = np.concatenate((x, box_x2))
        y = np.concatenate((y, [i] * len(box_x2)))
    num += 1
Function.set_subplot_1(x, y, '(j) Top-10: 218 agents')
print(x.shape)
