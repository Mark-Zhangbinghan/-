# Pythonic 编程

[toc]

## 编程规范

**自己去看，很重要**

## for生成器

~~~python
l = []
def f(x):
    return x*x-1
for i in range(250):
	l.append(f(i))
    
# ----------------------------------------------
l = [f(i) for i in range(250)]
l = list(map(f, range(250)))
~~~

****

~~~python
l = []
def f(x):
    return x*x-1
for i in range(250):
    if i%4 == 1:
		l.append(f(i))
    else:
        l.append(i)
        
# -----------------------------------------------
l = [f(i) if i%4 == 1 else i for i in range(250)]
l = [f(i) for i in range(250) if i%4 == 1]
l = list(filter(lambda x : x%4 == 1, range(250)))
# l == ?
~~~

****

~~~python
for i, j in zip(range(10), range(100, 110)):
    d[i] = j
d = {i:j for i, j in zip(range(10), range(100, 110))}
from collections import defaultdict
~~~

****

~~~python
a = [[1, 2], [3, 4]]
l = []
for temp_list in a:
	for x in templist:
		l.append(x)
	# l += temp_list
l = [x for temp_list in a for x in temp_list]
l = sum(a, [])
~~~

## str

~~~python
"*".join(map(str, range(10)))
str(list(range(10)))[1:-1].split(', ')
~~~

## copy

~~~
def f(a):
	a[0] = "ok"
def g(a):
	a[0][0] = "ok"

a = [1, 2]
f(a)
print(a)
# ok

a = [1, 2]
f(a.copy())
import copy
f(copy.copy(a))
print(a)
# 1

a = [[1, 2], [3, 4]]
g(a)
print(a)
# ok


a = [[1, 2], [3, 4]]
g(a.copy())
print(a)
# ok

a = [[1, 2], [3, 4]]
g(copy.copy(a))
print(a)
# ok

a = [[1, 2], [3, 4]]
g(copy.deepcopy(a))
print(a)
# 1
~~~

## Others

~~~python
# while + else
i = 1
while i < 10:
	if i*i % 10 == 4:
        break
    i += 1
else:
	print("Not Find")
print(i)
~~~

****

~~~python
for _ in range(4):
    pass
~~~

****

~~~python
a = [1, 2, 3, 4]
for index, value in enumerate(a):
	print(index, value)
~~~

****

