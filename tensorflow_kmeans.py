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

iris = datasets.load_iris()
num_pts = len(iris.data)
num_feats = len(iris.data[0])

sess = tf.compat.v1.Session()
k=3
generations = 25

data_points = tf.Variable(iris.data)
cluster_labels = tf.Variable(tf.zeros([num_pts], dtype=tf.int64))

rand_starts = np.array([iris.data[np.random.choice(len(iris.data))] for _ in range(k)])
centroids = tf.Variable(rand_starts)


centroid_matrix = tf.reshape(tf.tile(centroids, [num_pts, 1]), [num_pts, k, num_feats])

point_matrix = tf.reshape(tf.tile(data_points, [1,k]), [num_pts, k, num_feats])

distances = tf.reduce_sum(tf.square(centroid_matrix - point_matrix), axis=-1)

centroid_group = tf.argmin(distances, axis=-1)

sum_total = tf.compat.v1.unsorted_segment_sum(data_points, centroid_group, 3)
num_total = tf.compat.v1.unsorted_segment_sum(tf.ones_like(data_points), centroid_group, 3)
means = sum_total / num_total
update = tf.group(centroids.assign(means), cluster_labels.assign(centroid_group))

#8、初始化模型

init = tf.compat.v1.global_variables_initializer()
sess.run(init)

#9、遍历迭代训练，更新每组分类的几何中心点
for i in range(generations):
    print('Calculating gen {},out of {}.'.format(i, generations))
    _, centroid_group_count = sess.run([update, centroid_group])
    group_count = []
    for ix in range(k):
        group_count.append(np.sum(centroid_group_count==ix))
    print('Group counts：{}'.format(group_count))
