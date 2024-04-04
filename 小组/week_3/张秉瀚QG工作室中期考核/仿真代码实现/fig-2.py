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


"""  运用稀疏矩阵的做法
def make_matricx(N):  # 首次构造邻接矩阵
    nc = N.shape[0]
    rows = []
    cols = []
    data = []
    for i in trange(nc):
        for j in range(nc):
            if 0 < abs(N[i] - N[j]) < 1:
                rows.append(i)
                cols.append(j)
                data.append(1)
    return csr_matrix((data, (rows, cols)), shape=(nc, nc))

def count_out(x, N):  # 计算收敛一次后的结果
row, col, data = find(x)
nc = N.shape[0]
w = np.zeros(nc)
for number in trange(len(data)):
    i = row[number]
    j = col[number]
    num = 0
    for k in range(nc):
        if x[j, k] == 1:
            num += 1
        if num != 0:
            w[i] = 1 / num
N = np.dot(N, x)
nc = len(N)
for i in range(nc):
N[i] = N[i] * w[i]
return N
"""


fig_2 = plt.figure(figsize=(20, 15))
plt.plot(np.linspace(0, 25), np.linspace(0, 25//2), linestyle='--', color='black')
plt.plot(np.linspace(0, 25), np.linspace(0, -25//2), linestyle='--', color='black')

Line = np.linspace(0, 25, 200)
for L in tqdm(Line):
    num_points = 5000
    N = np.linspace(0, L, num_points)
    X = make_matricx(N)
    for i in trange(20):
        N = count_out(X, N)
        X = make_matricx(N)
    Y = N - L/2
    plt.scatter(np.full(len(Y), L), Y, marker='.', color='blue')
plt.xticks(fontsize=30)
plt.yticks(fontsize=30)
plt.xlabel('L', fontsize=30)
plt.ylabel('X-L/2', fontsize=30)
plt.title('fig-2', fontsize=30)
plt.show()
