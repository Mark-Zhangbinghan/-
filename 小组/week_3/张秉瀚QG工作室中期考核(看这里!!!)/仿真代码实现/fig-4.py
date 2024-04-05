import numpy as np
# import pandas as pd
import matplotlib.pyplot as plt
from tqdm import tqdm, trange   # trange(i)是tqdm(range(i))的一种简单写法

plt.rcParams['font.sans-serif'] = ['SimHei']  # 显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 设置正常显示符号


def make_matricx(N):  # 首次构造邻接矩阵
    nc = N.shape[0]
    x = np.zeros((nc, nc))
    for i in range(nc):
        for j in range(nc):
            if abs(N[i] - N[j]) < 0.95:
                x[i, j] = 1
    return x


def count_out(x, N):  # 计算收敛一次后的结果
    nc = len(x)
    w = []
    for i in range(nc):
        num = 0
        for j in range(nc):
            if x[i, j] == 1:
                num += 1
        if num != 0:
            w.append(1 / num)
        else:
            w.append(0)
    w = np.array(w)
    N = np.dot(N, x)
    nc = len(N)
    for i in range(nc):
        N[i] = N[i] * w[i]
    return N


fig_4 = plt.figure(figsize=(20, 15))
axis_x = []
axis_y = []
N = np.linspace(0, 4, 800)
for t in trange(16):
    axis_x.append(t)
    axis_y.append(N.copy())
    X = make_matricx(N)
    N = count_out(X, N)


axis_y = np.array(axis_y)
for i in range(axis_y.shape[1]):
    plt.plot(axis_x, axis_y[:, i])
plt.xlim(0, 15)
plt.ylim(0, 4)
plt.xticks(np.arange(0, 16, 5), fontsize=30)
plt.yticks(np.arange(0, 4.5, 0.5), fontsize=30)
plt.xlabel('t', fontsize=30)
plt.ylabel('X', fontsize=30)
plt.title('fig-4', fontsize=30)
plt.show()
