#作者：宝蓓
#名称：K-means算法
#代码思路：基本K-Means算法：1、首先确定常数K，常数K意味着最终的聚类类别数；
#                           2、随机选定初始点为质心，并通过计算每一个样本与质心之间的相似度(这里为欧式距离)，将样本点归到最相似的类中；
#                           3、接着，重新计算每个类的质心(即为类中心)
#                           4、重复这样的过程，直到质心不再改变，最终就确定了每个样本所属的类别以及每个类的质心。
#选用的数据集：iris数据集，数据集已明确标注为3类

#1、首先先导入必要的编程库。
import numpy as np
import matplotlib.pyplot as plt
import tensorflow as tf
from sklearn import datasets
from scipy.spatial import cKDTree
#PCA主要是用来数据降维，将高维度的特征映射到低维度的特征，加快机器学习的速度。
from sklearn.decomposition import PCA
from sklearn.preprocessing import scale

#2、创建一个计算图会话，加载iris数据集
sess = tf.Session()
iris = datasets.load_iris()
#num_pts表示数据的总数
num_pts = len(iris.data)
#每一个样本所含的特征数，即本例中每个样本中含有4个特征
num_feats = len(iris.data[0])

#3、设置分类树
k=3
#设置迭代次数
generations = 25
#创建计算图所需的变量，初始化点和每个点所含的标签（即每个点属于哪一类）
data_points = tf.Variable(iris.data)
cluster_labels = tf.Variable(tf.zeros([num_pts], dtype=tf.int64))

#4、声明并初始化每个分组所需的几何中心，本例中选择3个数据集来初始化算法的几何中心
#for _ in range(k),做range(k)次iris.data[np.random.choice(len(iris.data))]的循环，即做k次,随机选取数据点的循环
rand_starts = np.array([iris.data[np.random.choice(len(iris.data))] for _ in range(k)])
centroids = tf.Variable(rand_starts)

#5、计算每个数据点到每个几何中心的距离。
#本例所使用的是：将几何中心点和数据点分别放入矩阵中，然后计算两个矩阵的欧氏距离
#centroid_matrix表示几何中心矩阵
#tf.tile(centroids, [num_pts, 1])这行代码，表示，将矩阵中心复制150次，有3个矩阵中心，所以这里有450行，每一行有4个特征
#tf.reshape(tf.tile(centroids, [num_pts, 1]), [num_pts, k, num_feats])表示将前面得到的 450 * 4的矩阵变为150*3*4的矩阵，表示分为150组，每组中有3个向量，每个向量里含有4个值
centroid_matrix = tf.reshape(tf.tile(centroids, [num_pts, 1]), [num_pts, k, num_feats])
#tf.tile(data_points, [1,k])将data_points中的列复制3次，也就是原来是4列，现在变为12列，变为150*12
#然后 reshape成 150*3*4，仍旧是150组，每组中有3个向量（这3个向量是相同的），每个向量有4个特征值
point_matrix = tf.reshape(tf.tile(data_points, [1,k]), [num_pts, k, num_feats])
#于是对这2个矩阵计算其欧氏距离
#reduction_indices = 2表示对于 a*b*c矩阵，把每个向量加起来成为一个新值，于是distance=150*3
distances = tf.reduce_sum(tf.square(centroid_matrix - point_matrix), reduction_indices = 2)

#6、分配时，是以到每个数据点最小距离为最接近的几何中心点
#tf.argmin(input, dimension, name=None)
#tf.argmin是返回input最小值的索引index，而dimension=1，表示在第2个维度进行求解（当dimension=0时，表示第一个维度），所以得到的是150个索引号(0,1,2),0表示和第一个几何中心比较近，应该放在第1类中
centroid_group = tf.argmin(distances, 1)

#7、计算每组分类的平均距离得到新的几何中心
def data_group_avg(group_ids, data):
    sum_total = tf.unsorted_segment_sum(data, group_ids, 3)
    #tf.ones_like是用于创建一个所有参数均为 1 的tensor对象
    num_total = tf.unsorted_segment_sum(tf.ones_like(data), group_ids, 3)
    avg_by_group = sum_total / num_total
    return(avg_by_group)
means = data_group_avg(centroid_group, data_points)
update = tf.group(centroids.assign(means), cluster_labels.assign(centroid_group))

#8、初始化模型
init = tf.global_variables_initializer()
sess.run(init)

#9、遍历迭代训练，更新每组分类的几何中心点
for i in range(generations):
    print('Calculating gen {},out of {}.'.format(i, generations))
    _, centroid_group_count = sess.run([update, centroid_group])
    group_count = []
    for ix in range(k):
        group_count.append(np.sum(centroid_group_count==ix))
    print('Group counts：{}'.format(group_count))
