import numpy as np
# import pandas as pd
import matplotlib.pyplot as plt
# import seaborn as sns
from tqdm import tqdm, trange   # trange(i)是tqdm(range(i))的一种简单写法
# from scipy.sparse import csr_matrix  # 进行稀疏矩阵运算
# from scipy.sparse import find
# import numba  # numpy是为面向numpy数组的计算任务而设计的
# from numba import jit

plt.rcParams['font.sans-serif'] = ['SimHei']  # 显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 设置正常显示符号


def make_matricx(N):  # 首次构造邻接矩阵
    nc = N.shape[0]
    x = np.zeros((nc, nc))
    for i in range(nc):
        for j in range(nc):
            if 0 < abs(N[i] - N[j]) < 1:
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


fig_6 = plt.figure(figsize=(40, 15))

ax1 = plt.subplot(1, 2, 1)  # 一行两列中的第一个图
agents_a1 = np.random.rand(200)
opinions_a1 = 2.5 * agents_a1
agents_a2 = np.random.rand(351)
opinions_a2 = 0.5 * agents_a2 + 2.5
N_a = np.concatenate((opinions_a1, opinions_a2))
N_a = np.array(N_a)
axis_xa = []
axis_ya = []
for t in trange(9):
    axis_xa.append(t)
    axis_ya.append(N_a.copy())
    X = make_matricx(N_a)
    N_a = count_out(X, N_a)

axis_ya = np.array(axis_ya)
for i in range(axis_ya.shape[1]):
    ax1.plot(axis_xa, axis_ya[:, i])
ax1.set_xlim(0, 8)
ax1.set_ylim(0, 3)
ax1.set_xticks(np.arange(0, 9, 2))
ax1.set_yticks(np.arange(0, 3.5, 0.5))
ax1.tick_params(axis='both', labelsize=30)
ax1.set_xlabel('t', fontsize=30)
ax1.set_ylabel('X', fontsize=30)
ax1.set_title('fig-6(a)', fontsize=30)


ax2 = plt.subplot(1, 2, 2)  # 一行两列中的第二个图
agents_b1 = np.random.rand(1517)
opinions_b1 = 2.5 * agents_b1
agents_b2 = np.random.rand(3484)
opinions_b2 = 0.5 * agents_b2 + 2.5
N_b = np.concatenate((opinions_b1, opinions_b2))
N_b = np.array(N_b)
axis_xb = []
axis_yb = []
for t in trange(31):
    axis_xb.append(t)
    axis_yb.append(N_b.copy())
    X = make_matricx(N_b)
    N_b = count_out(X, N_b)

axis_yb = np.array(axis_yb)
for i in range(axis_yb.shape[1]):
    ax2.plot(axis_xb, axis_yb[:, i])
ax2.set_xlim(0, 30)
ax2.set_ylim(0, 3)
ax2.set_xticks(np.arange(0, 31, 5))
ax2.set_yticks(np.arange(0, 3.5, 0.5))
ax2.tick_params(axis='both', labelsize=30)
ax2.set_xlabel('t', fontsize=30)
ax2.set_ylabel('X', fontsize=30)
ax2.set_title('fig-6(b)', fontsize=30)

plt.show()
