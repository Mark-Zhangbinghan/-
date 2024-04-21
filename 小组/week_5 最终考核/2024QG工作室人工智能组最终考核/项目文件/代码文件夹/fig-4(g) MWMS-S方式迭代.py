import Function
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from tqdm import trange   # trange(i)是tqdm(range(i))的一种简单写法

plt.rcParams['font.sans-serif'] = ['SimHei']  # 显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 设置正常显示符号


def update(frame, alpha, title):
    global x, y, prev_x, prev_y
    prev_x = x.copy()
    prev_y = y.copy()
    x, y = Function.Algorithm_1(x, y, alpha)

    if np.array_equal(x, prev_x) and np.array_equal(y, prev_y):
        print("节点位置不再变化，系统已收敛")
        anim.event_source.stop()  # 停止生成动画

    distances = Function.distance(x, y)
    fig.clear()
    for i in trange(len(x)):
        for j in range(i + 1, len(x)):
            if i != j and distances[i, j] <= 1:
                fig.plot([x[i], x[j]], [y[i], y[j]],
                         linestyle='-.', linewidth='0.11', color='black', zorder=2, clip_on=False)
    fig.scatter(x, y, color='r', s=30, zorder=3, clip_on=False)
    fig.set_xlim(-5, 5)
    fig.set_ylim(-5, 5)
    fig.set_xticks(np.arange(-5, 6, 5))
    fig.set_yticks(np.arange(-5, 6, 5))
    fig.set_title(title)
    plt.gca().set_zorder(1)
    return fig,


# 生成初始数据
r = 1
L = 10 * r
m = np.arange(1, int((5 / (0.5 * r)) + 1))
x = [0]
y = [0]
prev_x = []
prev_y = []
for i in m:
    rou = i * 0.5
    num = int(np.ceil(2 * np.pi * rou / 0.8))
    theta = np.linspace(0, 2 * np.pi, num, endpoint=False)
    x = np.concatenate((x, rou * np.cos(theta)))
    y = np.concatenate((y, rou * np.sin(theta)))

axis = plt.figure(figsize=(5, 5))
fig = plt.subplot(111)
title = 'fig-4(g) MWMS-S方式迭代'
alpha = 0.4

anim = animation.FuncAnimation(axis,
                               func=update,
                               fargs=(alpha, title),
                               frames=60,
                               interval=4000)
anim.save('fig-4(g) MWMS-S方式迭代.gif', fps=10, writer='pillow')
